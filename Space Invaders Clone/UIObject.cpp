#include "UIObject.h"

UIObject::UIObject(string name, string path)
{
	load_texture(name, path);
	setup_sprite();
}

void UIObject::load_texture(string name, string path) {
	try {
		if (!texture.loadFromFile(path))
			throw runtime_error("Could not load " + name + " image!");
	}
	catch (runtime_error err) {
		Error_Window win(err.what());
		win.show();
	}
}

void UIObject::setup_sprite() {
	sprite.setTexture(texture);
	Vector2f pos((winSize.width - texture.getSize().x) / 2, (winSize.height - texture.getSize().y) / 2);
	sprite.setPosition(pos);
}