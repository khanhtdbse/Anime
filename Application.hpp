//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com

#ifndef _Application_HPP_
#define _Application_HPP_

#include "Ado/CommonFunctions.hpp"
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <stack>
#include <memory>
#include "CommonData.hpp"
#include "StateScreen/GameState.hpp"

namespace Goku
{
    typedef BaseStateScreeen*  State;

    class Application
    {
    private:
        sf::RenderWindow               m_window;
        const sf::Time                 m_time_per_second = sf::seconds(1.f / 60.f);

        std::stack<State>              m_all_state;
    public:
        Application();
        ~Application();

        void          run();
    };
}

#endif //   _Application_HPP_