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
    int score; // Bien luu diem so

    // Ham khoi tao
    SnakeGame() {
        gameOver = false;
        direction = 0; // Huong di chuyen ban dau (Phai)
        snake.push_back({ 10, 10 });
        snake.push_back({ 9, 10 });
        snake.push_back({ 8, 10 });
        placeFood(); // Dat thuc an
        lastMoveTime = clock();
    }

    // Ham dat thuc an o vi tri ngau nhien
    void placeFood() {
        food.x = rand() % 20;
        food.y = rand() % 20;
    }

    // Ham ve ran va thuc an len console
    void draw() {
        for (auto& segment : snake) {
            gotoxy(segment.x + 1, segment.y + 1);
            cout << "O"; // Ve doan ran
        }
        gotoxy(food.x + 1, food.y + 1);
        cout << "*"; // Ve thuc an
    }

    // Ham xoa ran khoi man hinh
    void clearSnake() {
        for (auto& segment : snake) {
            gotoxy(segment.x + 1, segment.y + 1);
            cout << " "; // Xoa doan ran
        }
    }

    // Ham ve duong bien
    void drawBorder() {
        for (int i = 0; i < 22; i++) {
            gotoxy(i + 1, 0);    // Ve bien tren
            cout << "#";
            gotoxy(i + 1, 21);   // Ve bien duoi
            cout << "#";
        }
        for (int i = 0; i < 22; i++) {
            gotoxy(0, i);        // Ve bien trai
            cout << "#";
            gotoxy(21, i);       // Ve bien phai
            cout << "#";
        }
    }

    // Ham di chuyen ran
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

        // Kiem tra va cham voi chinh ran
        for (size_t i = 0; i < snake.size(); i++) {
            if (newHead.x == snake[i].x && newHead.y == snake[i].y) {
                gameOver = true; // Ket thuc tro choi
                return;
            }
        }

        // Kiem tra an thuc an
        if (newHead.x == food.x && newHead.y == food.y) {
            snake.insert(snake.begin(), newHead); // Them dau moi
            placeFood(); // Dat thuc an moi
        }
        else {
            snake.insert(snake.begin(), newHead); // Them dau moi
            snake.pop_back(); // Xoa duoi
        }
    }

    // Ham thay doi huong di chuyen
    void changeDirection(char key) {
        if (key == 'a' && direction != 0) direction = 2; // Trai
        if (key == 'w' && direction != 1) direction = 3; // Len
        if (key == 'd' && direction != 2) direction = 0; // Phai
        if (key == 's' && direction != 3) direction = 1; // Xuong
    }

    // Ham choi tro choi
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
    }
};

int main() {
    srand(static_cast<unsigned>(time(0))); // Khoi tao seed cho ham random
    SnakeGame game; // Tao doi tuong tro choi
    game.play(); // Bat dau tro choi
    return 0;
}

// Ham di chuyen con tro den vi tri (column, line) tren console
void gotoxy(int column, int line) {
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
