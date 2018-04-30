//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com

#ifndef _GameState_HPP_
#define _GameState_HPP_

#include <SFML/Graphics.hpp>
#include "BaseStateScreen.hpp"
#include "../Entity/PlayerGoku.hpp"
#include "../CommonData.hpp"

namespace Goku
{
    class GameState : public BaseStateScreeen
    {
    private:
        bool                   m_live;

        PlayerGoku*            m_player;
        ado::AssetsManager     m_assets;

    public:
        GameState     (sf::RenderWindow* window);
        
        void          handleEvent();
        void          update();
        void          draw();

        bool          checkLive();

    };
}


#endif //   _GameState_HPP_