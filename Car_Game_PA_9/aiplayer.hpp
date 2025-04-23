#include "header.hpp"

class AIPlayer{
    public:
    AIPlayer(const Texture& carTexture, Vector2u windowSize);
    void update(const vector<Sprite>& obstacles, float deltaTime);
    Sprite& getSprite();
    void draw(RenderWindow& window);

    private:
    Sprite car; 
    float speed;
    Vector2u windowSize;

    float reactionDistance;
    float avoidanceDistance;
    float decisionCooldown;
    float currentCooldown;
    int currentLane;

    Vector2f getLanePosition(int lane);
    int chooseBestLane(const vector<Sprite>& obstacles);

};



