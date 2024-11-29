#pragma once
#include "button.h"
#include <array>
#include <string>
#include "ScoreBoard.h"

using GameButton::Button;

inline constexpr double calc_position(double wid_or_hei, double percent) {
	return wid_or_hei * percent / 100 - wid_or_hei / 2;
}

class Scene {
public:
	virtual void setup() { }
	virtual void Draw() {}
	virtual void Update() {}
	virtual void IsMouseClicked(doodle::MouseButtons /*button*/) {}
	virtual void keyReleased(KeyboardButtons /*button*/) {}
};

class MainScene : public Scene {
	Button mainButtons[3]{};
public:
	virtual void setup();
	virtual void Draw();
	virtual void Update();
	virtual void IsMouseClicked(doodle::MouseButtons button);
};

class CreditScene : public Scene {
	Button back{ };
	std::string junsu{ "Junsu Jang\n" };
	std::string seungheon{ "Seungheon Jeon\n" };
	std::string sangbeom{ "Sangbeom Kim\n" };
	std::string copyright{ " " };
	std::array<std::string, 4> credits{ copyright, junsu, seungheon, sangbeom };
public:
	virtual void setup();
	virtual void Draw();
	virtual void Update();
	virtual void IsMouseClicked(doodle::MouseButtons button);
};

class digipenLogo : public Scene {
	double time{ 0 };
public:
	virtual void Draw();
	virtual void Update();
};

class InputNameScene :public Scene {
	std::string playerName{};
	bool end_input_playerName{false};
private:
	void give_player_name(KeyboardButtons button) {
		constexpr int make_ascii_num{ 54 };
		int inputCharacter{};
		int max_plName{ 10 };
		if (playerName.size() <= max_plName && button <= KeyboardButtons::Z && button >= KeyboardButtons::A) {
			inputCharacter = static_cast<int>(button) + make_ascii_num;
			playerName += static_cast<char>(inputCharacter);
		}
		else if (playerName.size()>0 && button == KeyboardButtons::Backspace) {
			playerName.erase(playerName.size() - 1);
		}
		else if (button == KeyboardButtons::Enter) {
			end_input_playerName = true;
		}
	}
public:
	virtual void Draw() {
		const std::string inputName{ "Name : " };
		doodle::push_settings();
		doodle::set_fill_color(0);
		doodle::set_outline_color(255);
		doodle::set_font_size(30);
		constexpr int nameTextX{-130};
		doodle::draw_text(inputName, nameTextX, 0);
		doodle::draw_text(playerName, 10, 0);
		doodle::pop_settings();
	}
	virtual void Update();
	virtual void keyReleased(KeyboardButtons button) {
		if (end_input_playerName == false) {
			give_player_name(button);
		}
	}
};

class ExitScene :public Scene {
public:
	virtual void setup() {
		doodle::close_window();
	}
};

class GameScene : public Scene {
	virtual void setup();
	virtual void Draw();
	virtual void Update();
	virtual void IsMouseClicked(doodle::MouseButtons button);
	virtual void keyReleased(KeyboardButtons button);
};