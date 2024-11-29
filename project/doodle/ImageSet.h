#pragma once
#include"doodle/doodle.hpp"
#include "doodle/image.hpp"

struct ImageSet {
private:
	std::string logoPath{ "assets/image/DigiPen.PNG" };
public:
	doodle::Image logo() {
		doodle::Image logo{ logoPath };
		return logo;
	}
};