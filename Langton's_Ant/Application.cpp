#include "stdafx.h"
#include "Application.h"


Application::Application() {
	m_mainWindow.create(sf::VideoMode(1000, 650), "Langton's Ant", sf::Style::Close);

	m_pixelBuffer.create(1000, 650, sf::Color::White);
	m_cellsTex.loadFromImage(m_pixelBuffer);
	m_cells.setTexture(&m_cellsTex);
	m_cells.setPosition(0, 0);
	m_cells.setSize(sf::Vector2f(1000, 650));
}

inline void Application::SetTexture() {
	m_cellsTex.loadFromImage(m_pixelBuffer);
	m_cells.setTexture(&m_cellsTex);
}

void Application::Update() {
	
}

void Application::Render() {
	m_mainWindow.draw(m_cells);
}

void Application::Run() {
	while (m_mainWindow.isOpen()) {
		sf::Event evnt;
		while (m_mainWindow.pollEvent(evnt)) {
			if (evnt.type == sf::Event::Closed) {
				m_mainWindow.close();
			}
		}

		m_mainWindow.clear();

		if (m_deltaTime.getElapsedTime().asMilliseconds() > 20) {
			this->Update();
			this->SetTexture();
			m_deltaTime.restart();
		}
		this->Render();

		m_mainWindow.display();
	}
}


Application::~Application() {

}
