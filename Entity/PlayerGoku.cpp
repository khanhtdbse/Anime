//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com

#include "PlayerGoku.hpp"
#include "../Ado/CommonFunctions.hpp"

namespace Goku
{
    PlayerGoku::PlayerGoku(sf::RenderWindow* window, sf::Texture& texture, sf::Texture& skill, sf::Font& font) :
        m_current_state(PlayerGoku::State::Stand),
        m_state_doing(PlayerGoku::State::Null),
        m_HP(1000),
        m_KI(300)
    {
        this->m_window = window;
        this->m_texture_skill = skill;

        //this->m_srpite.setTexture(texture);
        this->m_animation[State::Buff]             = ado::Animation(0.1, sf::IntRect(0, 0, 100, 84), 7);
        this->m_animation[State::Kamehameha]       = ado::Animation(0.2, sf::IntRect(0, 84, 60, 60), 10);
        this->m_animation[State::Stand]            = ado::Animation(0.5, sf::IntRect(0, 144, 30, 60), 2);
        //this->m_animation[State::Shift]            = ado::Animation(0.1, sf::IntRect(0, 204, 30, 60), 3);
        this->m_animation[State::Kamejoko]         = ado::Animation(0.1, sf::IntRect(0, 264, 54, 50), 4);
        this->m_animation[State::StandLow]         = ado::Animation(0.5, sf::IntRect(0, 316, 50, 50), 2);
        this->m_animation[State::Move]             = ado::Animation(0.2, sf::IntRect(0, 366, 56, 40), 4);
        this->m_animation[State::Fly]              = ado::Animation(0.2, sf::IntRect(38, 406, 38, 64), 2);

        this->m_srpite.setOrigin(15, 30);
        this->m_srpite.setPosition(30, SCREEN_HEIGHT - 35);
        this->m_position = sf::Vector2f(30, 470);

        this->m_srpite.setTexture(texture);
        this->m_srpite.setTextureRect(m_animation[this->m_current_state].getIntRect());
        this->HP.setFont(font);
        this->KI.setFont(font);
        this->HP.setCharacterSize(15);
        this->KI.setCharacterSize(15);

        this->HP.setPosition(10, 0);
        this->KI.setPosition(10, 20);

        this->HP.setFillColor(sf::Color::Red);
        this->KI.setFillColor(sf::Color::Blue);
    }
    
