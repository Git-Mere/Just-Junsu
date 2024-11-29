#pragma once
#include "button.h"

using GameButton::Button;

class Level {
	Button quit{};
	Button toMain{};
public:
	void setup();
	void Draw();
	void Update();
	void IsMouseClicked(doodle::MouseButtons button);
};