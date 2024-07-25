#pragma once
#include "Tile.h"

class SnakeTile : public Tile
{
private:
	SnakeTile* m_prev{};
	SnakeTile* m_next{};
public:
	// Constructor for SnakeTile class
	// Arguments: x - the x coordinate of the tile
	//            y - the y coordinate of the tile
	//			  color - the color of the snake tile
	//            prev - the previous SnakeTile
	//            next - the next SnakeTile
	SnakeTile(int x = 0, int y = 0, const SDL_Color& color = { 0, 0, 0, 255 }, SnakeTile* prev = nullptr, SnakeTile* next = nullptr);

	// Virtual functions

	// --- Getters ----

	// Function name: getPrevious
	// Description:   getter for the previous SnakeTile
	// Return value:  the previous SnakeTile
	SnakeTile* getPrevious();

	// Function name: getNext
	// Description:   getter for the next SnakeTile
	// Return value:  the next SnakeTile
	SnakeTile* getNext();

	// --- Setters ----

	// Function name: setPrevious
	// Description:   setter for the previous SnakeTile
	// Arguments:     prev - the new previous SnakeTile
	void setPrevious(SnakeTile* const prev);

	// Function name: setNext
	// Description:   setter for the next SnakeTile
	// Arguments:     prev - the new next SnakeTile
	void setNext(SnakeTile* const next);

	// Destructor
	virtual ~SnakeTile() = default;
};

