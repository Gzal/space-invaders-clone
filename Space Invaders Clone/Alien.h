#ifndef ALIEN_H
#define ALIEN_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "constants.h"

using namespace std;
using namespace sf;

class Alien {

	friend class Bullet;
	friend class Ship;
	friend bool loadFiles(Font &);
	friend bool testCollision(const Bullet &, const Alien &);
	friend bool testCollision(const Ship &, const Alien &);

public:
	static Texture texture;
	Sprite sprite;
	bool destroyed{ false };
	Vector2f velocity = alienVel;

public:
	Alien(const int, const int);
	~Alien() = default;

public:
	void update();
private:
	inline static bool loadFiles();
	inline float top() const;
	inline float bot() const;
	inline float left() const;
	inline float right() const;
};

bool Alien::loadFiles() { return texture.loadFromFile("Sprites/Alien.png") ? true : false; }

float Alien::top() const { return sprite.getPosition().y; }

float Alien::bot() const { return sprite.getPosition().y + alienSize.y; }

float Alien::left() const { return sprite.getPosition().x; }

float Alien::right() const { return sprite.getPosition().x + alienSize.x; }

#endif