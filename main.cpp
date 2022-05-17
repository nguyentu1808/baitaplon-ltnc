#include <SDL.h>
#include <stdio.h>
#include <bits/stdc++.h>
//Screen dimension constants
const int SCREEN_WIDTH = 450;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;
SDL_Surface* gImage = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	gHelloWorld = SDL_LoadBMP( "image/background.bmp" );
	gImage = SDL_LoadBMP("image/red.bmp");

	if( gHelloWorld == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "image/background.bmp", SDL_GetError() );
		success = false;
	}

	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface( gHelloWorld );
	gHelloWorld = NULL;
    SDL_FreeSurface( gImage );
	gImage = NULL;
	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
		    SDL_Rect srcRect = {0, 0, 200, 200};
			SDL_Rect dstRect = {100, 10, 300, 300};

                //Apply the image
			//x, y, w, h
			bool quitGame = false;
            while (! quitGame) {
            SDL_BlitSurface( gHelloWorld, &srcRect, gScreenSurface, &dstRect);
			//Update the surface
			SDL_UpdateWindowSurface( gWindow );

			//Wait two seconds
			//SDL_Delay( 2000 );
			SDL_Delay(500);
			SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(gScreenSurface->format, 0, 0, 0));
			SDL_UpdateWindowSurface(gWindow);
            			SDL_Delay(500);

         /*   if () {
                srand();
                break;
            }*/
            }

		}
	}
	//Free resources and close SDL

	close();

	return 0;
}
