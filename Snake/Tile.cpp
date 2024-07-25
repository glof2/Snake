#include "Tile.h"

Tile::Tile(int x, int y, TileRenderStrategy* const render_strategy) : m_x{ x }, m_y{ y }, m_render_strategy{ render_strategy } {}

void Tile::render(SDL_Renderer* renderer) const
{
	m_render_strategy->render(renderer, *this);
}

int Tile::getX() const
{
	return m_x;
}

int Tile::getY() const
{
	return m_y;
}

unsigned int Tile::getRenderSize()
{
	return s_render_size;
}

void Tile::setX(int x)
{
	m_x = x;
}

void Tile::setY(int y)
{
	m_y = y;
}

void Tile::setRenderSize(unsigned int render_size)
{
	s_render_size = render_size;
}

Tile::~Tile()
{
	delete m_render_strategy;
}