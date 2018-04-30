//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com

#include "GameState.hpp"

namespace Goku
{
    GameState::GameState(sf::RenderWindow* window) :
        m_live(true)
    {
        this->m_window = window;

        this->m_assets.push_Texture("Goku", Path_Texture + "Goku.png");

        this->m_player = new PlayerGoku(this->m_window, this->m_assets.getTexture("Goku"));
    }

    void GameState::handleEvent()
    {
        sf::Event event;
        while (this->m_window->pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                this->m_window->close();
        }
    }

    void GameState::update()
    {
        this->m_player->update();
    }

    void GameState::draw()
    {
        this->m_window->clear();
        this->m_player->draw();
        this->m_window->display();
    }

    bool GameState::checkLive()
    {
        return this->m_live;
    }
}