#pragma once
#include <vector>
#include "Input.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

enum class Scene
{
    Title,
    Play,
    Result
};

class Game
{
private:
    Input m_input;

    Scene m_scene;

    Player m_player;

    // エネミーのリスト
    std::vector<Enemy> m_enemies;

    // 弾のリスト
    std::vector<Bullet> m_bullets;

    int m_score;

    // 敵スポーンタイマー
    int m_spawn_timer;

    // クリアフラグ
    bool m_isClear;
public:
    Game();

    void Update();
    void Draw();
private:
    void UpdateTitle();
    void UpdatePlay();
    void UpdateResult();

    bool CheckHit(
        float ax,
        float ay,
        float aw,
        float ah,
        float bx,
        float by,
        float bw,
        float bh
    );
};