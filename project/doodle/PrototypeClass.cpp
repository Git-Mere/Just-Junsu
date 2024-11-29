#include "PrototypeClass.h"
#include "variable.h"

void Prototype::setup() {
	manager.pushScene(main);
	manager.pushScene(credit);
	manager.pushScene(exit);
	manager.pushScene(logo);
	manager.pushScene(namingScene);
	manager.pushScene(play);
	ChangeScene(enumSceneType::logo);
}