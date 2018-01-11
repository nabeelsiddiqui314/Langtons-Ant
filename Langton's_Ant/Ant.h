#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

enum class Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

enum class TurnDir {
	LEFT,
	RIGHT
};

class Ant
{
public:
	Ant(const sf::Vector2i& max);
	~Ant();
public:
	const sf::Vector2i& GetPosition() const { return m_position; }
	const sf::Color& GetColor() const { return m_color; }
	void Turn(TurnDir dir);
	void Move();
private:
	int random(int min, int max) { 
		srand(time(NULL)); 
		return rand() % (max + 1 - min) + min; 
	}
private:
	sf::Vector2i m_position;
	Direction    m_direction;
	sf::Color    m_color;
};

