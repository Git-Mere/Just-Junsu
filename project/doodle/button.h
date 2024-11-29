#pragma once
#include "vector_point.h"
#include <string>
#include <doodle/doodle.hpp>
#include <iostream>

using doodle::push_settings;
using doodle::pop_settings;

namespace GameButton {
	class Button {
		vector_point position{};
		double width{};
		double height{ 60 };
		double color{ 220 };
		std::string text{};
	private:
		bool is_mouse_on(double mousex, double mousey) {
			if (mousex <= position.x + width && mousex >= position.x && mousey >= position.y && mousey <= position.y + height) {
				return true;
			}
			return false;
		}
		void when_mouse_on() {
			if (is_mouse_on(doodle::get_mouse_x(), doodle::get_mouse_y())) {
				color = 120;
			}
			else {
				color = 220;
			}
		}
	public:
		Button() {}
		Button(vector_point pos, std::string text) : position{ pos }{
			this->text = { text };
			constexpr double proportion{ 45 };
			width = static_cast<double>(this->text.size()) * proportion;
		}
		void draw() {
			push_settings();
			doodle::set_fill_color(color);
			doodle::draw_rectangle(position.x, position.y, width, height);
			doodle::set_font_size(50);
			doodle::set_fill_color(0);
			doodle::set_outline_color(255);
			doodle::draw_text(text, position.x + text.size() * 5, position.y - height / 3);
			pop_settings();
		}
		void update() {
			when_mouse_on();
		}
		bool mouse_clicked(doodle::MouseButtons button) {
			if (button == doodle::MouseButtons::Left && is_mouse_on(doodle::get_mouse_x(), doodle::get_mouse_y())) {
				return true;
			}
			return false;
		}
	};
}