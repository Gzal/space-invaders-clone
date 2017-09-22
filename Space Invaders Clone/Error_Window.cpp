#include "Error_Window.h"

Error_Window::Error_Window(const string msg) : window(errWinSize, "Error!") {
	load_font();
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	message.setString(msg);
	message.setFont(font);
	message.setCharacterSize(10);
}

void Error_Window::show() {
	while (window.pollEvent(event) || window.isOpen()) {
		if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Space)) {
			window.close();
			continue;
		}
		
		window.clear();
		window.draw(message);
		window.display();
	}
}

bool Error_Window::load_font() {
	return font.loadFromFile("Fonts/AppleMyungjo.ttf");
}