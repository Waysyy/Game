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

    system("cls");

    // рисует границы

    for (int i = 0; i < shirina + 1; ++i) //верхние и нижние границы

        cout << "*"; 
    cout << endl;

    for (int i = 0; i < visota; ++i) { //боковые границы

        for (int j = 0; j < shirina; ++j) {

            if (j == 0 || j == shirina - 1) //-1 потому что один шаг уже пройден, а старт должен быть с нуля

                cout << "*";
            cout << " "; 
        }

        cout << endl;
        
    } 

    for (int i = 0; i < shirina + 1; ++i)

        cout << "*";
        cout << endl;



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

    while (!GameOver) { // пока игра не завершена
    
        Draw();
        vvod();
        logic();

    }
    return 0;
}

