#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Error_Window.h"

using namespace std;
using namespace sf;

class UIObject
{
public:
	Sprite sprite;
protected:
	string name;
	Texture texture;
public:
	UIObject(string name, string path);
public:
	void load_texture(string name, string path);
	void setup_sprite();
};

