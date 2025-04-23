

#include "obstacles.hpp"

class Car : public ObjectManager {

public:

	//constructor for the car class 
	Car(Texture &newTexture, Vector2u newWindowSize, float newSpeed) : ObjectManager(newTexture, newWindowSize, newSpeed), car(newTexture) {

		this->movement = Vector2f(0.f, 0.f);

		//starting position dynamically starts at the bottom of the window regardless of size
		this->car.setPosition({ (windowSize.x - car.getGlobalBounds().size.x) / 2.f ,windowSize.y - car.getGlobalBounds().size.y - 10.f });
	}

	void update() override;
	void draw(RenderWindow& window) override;
	void checkCollision(Obstacles& obstacles);
private:

	void checkBounds();

	Vector2f movement;
	Sprite car;
};