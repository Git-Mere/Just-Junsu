#pragma once
#include <vector>
#include <string>
#include "PrototypeClass.h"
#include "game.h"
#include "level.h"
#include "ImageSet.h"

using namespace std;

inline bool stop = false;
inline bool overflow = false;
constexpr int windowwidth = 850;
constexpr int windowheight = 600;
inline vector<string> estimate{ "You're Perfect!!", "WOW!","So Good!","lollllllllll","Fooooooooo", "Are you kidding me?" };

inline int currentLevel = 1;
inline int cupheight = 500;
inline int offset = 5;
inline Catch moment;
inline ImageSet images{};
inline Prototype prototype3{};
inline Level level;
namespace enumSceneType {
	enum Scenetype {
		main = 0,
		credit,
		exit,
		logo,
		naming,
		play,
	};
}
