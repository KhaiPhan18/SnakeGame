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
void play() {
        drawBorder(); // Ve duong bien ngay khi bat dau tro choi
        while (!gameOver) {
            if (_kbhit()) {
                char key = _getch(); // Kiem tra phim nhan
                changeDirection(key); // Thay doi huong di chuyen
            }
            // Kiem tra thoi gian de di chuyen
            if (clock() - lastMoveTime > 200) { // 200 ms delay cho di chuyen
                clearSnake(); // Xoa ran cu
                move();       // Di chuyen ran
                draw();       // Ve ran moi
                lastMoveTime = clock(); // Cap nhat thoi gian
            }
        }
        gotoxy(5, 10);
        cout << "Game Over!" << endl; // Thong bao ket thuc tro choi
        gotoxy(5, 11);
        cout << "Final Score: " << score << endl; // Hien thi diem cuoi khi game ket thuc
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
