#include "mainheader.hpp"

int main(void) {

	
	Vector2u windowframe(500, 600); //general vector type
	RenderWindow window(VideoMode(windowframe), "Driving Game");
	window.setFramerateLimit(60);

	//get the car sprite
	Texture carTexture;
	carTexture.loadFromFile("images/car.png");
	Sprite car(carTexture);

	//set the background
	Texture backgroundTexture;
	backgroundTexture.loadFromFile("images/top down road 1.png");

	//create the sprites for the background -- these will loop to create "movement"
	Sprite bg1(backgroundTexture);
	Sprite bg2(backgroundTexture);

	//scale the background to be twice as wide and long --  intial image is too small
	Vector2f bgScale(2.0f, 4.0f);
	float bgHeight = backgroundTexture.getSize().y * bgScale.y;

	bg1.setScale(bgScale);
	bg2.setScale(bgScale);

	bg1.setPosition({ 0,0 });
	bg2.setPosition({ 0.f, bgHeight });

	//set the initial position at the bottom of the screen
	car.setPosition({ 225, 550 });

	//main game loop
	while (window.isOpen()) {

		//exit program
		while (const optional event = window.pollEvent()) {
			if (event->is<Event::Closed>()) {
				window.close();
			}

		}

		//Movement
		float carSpeed = 5.0f;
		Vector2f movement(0, 0);

		if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
			movement.x -= carSpeed;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
			movement.x += carSpeed;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
			movement.y -= carSpeed;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
			movement.y += carSpeed;
		}

		//Background Scrolling
		float scrollSpeed = 4.0f;
		bg1.move({ 0, scrollSpeed });
		bg2.move({ 0, scrollSpeed });

		if (bg1.getPosition().y >= windowframe.y) {
			bg1.setPosition({ 0, bg2.getPosition().y - bgHeight });
		}
		if (bg2.getPosition().y >= windowframe.y) {
			bg2.setPosition({ 0, bg1.getPosition().y - bgHeight });
		}

		//move the car
		car.move(movement);

		//draw all the game contents
		window.clear();
		window.draw(bg1);
		window.draw(bg2);
		window.draw(car);
		window.display();

	}



	return 0;
}