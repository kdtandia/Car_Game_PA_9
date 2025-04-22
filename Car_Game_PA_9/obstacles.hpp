
#include "header.hpp"

class Obstacles {
public:

	Obstacles(const string& newTexturePath, Vector2u newWindowSize, float newSpawnInterval, float newSpeed);
	void update(float changeInTime);
	void draw(RenderWindow& window);

	//getter
	const vector<Sprite>& getObstacles() const;

	
private:

	void createObstacle();

	Texture obstacleTexture;
	vector<Sprite> obstacles; //vector of sprites for all obstacle types
	Vector2u windowSize;

	float spawnInterval, //time between spawning obstacles
		lastSpawnTime, //time since last spawn
		speed; //speed of the obstacle
};
