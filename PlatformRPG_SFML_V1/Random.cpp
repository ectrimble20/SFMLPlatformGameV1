#include "Random.h"
#include <ctime>

Random& Random::get()
{
	static Random r;
	return r;
}

int Random::intInRange(int low, int high)
{
	std::uniform_int_distribution<int> distribution(low, high);
	return distribution(m_randomNumberAlgo);
}

float Random::floatInRange(float low, float high)
{
	std::uniform_real_distribution<float> distribution(low, high);
	return distribution(m_randomNumberAlgo);
}

//initialize the mt19937 algorithm
Random::Random()
{
	m_randomNumberAlgo.seed((unsigned int)std::time(nullptr));
}