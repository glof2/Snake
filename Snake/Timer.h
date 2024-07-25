#pragma once
#include <SDL.h>

class Timer
{
private:
	Uint32 m_start_time{};
	Uint32 m_paused_time{};
public:
	// --- Constructors ---

	// Constructor for timer class
	Timer() = default;

	// --- Getters ---

	// Function name: getElapsedMilliseconds
	// Decription:    returns the amount of milliseconds elapsed since the timer has been started
	// Return value:  the amount of milliseconds elapsed
	Uint32 getElapsedMilliseconds();

	// Function name: getElapsedSeconds
	// Decription:    returns the amount of seconds elapsed since the timer has been started
	// Return value:  the amount of seconds elapsed
	float getElapsedSeconds();

	// --- Setters ---

	// --- Other functions ---
	
	// Function name: start
	// Description:   Starts the timer if it hasn't started yet or if it has been paused
	void start();

	// Function name: pause
	// Description:   Pauses the timer
	void pause();

	// Function name: reset
	// Description:   resets the timer, start needs to be called to start the timer again
	void reset();

	// Function name: getCurrentTicks
	// Description:   returns the amount of milliseconds elapsed since program started
	// Return value:  the amount of milliseconds elapsed since program start
	static Uint32 getCurrentTicks();

	// --- Destructor ---

	~Timer() = default;
};

