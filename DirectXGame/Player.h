#pragma once
#include <KamataEngine.h>
#include "MathUtils.h"
#include <cassert>
#include "Bullet.h"

class Player {
public:
	// 初期化
	void Init(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position);

	// 更新処理
	void Update();

	// 描画処理
	void Draw();

	void ImGui();

	KamataEngine::Vector3 GetTranslate() { return worldTransform_.translation_; }

private:
	KamataEngine::WorldTransform worldTransform_{};
	KamataEngine::Model* model_ = nullptr;
	KamataEngine::Camera* camera_ = nullptr;
	float velocity = 1.0f;
	std::unique_ptr<Bullet> bullet_ = std::make_unique<Bullet>();
};
