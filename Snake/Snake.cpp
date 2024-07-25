#include "Snake.h"

// Constructor for Snake class
Snake::Snake(int x, int y) : m_head{ new SnakeTile(x, y, {104, 100, 0, 255})} {}

// --- Virtual functions ----
void Snake::render(SDL_Renderer* renderer) const
{
	SnakeTile* current{m_head};
	while (current != nullptr)
	{
		current->render(renderer);
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

		current = current->getNext();
	}
}

// --- Getters ---
SnakeTile* Snake::getHead()
{
	return m_head;
}

SnakeTile* Snake::getTail()
{
	SnakeTile* tail{ m_head };
	while (tail->getNext() != nullptr)
	{
		tail = tail->getNext();
	}
	return tail;
}

// --- Setters ---

// --- Other functions ---
void Snake::handleInput(const SDL_Event& ev)
{

	Direction prev_direction{ m_direction };
	if (ev.type == SDL_KEYDOWN)
	{
		switch (ev.key.keysym.sym)
		{
			// Add previous check thing (check based on the previous SnakeTile instead of direction)
			case SDLK_w:
			{
				m_direction = Direction::UP;
				break;
			}
			case SDLK_s:
			{
				m_direction = Direction::DOWN;
				break;
			}
			case SDLK_a:
			{
				m_direction = Direction::LEFT;
				break;
			}
			case SDLK_d:
			{
				m_direction = Direction::RIGHT;
				break;
			}
		}
	}

	if (m_head->getNext() == nullptr)
	{
		return;
	}


	int prev_x{ m_head->getNext()->getX() };
	int prev_y{ m_head->getNext()->getY() };

	switch (m_direction)
	{
		case Direction::UP:
		{
			if (m_head->getY() - prev_y == 1)
			{
				m_direction = prev_direction;
			}
			break;
		}
		case Direction::DOWN:
		{
			if (m_head->getY() - prev_y == -1)
			{
				m_direction = prev_direction;
			}
			break;
		}
		case Direction::LEFT:
		{
			if (m_head->getX() - prev_x == 1)
			{
				m_direction = prev_direction;
			}
			break;
		}
		case Direction::RIGHT:
		{
			if (m_head->getX() - prev_x == -1)
			{
				m_direction = prev_direction;
			}
			break;
		}
	}
}

void Snake::update()
{
	int prev_x{ m_head->getX() };
	int prev_y{ m_head->getY() };

	// Move the head
	switch (m_direction)
	{
		case Direction::UP:
		{
			m_head->setY(prev_y - 1);
			break;
		}
		case Direction::DOWN:
		{
			m_head->setY(prev_y + 1);
			break;
		}
		case Direction::LEFT:
		{
			m_head->setX(prev_x - 1);
			break;
		}
		case Direction::RIGHT:
		{
			m_head->setX(prev_x + 1);
			break;
		}
	}

	// Move the rest of the snake
	SnakeTile* current{m_head->getNext()};
	while (current != nullptr)
	{
		int x{ current->getX() };
		int y{ current->getY() };

		current->setX(prev_x);
		current->setY(prev_y);

		prev_x = x;
		prev_y = y;

		current = current->getNext();
	}
}

void Snake::enlarge()
{
	SnakeTile* tail{ getTail() };
	
	int x{tail->getX()};
	int y{tail->getY()};

	if (tail->getPrevious() != nullptr)
	{
		// If left as is the snake will "grow" by itself
		//x += x - tail->getPrevious()->getX();
		//y += y - tail->getPrevious()->getY();
	}
	else
	{
		switch (m_direction)
		{
			case Direction::UP:
			{
				y += 1;
				break;
			}
			case Direction::DOWN:
			{
				y -= 1;
				break;
			}
			case Direction::LEFT:
			{
				x += 1;
				break;
			}
			case Direction::RIGHT:
			{
				x -= 1;
				break;
			}
			case Direction::NONE:
			{
				// Shouldn't happen, but whatever
				y += 1;
				break;
			}
		}
	}
	

	SnakeTile* new_tile{ new SnakeTile(x, y, {104, 208, 0, 255} ,tail) };
	tail->setNext(new_tile);
}

bool Snake::isCollided(const Tile& tile)
{
	return (m_head->getX() == tile.getX()) && (m_head->getY() == tile.getY());
}

bool Snake::isCollidedWithSelf()
{
	SnakeTile* current{ m_head->getNext() };

	while (current != nullptr)
	{
		if (isCollided(*current))
		{
			return true;
		}
		current = current->getNext();
	}

	return false;
}

// Destructor
Snake::~Snake()
{
	SnakeTile* current{ m_head };
	while (current != nullptr)
	{
		// Save the next snake tile
		SnakeTile* next{ current->getNext() };

		// Destroy current snake tile
		delete current;

		// Set the current snake tile to the next one
		current = next;
	}

	current = nullptr;
}