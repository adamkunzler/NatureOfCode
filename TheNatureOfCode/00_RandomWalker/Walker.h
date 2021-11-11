#pragma once

class Walker
{
private:
	sf::Vector2f position{};
	size_t numSteps{};
	float timeSinceLastUpdate{ 0.0f };
	float speed = 0.00000001f; // time in seconds for each step

	RandomGenerator rand{ 1171 };


public:
	Walker() : Walker{ 0.0f, 0.0f }
	{

	}

	Walker(float x, float y)
		: position{ x, y }
	{

	}

	~Walker() = default;

	void update(float elapsedTime, sf::VertexArray& va, int boundsWidth, int boundsHeight)
	{
		//timeSinceLastUpdate += elapsedTime;
		//if (timeSinceLastUpdate >= speed)
		{
			position.x += rand.getUniform(-1.0f, 1.0f);
			position.y += rand.getUniform(-1.0f, 1.0f);

			if (position.x < 0.0) position.x = boundsWidth;
			if (position.x > boundsWidth) position.x = 0;
			if (position.y < 0.0) position.y = boundsHeight;
			if (position.y > boundsHeight) position.y = 0;
			
			va[0].position = sf::Vector2f{ position.x, position.y };

			//timeSinceLastUpdate = timeSinceLastUpdate - speed;			
		}
	}
};