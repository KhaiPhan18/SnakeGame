#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include <ctime>

using namespace std;

// Ham di chuyen con tro den vi tri (column, line) tren console
void gotoxy(int column, int line);

// Cau truc diem de luu tru toa do x, y
struct Point {
    int x, y;
};

// Lop tro choi Ran
class SnakeGame {
public:
    vector<Point> snake; // Danh sach cac doan cua ran
    Point food;          // Toa do thuc an
    int direction;       // Huong di chuyen
    bool gameOver;       // Trang thai tro choi
    clock_t lastMoveTime; // Thoi gian di chuyen cuoi cung
};
void changeDirection(char key) {
    if (key == -32) {
        key = _getch();
        if (key == 75 && direction != 0) direction = 2;
        if (key == 72 && direction != 1) direction = 3;
        if (key == 77 && direction != 2) direction = 0;
        if (key == 80 && direction != 3) direction = 1;
    } else {
        if (key == 'a' && direction != 0) direction = 2;
        if (key == 'w' && direction != 1) direction = 3;
        if (key == 'd' && direction != 2) direction = 0;
        if (key == 's' && direction != 3) direction = 1;
    }
}
int main() {
    srand(static_cast<unsigned>(time(0))); // Khoi tao seed cho ham random
    SnakeGame game; // Tao doi tuong tro choi
    return 0;
}

// Ham di chuyen con tro den vi tri (column, line) tren console
void gotoxy(int column, int line) {
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
