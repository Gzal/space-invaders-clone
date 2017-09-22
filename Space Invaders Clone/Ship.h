#ifndef SHIP_H
#define SHIP_H

#include <vector>
#include "SFML/Graphics.hpp"

#include "Bullet.h"
#include "constants.h"

using namespace std;
using namespace sf;

class Ship{
	
	friend bool loadFiles(Font &);
	friend bool testCollision(const Ship &, const Alien &);

public:
	static Texture texture;
	Sprite sprite;
	vector<Bullet> bullets;
	bool destroyed = false;
private:
	Vector2f velocity;

public:
	Ship();
	~Ship() = default;

public:
	void update(Event event);
	void updateBullets();
private:
	void shootBullet();
	void deleteBullets();

	static bool Ship::loadFiles() { return texture.loadFromFile("Sprites/Ship.png") ? true : false; }

	float Ship::top() const { return sprite.getPosition().y - shipSize.y / 2; }
	float Ship::bot() const { return sprite.getPosition().y + shipSize.y / 2; }
	float Ship::left() const { return sprite.getPosition().x - shipSize.x / 2; }
	float Ship::right() const { return sprite.getPosition().x + shipSize.x / 2; }
};
#endif