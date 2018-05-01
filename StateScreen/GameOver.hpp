//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com

#ifndef _GameOver_HPP_
#define _GameOver_HPP_

#include "BaseStateScreen.hpp"
#include "../Ado/AssetsManager.hpp"

namespace Goku
{
    class GameOver : public BaseStateScreeen
    {
    private:
        bool           m_live;

        sf::Text       m_text;


    public:

        GameOver(sf::RenderWindow* widnow);

        void        handleEvent();

        void        update();

        void        draw();

        bool        checkLive();
    };
}


#endif //  _GameOver_HPP_