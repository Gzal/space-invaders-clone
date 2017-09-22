#include "Alien.h"

Texture Alien::texture;

Alien::Alien(const int posx, const int posy){
	sprite.setTexture(texture);
	sprite.setPosition(posx, posy);
}


void Alien::update() {
	sprite.move(velocity);
}