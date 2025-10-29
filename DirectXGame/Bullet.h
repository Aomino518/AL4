#pragma once
#include <KamataEngine.h>

class Player;

class Bullet {
public:
	void Init(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position);

	void Update();

	void Draw();

	bool GetIsShot() const { return isShot_; }

	void SetPos(KamataEngine::Vector3& pos);

	void SetIsShot(bool isShot);

private:
	KamataEngine::Model* model_ = nullptr;
	KamataEngine::Camera* camera_ = nullptr;
	KamataEngine::WorldTransform worldTransform_{};
	bool isShot_ = false;
};