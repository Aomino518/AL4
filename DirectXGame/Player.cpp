#include "Player.h"
#include "MathUtils.h"

using namespace KamataEngine;

void Player::Init(Model* model, Camera* camera, const Vector3& position) { 
	model_ = model;
	camera_ = camera;
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	bullet_->Init(model, camera, position);
}

void Player::Update() { 

	if (worldTransform_.translation_.y <= 720.0f || worldTransform_.translation_.y > 0.0f) {
		if (Input::GetInstance()->PushKey(DIK_W)) {
			worldTransform_.translation_.y += velocity;
		}

		if (Input::GetInstance()->PushKey(DIK_S)) {
			worldTransform_.translation_.y -= velocity;
		}
	} else {
		velocity = 0.0f;
	}

	if (worldTransform_.translation_.x <= 1280.0f || worldTransform_.translation_.x > 0.0f) {
		if (Input::GetInstance()->PushKey(DIK_A)) {
			worldTransform_.translation_.x -= velocity;
		}

		if (Input::GetInstance()->PushKey(DIK_D)) {
			worldTransform_.translation_.x += velocity;
		}
	} else {
		velocity = 0.0f;
	}

	if (!bullet_->GetIsShot()) {
		if (Input::GetInstance()->PushKey(DIK_SPACE)) {
			bullet_->SetPos(worldTransform_.translation_);
			bullet_->SetIsShot(true);
		}
	}

	bullet_->Update();

	WtfUpdate(worldTransform_);
}

void Player::Draw() {
	// モデル描画
	bullet_->Draw();
	model_->Draw(worldTransform_, *camera_);
}

void Player::ImGui() {

}
