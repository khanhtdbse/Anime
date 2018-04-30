//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com

#ifndef _PlayerGoku_HPP_
#define _PlayerGoku_HPP_

#include "../Ado/Animation.hpp"
#include "../CommonData.hpp"
#include <SFML/Graphics.hpp>
#include <map>

namespace Goku
{
    class PlayerGoku
    {
    private:
        enum State
        {
            Stand,
            Buff,
            Fly,
            Kamehameha,
            Kamejoko,
            Move,
            Shift,
            StandLow
        };

    private:
        sf::RenderWindow*                   m_window;
        sf::Sprite                          m_srpite;

        State                               m_current_state;

        std::map<State, ado::Animation>     m_animation;

    public:
        PlayerGoku(sf::RenderWindow* window, sf::Texture& texture);

        void         update();
        void         draw();

    };
}

#endif //   _PlayerGoku_HPP_