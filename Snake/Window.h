#pragma once
#include <string>
#include <array>
#include <SDL.h>
#include "Renderable.h"

// Window class
// A wrapper class for SDL windows
// The class expects to be the manager of initializing and quitting SDL
// It will initialize SDL if no other Window object is in memory
// It will deinitialize SDL if a Window object gets destroyed and it was the last one in memory
class Window
{
private:
	SDL_Window* m_window{};
	SDL_Renderer* m_renderer{};
	static int s_window_count;
public:
	// --- Constructors ---

	// Window class constructor
	// Description: constructs a Window object with set width and height
	// Arguments: title - the title of the window
	//            width - the width of the window
	//            height - the height of the window
	Window(const std::string& title, int width, int height);

	// --- Getters ---

	// Function name: getSize
	// Description:   a getter for the current size of the window
	// Return value:  an array, the first element is the width and the second element is the height
	std::array<int, 2> getSize();

	// Function name: getPosition
	// Description:   a getter for the current position of the window
	// Return value:  an array, the first element is the x coordinate and the second element is the y coordinate
	std::array<int, 2> getPosition();

	// Function name: getId
	// Description:   get the SDL window id
	// Return value:  the SDL id of the window
	Uint32 getId();

	// --- Setters ---

	// Function name: setSize
	// Description:   sets the size of the window
	// Arguments:     width - the new width of the window
	//                height - the new height of the window
	void setSize(int width, int height);

	// Function name: setSize
	// Description:   sets the size of the window
	// Arguments:     size - an array with the first element being the new width and the second being new height
	void setSize(const std::array<int, 2>& size);

	// Function name: setPosition
	// Description:   setter for the position of the window
	// Arguments:     x - the new X coordinate
	//                y - the new Y coordinate
	void setPosition(int x, int y);

	// Function name: setPosition
	// Description:   setter for the position of the window
	// Arguments:     position - an array with the first element being the new x coordinate and the second being new y coordinate
	void setPosition(const std::array<int, 2>& position);

	// --- Other functions ---

	// Function name: clear
	// Description:   clears the window rendered content
	void clear();

	// Function name: render
	// Description:   renders a renderable to the window
	// Arguments:     renderable - the renderable to render
	void render(const Renderable& renderable);

	// Function name: present
	// Description:   presents the rendered content to the window
	void present();

	// Function name: hide
	// Description:   hides the window
	void hide();

	// Function name: show
	// Description:   shows the window
	void show();

	// --- Destructor ---

	~Window();
};

