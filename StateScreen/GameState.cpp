//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com

#include "GameState.hpp"
#include "../Ado/CommonFunctions.hpp"

namespace Goku
{
    GameState::GameState(sf::RenderWindow* window) :
        m_live(true)
    {
        this->m_window = window;

        this->m_assets.push_Texture("Goku", Path_Texture + "Goku.png");
        this->m_assets.push_Texture("SkillGoku", Path_Texture + "SkillGoku.png");
        this->m_assets.push_Texture("Dragon", Path_Texture + "Dragon.png");
        this->m_assets.push_Texture("Explosition", Path_Texture + "Explosition.png");
        this->m_assets.push_Texture("MainBackground", Path_Texture + "MainBackground.jpg");

        this->m_assets.push_Font("Font", Path_Font + "Font.ttf");
        this->m_text.setFont(this->m_assets.getFont("Font"));
        //this->m_text.setString(L"Chào Mọi Người");
        this->m_text.setCharacterSize(20);
        this->m_text.setPosition(800, 0);
        this->m_text.setFillColor(sf::Color::Green);

        this->m_player = new PlayerGoku(this->m_window, this->m_assets.getTexture("Goku"), this->m_assets.getTexture("SkillGoku"), this->m_assets.getFont("Font"));
        this->m_type = BaseStateScreeen::GamePlay;
    }

    void GameState::handleEvent()
    {
        sf::Event event;
        while (this->m_window->pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                this->m_window->close();
        }
    }

    void GameState::checkCollision()
    {
        if (this->m_monster.size() > 0)
        {
            //   Check collision with Player and Monster
            for (auto it = this->m_monster.begin(); it != this->m_monster.end(); it++)
            {
                int x = abs(it->getPosition().x - this->m_player->getPosition().x);
                int y = abs(it->getPosition().y - this->m_player->getPosition().y);

                if (x <= 100 && y <= 80)
                {
                    this->m_player->getHP() -= 100;
                    int x1;
                    int y1;
                    if (it->getPosition().x > this->m_player->getPosition().x)
                        x1 = it->getPosition().x;
                    else x1 = this->m_player->getPosition().x;
                    if (it->getPosition().y > this->m_player->getPosition().y)
                        y1 = it->getPosition().y;
                    else y1 = this->m_player->getPosition().y;
                    this->m_explosition.push_back(Explosition(this->m_window, this->m_assets.getTexture("Explosition"), x1 + x / 2, y1 + y / 2));
                    this->m_monster.erase(it);
                    this->m_score++;
                    break;
                }
            }

            if (this->m_player->getListKamejoko().size() > 0)
            {
                for (auto it = this->m_monster.begin(); it != this->m_monster.end(); it++)
                {
                    bool check = false;
                    for (auto it2 = this->m_player->getListKamejoko().begin(); it2 != this->m_player->getListKamejoko().end(); it2++)
                    {
                        int x = abs(it->getPosition().x - it2->getPosition().x);
                        int y = abs(it->getPosition().y - it2->getPosition().y);

                        if (x <= 100 && y <= 50)
                        {
                            it->getHP() -= this->m_player->getDamageKamejoko();
                            //std::cout << it->getHP() << std::endl;

                            if (it->getHP() <= 0)
                            {
                                
                                int x1;
                                int y1;
                                if (it->getPosition().x > it2->getPosition().x)
                                    x1 = it->getPosition().x;
                                else x1 = it2->getPosition().x;
                                if (it->getPosition().y > it2->getPosition().y)
                                    y1 = it->getPosition().y;
                                else y1 = it2->getPosition().y;
                                this->m_explosition.push_back(Explosition(this->m_window, this->m_assets.getTexture("Explosition"), x1 + x / 2, y1 + y / 2));
                                this->m_monster.erase(it);
                                this->m_score++;
                            }
                            this->m_player->getListKamejoko().erase(it2);
                            check = true;
                            break;
                        }
                    }
                    if (check)
                        break;
                }
            }

            if (this->m_player->getKamehameha())
            {
                for (auto it = this->m_monster.begin(); it != this->m_monster.end(); it++)
                {
                    int x = it->getPosition().x - this->m_player->getPosition().x;
                    int y = abs(it->getPosition().y - this->m_player->getPosition().y);
                    if (x > 0 && y <= 100)
                    {
                        this->m_monster.erase(it);
                        this->m_score++;
                        break;
                    }
                }
            }
        }
    }

    void GameState::update()
    {
        this->m_player->update();

        if (this->m_monster.size() > 0)
        {
            if (this->m_monster.begin()->getHP() < 0 || this->m_monster.begin()->getPosition().x < 0)
                this->m_monster.pop_front();
            for (auto it = this->m_monster.begin(); it != this->m_monster.end(); it++)
                it->update();
        }

        if (this->m_clock.getElapsedTime().asSeconds() > 2)
        {
            this->m_monster.push_back(Monster(this->m_window, this->m_assets.getTexture("Dragon")));
            this->m_clock.restart();
        }

        if (this->m_explosition.size() > 0)
        {
            for (auto it = this->m_explosition.begin(); it != this->m_explosition.end(); it++)
                it->update();

            if (!this->m_explosition.begin()->isLive())
                this->m_explosition.pop_front();
        }
        std::wstring Diem = L"Điểm: " + ado::int_to_wstring(this->m_score);
        this->m_text.setString(Diem);

        this->checkCollision();

        if (this->m_player->getHP() <= 0)
            this->m_live = false;
    }

    void GameState::draw()
    {
        sf::Sprite sp(this->m_assets.getTexture("MainBackground"));
        sp.setColor(sf::Color::Cyan);
        this->m_window->draw(sp);

        if (this->m_monster.size() > 0)
        {
            for (auto it = this->m_monster.begin(); it != this->m_monster.end(); it++)
                it->draw();
        }
        this->m_player->draw();
        if (this->m_explosition.size() > 0)
        {
            for (auto it = this->m_explosition.begin(); it != this->m_explosition.end(); it++)
                it->draw();
        }

        this->m_window->draw(this->m_text);

    }

    bool GameState::checkLive()
    {
        return this->m_live;
    }
}