//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com

#ifndef _Monster_HPP_
#define _Monster_HPP_

#include "../Ado/Animation.hpp"
#include "../CommonData.hpp"
#include <SFML/Graphics.hpp>

namespace Goku
{
    class Monster
    {
    private:
        sf::RenderWindow*               m_window;
        sf::Sprite                      m_sprite;

        ado::Animation                  m_animation;
        sf::Texture a;

        int                             m_HP;
    public:
        Monster(sf::RenderWindow* window, sf::Texture& texture);
        ~Monster();

        void                  update();
        void                  draw();

        sf::Vector2f          getPosition();
        int&                  getHP();

    };
}


#endif //   _Monster_HPP_