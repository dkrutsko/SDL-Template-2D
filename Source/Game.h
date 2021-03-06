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

#pragma once

#include "Types.h"
struct SDL_Window;
struct SDL_Renderer;



//----------------------------------------------------------------------------//
// Classes                                                                    //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////

class Game
{
public:
	Game							(void);

public:
	bool			Init			(void);
	void			Exit			(void);
	void			Loop			(void);

	bool			Setup			(void);
	void			Update			(uint32 elapsed);
	void			Render			(uint32 elapsed);

private:
	SDL_Window*		mWindow;		// The game window
	SDL_Renderer*	mRender;		// Window renderer
};
