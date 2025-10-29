#include "Enemy.h"
#include "MathUtils.h"

void Enemy::Init(EnemyPattern pattern, ModelManager * model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position) {
	model_ = model->GetInstance()->Get("Enemy");
	camera_ = camera;
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	pattern_ = pattern;
}

void Enemy::Update() {

	switch (pattern_) { 
	case EnemyPattern::Straight:
		worldTransform_.translation_.z -= speed;

		break;
	case EnemyPattern::SinWave:
		theta += float(M_PI) / 60.0f;
		worldTransform_.translation_.x += sin(theta) * amplitude;
		worldTransform_.translation_.z -= speed;

		break;
	}

	WtfUpdate(worldTransform_);
}

void Enemy::Draw() { 
	model_->Draw(worldTransform_, *camera_); 
}
