#include "ModelManager.h"

using namespace KamataEngine;

ModelManager* ModelManager::GetInstance() { 
	static ModelManager instance;
	return &instance;
}

void ModelManager::Load(const std::string& name, const std::string& path) { 
	// 二重ロード防止
	if (models_.count(name)) {
		return;
	} 

	models_[name] = std::unique_ptr<Model>(Model::CreateFromOBJ(path));

}

KamataEngine::Model* ModelManager::Get(const std::string& name) { 
	auto it = models_.find(name);

	if (it != models_.end()) {
		return it->second.get();
	}

	return nullptr; 
}

void ModelManager::Clear() { 
	models_.clear(); 
}
