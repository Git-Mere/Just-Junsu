#pragma once
#pragma once
#include "Scene.h"

class SceneManager {
	std::vector<Scene*> proto_scenes{ };
	Scene* currentScene{};
public:
	void setup() {}
	void pushScene(Scene & scene) {
		proto_scenes.push_back(&scene);
	}
	void changeScene(int scene_name) {
		currentScene = proto_scenes[scene_name];
	}
	Scene* getCurrent() {
		return currentScene;
	}
};