//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com

#include "PlayerGoku.hpp"

namespace Goku
{
    PlayerGoku::PlayerGoku(sf::RenderWindow* window, sf::Texture& texture) :
        m_current_state(PlayerGoku::State::Stand)
    {
        this->m_window = window;

        this->m_srpite.setTexture(texture);
        this->m_animation[State::Buff] = ado::Animation(0.1, sf::IntRect(0, 0, 100, 84), 7);
        this->m_animation[State::Kamehameha] = ado::Animation(0.2, sf::IntRect(0, 84, 60, 60), 10);
        this->m_animation[State::Stand] = ado::Animation(0.5, sf::IntRect(0, 144, 30, 60), 2);
        this->m_animation[State::Shift] = ado::Animation(0.1, sf::IntRect(0, 204, 30, 60), 3);
        this->m_animation[State::Kamejoko] = ado::Animation(0.1, sf::IntRect(0, 264, 54, 50), 4);
        this->m_animation[State::StandLow] = ado::Animation(0.5, sf::IntRect(0, 316, 50, 50), 2);
        this->m_animation[State::Move] = ado::Animation(0.2, sf::IntRect(0, 366, 56, 40), 4);
        this->m_animation[State::Fly] = ado::Animation(0.5, sf::IntRect(0, 406, 38, 64), 4);
    }

    void PlayerGoku::update()
    {
        this->m_srpite.setTextureRect(m_animation[this->m_current_state].getIntRect());
    }

    void PlayerGoku::draw()
    {
        this->m_window->draw(this->m_srpite);
    }
}