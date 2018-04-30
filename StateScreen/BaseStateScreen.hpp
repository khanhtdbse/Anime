//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com

#ifndef _BaseStateScreen_HPP_
#define _BaseStateScreen_HPP_

#include "../Ado/AssetsManager.hpp"
#include <SFML/Graphics.hpp>

namespace Goku
{
    class BaseStateScreeen
    {
    protected:
        sf::RenderWindow*        m_window;

    public:

        virtual void       handleEvent() = 0;
        virtual void       update() = 0;
        virtual void       draw() = 0;

        virtual bool       checkLive() = 0;
    };
}


#endif //   _BaseStateScreen_HPP_