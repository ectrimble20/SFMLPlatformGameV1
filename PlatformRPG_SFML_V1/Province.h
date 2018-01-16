#pragma once
#include "Chunk.h"

/*
Note:

This classes X/Y are in Chunks.

A Chunk is a set of 32 wide by 128 high tiles.  So if the size is 4, it is 32x4 by 128 (so 128x128 in this case.  So each "size"
increases the number of chunk sets by 1.  Chunks are always in order left[0] -> right[n]
*/

class Province
{
public:
	Province(unsigned int size);
	~Province();
private:
	//these are just for reference when something is asking for size parameters
	unsigned int m_size;
	Chunk * m_chunks;
};

