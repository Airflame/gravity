#include <cmath>
#include <vector>
#include <iostream>
#include "include/Star.h"
#include "include/Particle.h"

int main() {
    sf::Clock clock;
    float dt = 0;
    bool pressed = false;
    int selected = 0;
    sf::Color color(0, 255, 255);

    std::vector<Particle*> particles;
    std::vector<Star*> stars;

    sf::RenderWindow window(sf::VideoMode(600, 600), "Gravity");
    while (window.isOpen())
    {
        window.clear(sf::Color::Black);
        particles.push_back(new Particle(sf::Vector2f(10,10)));
        particles[particles.size()-1]->setFillColor(color);
        color.g += 1;
        for (auto s : stars)
            window.draw(*s);
        for (auto p : particles)
            window.draw(*p);

        for (int i = 0; i < particles.size(); i++)
        {
            sf::Vector2f position = particles[i]->getPosition();
            if (position.x > 600 or position.y > 600 or position.x < 0 or position.y < 0)
            {
                particles.erase(particles.begin()+i);
            }
            else
            {
                sf::Vector2f force(0, 0);
                for (auto s : stars)
                {
                    force += s->getForce(particles[i]->getPosition());
                }
                particles[i]->applyForce(force);
                particles[i]->move(dt);
            }
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2f mousePosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                {
                    bool chosen = false;
                    pressed = true;
                    for (int i = 0; i < stars.size(); i++)
                    {
                        sf::Vector2f v = stars[i]->getPosition() - mousePosition;
                        if (std::sqrt(v.x*v.x+v.y*v.y) < 30)
                        {
                            selected = i;
                            chosen = true;
                            break;
                        }
                    }
                    if (!chosen)
                        stars.push_back(new Star(mousePosition));
                }
                else
                {
                    if (!stars.empty())
                        stars.pop_back();
                }

            }
            if (event.type == sf::Event::MouseButtonReleased)
                pressed = false;
            if (event.type == sf::Event::MouseMoved and pressed)
            {
                stars[selected]->move(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
            }
        }
        window.display();
        dt = clock.restart().asSeconds();
    }
    return 0;
}