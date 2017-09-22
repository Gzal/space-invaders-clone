#include "AlienHorde.h"

AlienHorde::AlienHorde()
{
	for (int i = 0; i < winSize.width / alienSize.x - 2; i++) {
		for (int j = 0; j < 4; j++) 
			aliens.emplace_back((i + 1) * alienSize.x, (j + 1) * alienSize.y);
	}
}

void AlienHorde::updateAliens()
{
	static int count = 0;
	count++;

	deleteAliens();

	if (count >= waitFrames) {
		count = 0;
		for (auto &a : aliens)
			a.update();
	}
}

void AlienHorde::deleteAliens()
{
	bool reachedEnd{ false };
	vector<Alien>::iterator toDelete;
	bool flag{ false };

	while (aliens.begin() != aliens.end() && !reachedEnd)
	{
		for (auto it{ aliens.begin() }; it < aliens.end(); it++)
		{
			if (it->destroyed)
			{
				toDelete = it;
				flag = true;
				break;
			}
		}

		if (flag)
		{
			aliens.erase(toDelete);
			flag = false;
		}
		else reachedEnd = !flag;
	}
}
