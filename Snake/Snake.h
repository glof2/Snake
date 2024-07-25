#pragma once
#include <SDL.h>
#include "SnakeTile.h"
#include "Renderable.h"


class Snake : public Renderable
{
public:
	enum class Direction
	{
		UP,
		LEFT,
		RIGHT,
		DOWN,
		NONE
	};
private:
	// Made a pointer for consistency sake, I'll need to dynamically allocate other SnakeTiles (or store them somewhere, but I chose this)
	SnakeTile* m_head{};
	Direction m_direction{ Direction::NONE };
public:
	// --- Constructors ---

	// Constructor for Snake class
	// Arguments: x - the x position of the head of the snake
	//            y - the y position of the head of the snake
	Snake(int x=0, int y=0);

	// Stop copying, because the class isn't non deep copy safe
	Snake(const Snake&) = delete;
	Snake& operator=(const Snake&) = delete;

	// --- Virtual functions ----

	// Function name: render
	// Description:   Renders Snake to the renderer
	// Arguments:     renderer - the renderer to render to
	virtual void render(SDL_Renderer* renderer) const override;

	// --- Getters ---

	// Function name: getHead
	// Description:   getter for the head of the snake
	// Return value:  the pointer to the head of the snake
	SnakeTile* getHead();

	// Function name: getTail
	// Description:   getter for the tail of the snake
	// Return value:  the pointer to the tail of the snake
	SnakeTile* getTail();

	// --- Other functions ---

	// Function name: handleInput
	// Description:   handles the input for the snake
	// Arguments:     ev - the event to handle
	void handleInput(const SDL_Event& ev);

	// Function name: update
	// Description:   updates the state of the snake
	void update();

	// Function name: enlarge
	// Description:   increases the size of the snake
	void enlarge();

	// Function name: isCollided
	// Description:   return whether or not the snake is collided with a Tile
	// Arguments:     tile - the tile to check against
	// Return value:  true if the snake is collieded with the Tile, false otherwise
	bool isCollided(const Tile& tile);

	// Function name: isCollidedWithSelf
	// Description:   returns whether or not the snake is collided with itself
	// Return value:  true if the snake is collided with itself, false otherwise
	bool isCollidedWithSelf();

	// Destructor
	virtual ~Snake();
};

