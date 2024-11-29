#pragma once
#include "vector_point.h"
#include "level.h"
#include <doodle/doodle.hpp>
#include <string>
#include <vector>
#include <cmath>

using namespace doodle;
using namespace std;

class Catch {
	vector_point rect{ 0.0, -250.0 };
	double width{ 250.0 };
	double height{ 0.0 };
	double stopline{ 100.0 };
	double speed {2.125};
	double result{0};
	string eval{};

public:
	Catch() {};
	Catch(double line) {
		stopline = line;
	};
	void draw();
	void update();
	void space();
	void reset();
	double roundNum(double var);
	bool pass();
	double speed_deter();
	void all_reset();

};