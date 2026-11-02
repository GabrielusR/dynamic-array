#pragma once

#include <cstddef>
#include <cmath>

const std::size_t BUFF_SIZE = 1;

template<typename T>
class DynamicArray {
	
public:

	//constructors and destructors
	DynamicArray();
	explicit DynamicArray(std::size_t size);
	DynamicArray(const DynamicArray & another);
	DynamicArray(DynamicArray && another) noexcept;
	DynamicArray & operator=(const DynamicArray & another);
	DynamicArray & operator=(DynamicArray && another) noexcept;
	~DynamicArray();
	
	//element methods
	void add(const T& data);
	void remove(unsigned int index);
	
	const T & at(unsigned int index) const;
	const T & operator[](unsigned int index) const;
	
	//container methods
	void printArray() const;
	std::size_t getSize() const;
	std::size_t getCapacity() const;
	
	const T * const get() const;

private:

	//private members
	T * m_buffer;
	std::size_t m_size;
	std::size_t m_capacity;
	
	//internal methods
	void resize();
};

#include <iostream>
#include <cstring>

template<typename T>
DynamicArray<T>::DynamicArray() 
	: m_size(0), m_capacity(BUFF_SIZE) { 
	
	DEBUG("DynamicArray()");
	
	m_buffer = new T[BUFF_SIZE]{}; 
}

template<typename T>
DynamicArray<T>::DynamicArray(std::size_t size) 
	: m_size(0), m_capacity(size) { 
	
	DEBUG("DynamicArray(std::size_t)");
	
	m_buffer = new T[size]{}; 
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray & another) 
	: m_size(another.m_size), m_capacity(another.m_capacity) {
		
	DEBUG("DynamicArray(const DynamicArray&)");
	
	m_buffer = new T[another.m_capacity];
	
	memcpy(m_buffer, another.m_buffer, another.m_size*sizeof(T));
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray & another) {
	
	DEBUG("DynamicArray & operator=(const DynamicArray&)");
	
	if(this == &another) {

		return *this;
	}
	
	delete [] m_buffer;
	
	m_buffer = new T[another.m_capacity];
	
	memcpy(m_buffer, another.m_buffer, another.m_size*sizeof(T));
	
	m_size = another.m_size;
	m_capacity = another.m_capacity;
	
	return *this;
}

template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray && another) noexcept
	: m_size(another.m_size), m_capacity(another.m_capacity)
{
	DEBUG("DynamicArray(DynamicArray&&)");
	
	m_buffer = another.m_buffer;
	
	//create hollow object
	another.m_size = 0;
	another.m_capacity = 0;
	another.m_buffer = nullptr;
}

template<typename T>
DynamicArray<T> & DynamicArray<T>::operator=(DynamicArray && another) noexcept {
	
	DEBUG("DynamicArray & operator=(DynamicArray&&)");
	
	if(this != &another) {
		
		//change ownership ("steal")
		m_size = another.m_size;
		m_capacity = another.m_capacity;
		delete [] m_buffer;
		m_buffer = another.m_buffer;
		
		//create hollow object
		another.m_size = 0;
		another.m_capacity = 0;
		another.m_buffer = nullptr;
	}
		
	return *this;
}

template<typename T>
DynamicArray<T>::~DynamicArray() { 
	
	DEBUG("~DynamicArray()");
	
	delete [] m_buffer; 
	
}

template<typename T>
std::size_t DynamicArray<T>::getSize() const {

	return m_size;
}

template<typename T>
std::size_t DynamicArray<T>::getCapacity() const {
	
	return m_capacity;
}

template<typename T>
void DynamicArray<T>::resize() {
	
	DEBUG("resize()");
	
	std::size_t newSize = round(m_size * 1.5f);
	
	T * tmp = new T[newSize];
	
	memcpy(tmp, m_buffer, m_size*sizeof(T));
	
	delete [] m_buffer;
	
	m_buffer = tmp;
	
	m_capacity = newSize;
}

template<typename T>
void DynamicArray<T>::add(const T&data) {
	
	if(m_size == m_capacity) {
		
		resize();
	}
	
	m_buffer[m_size] = data;
	
	m_size++;	
}

template<typename T>
void DynamicArray<T>::remove(unsigned int index) {
	
	if(index >= m_capacity) {
		
		LOG("Index out of bound.");
		
		throw std::perror;
	}
	
	m_buffer[index] = 0;
	
	m_size--;
}

template<typename T>
const T & DynamicArray<T>::operator[](unsigned int index) const {
	
	if(index >= m_capacity) {
		
		LOG("Index out of bound.");
		
		throw std::perror;
	}
	
	return m_buffer[index];
}

template<typename T>
const T & DynamicArray<T>::at(unsigned int index) const {
	
	if(index >= m_capacity) {
		
		DEBUG("Index out of bound.");
		
		throw std::perror;
	}
	
	return m_buffer[index];
}

template<typename T>
void DynamicArray<T>::printArray() const {
	
	for(std::size_t i = 0; i < m_size; i++) {
		
		std::cout << m_buffer[i] << ' ';
	}
	
	std::cout << std::endl;
}

template<typename T>
std::ostream & operator<<(std::ostream& os, const DynamicArray<T>& arr) {
	
	for(std::size_t i = 0; i < arr.getSize(); i++) {
		
		os << arr.at(i) << ' ';
	}
	
	os << std::endl;
	
	return os;
}
