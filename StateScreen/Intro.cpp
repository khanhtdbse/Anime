//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com

#include "Intro.hpp"
#include "../CommonData.hpp"

namespace Goku
{
    Intro::Intro(sf::RenderWindow* widnow) :
        m_live(true)
    {
        this->m_window = widnow;

        this->m_type = BaseStateScreeen::Intro;

        this->m_assets.push_Texture("Intro_1", Path_Texture + "Intro_1.png");
        this->m_assets.push_Texture("Intro_2", Path_Texture + "Intro_2.png");

        this->m_sprite.setTexture(this->m_assets.getTexture("Intro_1"));
        this->m_sprite.setPosition(450, 250);
        this->m_sprite.setOrigin(450, 250);
        this->m_sprite.setScale(intdex, intdex);
    }

    void Intro::handleEvent()
    {
        sf::Event event;
        while (this->m_window->pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                this->m_window->close();
        }
    }

    void Intro::update()
    {
        if (intdex < 1.0)
        {
            intdex += 0.01;
            this->m_sprite.setScale(intdex, intdex);
        }
        else
        {
            this->m_sprite.setTexture(this->m_assets.getTexture("Intro_2"));
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                this->m_live = false;
        }

    }

    void Intro::draw()
    {
        this->m_window->draw(this->m_sprite);
    }

    bool Intro::checkLive()
    {
        return this->m_live;
    }
}