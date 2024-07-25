
#include "ColorRenderStrategy.h"

ColorRenderStrategy::ColorRenderStrategy(const SDL_Color& color) : m_color {color.r, color.g, color.b, color.a} {}

void ColorRenderStrategy::render(SDL_Renderer* renderer, const Tile& tile) const
{
	// Save color 
	SDL_Color prev_color{};
	SDL_GetRenderDrawColor(renderer, &prev_color.r, &prev_color.g, &prev_color.b, &prev_color.a);

	// Set new color
	SDL_SetRenderDrawColor(renderer, m_color.r, m_color.g, m_color.b, m_color.a);

	// Render
	unsigned int render_size{ tile.getRenderSize() };
	SDL_Rect rect{ tile.getX() * render_size, tile.getY() * render_size, render_size, render_size };
	SDL_RenderFillRect(renderer, &rect);

	// Set previous color
	SDL_SetRenderDrawColor(renderer, prev_color.r, prev_color.g, prev_color.b, prev_color.a);
}