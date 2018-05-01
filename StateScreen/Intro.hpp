//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com

#ifndef _Intro_HPP_
#define _Intro_HPP_

#include <SFML/Graphics.hpp>
#include "../Ado/Animation.hpp"
#include "BaseStateScreen.hpp"

namespace Goku
{
    class Intro : public BaseStateScreeen
    {
    private:
        bool           m_live;

        sf::Sprite     m_sprite;

        float          intdex = 0.1;

    public:
        Intro(sf::RenderWindow* widnow);

        void        handleEvent();
        
        void        update();

        void        draw();

        bool        checkLive();

    };
}

#endif //   _Intro_HPP_