#include "GameScene.h"

using namespace KamataEngine;

// 初期化
void GameScene::Init() { 
	worldTransform_.Initialize();
	camera_.Initialize();


	modelPlayer_ = Model::CreateFromOBJ("player");

	player_ = std::make_unique<Player>();
	KamataEngine::Vector3 playerPosition = {0, 0, 0};
	player_->Init(modelPlayer_, &camera_, playerPosition);
}

// 更新
void GameScene::Update() {

	player_->Update();
}

// 描画
void GameScene::Draw() { 
	Model::PreDraw();
	player_->Draw(); 
	Model::PostDraw();
}
