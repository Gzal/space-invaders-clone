#include "Bullet.h"

Texture Bullet::texture;

Bullet::Bullet(const Vector2f shipPos){

	sprite.setTexture(texture);
	sprite.setOrigin(bulletSize.x / 2, bulletSize.y / 2);
	sprite.setPosition(shipPos);
}

void Bullet::update() 
{
	if (sprite.getPosition().y < 0) exists = false;

	sprite.move(velocity);
}