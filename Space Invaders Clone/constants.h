#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


//Main file
const VideoMode winSize(512, 480);
const VideoMode errWinSize(256, 120);

//Ship Class
const Vector2i shipSize{ 64, 64 };
const Vector2f shipVel{ 4.0f, 0.0f };

//Bullet Class
const Vector2i bulletSize{ 8, 8 };
const Vector2f bulletVel{ 0.0f, -8.0f };

//Alien Class
const Vector2i alienSize{ 32, 32 };
const Vector2f alienVel{ 0.0f, 3.0f };
const int initWaitFrames = 10;

//File Paths
const string gameOverPath{ "Sprites/GameOver!.png" };
const string gameWonPath{ "Sprites/YouWon!.png" };
const string gamePausedPath{ "Sprites/GamePaused.png" };
#endif
