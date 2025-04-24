
#include "header.hpp"

/*
Description: This class actively manages all of the obstacles on the screen
It is responsible for updating and deleting all of the obstacles
*/
class ObstacleManager {
public:

	//constructor for obscales
	ObstacleManager(Texture &newTexture, Vector2u newWindowSize, float newSpawnInterval, float newSpeed);
	void update(float changeInTime);
	void draw(RenderWindow& window);
	void restart();
	//getter
	const vector<Sprite>& getObstacles() const;

	
private:

	void createObstacle(); //creates the obstacle in a random location on the screen

	Texture obstacleTexture;
	vector<Sprite> obstacles; //vector of sprites for all obstacle types
	Vector2u windowSize;

	float spawnInterval, //time between spawning obstacles
		lastSpawnTime, //time since last spawn
		speed; //speed of the obstacle
};
