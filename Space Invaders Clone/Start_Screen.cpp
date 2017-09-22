#include "Start_Screen.h"

Start_Screen::Start_Screen()
{
	load_files();
}

void Start_Screen::load_files() {
	bool success;
	int count = 1;
	Texture scrn_txtr;

	try {
		if (!scrn_txtr.loadFromFile("Sprites/Start Screen/Start Screen " + to_string(count) + ".png"))
			throw runtime_error("Could not load texture files!");
	}
	catch (runtime_error err) {
		Error_Window win(err.what());
		win.show();
		return;
	}
	
	do {
		screen_textures.push_back(scrn_txtr);
		count++;
		success = scrn_txtr.loadFromFile("Sprites/Start Screen/Start Screen " + to_string(count) + ".png");
	} while (success);
}

Sprite Start_Screen::sprite() {
	static int count = 0;
	static vector<Texture>::size_type frame = 0;

	++count;

	if (count >= 20) {
		count = 0;
		screen_sprite.setTexture(screen_textures[frame]);
		frame = ++frame % screen_textures.size();
	}
	
	return screen_sprite;
}