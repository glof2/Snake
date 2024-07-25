#include "AppleTile.h"
#include "ColorRenderStrategy.h"

// --- Constructor ---
AppleTile::AppleTile(int x, int y, int points) : Tile(x, y, new ColorRenderStrategy({255, 0, 0, 255})), m_points{points} {}

// --- Virtual functions ---

// --- Getters ---
int AppleTile::getPoints() const
{
	return m_points;
}