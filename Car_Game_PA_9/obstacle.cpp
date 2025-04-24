#include "obstacle.hpp"


void Obstacle::draw(RenderWindow& window) {
	window.draw(this->obstacle);
}

void Obstacle::setPostion(Vector2f newPosition) {
	this->obstacle.setPosition(newPosition);
}

