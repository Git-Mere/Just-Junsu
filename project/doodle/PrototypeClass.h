#pragma once
#include "SceneManager.h"
#include "Scene.h"
#include "ScoreBoard.h"

class Prototype {
	ScoreBoard score{};
	MainScene main{};
	CreditScene credit{};
	ExitScene exit{};
	digipenLogo logo{};
	InputNameScene namingScene{};
	GameScene play{};
	SceneManager manager{};
	Scene* currentScene() {
		return manager.getCurrent();
	}
	void SceneSetUp() {
		currentScene()->setup();
	}
public:
	void givePlayerName(std::string name) {
		score.give_player_name(name);
	}
	void ChangeScene(int i) {
		manager.changeScene(i);
		SceneSetUp();
	}
	void setup();
	void draw() {
		currentScene()->Draw();
	}
	void update() {
		score.update();
		currentScene()->Update();
	}
	void mouseIsClicked(doodle::MouseButtons button) {
		currentScene()->IsMouseClicked(button);
	}
	void KeyIspressed(doodle::KeyboardButtons button) {
		currentScene()->keyReleased(button);
	}
	void input_score() {
		score.input_score_data();
	}
	void ouput_score() {
		score.output_score();
	}
	void giveScore(int point) {
		this->score.add_score(point);
	}
	void draw_scoreBoard() {
		score.draw_scoreBoard();
	}
	void reset() {
		score.reset();
	}
};