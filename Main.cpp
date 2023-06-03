#include <iostream>
#include <windows.h>
#include <thread>

int main() {
    POINT position{1920 / 2, 1080 / 2};
    int radius = 400;
    double speed = 1, angle = 0;
    bool toggled = false;

    while (true) {
        while (toggled) {
            if (GetAsyncKeyState(VK_LBUTTON)) {
                //calculate the next point in the circle
                float x = position.x + radius * cos(angle);
                float y = position.y + radius * sin(angle);
                SetCursorPos(x, y);
                angle += 0.05;
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }

            if (GetAsyncKeyState(VK_F1)) {
                toggled = false;
                std::cout << "toggled off!\n";
            }
        }

        if (GetAsyncKeyState(VK_F2)) {
            toggled = true;
            std::cout << "toggled on!\n";
        }
    }

    return 0;
}