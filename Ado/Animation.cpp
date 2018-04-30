//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com
//   Facebook:https://www.facebook.com/adonis.harding

#include "Animation.hpp"

namespace ado
{
    Animation::Animation()
    {
    	//   Constructor
    }

    Animation::Animation(float time_to_next_frame, sf::IntRect frame, int count, Direction direction)
    {
        this->m_time_to_next_frame = time_to_next_frame;
        this->m_current_frame = 0;

        switch (direction)
        {
		case Direction::Horizontal:
			for (int i = 0; i < count; i++)
				this->m_all_frames.push_back(sf::IntRect(frame.left + i * frame.width, frame.top, frame.width, frame.height));
			break;

		case Direction::Vertical:
			for (int i = 0; i < count; i++)
				this->m_all_frames.push_back(sf::IntRect(frame.left, frame.top + i * frame.height, frame.width, frame.height));
			break;
        }
    }

    Animation::~Animation()
    {
    	//   Destructor
    }

    void Animation::create(float time_to_next_frame, sf::IntRect frame, int count, Direction direction)
    {
    	this->m_time_to_next_frame = time_to_next_frame;
        this->m_current_frame = 0;

        switch (direction)
        {
		case Direction::Horizontal:
			for (int i = 0; i < count; i++)
				this->m_all_frames.push_back(sf::IntRect(frame.left + i * frame.width, frame.top, frame.width, frame.height));
			break;

		case Direction::Vertical:
			for (int i = 0; i < count; i++)
				this->m_all_frames.push_back(sf::IntRect(frame.left, frame.top + i * frame.height, frame.width, frame.height));
			break;
        }
    }

    sf::IntRect Animation::getIntRect()
    {
        if (this->m_timer.getElapsedTime().asSeconds() > this->m_time_to_next_frame)
		{
			this->m_current_frame++;
			if (this->m_current_frame == this->m_all_frames.size())
				this->m_current_frame = 0;
			this->m_timer.restart();
		}
		return this->m_all_frames[this->m_current_frame];

    }


    unsigned int Animation::getCurrentFrame()
    {
    	return this->m_current_frame;
    }

    void Animation::setCurrentFrame(int frame)
    {
    	if (frame >= 0 && frame < this->m_all_frames.size())
		{
            this->m_current_frame = frame;
            this->m_timer.restart();
		}
    }

}
