#pragma once
#include "KamataEngine.h"
#include "Player.h"

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

	// プレイヤーのモデル
	KamataEngine::Model* modelPlayer_ = nullptr;

};
