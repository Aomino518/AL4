#include "GameScene.h"

using namespace KamataEngine;

// 初期化
void GameScene::Init() { 
	worldTransform_.Initialize();
	camera_.Initialize();

	auto modelMgr = ModelManager::GetInstance();

	modelMgr->GetInstance()->Load("Player", "player");
	modelMgr->GetInstance()->Load("Bullet", "bullet");
	modelMgr->GetInstance()->Load("Enemy", "enemy");

	player_ = std::make_unique<Player>();
	KamataEngine::Vector3 playerPosition = {0.0f, 0.0f, -10.0f};
	player_->Init(modelMgr, &camera_, playerPosition);

	enemy_ = std::make_unique<Enemy>();
	KamataEngine::Vector3 enemyPosition = {10.0f, -10.0f, 100.0f};
	enemy_->Init(EnemyPattern::SinWave, modelMgr, &camera_, enemyPosition);
}

// 更新
void GameScene::Update() {

	player_->Update();
	enemy_->Update();
}

// 描画
void GameScene::Draw() { 
	Model::PreDraw();
	player_->Draw(); 
	enemy_->Draw();
	Model::PostDraw();
}
