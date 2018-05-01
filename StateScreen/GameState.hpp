//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com

#ifndef _GameState_HPP_
#define _GameState_HPP_

#include <SFML/Graphics.hpp>
#include "BaseStateScreen.hpp"
#include "../Entity/PlayerGoku.hpp"
#include "../CommonData.hpp"
#include "../Entity/Monster.hpp"
#include "../Entity/Explosition.hpp"

namespace Goku
{
    class GameState : public BaseStateScreeen
    {
    private:
        bool                   m_live;

        PlayerGoku*            m_player;
        
        std::list<Monster>     m_monster;

        sf::Clock              m_clock;

        sf::Text               m_text;
        unsigned int           m_score = 0;
        std::list<Explosition> m_explosition;
        void          checkCollision();

        
    public:
        GameState     (sf::RenderWindow* window);
        
        void          handleEvent();
        void          update();
        void          draw();

        bool          checkLive();

    };
}


#endif //   _GameState_HPP_