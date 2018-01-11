#include "stdafx.h"
#include "Ant.h"


Ant::Ant(const sf::Vector2i& pos, const sf::Color& color, int dir) 
: m_position(pos)
, m_color(color)
, m_direction((Direction)dir) {
	
}

void Ant::Turn(TurnDir dir) {
	switch (m_direction) {
	case Direction::UP:
		if (dir == TurnDir::RIGHT) m_direction = Direction::RIGHT;
		else m_direction = Direction::LEFT;
		break;
	case Direction::DOWN:
		if (dir == TurnDir::RIGHT) m_direction = Direction::LEFT;
		else m_direction = Direction::RIGHT;
		break;
	case Direction::LEFT:
		if (dir == TurnDir::RIGHT) m_direction = Direction::UP;
		else m_direction = Direction::DOWN;
		break;
	case Direction::RIGHT:
		if (dir == TurnDir::RIGHT) m_direction = Direction::DOWN;
		else m_direction = Direction::UP;
		break;
	}
}

void Ant::Move() {
	switch (m_direction) {
	case Direction::UP:
		m_position.y--;
		break;
	case Direction::DOWN:
		m_position.y++;
		break;
	case Direction::LEFT:
		m_position.x--;
		break;
	case Direction::RIGHT:
		m_position.x++;
		break;
	}
}


Ant::~Ant()
{
}
