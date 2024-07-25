#pragma once
#include "TileRenderStrategy.h"

// ColorRenderStrategy
// Renders the tile by filling the space the tile occupies with provided color
class ColorRenderStrategy : public TileRenderStrategy
{
private:
	SDL_Color m_color{};
public:
	// --- Constructors ---

	// The ColorRenderStrategy constructor
	// Arguments: color - the color that the strategy will render
	ColorRenderStrategy(const SDL_Color& color);

	// --- Virtual functions ---

	// Function name: render
	// Description:   renders the tile with ColorRenderStrategy
	// Arguments:     renderer - the renderer to render to
	//                tile - the tile to render
	virtual void render(SDL_Renderer* renderer, const Tile& tile) const override;

	// --- Destructor ---

	virtual ~ColorRenderStrategy() = default;
};

