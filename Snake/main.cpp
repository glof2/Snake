#include <iostream>
#include <SDL.h>
#include "Game.h"
#include "Window.h"
#include "Timer.h"

int main(int argc, char* argv[])
{
	// Create a window & hide it
	Window window{"Snake", 0, 0};
	window.hide();

	// Get display mode
	SDL_DisplayMode display_mode{};
	SDL_GetDesktopDisplayMode(0, &display_mode);

	// Calculate window size
	int window_width{ int(display_mode.w / 1.1f) };
	int window_height{ int(display_mode.h / 1.1f) };

	// Get game settings
	std::cout << "Map width: ";
	unsigned int map_w{};
	std::cin >> map_w;

	std::cout << "Map height: ";
	unsigned int map_h{};
	std::cin >> map_h;

	std::cout << "Apple count: ";
	unsigned int apple_count{};
	std::cin >> apple_count;

	std::cout << "Apple points: ";
	int apple_points{};
	std::cin >> apple_points;

	std::cout << "Game speed (1-20 recommended): ";
	unsigned int game_speed{};
	std::cin >> game_speed;

	// Calculate tile size
	unsigned int tile_size{ window_width / map_w };
	if (tile_size > window_height / map_h)
	{
		tile_size = window_height / map_h;
	}

	// Set tile size
	Tile::setRenderSize(tile_size);

	// Calculate new window size
	window_width = tile_size * map_w;
	window_height = tile_size * map_h;

	// Calculate position centered
	int window_x{ int((display_mode.w - window_width)/2) };
	int window_y{ int((display_mode.h - window_height) / 2) };

	// Set window size
	window.setSize(window_width, window_height);
	window.setPosition(window_x, window_y);

	// Calculate game speed
	game_speed = 1000 / game_speed;

	// Create game
	Game game{map_w, map_h, apple_count, apple_points};

	// Logic values
	bool running{ true };
	Timer upd_timer{};
	Timer reset_timer{};

	// Show window & Start game
	window.show();
	upd_timer.start();

	while(running)
	{
		// --- Handle Events ---
		SDL_Event ev{};
		while (SDL_PollEvent(&ev))
		{
			if (ev.window.windowID != window.getId())
			{
				continue;
			}

			switch (ev.type)
			{
				case SDL_WINDOWEVENT:
				{
					if (ev.window.event == SDL_WINDOWEVENT_CLOSE)
					{
						running = false;
					}
					break;
				}
				// ...
			}

			game.handleInput(ev);
		}

		// --- Update ---
		if (upd_timer.getElapsedMilliseconds() >= game_speed)
		{
			// reset timer & start it again
			upd_timer.reset();
			upd_timer.start();

			game.update();
		}

		switch (game.getState())
		{
			case Game::GameState::OVER:
			{
				if (reset_timer.getElapsedMilliseconds() >= 1000)
				{
					game.reset();
					reset_timer.reset();
				}
				else
				{
					reset_timer.start();
				}
				break;
			}
			case Game::GameState::NOT_STARTED:
			{
				game.start();
				break;
			}
		}		

		// --- Render ---
		// Clear the renderer
		window.clear();
		
		// Render
		window.render(game);
		
		// Present the rendered stuff
		window.present();

		// ...
	}

	return 0;
}