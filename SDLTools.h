#include <SDL.h>
#include <stdio.h>
#include <bits/stdc++.h>

//Screen dimension constants
const int SCREEN_WIDTH = 450;
const int SCREEN_HEIGHT = 450;

enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

//Starts up SDL and creates window

bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

void start();
