//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com

#ifndef _Explosition_HPP_
#define _Explosition_HPP_

#include <SFML/Graphics.hpp>
#include "../Ado/Animation.hpp"


namespace Goku
{
    class Explosition
    {
    private:
        sf::RenderWindow*           m_window;
        sf::Sprite                  m_sprite;

        ado::Animation              m_animation;

    public:
        Explosition(sf::RenderWindow* window, sf::Texture& texture, int x, int y);

        void                        update();
        void                        draw();
        bool                        isLive();
    };
}


#endif  //   _Explosition_HPP_