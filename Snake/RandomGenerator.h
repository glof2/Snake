#pragma once
#include <random>

class RandomGenerator
{
private:
	std::mt19937 m_mt{static_cast<std::mt19937::result_type>( time(NULL) ) };
	RandomGenerator() = default;
public:
	// Get rid of copying because it's a singleton
	RandomGenerator(RandomGenerator&) = delete;
	RandomGenerator& operator=(const RandomGenerator&) = delete;

	// --- Getters ---

	// Function name: getInt
	// Description:   generates a random number between two given values
	// Arguments:     min - minimum value
	//                max - maximum value
	// Return value:  the random number generated
	int getInt(int min, int max);

	// Function name: getInstance
	// Description:   gets RandomGenerator object, if one doesn't exist it creates it
	// Return value:  RandomGenerator singleton object
	static RandomGenerator& getInstance();

	// --- Destructor ---

	~RandomGenerator() = default;
};

