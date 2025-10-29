#pragma once
#include <KamataEngine.h>
#include "ModelManager.h"

enum class EnemyPattern {
	Straight,
	SinWave,
};

class Enemy {
public:
	void Init(EnemyPattern pattern, ModelManager * model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position);

	void Update();

	void Draw();

private:
	KamataEngine::WorldTransform worldTransform_{};
	KamataEngine::Model* model_ = nullptr;
	KamataEngine::Camera* camera_ = nullptr;
	float speed = 0.3f;
	float amplitude = 0.5f;
	float theta = 0.0f;

	EnemyPattern pattern_;
};