#pragma once

#include <iostream>
#include <vector>
#include <SFML\Graphics.hpp>

#include "Error_Window.h"

using namespace std;
using namespace sf;

class Start_Screen
{
	vector<Texture> screen_textures;
	Sprite screen_sprite;

	void load_files();

public:
	Start_Screen();

	Sprite sprite();
};

