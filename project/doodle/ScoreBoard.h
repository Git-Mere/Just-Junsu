#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "doodle/doodle.hpp"

inline void error(const std::string& s) { throw std::runtime_error(s); }
using doodle::KeyboardButtons;

class ScoreBoard {
	std::string playerName{};
	int currentScore{};
	std::map<std::string, int> scoreData{};
private:
	void update_highScore() {
		if (scoreData[playerName] < currentScore) {
			scoreData[playerName] = currentScore;
		}
	}
	void check_score() {
		if (currentScore < 0) {
			currentScore = 0;
		}
	}
public:
	void add_score(int point) {
		currentScore += point;
	}
	void give_player_name(std::string PN) {
		playerName = {PN};
	}
	void output_score() {
		std::ofstream Oscore{ "scoreData.txt" };
		for (auto itr = scoreData.begin(); itr != scoreData.end();itr++) {
			if (itr->first !="") {
				Oscore << itr->first << " " << itr->second << std::endl;
			}
		}
		Oscore.close();
	}
	void input_score_data() {
		std::string plName{};
		int score{};
		std::ifstream Iscore{ "scoreData.txt" };
		while (Iscore >> plName, Iscore >> score) {
			scoreData[plName] = score;
		}
		Iscore.close();
	}
	void draw_scoreBoard() {
		constexpr int x = -370;
		constexpr int y = 105;
		constexpr int scoreInterval{180};
		constexpr int score_to_high_interval{50};
		constexpr int highScore_interval{ 200 };
		push_settings();
		doodle::draw_text("score :", x, y);
		doodle::draw_text(std::to_string(currentScore), x + scoreInterval, y);
		doodle::set_font_size(21);
		doodle::draw_text("High score :", x, y- score_to_high_interval);
		doodle::draw_text(std::to_string(scoreData[playerName]), x + highScore_interval, y- score_to_high_interval);
		pop_settings();
	}
	void update() {
		update_highScore();
		check_score();
	}
	void reset() {
		currentScore = 0;
	}
};