#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "constants.h"

using namespace sf;
using namespace std;

class Error_Window
{
	Event event;
	Font font;
	RenderWindow window;
	Text message;

public:
	Error_Window(const string msg = "Error!");

	void show();
private:
	bool load_font();
};

