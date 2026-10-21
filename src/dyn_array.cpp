#include <iostream>
#include <cstring>
#include "dyn_array.h"

DynamicArray::DynamicArray() 
	: m_size(0), m_capacity(BUFF_SIZE) { 
	
	std::cout << "DynamicArray()" << std::endl; 
	
	m_buffer = new int[BUFF_SIZE]; 
}

DynamicArray::DynamicArray(unsigned int size) 
	: m_size(0), m_capacity(size) { 
	
	std::cout << "DynamicArray(unsigned int)" << std::endl; 
	
	m_buffer = new int[size]; 
	
}

DynamicArray::DynamicArray(const DynamicArray & another) 
	: m_size(another.m_size), m_capacity(another.m_capacity) {
		
	std::cout << "DynamicArray(const DynamicArray&)" << std::endl; 
	
	m_buffer = new int[another.m_capacity];
	
	memcpy(m_buffer, another.m_buffer, another.m_size*sizeof(int));
}

DynamicArray& DynamicArray::operator=(const DynamicArray & another) {
	
	std::cout << "DynamicArray & operator=(const DynamicArray&)" << std::endl; 
	
	if(this == &another) {

		return *this;
	}
	
	delete [] m_buffer;
	
	m_buffer = new int[another.m_capacity];
	
	memcpy(m_buffer, another.m_buffer, another.m_size*sizeof(int));
	
	m_size = another.m_size;
	m_capacity = another.m_capacity;
	
	return *this;
}

DynamicArray::DynamicArray(DynamicArray && another) noexcept
	: m_size(another.m_size), m_capacity(another.m_capacity)
{
	std::cout << "DynamicArray(DynamicArray&&)" << std::endl;
	
	m_buffer = another.m_buffer;
	
	//create hollow object
	another.m_size = 0;
	another.m_capacity = 0;
	another.m_buffer = nullptr;
}

DynamicArray & DynamicArray::operator=(DynamicArray && another) noexcept {
	
	std::cout << "DynamicArray & operator=(DynamicArray&&)" << std::endl;
	
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

DynamicArray::~DynamicArray() { 
	
	std::cout << "~DynamicArray()" << std::endl; 
	
	delete [] m_buffer; 
	
}

unsigned int DynamicArray::getSize() const {

	return m_size;
}

unsigned int DynamicArray::getCapacity() const {
	
	return m_capacity;
}

void DynamicArray::resize() {
	
	std::cout << "resize()" << std::endl;
	
	unsigned int newSize = m_size * 1.5;
	
	int * tmp = new int[newSize];
	
	memcpy(tmp, m_buffer, m_size*sizeof(int));
	
	delete [] m_buffer;
	
	m_buffer = tmp;
	
	m_capacity = newSize;
}

void DynamicArray::add(const int&data) {
	
	if(m_size == m_capacity) {
		
		resize();
	}
	
	m_buffer[m_size] = data;
	
	m_size++;	
}

void DynamicArray::remove(unsigned int index) {
	
	if(index >= m_capacity) {
		
		std::cout << "Index out of bound." << std::endl;
		
		throw std::perror;
	}
	
	m_buffer[index] = 0;
	
	m_size--;
}

const int & DynamicArray::operator[](unsigned int index) const {
	
	if(index >= m_capacity) {
		
		std::cout << "Index out of bound." << std::endl;
		
		throw std::perror;
	}
	
	return m_buffer[index];
}

const int & DynamicArray::at(unsigned int index) const {
	
	if(index >= m_capacity) {
		
		std::cout << "Index out of bound." << std::endl;
		
		throw std::perror;
	}
	
	return m_buffer[index];
}

void DynamicArray::printArray() const {
	
	for(unsigned int i = 0; i < m_size; i++) {
		
		std::cout << m_buffer[i] << ' ';
	}
	
	std::cout << std::endl;
}

std::ostream & operator<<(std::ostream& os, const DynamicArray& arr) {
	
	for(unsigned int i = 0; i < arr.getSize(); i++) {
		
		os << arr.at(i) << ' ';
	}
	
	os << std::endl;
	
	return os;
}
