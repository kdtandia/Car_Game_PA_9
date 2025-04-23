
#include "obstacles.hpp"

class Car {

public:

	Car(Texture &newTexture, Vector2u newWindowSize, float newCarSpeed) : car(newTexture) {

		this->carTexture = newTexture;
		this->windowSize = newWindowSize;
		this->carSpeed = newCarSpeed;
		this->movement = Vector2f(0.f, 0.f);

		this->car.setPosition({ (windowSize.x - car.getGlobalBounds().size.x) / 2.f ,windowSize.y - car.getGlobalBounds().size.y - 10.f });
	}

	void drive();
	void checkBounds();
	void draw(RenderWindow& window);
	void checkCollision(Obstacles& obstacles);
private:

	Texture carTexture; //made a pointer to fix issues with refrencing
	Vector2u windowSize;
	Vector2f movement;
	Sprite car;
	float carSpeed;



};