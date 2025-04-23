#include "car.hpp"


void Car::update() {
	
	this->movement = Vector2f(0.f, 0.f);

	if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
		this->movement.x -= this->speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
		this->movement.x += this->speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
		this->movement.y -= this->speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
		this->movement.y += this->speed;
	}

	this->car.move(this->movement);

	checkBounds();
}

void Car::checkBounds() {
	
	float leftBound = 100.f;
	float rightBound = 400.f;

	float topBound = 0.f;
	float bottomBound = windowSize.y - this->car.getGlobalBounds().size.y;

	Vector2f position = this->car.getPosition();

	if (position.x < leftBound) {
		position.x = leftBound;
	}
	if (position.x + this->car.getGlobalBounds().size.x > rightBound) {
		position.x = rightBound - this->car.getGlobalBounds().size.x;
	}
	
	if (position.y < topBound) {
		position.y = topBound;
	}
	if (position.y > bottomBound) {
		position.y = bottomBound;
	}

	this->car.setPosition(position);
}

void Car::draw(RenderWindow& window) {
	window.draw(this->car);
}

void Car::checkCollision(Obstacles &obstacles) {
	
	for (const auto& obstacle : obstacles.getObstacles()) {
		if (this->car.getGlobalBounds().findIntersection(obstacle.getGlobalBounds())) {
			//Car hit trash
			/* Add end screen */
			cout << "Car Crashed!" << endl; //placeholder
		}
	}
}
