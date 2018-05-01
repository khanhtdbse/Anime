//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com

#include "Explosition.hpp"

namespace Goku
{
    Explosition::Explosition(sf::RenderWindow* window, sf::Texture& texture, int x, int y) :
        m_animation(0.05, sf::IntRect(0, 0, 50, 50), 20)
    {
        this->m_window = window;
        this->m_sprite.setTexture(texture);

        this->m_sprite.setOrigin(25, 25);
        this->m_sprite.setPosition(x, y);
        this->m_sprite.setScale(3, 3);
        this->m_sprite.setTextureRect(this->m_animation.getIntRect());
    }

    void Explosition::update()
    {
        this->m_sprite.setTextureRect(this->m_animation.getIntRect());
    }

    void Explosition::draw()
    {
        this->m_window->draw(this->m_sprite);
    }

    bool Explosition::isLive()
    {
        if (this->m_animation.getCurrentFrame() == 19)
            return false;
        return true;
    }
}