#pragma once

#include "Walker.h"

class BaseScene;

class Scene : public BaseScene
{
private:
	sf::VertexArray va;
	sf::Texture texture;
	sf::Sprite sprite;
	
	Walker walker{};
	
public:
	Scene(int width, int height, std::string title)
		:BaseScene{ width, height, title }
	{		
		walker = Walker{ (float)width / 2.0f, (float)height / 2.0f };
		va = sf::VertexArray{ sf::Points, 1 };

		if (!texture.create(width, height))
		{
			std::cout << "error creating texture\n";
		}
		sprite.setTexture(texture);
	}		

	void updateScene(float elapsed) override
	{		
		
	}

	void drawScene() override
	{	
		// draw our saved scene texture
		window.draw(sprite);

		// draw new walker position
		for (int i = 0; i < 100; i++)
		{
			walker.update(0.0f, va, width, height);
			window.draw(va);
		}
			
		// save the current scene as texture
		texture.update(window);
	}
};