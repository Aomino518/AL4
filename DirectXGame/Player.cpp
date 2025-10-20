#include "Player.h"
#include "MathUtils.h"

using namespace KamataEngine;

void Player::Init(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position) { 
	model_ = model;
	camera_ = camera;
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
}

void Player::Update() { 
	if (Input::GetInstance()->PushKey(DIK_W)) {
		worldTransform_.translation_.y += 1.0f;
	}

	if (Input::GetInstance()->PushKey(DIK_S)) {
		worldTransform_.translation_.y -= 1.0f;
	}

	if (Input::GetInstance()->PushKey(DIK_A)) {
		worldTransform_.translation_.x -= 1.0f;
	}

	if (Input::GetInstance()->PushKey(DIK_D)) {
		worldTransform_.translation_.x += 1.0f;
	}

	WtfUpdate(worldTransform_);
}

void Player::Draw() {
	// モデル描画
	model_->Draw(worldTransform_, *camera_);
}

void Player::ImGui() {

}
