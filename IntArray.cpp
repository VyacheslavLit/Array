#include "IntArray.h"


IntArray::IntArray(int length) :m_length{ length }
{
	if (length > 0) {
		m_data = new int[length] {};
	}
	else m_data = nullptr;
}

void IntArray::reallocate(int newLength)
 {
		erase();
		if (newLength <= 0)
			return;
		m_data = new int[newLength];
		m_length = newLength;
	}

void IntArray::resize(int newLength)
{
	if (newLength == m_length)
		return;
	if (newLength <= 0)
	{
		erase();
		return;
	}
	int* data = new int[newLength];
	if (m_length > 0)
	{
		int elementsToCopy = (newLength > m_length) ? m_length : newLength;
		for (int index = 0; index < elementsToCopy; ++index)
			data[index] = m_data[index];
	}
	delete[] m_data;
	m_data = data;
	m_length = newLength;
}

void IntArray::insertBefore(int value, int index)
{
	if (index < 0 || index > m_length)
	{
		throw Bad_Range();
	}
	int* data = new int[m_length + 1];
	for (int before = 0; before < index; ++before)
		data[before] = m_data[before];
	data[index] = value;
	for (int after = index; after < m_length; ++after)
		data[after + 1] = m_data[after];
	delete[] m_data;
	m_data = data;
	++m_length;
}

void IntArray::remove(int index)
{
	if (index < 0 || index >= m_length)
	{
		throw Bad_Range();
	}
	if (m_length == 1)
	{
		erase();
		return;
	}
	int* data = new int[m_length - 1];
	for (int before = 0; before < index; ++before)
		data[before] = m_data[before];
	for (int after = index + 1; after < m_length; ++after)
		data[after - 1] = m_data[after];
	delete[] m_data;
	m_data = data;
	--m_length;
}