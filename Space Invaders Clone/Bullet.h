#ifndef BULLET_H
#define BULLET_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "constants.h"

using namespace std;
using namespace sf;

class Bullet {

	friend class Alien;
	friend bool loadFiles(Font &);
	friend bool testCollision(const Bullet &, const Alien &);

public:
	static Texture texture;
	Sprite sprite;
	bool exists{ true };
private:
	Vector2f velocity = bulletVel;

public:
	Bullet(Vector2f shipPos);
	~Bullet() = default;

public:
	void update();
private:
	static bool Bullet::loadFiles() { return texture.loadFromFile("Sprites/Bullet.png") ? true : false; }

	float top() const { return sprite.getPosition().y - bulletSize.y / 2; }
	float bot() const { return sprite.getPosition().y + bulletSize.y / 2; }
	float left() const { return sprite.getPosition().x - bulletSize.x / 2; }
	float right() const { return sprite.getPosition().x + bulletSize.x / 2; }
};
#endif