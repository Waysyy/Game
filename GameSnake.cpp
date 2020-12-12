// GameSnake
 
//РАЗОБРАТЬСЯ В ПРОКРУТКОЙ КАРТЫ

#include <iostream>
#include <Windows.h> //для замедления
#include <conio.h> //библиотека позволяющая вводить/выводить

using namespace std;

bool GameOver; // изначально false

const int shirina = 50;
const int visota = 50;

int score, x, y, fruitX, fruitY; //x и y - координаты

//движения

enum dvij { stop = 0, UP, DOWN, RIGHT, LEFT}; //пришлось написать капсом, т.к. в "using namespace std" уже есть right и left 
dvij dv; //управление движениями

// Изначальные установки

void Setup() {

    GameOver = false; // пока игрок не проиграл

      dv = stop; //изначально стоит на месте

          x = shirina / 2 - 1;    // изначальные координаты
          y = visota / 2 - 1;

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

            if (i == y && j == x) // координаты для змейки (проверка координат)
                cout << "@";

            else if (i == fruitY && j == fruitX)
                cout << "$";

            else
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

    if (_kbhit ()) { //отследить движения пользователя
        switch (_getch ()) //позволяет отслеживать нажатия
        {
        case 'w':
            dv = UP;

            break;
        case 's':
            dv = DOWN;

            break;

        case 'd':
            dv = RIGHT;

            break;

        case 'a':
            dv = LEFT;

            break;

        case 'x':
            GameOver = true;

            break;
        }


    }

}

// проверка направления движения змейки

void logic() {

    switch (dv)
    {
    case LEFT:
        --x; //за счет уменьшения значения координаты происходит движение
        break;
    case RIGHT:
        ++x;
        break;
    case UP:
        --y;
        break;
    case DOWN:
        ++y;
        break;
    
    }

    if (x > shirina || x < 0 || y > visota || y < 0) //если змея выйдет за пределы карты - игра окончена
        GameOver = true;
}

int main()
{

    Setup(); // вызов для настройки игры при включении

    while (!GameOver) { // пока игра не завершена
    
        Draw();
        vvod();
        logic();
        Sleep(1000); //замедляет
    }
    return 0;
}

