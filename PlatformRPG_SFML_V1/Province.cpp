#include "Province.h"



Province::Province(unsigned int size)
{
	m_size = size;
	m_chunks = new Chunk[size];
}


Province::~Province()
{
	delete[] m_chunks;
}
