#pragma once
#include "Tile.h"

class AppleTile : public Tile
{
private:
	int m_points{};
public:
	// --- Constructor ---

	// Constructor for AppleTile class
	// Arguments: x - the x coordinate of the tile
	//            y - the y coordinate of the tile
	//            points - the amount of points the AppleTile gives
	AppleTile(int x, int y, int points = 1);

	// --- Virtual functions ---

	// --- Getters ---

	// Function name: getPoints
	// Description:   returns the amount of points that this AppleTile gives
	// Return value:  the amount of points that this AppleTile gives
	int getPoints() const;

	// --- Destructor ---

	virtual ~AppleTile() = default;
};

