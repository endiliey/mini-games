#include <SFML/Graphics.hpp>
#include <time.h>
#define BLOCKS 10
using namespace sf;

struct point
{
	int x,y;
};

int main()
{
	srand(time(0));

	RenderWindow app(VideoMode(400, 533), "Endi Jump!");
	app.setFramerateLimit(60);
	
	// setup background, platform and character
	Texture bg, endi, platform;
	bg.loadFromFile("img/background.png");
	endi.loadFromFile("img/endi.png");
	platform.loadFromFile("img/platform.png");

	Sprite sBackground(bg), sEndi(endi), sPlatform(platform);
	
	point plat[BLOCKS];
	
	// random plot platform
	for (auto i = 0; i != BLOCKS; ++i)
	{
		plat[i].x = rand() % 400;
		plat[i].y = rand() % 533;
	}

	int x = 100, y = 100, h = 200;
	float dx = 0, dy =0;

	while (app.isOpen())
	{
		// close event
		Event e;
		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();
		}

		// movement of keyboard
		if (Keyboard::isKeyPressed(Keyboard::Right))
			x += 3;
		if (Keyboard::isKeyPressed(Keyboard::Left))
			x -= 3;

		// gravity
		dy += 0.2;
		y += dy;
		if (y > 500)
			dy = -10;

		if (y < h)
		{
			for (auto i = 0; i != BLOCKS; ++i)
			{
				y = h;
				plat[i].y = plat[i].y - dy;
				if (plat[i].y > 533)
				{
					plat[i].y = 0;
					plat[i].x = rand() % 400;
				}
			}
		}
		
		for (auto i = 0; i != BLOCKS; ++i)
		{
			//TODO : trial and error to get good value
			if ((x+50>plat[i].x) && (x+20<plat[i].x+68) && (y+80>plat[i].y) && (y+70<plat[i].y+14) && (dy>0))
 				dy=-10;
		}

		sEndi.setPosition(x,y);

		app.draw(sBackground);
		app.draw(sEndi);

		// draw platforms
		for (auto i = 0; i != BLOCKS; ++i)
		{
			sPlatform.setPosition(plat[i].x, plat[i].y);
			app.draw(sPlatform);
		}

		app.display();
	}
		return 0;
}
