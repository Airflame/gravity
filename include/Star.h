#ifndef GRAVITY_STAR_H
#define GRAVITY_STAR_H
#include <SFML/Graphics.hpp>
#include <cmath>


class Star : public sf::CircleShape
{
public:
    Star(sf::Vector2f);
    sf::Vector2f getForce(sf::Vector2f);
    void move(sf::Vector2f);

private:
    sf::Vector2f position;
    double g;
    double radius;
};


#endif //GRAVITY_STAR_H
