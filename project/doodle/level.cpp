#include "variable.h"
#include "level.h"

void Level::setup() {
		toMain = Button{ {-370, -150}, "Main" };
		quit = Button{ {-370, -250},"Quit" };
}
void Level::Draw() {
	if (stop == true && !moment.pass()) {
		toMain.draw();
		quit.draw();
	}
}
void Level::Update() {
	toMain.update();
	quit.update();
}
void Level::IsMouseClicked(doodle::MouseButtons button) {
	if (stop == true && !moment.pass()) {
		if (toMain.mouse_clicked(button)) {
			prototype3.ChangeScene(enumSceneType::main);
			moment.all_reset();
		}
		if (quit.mouse_clicked(button)) {
			close_window();
		}
	}
}