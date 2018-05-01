//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com

#include "Monster.hpp"

namespace Goku
{
    Monster::Monster(sf::RenderWindow* window, sf::Texture& texture) :
        m_animation(0.3, sf::IntRect(0, 0, 176, 140), 3),
        m_HP(150)
    {
        this->m_window = window;
        a.loadFromFile(Path_Texture + "Dragon.png");
        this->m_sprite.setTexture(texture);
        this->m_sprite.setOrigin(88, 70);

        int y = rand() % 360 + 70;
        

        this->m_sprite.setPosition(1000, y);
        //this->m_sprite.setScale(-1, 1);
    }

    Monster::~Monster()
    {

    }

    void Monster::update()
    {
        this->m_sprite.move(-3, 0);

        this->m_sprite.setTextureRect(this->m_animation.getIntRect());
    }

    void Monster::draw()
    {
        this->m_window->draw(this->m_sprite);
    }

    sf::Vector2f Monster::getPosition()
    {
        return this->m_sprite.getPosition();
    }

    int& Monster::getHP()
    {
        return this->m_HP;
    }
}