//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com

#include "KamehamehaSkill.hpp"

namespace Goku
{
    KamehamekaSkill::KamehamekaSkill(sf::RenderWindow* window, sf::Texture& texture, sf::Vector2f position) :
        m_animation(0.2, sf::IntRect(0, 0, 900, 84), 3, ado::Animation::Direction::Vertical),
        m_live(true)
    {
        this->m_window = window;
        this->m_sprite.setTexture(texture);

        this->m_sprite.setOrigin(-20, 42);
        this->m_sprite.setPosition(position);
    }

    KamehamekaSkill::~KamehamekaSkill()
    {

    }

    void KamehamekaSkill::update()
    {
        this->m_sprite.setTextureRect(this->m_animation.getIntRect());
        //std::cout << m_animation.getCurrentFrame() << std::endl;
        if (this->m_animation.getCurrentFrame() == 2)
            this->m_live = false;
    }

    void KamehamekaSkill::draw()
    {
        this->m_window->draw(this->m_sprite);
    }

    bool KamehamekaSkill::getLive()
    {
        return this->m_live;
    }
}