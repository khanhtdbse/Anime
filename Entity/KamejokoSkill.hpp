//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com

#ifndef _KamejokokSill_HPP_
#define _KamejokoSkill_HPP_

#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include "../CommonData.hpp"
#include "../Ado/Animation.hpp"

namespace Goku
{
    class KamejokoSkill
    {
    private:
        sf::RenderWindow*           m_window;
        sf::Sprite                  m_sprite;

        ado::Animation              m_animation;

        bool                        m_live;

    public:
        KamejokoSkill(sf::RenderWindow* window, sf::Texture& texture, sf::Vector2f position);
        ~KamejokoSkill();

        void               update();
        void               draw();

        sf::Vector2f       getPosition();

        bool               getLive();
    };
}

#endif //   _Kamejokokill_HPP_