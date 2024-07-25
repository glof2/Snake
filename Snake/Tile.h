#pragma once
#include "Renderable.h"
#include "TileRenderStrategy.h"

class TileRenderStrategy;

class Tile : public Renderable
{
private:
	int m_x{};
	int m_y{};
	TileRenderStrategy* m_render_strategy{};
	static int s_render_size;
public:
	// Constructor for Tile interaface
	// Arguments: x - the x coordinate of the tile
	//            y - the y coordinate of the tile
	Tile(int x, int y, TileRenderStrategy* render_strategy);

	// Stop copying, because the class isn't non deep copy safe
	Tile(const Tile&) = delete;
	Tile& operator=(const Tile&) = delete;

	// Virtual functions
	// -- TODO --
	// Switch over to Strategy pattern for rendering
	// AppleTile and SnakeTile for example use the same render function so they don't adhere to DRY
	virtual void render(SDL_Renderer* render) const override;

	// --- Getters ---
	
	// Function name: getX
	// Description:   a getter for the X coordinate of the tile
	// Return value:  the x coordinate of the tile
	int getX() const;

	// Function name: getY
	// Description:   a getter for the Y coordinate of the tile
	// Return value:  the y coordinate of the tile
	int getY() const;

	// Function name: getRenderSize
	// Description:   getter for the render size of all Tiles
	// Return value:  the render size of all SnakeTiles
	static unsigned int getRenderSize();

	// --- Settters ---

	// Function name: setX
	// Description:   a setter for the X coordinate of the tile
	// Arguments:     x - the new x coordinate
	void setX(int x);

	// Function name: setY
	// Description:   a setter for the Y coordinate of the tile
	// Arguments:     y - the new y coordinate
	void setY(int y);

	// Function name: setRenderSize
	// Description:   setter for the render size of all Tiles
	// Arguments:     render_size - the new render size
	static void setRenderSize(unsigned int render_size);

	virtual ~Tile();
};

