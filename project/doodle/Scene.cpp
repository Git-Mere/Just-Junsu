#include "Scene.h"
#include "variable.h"


void MainScene::setup() {
	mainButtons[0] = Button{ {calc_position(windowwidth,17),calc_position(windowheight, 50) },"Start"  };
	mainButtons[1] = Button{ {calc_position(windowwidth,17),calc_position(windowheight, 20) },"Exit"  };
	mainButtons[2] = Button{ {calc_position(windowwidth,17),calc_position(windowheight, 35)},"Credits" };
}

void MainScene::Draw() {
	for (auto& butn : mainButtons) {
		butn.draw();
	}
	push_settings();
	set_fill_color(0);
	set_outline_color(255);
	set_font_size(60);
	draw_text("Catch Moment", -270, 130);
	set_font_size(15);
	draw_text("All content 2020 DigiPen(USA) Corporation, all rights reserved.", -400, -280);
	pop_settings();
}

void MainScene::Update() {
	for (auto& butn : mainButtons) {
		butn.update();
	}
}

void MainScene::IsMouseClicked(doodle::MouseButtons button) {
	if (mainButtons[0].mouse_clicked(button)) {
		prototype3.ChangeScene(enumSceneType::play);
	}
	if (mainButtons[1].mouse_clicked(button)) {
		prototype3.ChangeScene(enumSceneType::exit);
	}
	if (mainButtons[2].mouse_clicked(button)) {
		prototype3.ChangeScene(enumSceneType::credit);
	}
}

void CreditScene::setup() {
	back = Button{ { calc_position(windowwidth, 70), calc_position(windowheight, 10) }, "Back" };
}

void CreditScene::Draw() {
	push_settings();
	doodle::set_fill_color(0);
	doodle::set_outline_color(255);
	doodle::set_font_size(30);
	constexpr int creditStartY{ 10 };
	constexpr int creditInterval{ 20 };
	for (int i = 0;i < credits.size();i++) {
		doodle::draw_text(credits[i], calc_position(windowwidth, 10), calc_position(windowheight, creditStartY + creditInterval * i));
	}
	set_font_size(15);
	draw_text("All content 2020 DigiPen(USA) Corporation, all rights reserved.", -400, -280);
	pop_settings();
	back.draw();
}

void CreditScene::Update() {
	back.update();
}

void CreditScene::IsMouseClicked(doodle::MouseButtons button) {
	if (back.mouse_clicked(button)) {
		prototype3.ChangeScene(enumSceneType::main);
	}
}

void digipenLogo::Draw() {
	push_settings();
	doodle::set_image_mode(doodle::RectMode::Center);
	doodle::draw_image(images.logo(), 0, 20, windowwidth/2 , windowheight/5.3 );
	pop_settings();
}

void digipenLogo::Update() {
	if (time > 2) {
		prototype3.ChangeScene(enumSceneType::naming);
	}
	time += doodle::DeltaTime;
}

void InputNameScene::Update() {
	if (end_input_playerName == true) {
		prototype3.givePlayerName(playerName);
		prototype3.ChangeScene(enumSceneType::main);
	}
}

void GameScene::setup() { 
	level.setup();
}
void GameScene::Draw() {
	moment.draw();
}
void GameScene::Update() {
	if (stop == false) {
		moment.update();
	}
}
void GameScene::IsMouseClicked(doodle::MouseButtons button) {
	if (moment.pass()) {
		level.IsMouseClicked(button);
	}
	level.IsMouseClicked(button);
}
void GameScene::keyReleased(KeyboardButtons button) {
	if (button == KeyboardButtons::Space) {
		if (stop == false) {
			stop = true;
			moment.space();
		}
		else {
			if (moment.pass()) {
				stop = false;
				moment.reset();
			}
		}
	}
	if (button == KeyboardButtons::R) {
		moment.reset();
	}
}