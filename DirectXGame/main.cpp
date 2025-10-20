#include <Windows.h>
#include <KamataEngine.h>
#include "GameScene.h"
#include <imgui.h>

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// エンジンの初期化
	KamataEngine::Initialize(L"LE2B_27_モリ_アオト");
	// DirectXCommonインスタンスの取得
	KamataEngine::DirectXCommon* dxCommon = KamataEngine::DirectXCommon::GetInstance();
	// ゲームシーンのインスタンス生成
	GameScene* gameScene = new GameScene();
	// ゲームシーンの初期化
	gameScene->Init();
	// ImGuiManagerインスタンスの取得
	KamataEngine::ImGuiManager* imguiManager = KamataEngine::ImGuiManager::GetInstance();

	// メインループ
	while (true) {
		// エンジンの更新
		if (KamataEngine::Update()) {
			break;
		}

		// ゲームシーンの更新
		gameScene->Update();

		// 描画開始
		dxCommon->PreDraw();
		imguiManager->Begin();
		ImGui::Begin("GameScene");

		// ゲームシーンの描画
		gameScene->Draw();

		ImGui::End();
		imguiManager->End();
		// 描画終了
		dxCommon->PostDraw();
	}

	// ゲームシーンの解放
	delete gameScene;
	// nullptrの代入
	gameScene = nullptr;
	// エンジンの終了処理
	KamataEngine::Finalize();

	return 0;
}
