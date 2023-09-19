#include "MainResources.h"

bool MainResources::m_gameRunning = false;
std::shared_ptr<sf::RenderWindow> MainResources::m_window = std::make_shared<sf::RenderWindow>(sf::VideoMode::getDesktopMode(), "Mactangle", sf::Style::Fullscreen);
std::shared_ptr<sf::View> MainResources::m_camera = std::make_shared<sf::View>();
sf::Font MainResources::m_font = sf::Font();

MainResources::MainResources() {
    m_window->setVisible(true);
    m_window->setVerticalSyncEnabled(true);
    m_window->setKeyRepeatEnabled(false);
    m_window->setMouseCursorGrabbed(true);
    m_window->setActive(true);
    m_window->setPosition(sf::Vector2i(0, 0));

    m_camera->setSize(sf::Vector2<float>(m_window->getSize()));
    m_camera->setCenter(m_camera->getSize().x / 2, m_camera->getSize().y / 2);
    m_camera->setViewport(sf::FloatRect(0, 0, 1, 1));

    m_window->setView(*m_camera);

    m_gameRunning = false;
    m_font.loadFromFile(CUBICCOREMONO_TTF);
}

std::shared_ptr<sf::RenderWindow> MainResources::getWindow() {
    return m_window;
}
