#include "Ship.h"

Texture Ship::texture;

Ship::Ship()
{
	bullets.reserve(3);
	sprite.setTexture(texture);
	sprite.setOrigin(shipSize.x / 2, shipSize.y / 2);
	sprite.setPosition(winSize.width / 2, winSize.height - shipSize.y / 2);
}

void Ship::update(Event event)
{
	if (Keyboard::isKeyPressed(Keyboard::Left) && left() > 0 )
		velocity.x = -shipVel.x;
	else if (Keyboard::isKeyPressed(Keyboard::Right) && right() < winSize.width)
		velocity.x = shipVel.x;
	else
		velocity.x = 0;

	sprite.move(velocity);

	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space && bullets.size() < 3)
		shootBullet();
}

void Ship::shootBullet() 
{
	Bullet bullet(sprite.getPosition());
	bullets.push_back(bullet);
}

void Ship::updateBullets() 
{	
	deleteBullets();
	
	for (auto &b : bullets)
		b.update();
}
//
void Ship::deleteBullets() 
{
	bool reachedEnd{ false };
	vector<Bullet>::iterator toDelete;
	bool flag{ false };

	while (bullets.begin() != bullets.end() && !reachedEnd)
	{	
		for (auto it{ bullets.begin() }; it < bullets.end(); it++) 
		{
			if (!it->exists)
			{
				toDelete = it;
				flag = true;
				break;
			}
		}

		if (flag)
		{
			bullets.erase(toDelete);
			flag = false;
		}
		else reachedEnd = !flag;
	}
}
//
/* Debug Assertion Failed: Vector iterator not incrementable
void Ship::deleteBullets()
{
	for (auto it = bullets.begin(); it < bullets.end(); it++)
	{
		if (!it->exists)
		{
			it = bullets.erase(it);
			continue;
		}
	}
}*/