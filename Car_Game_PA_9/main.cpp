/*

Names: Iyke Odum, Austin Daniels, Kadara Tandia
Assignment: Programming Assignment 9
Due: 4/23/2025
Description: For this final assignment, we are required to create a solution, as a team,
to a game or graphical application of our choice



UPDATES NEEDED:

-create classes for background and car
-create main menu
-add obstacales
-allow customization of car? (change color)

*/
#include "obstacles.hpp"

int main(void) {

	//randomness
	srand(static_cast<unsigned>(time(nullptr)));

	//creating the game window
	Vector2u windowSize(500, 600);
	RenderWindow window(VideoMode(windowSize), "Top Down Driving Game");
	window.setFramerateLimit(60);

	float spawnInterval = 1.0f;
	float obstacleSpeed = 4.0f;
	Obstacles obstacles("images/trash bag.png", windowSize, spawnInterval, obstacleSpeed);

	//get the car sprite
	Texture carTexture; //texture sourced from -- https://www.youtube.com/watch?v=YzhhVHb0WVY
	carTexture.loadFromFile("images/car.png");
	Sprite car(carTexture);

	//set the background
	Texture backgroundTexture; //texture sourced from -- https://opengameart.org/content/2d-top-down-highway-background
	backgroundTexture.loadFromFile("images/top down road 1.png"); 

	//create the sprites for the background -- these will loop to create "movement"
	Sprite bg1(backgroundTexture);
	Sprite bg2(backgroundTexture);

	//scale the background to be twice as wide and long --  original image is too small
	Vector2f bgScale(2.0f, 4.0f);
	float bgHeight = backgroundTexture.getSize().y * bgScale.y;

	//scalling the background sprites 
	bg1.setScale(bgScale);
	bg2.setScale(bgScale);

	bg1.setPosition({ 0,0 });
	bg2.setPosition({ 0.f, bgHeight });

	//set the initial position at the bottom of the screen
	car.setPosition({ 225, 550 });

	Clock changeClock;
	//main game loop
	while (window.isOpen()) {

		Time changeTime = changeClock.restart(); //starts the timer back to 0
		float changeSeconds = changeTime.asSeconds();
		/* This could also be used for a time based scoring system
		Example: Every 10 second the player gets an additional 100 points */

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

		if (bg1.getPosition().y >= windowSize.y) {
			bg1.setPosition({ 0, bg2.getPosition().y - bgHeight });
		}
		if (bg2.getPosition().y >= windowSize.y) {
			bg2.setPosition({ 0, bg1.getPosition().y - bgHeight });
		}

		

		car.move(movement);
		obstacles.update(changeSeconds);


		window.clear();
		window.draw(bg1);
		window.draw(bg2);
		obstacles.draw(window);
		window.draw(car);
		window.display();

		for (const auto& obstacle : obstacles.getObstacles()) {
			if (car.getGlobalBounds().findIntersection(obstacle.getGlobalBounds())) {
				//Car hit trash
				/* Add end screen */
				cout << "Car Crashed!" << endl; //placeholder
			}
		}

	}



	return 0;
}