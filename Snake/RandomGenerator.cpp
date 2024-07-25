#include "RandomGenerator.h"

// --- Getters ---
int RandomGenerator::getInt(int min, int max)
{
	return min + (m_mt() % (max-min+1));
}


RandomGenerator& RandomGenerator::getInstance()
{
	static RandomGenerator instance{};
	return instance;
}