#include <doodle/window.hpp>
#include <exception>
#include <iostream>
#include "game.h"
#include "variable.h"

using namespace doodle;

int main(void)
try
{
    create_window("Just Junsu", windowwidth, windowheight);
    prototype3.input_score();
    prototype3.setup();
    while (!is_window_closed())
    {
        doodle::update_window();
        clear_background(255);
        prototype3.draw();
        prototype3.update();
    }
    prototype3.ouput_score();
    return 0;
}
catch (std::exception& e)
{
    std::cerr << e.what() << "\n";
    return -1;
}

void on_mouse_released(MouseButtons button) {
    prototype3.mouseIsClicked(button);
}

void on_key_pressed(KeyboardButtons button)
{
    if (button == KeyboardButtons::Escape) {
        close_window();
    }
    prototype3.KeyIspressed(button);
}