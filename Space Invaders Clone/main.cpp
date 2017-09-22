#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "constants.h"
#include "Ship.h"
#include "Bullet.h"
#include "AlienHorde.h"
#include "Start_Screen.h"
#include "Error_Window.h"
#include "UIObject.h"

using namespace std;
using namespace sf;

bool loadFiles(Font &, vector<Texture>);
bool testCollision(const Bullet &, const Alien &);
bool testCollision(const Ship &, const Alien &);

int main(){

	Event event;
	RenderWindow window(winSize, "Space Invaders");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);
	Start_Screen screen;

	//Show start screen
	while (window.pollEvent(event) || window.isOpen()) {
		if (Keyboard::isKeyPressed(Keyboard::Return))
			break;
		else if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
			window.close();

		window.clear();
		window.draw(screen.sprite());
		window.display();
	}

	Font font;

	if(!loadFiles(font))
		return 0;

	//Initialize Game Variables
	Ship ship;
	AlienHorde alienHorde;
	bool gameOver = false;
	bool gameWon = false;
	int wins = 0;

	//Initialize Game Score
	Color scrColor(255, 6, 6);
	Text score("Score:00", font, 16);
	score.setColor(scrColor);
	score.setPosition(16.0f, 8.0f);
	score.setStyle(Text::Bold);

	//Game logic
	while (window.pollEvent(event) || window.isOpen()) {
		//Window closing conditions
		if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
			continue;
		}
		//Pause game
		if (event.type == Event::KeyPressed && event.key.code == Keyboard::P) {
			UIObject gamePausedUI("Game Paused", gamePausedPath);

			window.draw(gamePausedUI.sprite);
			window.display();

			while (window.pollEvent(event) || window.isOpen()) {
				if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) {
					window.close();
					continue;
				}
				if (event.type == Event::KeyPressed && event.key.code == Keyboard::P)
					break;
			}
		}
		//Winning and losing cheat codes
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			gameWon = true;
			wins += 1;
		}
		if (Keyboard::isKeyPressed(Keyboard::L))
			gameOver = true;
		//Determine whether to restart the game
		if (gameOver || gameWon) {
			bool decision = false;

			if (gameOver) {
				UIObject gameOverUI("Game Over", gameOverPath);

				window.draw(gameOverUI.sprite);
				window.display();
			}
			else if (gameWon) {
				UIObject gameWonUI("Game Won", gameWonPath);

				window.draw(gameWonUI.sprite);
				window.display();
			}

			while (!decision || (window.pollEvent(event) && event.type == Event::EventType::KeyPressed)) {
					if (Keyboard::isKeyPressed(Keyboard::Key::Y)) {
						Ship newShip;
						AlienHorde newAlienHorde;

						ship = newShip;
						alienHorde = newAlienHorde;

						if (gameWon && wins != 0)
							alienHorde.waitFrames = 5 + (1 / (1 + 0.00625f * wins - 54.0f / 55.0f));

						decision = true;
						gameOver = false;
						gameWon = false;
					}
					if (Keyboard::isKeyPressed(Keyboard::Key::N) || Keyboard::isKeyPressed(Keyboard::Escape)) {
						window.close();
						decision = true;
					}
			}
		}

		//Test collisions
		for (auto &a : alienHorde.aliens) {
			if (testCollision(ship, a)) {
				ship.destroyed = true;
				gameOver = true;
				break;
			}
			for (auto &b : ship.bullets){
				if (testCollision(b, a)){
					a.destroyed = true;
					b.exists = false;
				}
			}
		}
		//Update game elements
		ship.update(event);
		ship.updateBullets();
		alienHorde.updateAliens();

		if (alienHorde.aliens.size() == 0) {
			gameWon = true;
			wins += 1;
		}
		if (wins < 10)
			score.setString("Score:0" + to_string(wins));
		else
			score.setString("Score:" + to_string(wins));

		window.clear();

		//Draw game elements
		window.draw(ship.sprite);
		for (auto &b : ship.bullets)
			window.draw(b.sprite);
		for (auto a : alienHorde.aliens)
			window.draw(a.sprite);
		window.draw(score);
		
		
		window.display();
	}
	return 0;
}

bool loadFiles(Font &font) {

	if (!font.loadFromFile("Fonts/AppleMyungjo.ttf"))
		return false;
	
	if (!Ship::loadFiles() || !Bullet::loadFiles() || !Alien::loadFiles()) {
		
		RenderWindow errWin(errWinSize, "Error!");
		Event event;
		Text errtext("Could not load textures!", font, 15);
		
		while (errWin.isOpen()) {

			while (errWin.pollEvent(event)) {

				errWin.clear();
				errWin.draw(errtext);
				errWin.display();

				if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
					errWin.close();
			}
		}

		return false;
	}
	else
		return true;
};

bool testCollision(const Bullet &b, const Alien &a) {
	return (b.top() - a.bot() < 0 && b.left() - a.right() < 0 && a.left() - b.right() < 0);
}

bool testCollision(const Ship &s, const Alien &a) {
	return (s.top() - a.bot() < 0 && s.left() - a.right() < 0 && a.left() - s.right() < 0);
}