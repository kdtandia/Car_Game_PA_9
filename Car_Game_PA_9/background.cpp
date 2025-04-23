#include "background.hpp"

Background::Background(const string& newTexturePath, Vector2u newWindowSize, Vector2f newbgScale, float newScrollSpeed) {

	//check to make sure the compiler is able to find the path
	if (!this->bgTexture.loadFromFile(newTexturePath)) {
		cerr << "Failed to load obstacle texture from: " << newTexturePath << endl;
	}

	//intialize data members
	this->windowSize = newWindowSize;
	this->bgScale = newbgScale;
	this->scrollSpeed = newScrollSpeed;
	this->bgHeight = this->bgTexture.getSize().y * this->bgScale.y;

	//creating the sprites -- These will loop together to create the illusion of a moving road
	Sprite bg1(this->bgTexture);
	Sprite bg2(this->bgTexture);

	//scale the background -- original png doesnt fit the window
	bg1.setScale(this->bgScale);
	bg2.setScale(this->bgScale);

	//set the intial positions of the backgrounds
	bg1.setPosition({ 0.f, 0.f });
	bg2.setPosition({ 0.f, this->bgHeight });

	//add these to the background vector
	this->backgrounds.push_back(bg1);
	this->backgrounds.push_back(bg2);
}

//Checks to see if the background is off screen and then puts it in front of the next background
void Background::scroll() {

	this->backgrounds[0].move({ 0, this->scrollSpeed });
	this->backgrounds[1].move({ 0, this->scrollSpeed });

	if (this->backgrounds[0].getPosition().y >= windowSize.y) {
		this->backgrounds[0].setPosition({ 0, this->backgrounds[1].getPosition().y - bgHeight });
	}
	if (this->backgrounds[1].getPosition().y >= windowSize.y) {
		this->backgrounds[1].setPosition({ 0, this->backgrounds[0].getPosition().y - bgHeight });
	}
}

//Draws the backgrounds on the screen
void Background::draw(RenderWindow& window) {

	window.draw(this->backgrounds[0]);
	window.draw(this->backgrounds[1]);
}
