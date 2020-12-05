#ifndef GRAVITY_PLANET_H
#define GRAVITY_PLANET_H
#include <SFML/Graphics.hpp>
#include <cmath>


class Particle : public sf::CircleShape
{
public:
    Particle(sf::Vector2f);
    void move(float);
    void applyForce(sf::Vector2f);
    sf::Vector2f getPosition();

private:
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
};


#endif //GRAVITY_PLANET_H
