//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com

#include "KamejokoSkill.hpp"

namespace Goku
{
    KamejokoSkill::KamejokoSkill(sf::RenderWindow* window, sf::Texture& texture, sf::Vector2f position) :
        m_animation(0.15, sf::IntRect(0, 252, 106, 30), 5),
        m_live(true)
    {
        this->m_window = window;

        this->m_sprite.setTexture(texture);

        this->m_sprite.setOrigin(53, 15);
        this->m_sprite.setPosition(position);
    }

    KamejokoSkill::~KamejokoSkill()
    {

    }

    void KamejokoSkill::update()
    {
        this->m_sprite.setTextureRect(this->m_animation.getIntRect());
        this->m_sprite.move(20, 0);
        if (this->m_animation.getCurrentFrame() == 4)
            this->m_live = false;
    }

    void KamejokoSkill::draw()
    {
        this->m_window->draw(this->m_sprite);
    }

    sf::Vector2f KamejokoSkill::getPosition()
    {
        return this->m_sprite.getPosition();
    }

    bool KamejokoSkill::getLive()
    {
        return m_live;
    }
}