#include "Game.h"
#include "DxLib.h"

#include <algorithm>
#include <ctime>

Game::Game()
{
    m_scene = Scene::Title;

    m_score = 0;
    m_spawn_timer = 0;

    m_isClear = false;

    srand((unsigned int)time(nullptr));
}

void Game::Update()
{
    m_input.Update();

    switch (m_scene)
    {
    case Scene::Title:
        UpdateTitle();
        break;

    case Scene::Play:
        UpdatePlay();
        break;

    case Scene::Result:
        UpdateResult();
        break;
    }
}

void Game::Draw()
{
    switch (m_scene)
    {
    case Scene::Title:

        DrawString(
            500,
            300,
            "SIMPLE SHOOTING",
            GetColor(255, 255, 255));

        DrawString(
            450,
            400,
            "PRESS ENTER",
            GetColor(255, 255, 255));

        break;

    case Scene::Play:

        m_player.Draw();

        for (auto& enemy : m_enemies)
        {
            enemy.Draw();
        }

        for (auto& bullet : m_bullets)
        {
            bullet.Draw();
        }

        DrawFormatString(
            1000,
            20,
            GetColor(255, 255, 255),
            "SCORE : %d",
            m_score);

        DrawFormatString(
            1000,
            50,
            GetColor(255, 255, 255),
            "HP : %d",
            m_player.GetHP());

        break;

    case Scene::Result:

        if (m_isClear)
        {
            DrawString(
                500,
                300,
                "GAME CLEAR",
                GetColor(0, 255, 0));
        }
        else
        {
            DrawString(
                500,
                300,
                "GAME OVER",
                GetColor(255, 0, 0));
        }

        DrawFormatString(
            500,
            400,
            GetColor(255, 255, 255),
            "SCORE : %d",
            m_score);

        DrawString(
            420,
            500,
            "PRESS ENTER TO TITLE",
            GetColor(255, 255, 255));

        break;
    }
}

void Game::UpdateTitle()
{
    if (m_input.IsTrigger(KEY_INPUT_RETURN))
    {
        m_scene = Scene::Play;
    }
}

void Game::UpdatePlay()
{
    m_player.Update(m_input);

    m_spawn_timer++;

    if (m_spawn_timer >= 30)
    {
        m_spawn_timer = 0;

        m_enemies.push_back(
            Enemy(
                (float)(rand() % 1170)));
    }

    if (m_input.IsTrigger(KEY_INPUT_RETURN))
    {
        m_bullets.push_back(
            Bullet(
                m_player.GetX() + 15,
                m_player.GetY()));
    }

    for (auto& enemy : m_enemies)
    {
        enemy.Update();
    }

    for (auto& bullet : m_bullets)
    {
        bullet.Update();
    }

    // 弾と敵
    for (auto& enemy : m_enemies)
    {
        if (!enemy.IsActive())
        {
            continue;
        }

        for (auto& bullet : m_bullets)
        {
            if (!bullet.IsActive())
            {
                continue;
            }

            if (CheckHit(
                bullet.GetX(),
                bullet.GetY(),
                10,
                10,

                enemy.GetX(),
                enemy.GetY(),
                enemy.GetWidth(),
                enemy.GetHeight()))
            {
                enemy.Destroy();
                bullet.Destroy();

                m_score += 100;
            }
        }
    }

    // プレイヤーとエネミー
    for (auto& enemy : m_enemies)
    {
        if (!enemy.IsActive())
        {
            continue;
        }

        if (CheckHit(
            m_player.GetX(),
            m_player.GetY(),
            m_player.GetWidth(),
            m_player.GetHeight(),

            enemy.GetX(),
            enemy.GetY(),
            enemy.GetWidth(),
            enemy.GetHeight()))
        {
            m_player.Damage(1);

            enemy.Destroy();
        }
    }

    m_enemies.erase(
        std::remove_if(
            m_enemies.begin(),
            m_enemies.end(),
            [](const Enemy& enemy)
            {
                return !enemy.IsActive();
            }),
        m_enemies.end());

    m_bullets.erase(
        std::remove_if(
            m_bullets.begin(),
            m_bullets.end(),
            [](const Bullet& bullet)
            {
                return !bullet.IsActive();
            }),
        m_bullets.end());

    if (m_player.IsDead())
    {
        m_isClear = false;
        m_scene = Scene::Result;
    }

    if (m_score >= 1000)
    {
        m_isClear = true;
        m_scene = Scene::Result;
    }
}

void Game::UpdateResult()
{
    if (m_input.IsTrigger(KEY_INPUT_RETURN))
    {
        *this = Game();
    }
}

bool Game::CheckHit(
    float ax,
    float ay,
    float aw,
    float ah,
    float bx,
    float by,
    float bw,
    float bh)
{
    return
        ax < bx + bw &&
        ax + aw > bx &&
        ay < by + bh &&
        ay + ah > by;
}