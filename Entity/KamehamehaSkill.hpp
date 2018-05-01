//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com

#ifndef _KamehamehaSkill_HPP_
#define _KamehamehaSkill_HPP_

#include "../Ado/Animation.hpp"
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>

namespace Goku
{
    class KamehamekaSkill
    {
    private:
        sf::RenderWindow*            m_window;
        sf::Sprite                   m_sprite;

        ado::Animation               m_animation;

        bool                         m_live;

    public:
        KamehamekaSkill(sf::RenderWindow* window, sf::Texture& texture, sf::Vector2f position);
        ~KamehamekaSkill();

        void             update();
        void             draw();

        bool             getLive();

    };
}


#endif //   _KamehamehaSkill_HPP_