    void PlayerGoku::update()
    {
        if (this->m_state_doing == State::Null)
        {
            if (this->m_position.y < SCREEN_HEIGHT - 35)
                this->m_current_state = State::Fly;
            else this->m_current_state = State::Stand;
            this->m_srpite.setScale(1, 1);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
                this->m_position.y -= 10;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            {
                if (this->m_position.y == SCREEN_HEIGHT - 35)
                    this->m_current_state = State::StandLow;
                this->m_position.y += 10;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            {
                this->m_srpite.setScale(1, 1);
                this->m_current_state = State::Move;
                this->m_position.x += 5;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            {
                this->m_srpite.setScale(-1, 1);
                this->m_current_state = State::Move;
                this->m_position.x -= 5;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::L))
                this->m_current_state = State::Buff;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J) && this->m_KI >= 20)
            {
                this->m_current_state = State::Kamejoko;
                if (this->m_timer.getElapsedTime().asSeconds() >= 0.4 && this->m_animation[State::Kamejoko].getCurrentFrame() == 3)
                {
                    this->m_list_kamejoko.push_back(KamejokoSkill(this->m_window, this->m_texture_skill, this->m_srpite.getPosition() + sf::Vector2f(10, 0)));
                    this->m_KI -= 20;
                    this->m_timer.restart();
                }
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K) && this->m_KI >= 200)
            {
                this->m_current_state = State::Kamehameha;
                this->m_KI -= 200;
            }
        }
        
        switch (this->m_current_state)
        {
        case State::Buff:
            this->m_srpite.setOrigin(50, 42);
            if (this->m_animation[State::Buff].getCurrentFrame() == 4)
                this->m_animation[State::Buff].setCurrentFrame(2);
            if (this->m_HP < 1000)
                this->m_HP += 10;
            if (this->m_KI < 1000)
                this->m_KI += 20;
            break;

        case State::Kamehameha:
            this->m_srpite.setOrigin(30, 30);
            if (this->m_animation[State::Kamehameha].getCurrentFrame() == 5)
                this->m_kamehameha.push_back(KamehamekaSkill(this->m_window, this->m_texture_skill, this->m_srpite.getPosition()));
            if (this->m_animation[State::Kamehameha].getCurrentFrame() == 9)
                this->m_state_doing = State::Null;
            else this->m_state_doing = State::Kamehameha;
            break;

        case State::Stand:
            this->m_srpite.setOrigin(15, 30);
            break;

        case State::Kamejoko:
            this->m_srpite.setOrigin(27, 25);
            break;

        case State::StandLow:
            this->m_srpite.setOrigin(25, 25);
            break;

        case State::Move:
            this->m_srpite.setOrigin(28, 20);
            break;

        case State::Fly:
            this->m_srpite.setOrigin(19, 32);
            break;
        }
        
        if (this->m_position.x < 25)
            this->m_position.x = 25;
        if (this->m_position.x > SCREEN_WITDH - 25)
            this->m_position.x = SCREEN_WITDH - 25;
        if (this->m_position.y < 35)
            this->m_position.y = 35;
        if (this->m_position.y > SCREEN_HEIGHT - 35)
            this->m_position.y = SCREEN_HEIGHT - 35;
        
        this->m_srpite.setPosition(this->m_position);
        this->m_srpite.setTextureRect(m_animation[this->m_current_state].getIntRect());

        if (this->m_list_kamejoko.size() > 0)
        {
            for (auto it = this->m_list_kamejoko.begin(); it != this->m_list_kamejoko.end(); it++)
                it->update();
            if (!this->m_list_kamejoko.begin()->getLive())
                this->m_list_kamejoko.pop_front();
        }

        if (this->m_kamehameha.size() > 0)
        {
            for (auto it = this->m_kamehameha.begin(); it != this->m_kamehameha.end(); it++)
                it->update();
            if (!this->m_kamehameha.begin()->getLive())
                this->m_kamehameha.pop_front();
        }

        if (this->m_HP > 1000)
            this->m_HP = 1000;
        if (this->m_KI > 300)
            this->m_KI = 300;

        std::wstring Hp = L"Máu:               " + ado::int_to_wstring(m_HP);
        this->HP.setString(Hp);

        std::wstring Ki = L"Năng Lượng: " + ado::int_to_wstring(m_KI);
        this->KI.setString(Ki);
    }


    void PlayerGoku::draw()
    {
        if (this->m_list_kamejoko.size() > 0)
        {
            for (auto it = this->m_list_kamejoko.begin(); it != this->m_list_kamejoko.end(); it++)
                it->draw();
        }

        if (this->m_kamehameha.size() > 0)
        {
            for (auto it = this->m_kamehameha.begin(); it != this->m_kamehameha.end(); it++)
                it->draw();
        }

        this->m_window->draw(this->m_srpite);
        this->m_window->draw(this->HP);
        this->m_window->draw(this->KI);
    }

    unsigned int PlayerGoku::getDamageKamejoko() const
    {
        return 100;
    }

    unsigned int PlayerGoku::getDamageKamehameha() const
    {
        return 500;
    }

    std::list<KamejokoSkill>&  PlayerGoku::getListKamejoko()
    {
        return this->m_list_kamejoko;
    }

    sf::Vector2f PlayerGoku::getPosition()
    {
        return this->m_position;
    }

    bool PlayerGoku::getKamehameha()
    {
        if (this->m_kamehameha.size() > 0)
            return !this->m_kamehameha.begin()->getLive();
        return false;
    }

    int& PlayerGoku::getHP()
    {
        return this->m_HP;
    }
}