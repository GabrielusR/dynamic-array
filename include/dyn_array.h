#pragma once

const unsigned int BUFF_SIZE = 10;

class DynamicArray {
	
public:

	//constructors and destructors
	DynamicArray();
	explicit DynamicArray(unsigned int size);
	DynamicArray(const DynamicArray & another);
	DynamicArray(DynamicArray && another) noexcept;
	DynamicArray & operator=(const DynamicArray & another);
	DynamicArray & operator=(DynamicArray && another) noexcept;
	~DynamicArray();
	
	//element methods
	void add(const int& data);
	void remove(unsigned int index);
	
	const int & at(unsigned int index) const;
	const int & operator[](unsigned int index) const;
	
	//container methods
	void printArray() const;
	unsigned int getSize() const;
	unsigned int getCapacity() const;
	
	const int * const get() const;

private:

	//private members
	int * m_buffer;
	unsigned int m_size;
	unsigned int m_capacity;
	
	//internal methods
	void resize();
};