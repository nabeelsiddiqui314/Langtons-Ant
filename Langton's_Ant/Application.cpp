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

State Application::GetPixelState(const sf::Vector2u& pixel) const {
	if (m_pixelBuffer.getPixel(pixel.x, pixel.y) == sf::Color::White)
		return State::OFF;
	else
		return State::ON;
}

void Application::AddAnt() {
	m_ants.emplace_back(sf::Vector2i(sf::Mouse::getPosition(m_mainWindow)), sf::Color(random(50, 255), random(70, 255), random(130, 255)), random(0, 3));

}

void Application::Update() {
	for (unsigned int i = 0; i < m_ants.size(); i++) {
		if (this->GetPixelState((sf::Vector2u)m_ants[i].GetPosition()) == State::OFF) {
			if (m_ants[i].GetPosition().x > 0 && m_ants[i].GetPosition().x < 1000 &&
				m_ants[i].GetPosition().y > 0 && m_ants[i].GetPosition().y < 650) {
				m_pixelBuffer.setPixel(m_ants[i].GetPosition().x, m_ants[i].GetPosition().y, m_ants[i].GetColor());
				m_ants[i].Turn(TurnDir::RIGHT);
				m_ants[i].Move();
			}
		}
		else {
			if (m_ants[i].GetPosition().x > 0 && m_ants[i].GetPosition().x < 1000-1 &&
				m_ants[i].GetPosition().y > 0 && m_ants[i].GetPosition().y < 650-1) {
				m_pixelBuffer.setPixel(m_ants[i].GetPosition().x, m_ants[i].GetPosition().y, sf::Color::White);
				m_ants[i].Turn(TurnDir::LEFT);
				m_ants[i].Move();
			}
		}
	}
}

void Application::Render() {
	m_mainWindow.draw(m_cells);
}

void Application::Run() {
	while (m_mainWindow.isOpen()) {
		sf::Event evnt;
		while (m_mainWindow.pollEvent(evnt)) {
			if (evnt.type == sf::Event::MouseButtonPressed) {
				this->AddAnt();
			}

			if (evnt.type == sf::Event::Closed) {
				m_mainWindow.close();
			}
		}

		m_mainWindow.clear();
		this->Update();
		this->SetTexture();
		this->Render();

		m_mainWindow.display();
	}
}


int Application::random(int min, int max) {
	srand(m_seed.getElapsedTime().asMicroseconds());
	return rand() % (max + 1 - min) + min;
}

Application::~Application() {

}
