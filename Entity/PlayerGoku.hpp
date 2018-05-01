//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com

#ifndef _PlayerGoku_HPP_
#define _PlayerGoku_HPP_

#include <SFML/Graphics.hpp>
#include <map>
#include <list>
#include "../Ado/Animation.hpp"
#include "../CommonData.hpp"
#include "KamejokoSkill.hpp"
#include "KamehamehaSkill.hpp"

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
            StandLow,
            Null
        };

    private:
        sf::RenderWindow*                   m_window;
        sf::Sprite                          m_srpite;
        sf::Texture                         m_texture_skill;
        sf::Clock                           m_timer;

        State                               m_current_state;
        State                               m_state_doing;

        std::map<State, ado::Animation>     m_animation;

        sf::Vector2f                        m_position;

        std::list<KamejokoSkill>            m_list_kamejoko;
        std::list<KamehamekaSkill>          m_kamehameha;

        int                                 m_KI;
        int                                 m_HP;

        sf::Text                            HP;
        sf::Text                            KI;

    public:
        PlayerGoku(sf::RenderWindow* window, sf::Texture& texture, sf::Texture& skill, sf::Font& font);
         
        void                              update();
        void                              draw();

        unsigned int                      getDamageKamejoko() const;
        unsigned int                      getDamageKamehameha() const;

        bool                              getKamehameha();

        std::list<KamejokoSkill>&         getListKamejoko();

        sf::Vector2f                      getPosition();

        int&                              getHP();

    };
}

#endif //   _PlayerGoku_HPP_