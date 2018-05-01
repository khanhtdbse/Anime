//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com

#include "GameOver.hpp"
#include "../CommonData.hpp"

namespace Goku
{
    GameOver::GameOver(sf::RenderWindow* widnow)
    {
        this->m_window = widnow;
        this->m_type = BaseStateScreeen::GameOver;

        this->m_assets.push_Font("Font", Path_Font + "Font.ttf");

        this->m_text.setFillColor(sf::Color::Red);
        this->m_text.setFont(this->m_assets.getFont("Font"));
        this->m_text.setString("Game Over");
        this->m_text.setCharacterSize(100);

        this->m_text.setPosition(200, 150);
    }

    void GameOver::handleEvent()
    {
        sf::Event event;
        while (this->m_window->pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                this->m_window->close();
        }
    }

    void GameOver::update()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
            this->m_window->close();
    }

    void GameOver::draw()
    {
        this->m_window->draw(this->m_text);
    }

    bool GameOver::checkLive()
    {
        return this->m_live;
    }
}