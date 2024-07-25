#pragma once
#include <SDL.h>
#include "Tile.h"

class Tile;

class TileRenderStrategy
{
public:
	// --- Virtual Functions ---

	// Function name: render
	// Description:   renders the Tile based on the strategy implementation
	// Arguments:     renderer - the renderer to render to
	//                tile - the tile to renderer
	virtual void render(SDL_Renderer* renderer, const Tile& tile) const = 0;

	// --- Destructor ---

	virtual ~TileRenderStrategy() = default;
};

