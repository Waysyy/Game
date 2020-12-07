// GameSnake

#include <iostream>

using namespace std;

bool GameOver; // изначально false

const int shirina = 50;
const int visota = 50;

int score, x, y, fruitX, fruitY; //x и y - координаты

//движения

enum dvij { stop = 0, left, right, up, down};
dvij dv; //управление движениями

// Изначальные установки

void Setup() {

    GameOver = false; // пока игрок не проиграл

      dv = stop; //изначально стоит на месте

          x = shirina / 2;    // изначальные координаты
          y = visota / 2;

             fruitX = rand() % shirina; // рандомное положение фрукта  
             fruitY = rand() % visota;

             score = 0;

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

