#pragma once
#ifndef INTARRAY_H
#define INTARRAY_H
#include "Bad.h"
#include <iostream>
#include <Windows.h>
using namespace std;


class IntArray {
public:
	int m_length{};
	int* m_data{};
public:
	IntArray() :m_length(0), m_data(nullptr) {}
	IntArray(int length);
	~IntArray() { delete[] m_data; }
	void erase() { delete[] m_data, m_data = nullptr, m_length = 0; }
	int& operator[](int index) {
		if (index < 0 || index >= m_length)
		{
			throw Bad_Range();
		}
		return m_data[index];
	}
	int getLength() { return m_length; }
	int getMdata(int index) { return m_data[index]; }
	void setMdata(int index, int a) { m_data[index] = a; }
	void setLength(int length) { m_length = length; }
	void reallocate(int newLength);
	void resize(int newLength);
	void insertBefore(int value, int index);
	void remove(int index);
	void insertAtBeginning(int value) { insertBefore(value, 0); } 
	void insertAtEnd(int value) { insertBefore(value, m_length); }
};
#endif