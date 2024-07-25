#include "SnakeTile.h"
#include "ColorRenderStrategy.h"

// Static
int SnakeTile::s_render_size{ 0 };

// Constructor
SnakeTile::SnakeTile(int x, int y, const SDL_Color& color, SnakeTile* prev, SnakeTile* next) : Tile(x, y, new ColorRenderStrategy(color)), m_prev{prev}, m_next{next} {}

// Virtual functions

// --- Getters ----
SnakeTile* SnakeTile::getPrevious()
{
	return m_prev;
}

SnakeTile* SnakeTile::getNext()
{
	return m_next;
}

// --- Setters ----
void SnakeTile::setPrevious(SnakeTile* const prev)
{
	m_prev = prev;
}

void SnakeTile::setNext(SnakeTile* const next)
{
	m_next = next;
}