#include "Timer.h"

// --- Getters ---
Uint32 Timer::getElapsedMilliseconds()
{
	if (m_start_time != 0 && m_paused_time == 0)
	{
		return (getCurrentTicks() - m_start_time);
	}
	else if (m_start_time != 0 && m_paused_time != 0)
	{
		return (getCurrentTicks() - m_start_time) - (getCurrentTicks() - m_paused_time);
	}
	else
	{
		return 0;
	}
}

float Timer::getElapsedSeconds()
{
	return getElapsedMilliseconds() / 1000.0f;
}

// --- Setters ---

// --- Other functions ---
void Timer::start()
{
	if (m_start_time == 0) // Situation where timer is started exactly at 0 SDL ticks shouldn't be possible
	{
		m_start_time = SDL_GetTicks(); 
		m_paused_time = 0;
	}
	else if (m_paused_time != 0)
	{
		m_start_time = getCurrentTicks() - getElapsedMilliseconds();
		m_paused_time = 0;
	}
}

// Function name: pause
// Description:   Pauses the timer
void Timer::pause()
{
	if (m_paused_time == 0)
	{
		m_paused_time = getCurrentTicks();
	}
}

// Function name: reset
// Description:   resets the timer, start needs to be called to start the timer again
void Timer::reset()
{
	m_paused_time = 0;
	m_start_time = 0;
}

Uint32 Timer::getCurrentTicks()
{
	return SDL_GetTicks();
}