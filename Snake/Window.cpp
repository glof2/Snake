#include "Window.h"
#include <stdexcept>

// --- Static members ---
int Window::s_window_count{ 0 };

// --- Constructors ---
Window::Window(const std::string& title, int width, int height)
{
	if (s_window_count == 0)
	{
		// Init SDL
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			throw std::runtime_error(SDL_GetError());
		}
	}

	// Create window
	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
	if (m_window == NULL)
	{
		throw std::runtime_error(SDL_GetError());
	}

	// Create renderer
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_renderer == NULL)
	{
		throw std::runtime_error(SDL_GetError());
	}

	// Add window count
	++s_window_count;
}

// --- Getters ---
std::array<int, 2> Window::getSize()
{
	std::array<int, 2> ret_val{};

	SDL_GetWindowSize(m_window, &(ret_val[0]), &(ret_val[1]));

	return ret_val;
}

std::array<int, 2> Window::getPosition()
{
	std::array<int, 2> ret_val{};

	SDL_GetWindowPosition(m_window, &(ret_val[0]), &(ret_val[1]));

	return ret_val;
}

Uint32 Window::getId()
{
	return SDL_GetWindowID(m_window);
}

// --- Setters ---

void Window::setSize(int width, int height)
{
	SDL_SetWindowSize(m_window, width, height);
}

void Window::setSize(const std::array<int, 2>& size)
{
	setSize(size[0], size[1]);
}

void Window::setPosition(int x, int y)
{
	SDL_SetWindowPosition(m_window, x, y);
}

void Window::setPosition(const std::array<int, 2>& position)
{
	setPosition(position[0], position[1]);
}

// --- Other functions ---
void Window::clear()
{
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_RenderClear(m_renderer);
}

void Window::render(const Renderable& renderable)
{
	renderable.render(m_renderer);
}

void Window::present()
{
	SDL_RenderPresent(m_renderer);
}

void Window::hide()
{
	SDL_HideWindow(m_window);
}


void Window::show()
{
	SDL_ShowWindow(m_window);
}

// --- Destructor ---

Window::~Window()
{
	// Free renderer & window
	SDL_DestroyRenderer(m_renderer);
	m_renderer = nullptr;

	SDL_DestroyWindow(m_window);
	m_window = nullptr;

	// 
	--s_window_count;

	// 
	if (s_window_count == 0)
	{
		SDL_Quit();
	}
}