#include "Game.h"
#include "RandomGenerator.h"
#include "array"
#include "vector"

void Game::free()
{
	for (AppleTile* tile : m_tiles)
	{
		delete tile;
	}
	m_tiles.clear();

	delete m_snake;
	m_snake = nullptr;
}

// --- Constructor ---
Game::Game(unsigned int width, unsigned int height, unsigned int apple_count, int apple_points) : m_width{width}, m_height{height}, m_start_apple_count{apple_count}, m_apple_points{apple_points}, m_snake{new Snake(width / 2, height / 2)}
{
	addApple(apple_count);
}

// --- Getters ---

unsigned int Game::getWidth() const
{
	return m_width;
}

unsigned int Game::getHeight() const
{
	return m_height;
}

Game::GameState Game::getState() const
{
	return m_state;
}

// --- Setters ---



// --- Other functions ---

void Game::addApple(unsigned int count)
{
	if (count == 0)
	{
		return;
	}

	// Gather possible spawn locations
	std::vector<std::array<int, 2>> possible_locations{};
	for (int x{}; x < m_width; ++x)
	{
		for (int y{}; y < m_height; ++y)
		{
			possible_locations.push_back({ x, y });
		}
	}

	// Delete spawn locations already taken by other tiles
	for (const Tile* tile : m_tiles)
	{
		auto possible_location_it{ std::find(possible_locations.begin(), possible_locations.end(), std::array<int,2>{tile->getX(), tile->getY()})};
		if (possible_location_it != possible_locations.end())
		{
			possible_locations.erase(possible_location_it);
		}
	}

	// Delete spawn locations already taken by the snake
	SnakeTile* current{ m_snake->getHead() };
	int size{};
	while (current != nullptr)
	{
		++size;
		auto possible_location_it{ std::find(possible_locations.begin(), possible_locations.end(), std::array<int,2>{current->getX(), current->getY()}) };
		if (possible_location_it != possible_locations.end())
		{
			possible_locations.erase(possible_location_it);
		}

		current = current->getNext();
	}

	// Add Apples to possible spawn locations
	RandomGenerator& generator{ RandomGenerator::getInstance() };
	for (int i{}; i < count; ++i)
	{
		if (possible_locations.size() == 0)
		{
			break;
		}
		int position{ generator.getInt(0, possible_locations.size() - 1) };
		m_tiles.push_back(new AppleTile{ possible_locations[position][0], possible_locations[position][1], m_apple_points });

		possible_locations.erase(possible_locations.begin() + position);
	}
	
}

void Game::update()
{
	if (m_state != GameState::RUNNING)
	{
		return;
	}

	m_snake->update();

	// Check for collision with self
	if (m_snake->isCollidedWithSelf())
	{
		m_state = GameState::OVER;
	}

	// Check for out of bounds
	int x{m_snake->getHead()->getX()};
	int y{ m_snake->getHead()->getY() };
	if (x < 0 || x >= m_width || y < 0 || y >= m_height)
	{
		m_state = GameState::OVER;
	}

	// Check for collision with apple
	for (auto tile{ m_tiles.begin()}; tile < m_tiles.end();)
	{
		if (m_snake->isCollided(**tile))
		{
			// Add points
			m_score += (*tile)->getPoints();
			for (int i{}; i < (*tile)->getPoints(); ++i)
			{
				m_snake->enlarge();
			}

			// Erase the tile
			delete (*tile);
			tile = m_tiles.erase(tile);
		}
		else
		{
			++tile;
		}
	}

	if (m_score >= m_width * m_height)
	{
		m_state = GameState::OVER;
	}
	// Add apples
	else if (m_tiles.size() < m_start_apple_count)
	{
		addApple();
	}
}

void Game::handleInput(const SDL_Event& ev)
{
	if (m_state == GameState::RUNNING)
	{
		m_snake->handleInput(ev);
	}
}

void Game::render(SDL_Renderer* renderer) const
{
	for (AppleTile* tile : m_tiles)
	{
		tile->render(renderer);
	}

	m_snake->render(renderer);
}

void Game::start()
{
	m_state = GameState::RUNNING;
}

void Game::reset()
{
	free();
	m_score = 1;
	m_state = GameState::NOT_STARTED;
	m_snake = new Snake(m_width / 2, m_height / 2);
	addApple(m_start_apple_count);
}

Game::~Game()
{
	free();
}