#include <iostream>
#include <windows.h>
#include <thread>

int main() {
    RECT rect;
    const HWND hDesktop = GetDesktopWindow();
    GetWindowRect(hDesktop, &rect);

    POINT position{rect.right / 2, rect.bottom / 2};
    int radius = 400;
    int speed = 10;
    double angle = 0;
    bool toggled = false;

    while (true) {
        while (toggled) {
            if (GetAsyncKeyState(VK_LBUTTON)) {
                //calculate the next point in the circle
                float x = position.x + radius * cos(angle);
                float y = position.y + radius * sin(angle);
                SetCursorPos(x, y);
                angle += 0.05;
                std::this_thread::sleep_for(std::chrono::milliseconds(speed));
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
