
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

	Vector2f bgScale;
	float bgHeight;
	float scrollSpeed;
};