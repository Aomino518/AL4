#pragma once
#include <KamataEngine.h>
#include "MathUtils.h"
#include <cassert>

class Player {
public:
	// 初期化
	void Init(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position);

	// 更新処理
	void Update();

	// 描画処理
	void Draw();

	void ImGui();

private:
	KamataEngine::WorldTransform worldTransform_{};
	KamataEngine::Model* model_ = nullptr;
	KamataEngine::Camera* camera_ = nullptr;

};
