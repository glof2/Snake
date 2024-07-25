#pragma once
#include <SDL.h>

class Renderable
{
private:

public:
	// --- Other funtions ---

	// Function name: render
	// Description:   renders the Renderable to the renderer
	// Arguments:     renderer - the renderer to render to
	virtual void render(SDL_Renderer* renderer) const = 0;

	// --- Destructor ---

	virtual ~Renderable() = default;
};