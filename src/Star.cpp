#include "../include/Star.h"

Star::Star(sf::Vector2f pos)
{
    radius = 30;
    position = pos;
    setFillColor(sf::Color::Yellow);
    setRadius(radius);
    setOrigin(radius, radius);
    setPosition(position);
    g = 5000000;
}

sf::Vector2f Star::getForce(sf::Vector2f point)
{
    sf::Vector2f force = position - point;
    double distance = std::sqrt(force.x*force.x + force.y*force.y);
    if (distance < radius)
        distance = radius;
    force.x *= (1/distance)*(1/distance)*(1/distance)*g;
    force.y *= (1/distance)*(1/distance)*(1/distance)*g;
    return force;
}

void Star::move(sf::Vector2f m)
{
    position = m;
    setPosition(position);
}