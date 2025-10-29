#pragma once
#include "KamataEngine.h"
#include "Player.h"
#include "Enemy.h"
#include "ModelManager.h"

class GameScene {
public:
	// 初期化
	void Init();

	// 更新
	void Update();

	// 描画
	void Draw();

private:
	KamataEngine::WorldTransform worldTransform_{};
	KamataEngine::Camera camera_{};

	// プレイヤーインスタンス
	std::unique_ptr<Player> player_;
	// エネミーインスタンス
	std::unique_ptr<Enemy> enemy_;
};
