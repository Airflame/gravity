#include "../include/Particle.h"

Particle::Particle(sf::Vector2f pos)
{
    position = pos;
    setFillColor(sf::Color::Blue);
    setRadius(5);
    setPosition(position);
    velocity = sf::Vector2f(1, 1);
}

void Particle::move(float dt)
{
    velocity += acceleration*dt;
    int d = (int) std::sqrt(velocity.x*velocity.x + velocity.y*velocity.y);
    if (d != 300)
    {
        velocity.x /= d;
        velocity.y /= d;
        velocity.x *= 300;
        velocity.y *= 300;
    }
    position += velocity*dt;
    setPosition(position);
}

void Particle::applyForce(sf::Vector2f force)
{
    acceleration = force;
}

sf::Vector2f Particle::getPosition()
{
    return position;
}