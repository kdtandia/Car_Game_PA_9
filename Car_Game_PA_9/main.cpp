/*

Names: Iyke Odum, Austin Daniels, Kadara Tandia
Assignment: Programming Assignment 9
Professor: Andrew O'Fallon
Due: 4/23/2025
Description: For this final assignment, we are required to create a solution, as a team,
to a game or graphical application of our choice

UPDATES NEEDED:

-create classes for car
-create main menu (button to play the game and button for customization)
-score system (time based or number of obstacles dodged based)
-create end screen (display score)
-allow customization of car? (change color)


UPDATES COMPLETED:

-created obstacles
-class for background
-scrolling background
-moving car


*/

#include "background.hpp"
#include "car.hpp"

int main(void) {

	//randomness -- Used for obstacles 
	srand(static_cast<unsigned>(time(nullptr)));

	//creating the game window
	Vector2u windowSize(500, 600);
	RenderWindow window(VideoMode(windowSize), "Top Down Driving Game");
	window.setFramerateLimit(60);


	float spawnInterval = 1.0f; //how fast the trash bags spawn - the lower the faster 
	float obstacleSpeed = 4.0f; //how fast the obstacles scroll down the screen 
	Obstacles obstacles("images/trash bag.png", windowSize, spawnInterval, obstacleSpeed);

	//get the car sprite
	Texture carTexture("images/car.png"); //texture sourced from -- https://www.youtube.com/watch?v=YzhhVHb0WVY
	float carSpeed = 5.0f;
	Car playerCar(carTexture, windowSize, carSpeed);
	// Sprite car(carTexture);


	//set the background
	Vector2f bgScale(2.0f, 4.0f);
	float scrollSpeed = 4.0f;
	Texture bgTexture("images/top down road 1.png");
	Background background(bgTexture, windowSize, bgScale, scrollSpeed);


	//car.setPosition({ 225, 550 });

	Clock changeClock; //track the time

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

		playerCar.update();
		background.update();
		obstacles.update(changeSeconds);

		//drawing all of the elements onto the window
		window.clear();
		background.draw(window);
		obstacles.draw(window);
		playerCar.draw(window);
		window.display();

		playerCar.checkCollision(obstacles);
		
	}



	return 0;
}