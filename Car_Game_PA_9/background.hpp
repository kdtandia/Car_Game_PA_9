
#include "header.hpp"

class Background {

public:

	Background(const string& newTexturePath, Vector2u newWindowSize, Vector2f newbgScale, float newScrollSpeed);

	void scroll();
	void draw(RenderWindow& window);
private:
	Texture bgTexture;
	vector<Sprite> backgrounds;
	Vector2u windowSize;

	Vector2f bgScale; //scale to so that the vector fits the window properly
	float bgHeight; //height of the scaled vector
	float scrollSpeed; //speed that the background is scrolling at
};