//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com

#include "Application.hpp"

namespace Goku
{
    Application::Application() :
        m_window(sf::VideoMode(SCREEN_WITDH, SCREEN_HEIGHT), L"Son Goku Đại Chiến Ninja", sf::Style::Close)
    {
        this->m_window.setFramerateLimit(60);
        State temp = new GameState(&this->m_window);
        this->m_all_state.push(temp);
    }

    Application::~Application()
    {
        
    }


    void Application::run()
    {
        sf::Clock clock;
        sf::Time  timeSinceLastUpdate = sf::Time::Zero;

        while (this->m_window.isOpen())
        {
            this->m_all_state.top()->handleEvent();
            timeSinceLastUpdate += clock.restart();

            while (timeSinceLastUpdate > this->m_time_per_second)
            {
                timeSinceLastUpdate -= m_time_per_second;
                this->m_all_state.top()->handleEvent();
                this->m_all_state.top()->update();
            }
            this->m_all_state.top()->draw();
        }
    }
}