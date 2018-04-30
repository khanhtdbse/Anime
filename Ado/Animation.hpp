//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com
//   Facebook:https://www.facebook.com/adonis.harding

#ifndef _Animation_HPP_
#define _Animation_HPP_

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <Windows.h>
#include <iostream>
#include <vector>

namespace ado
{
    class Animation
    {
	public:
		enum Direction
		{
			Horizontal,
			Vertical
		};

	protected:
        std::vector<sf::IntRect>     m_all_frames;
        sf::Clock                    m_timer;

        float                        m_time_to_next_frame;
        unsigned int                 m_current_frame;

	public:
		Animation();
		Animation(float time_to_next_frame, sf::IntRect frame, int count, Direction direction = Direction::Horizontal);
		~Animation();

		void                create(float time_to_next_frame, sf::IntRect frame, int count, Direction direction = Direction::Horizontal);

		sf::IntRect         getIntRect();
		unsigned int        getCurrentFrame();
		void                setCurrentFrame(int frame);

    };
}

#endif // _Animation_HPP_
