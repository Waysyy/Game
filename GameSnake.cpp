// GameSnake

#include <iostream>

using namespace std;

bool GameOver; // изначально false

const int shirina = 50;
const int visota = 50;

int score, x, y, fruitX, fruitY;

//движения

enum dvij { stop = 0, left, right, up, down};

// Настройка параметров после запуска игры

void Setup() {

    GameOver = false; // пока игрок не проиграл

}

// Прорисовка карты

void Draw() {

}

// Действия пользователя

void vvod() {

}

// Логика игры

void logic() {

}

int main()
{

    Setup(); // вызов для настройки игры при включении

    while (!GameOver = false) { // пока игра не завершена
    
        Draw();
        vvod();
        logic();

    }
    return 0;
}

