
#include "header.hpp"
/*



FOR FUTURE USE



*/
class Obstacle : public ObjectManager {

public:

	Obstacle(Texture& newTexture, Vector2u newWindowSize, float newSpawnInterval, float newSpeed, Vector2f newObstacleScale) :
		ObjectManager(newTexture, newWindowSize, newSpeed), obstacle(newTexture) {
		
		this->obstacleScale = newObstacleScale;
		obstacle.setScale(this->obstacleScale);

		this->obstacleWidth = obstacle.getGlobalBounds().size.x;
		this->obstacleHeight = obstacle.getGlobalBounds().size.y;
	}

	void update() override;
	void draw(RenderWindow &window) override;
	void setPostion(Vector2f newPosition);

private:
	Sprite obstacle;
	Vector2f obstacleScale;
	float obstacleWidth, obstacleHeight;
};