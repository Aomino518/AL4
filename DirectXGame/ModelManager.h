#pragma once
#include <KamataEngine.h>
#include <unordered_map>
#include <memory>
#include <string>

class ModelManager {
public:
	static ModelManager* GetInstance();

	/// <summary>
	/// モデルのロード関数
	/// </summary>
	/// <param name="name">モデル名</param>
	/// <param name="path">ファイルパス</param>
	void Load(const std::string& name, const std::string& path);

	/// <summary>
	/// モデルのゲッター関数
	/// </summary>
	/// <param name="name">ファイルパス</param>
	/// <returns>モデル</returns>
	KamataEngine::Model* Get(const std::string& name);

	void Clear();

private:
	std::unordered_map<std::string, std::unique_ptr<KamataEngine::Model>> models_;
};
