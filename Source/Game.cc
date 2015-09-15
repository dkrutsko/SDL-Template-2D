////////////////////////////////////////////////////////////////////////////////
// -------------------------------------------------------------------------- //
//                                                                            //
//                           (C) 2015 David Krutsko                           //
//                                                                            //
// -------------------------------------------------------------------------- //
////////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------//
// Prefaces                                                                   //
//----------------------------------------------------------------------------//

#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>



//----------------------------------------------------------------------------//
// Constructors                                                          Game //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////

Game::Game (void)
{
	mWindow = nullptr;
	mRender = nullptr;
}



//----------------------------------------------------------------------------//
// Functions                                                             Game //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////

bool Game::Init (void)
{
	// Attempt to initialize the various SDL subsystems
	if (SDL_Init (SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
		return false;

	// Attempt to initialize SDL image library
	int flags = IMG_INIT_JPG | IMG_INIT_PNG;
	if ((IMG_Init (flags) & flags) != flags)
		return false;

	SDL_DisplayMode current;
	// Attempt to get the resolution of main screen
	if (SDL_GetCurrentDisplayMode (0, &current) < 0)
		return false;

	int w = 640;
	int h = 480;
	int x = (current.w / 2) - (w / 2);
	int y = (current.h / 2) - (h / 2);

	// Attempt to create game window
	if (!(mWindow = SDL_CreateWindow
		("Game Title", x, y, w, h, 0)))
		return false;

	// Create an accelerated 2D rendering context
    if (!(mRender = SDL_CreateRenderer (mWindow, -1,
		SDL_RENDERER_ACCELERATED))) return false;

	return Setup();
}

////////////////////////////////////////////////////////////////////////////////

void Game::Exit (void)
{
	// Shutdown all SDL constructs
	SDL_DestroyRenderer (mRender);
	SDL_DestroyWindow   (mWindow);
	IMG_Quit();
	SDL_Quit();
}

////////////////////////////////////////////////////////////////////////////////

void Game::Loop (void)
{
	bool running = true;
	uint32 updated = 0;
	uint32 elapsed = 0;

	while (running)
	{
		SDL_Event evt;
		// Handle pending SDL events
		while (SDL_PollEvent (&evt))
		{
			// User has asked to exit
			if (evt.type == SDL_QUIT)
				running = false;

			if (evt.type == SDL_KEYDOWN)
			{
				switch (evt.key.keysym.sym)
				{
					case SDLK_UP   : break;
					case SDLK_DOWN : break;
					case SDLK_LEFT : break;
					case SDLK_RIGHT: break;
					case SDLK_SPACE: break;
				}
			}
		}

		// Update the elapsed time
		auto time = SDL_GetTicks();
		elapsed += time - updated;
		updated  = time;

		if (elapsed > 15)
		{
			Update (elapsed);
			Render (elapsed);
			elapsed = 0;
		}

		SDL_Delay (4);
	}
}

////////////////////////////////////////////////////////////////////////////////

bool Game::Setup (void)
{
	// TODO:
	return true;
}

////////////////////////////////////////////////////////////////////////////////

void Game::Update (uint32 elapsed)
{
	// TODO:
}

////////////////////////////////////////////////////////////////////////////////

void Game::Render (uint32 elapsed)
{
	// Clear window contents
	SDL_RenderClear (mRender);

	// TODO:

	// SDL_Texture* image = IMG_LoadTexture (mRender, "name");
	// SDL_Rect rc; rc.x = 0; rc.w = 0; rc.y = 0; r.h = 0;
	// SDL_RenderCopy (mRender, SdlTexture, nullptr, &rc);
	// SDL_DestroyTexture (image);

	// Show new window contents
	SDL_RenderPresent (mRender);
}



//----------------------------------------------------------------------------//
// Main                                                                       //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////

int main (int argc, char* argv[])
{
	Game game;
	if (game.Init())
	{
		game.Loop();
		game.Exit();
	}

	return 0;
}
