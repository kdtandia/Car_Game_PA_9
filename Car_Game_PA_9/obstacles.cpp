#include "obstacles.hpp"

//constructor for the obstacle manager
Obstacles::Obstacles(const string& newTexturePath, Vector2u newWindowSize, float newSpawnInterval, float newSpeed) {
	
	//check to make sure the obstacle texture loaded properly
	if (!this->obstacleTexture.loadFromFile(newTexturePath)) {
		cerr << "Failed to load obstacle texture from: " << newTexturePath << endl;
	}

	this->windowSize = newWindowSize;
	this->spawnInterval = newSpawnInterval;
	this->speed = newSpeed;
	this->lastSpawnTime = 0.f;
}

//update the screen
void Obstacles::update(float changeInTime) {
	//update the last spawn time
	this->lastSpawnTime += changeInTime;

	if (this->lastSpawnTime >= this->spawnInterval) {
		createObstacle(); //make a new obstacle
		this->lastSpawnTime = 0.f; //reset last spawn time
	}

	for (auto it = obstacles.begin(); it != obstacles.end(); ) { //learned about auto from: https://www.geeksforgeeks.org/type-inference-in-c-auto-and-decltype/
		it->move({ 0.f, speed });

		if (it->getPosition().y > windowSize.y) {
			it = obstacles.erase(it); // Remove if off-screen
		}
		else {
			++it;
		}
	}
}

//display the obstacles on the screen
void Obstacles::draw(RenderWindow& window) {
	
	//draw all the obstacles
	for (const auto& obstacle : this->obstacles) {
		window.draw(obstacle);
	}
		
}

//get the obstacles class member
const vector<Sprite>& Obstacles::getObstacles() const
{
	return this->obstacles;
}

void Obstacles::createObstacle() {

	//create the obstacle sprite
	Sprite obstacle(this->obstacleTexture);

	// scale the sprite down -- original picture is too big
	obstacle.setScale({ 0.09f, 0.09f });

	// get the new width of the sprite
	float spriteWidth = obstacle.getGlobalBounds().size.x;

	// set up safe margins
	const float margin = 40.f;
	float minX = margin;
	float maxX = static_cast<float>(windowSize.x) - spriteWidth - margin;

	// make sure the bounds work
	if (maxX < minX) maxX = minX;

	// generate random X position
	float x = minX + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (maxX - minX);
	float y = -obstacle.getGlobalBounds().size.y;

	obstacle.setPosition({ x, y });

	this->obstacles.push_back(obstacle);

}
