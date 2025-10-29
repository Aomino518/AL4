#include "Bullet.h"
#include "Player.h"

using namespace KamataEngine;

void Bullet::Init(Model* model, Camera* camera, const Vector3& position) { 
	model_ = model;
	camera_ = camera;
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
}

void Bullet::Update() {
	if (isShot_) {
		worldTransform_.translation_.z += 1.0f;

		if (worldTransform_.translation_.z >= 200.0f) {
			isShot_ = false;
		}
	}

	WtfUpdate(worldTransform_);
}

void Bullet::Draw() {
	if (isShot_) {
		model_->Draw(worldTransform_, *camera_);
	}
}

void Bullet::SetPos(Vector3& pos) { 
	worldTransform_.translation_.x = pos.x;
	worldTransform_.translation_.y = pos.y;
	worldTransform_.translation_.z = pos.z;
}

void Bullet::SetIsShot(bool isShot) { isShot_ = isShot; }
