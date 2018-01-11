#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>

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
	Ant(const sf::Vector2i& pos, const sf::Color& color, int dir);
	~Ant();
public:
	const sf::Vector2i& GetPosition() const { return m_position; }
	const sf::Color& GetColor() const { return m_color; }
	void Turn(TurnDir dir);
	void Move();
private:
	sf::Vector2i m_position;
	Direction    m_direction;
	sf::Color    m_color;
};

