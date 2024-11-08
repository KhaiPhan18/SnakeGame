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
 void move() {
        Point newHead = snake[0]; // Tao dau moi cho ran
        if (direction == 0) newHead.x++; // Di chuyen phai
        if (direction == 1) newHead.y++; // Di chuyen xuong
        if (direction == 2) newHead.x--; // Di chuyen trai
        if (direction == 3) newHead.y--; // Di chuyen len
        // Kiem tra va cham voi bien
        if (newHead.x < 0 || newHead.x >= 20 || newHead.y < 0 || newHead.y >= 20) {
            gameOver = true; // Ket thuc tro choi
            return;
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
