#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ant.h"

enum class State {
	ON,
	OFF
};

class Application
{
public:
	Application();
	Application(const Application& other) = delete;
	~Application();
public:
	void Run();
private:
	inline void SetTexture();

	void Update();
	void Render();
private:
	sf::Clock        m_deltaTime;
	sf::RenderWindow m_mainWindow;

	sf::RectangleShape m_cells;
	sf::Texture        m_cellsTex;
	sf::Image          m_pixelBuffer;
};

