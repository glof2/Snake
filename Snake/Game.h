#pragma once
#include <vector>
#include "Snake.h"
#include "AppleTile.h"

class Game : public Renderable
{
public:
	enum class GameState
	{
		RUNNING,
		OVER,
		NOT_STARTED
	};

private:
	std::vector<AppleTile*> m_tiles{};
	Snake* m_snake{};
	unsigned int m_width{};
	unsigned int m_height{};
	unsigned int m_start_apple_count{};
	int m_apple_points{};
	int m_score{1};
	GameState m_state{GameState::NOT_STARTED};

	// --- Private functions ---

	// Function name: free
	// Description:   frees all of the resources allocated by the Game object
	void free();
public:
	// --- Constructors ---

	// Constructor for Game
	// Arguments: width - the width of the Game
	//            height - the height of the Game
	//            apple_cont - the starting number of apples
	//            apple_points - the amount of points that apples grant
	Game(unsigned int width, unsigned int height, unsigned int apple_count = 1, int apple_points = 1);

	// Stop copying, because the class isn't non deep copy safe
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	// --- Getters ---

	// Function name: getWidth
	// Description:   getter for the width of the Game
	// Return value:  the width of the Game
	unsigned int getWidth() const;

	// Function name: getHeight
	// Description:   getter for the height of the Game
	// Return value:  the height of the Game
	unsigned int getHeight() const;

	// Function name: getState
	// Description:   getter for the current state of the game
	// Return value:  the current state of the game
	GameState getState() const;

	// --- Setters ---
	
	// --- Other functions ---

	// Function name: addApple
	// Description:   adds a new apple to the Game at random coordinates
	// Arguments:     count - the amount of apples to add
	void addApple(unsigned int count = 1);

	// Function name: update
	// Description:   updates the state of the game
	void update();

	// Function name: handleInput
	// Description:   handles the input for the game
	// Arguments:     ev - the event to handle
	void handleInput(const SDL_Event& ev);

	// Function name: render
	// Description:   renders all game objects
	virtual void render(SDL_Renderer* renderer) const override;

	// Function name: start
	// Description:   starts the game
	void start();

	// Function name: reset
	// Description:   resets the game, start needs to be called to start the game afterwards
	void reset();

	// --- Destructor ---

	virtual ~Game();
};

