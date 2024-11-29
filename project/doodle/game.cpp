#include "game.h"
#include "variable.h"

void Catch::draw() {
	push_settings();
	set_fill_color(0, 0, 255);
	draw_rectangle(rect.x, rect.y, width, height);
	pop_settings();
	push_settings();
	set_outline_width(2);
	draw_line(rect.x, stopline, rect.x+width, stopline);
	pop_settings();
	push_settings();
	set_font_size(15);
	set_outline_color(0);
	draw_text("Stop line", rect.x + offset + offset, stopline);
	set_font_size(40);
	set_fill_color(0); 
	set_outline_color(255);
	draw_text("Level", -370, windowheight / 3);
	draw_text(to_string(currentLevel), -220, windowheight / 3);
	prototype3.draw_scoreBoard();
	set_outline_color(0);
	set_outline_width(10);
	draw_line(rect.x, rect.y - offset, rect.x, rect.y + cupheight);
	draw_line(rect.x, rect.y, rect.x + width, rect.y);
	draw_line(rect.x + width, rect.y - offset, rect.x + width, rect.y + cupheight);
	pop_settings();
	if (stop == true) {
		if (overflow == false) {
			string res = to_string(result);
			res.erase(res.find_last_not_of('0') + 1, std::string::npos);
			res.erase(res.find_last_not_of('.') + 1, std::string::npos);
			push_settings();
			set_fill_color(220, 120);
			set_font_size(25);
			draw_rectangle(-windowwidth / 2, -windowheight / 2, windowwidth, windowwidth);
			set_outline_color(255);
			set_fill_color(0);
			draw_text(eval, -370, 0);
			draw_text("distance :", -370, -50);
			draw_text(res, -200, -50);
			pop_settings();
			level.Draw();
			level.Update();
		}
		else {
			push_settings();
			set_fill_color(220, 120);
			draw_rectangle(-windowwidth / 2, -windowheight / 2, windowwidth, windowwidth);
			set_font_size(25);
			set_outline_color(255);
			set_fill_color(0);
			draw_text(estimate[5], -370, 0);
			draw_text("Water Overflow", -370, -50);
			pop_settings();
			level.Draw();
			level.Update();
		}
	}
}

void Catch::update() {
	speed_deter();
	height += speed;
	if (height >= cupheight) {
		stop = true;
		overflow = true;
	}
}

void Catch::space() {
	result = roundNum(height + rect.y - stopline);

	if (result <= 1 && result >= -1) {
		eval = estimate[0];
		prototype3.giveScore(500);
	}else if (result <= 10 && result >= -10) {
		eval = estimate[1];
		prototype3.giveScore(100);
	}
	else if (result <= 20 && result >= -20) {
		eval = estimate[2];
		prototype3.giveScore(50);
	}
	else if (result <= 50 && result >= -50) {
		eval = estimate[3];
	}
	else if (result <= 100 && result >= -100) {
		eval = estimate[4];
	}
	else{
		eval = estimate[5];
	}
}

void Catch::reset() {
	stop = false;
	overflow = false;
	height= 0.0;
	stopline= floor(random(0.0, 150.0));
	result= 0;
	eval = {};
	currentLevel += 1;
}

void Catch::all_reset() {
	stop = false;
	overflow = false;
	height = 0.0;
	stopline = 100;
	result = 0;
	eval = {};
	speed= 1.125;
	currentLevel = 1;
	prototype3.reset();
}

double Catch::roundNum(double var) {
	double value = std::floor(var * 1000 + 0.5) / 1000;
	return value;
}

bool Catch::pass() {
	if (eval == estimate[0] || eval == estimate[1] || eval == estimate[2]) {
		return true;
	}
	else {
		return false;
	}
}

double Catch::speed_deter() {
	if ((currentLevel - 1) % 5 == 0) {
		double speedvar = static_cast<double>(currentLevel) / 10;
		speed = 2.125 + speedvar;
	}
	return speed;
}