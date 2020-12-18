// GameSnake
 
//РАЗОБРАТЬСЯ В ПРОКРУТКОЙ КАРТЫ

#include <iostream>
#include <Windows.h> //для замедления
#include <conio.h> //библиотека позволяющая вводить/выводить

using namespace std;

bool GameOver; // изначально false

const int shirina = 100;
const int visota = 20;

int score, x, y, fruitX, fruitY; //x и y - координаты

int tailX[100], tailY[100]; //перемещение хвоста
int ntail; // количесвто элементов в хвосте

//движения

enum dvij { stop = 0, UP, DOWN, RIGHT, LEFT}; //пришлось написать капсом, т.к. в "using namespace std" уже есть right и left 
dvij dv; //управление движениями

// Изначальные установки

void Setup() {

    GameOver = false; // пока игрок не проиграл

      dv = stop; //изначально стоит на месте

          x = shirina / 2 - 1;    // изначальные координаты
          y = visota / 2 - 1; // добавила -1, т.к. змея сдвинулась с начальной точки после изменения границ карты

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

            else {

                bool vivod = false; // чтобы не ставил пробелы

                for (int k = 0; k < ntail; ++k) { //отрисовка хвоста
                
                    if (tailX[k] == j && tailY[k] == i) {
                    
                        vivod = true;
                        cout << "o";
                    }

                    

                }

                if (!vivod)
                cout << " ";
             }
        }

        cout << endl;
        
    } 

    for (int i = 0; i < shirina + 1; ++i)

        cout << "*";

        cout << endl;

        cout << "~~~ score:  " << score << "  ~~~" << endl;



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

    int predX = tailX[0]; //во время игры значение будет меняться (предыдущее позиция по Х)(первый элемент хвоста)
    int predY = tailY[0];
    int pred2X, pred2Y; // переменные в котороые мы помещаем следующие элементы хвоста

    tailX[0] = x; // первый элемент в хвосте = координате х
    tailY[0] = y;

    for (int i = 1; i < ntail; ++i) { // i идет до кол-ва элементов в хвосте
    
        pred2X = tailX[i]; 
        pred2Y = tailY[i];

        tailX[i] = predX; // помещаем первую координату
        tailY[i] = predY;

        predX = pred2X;
        predY = pred2Y;

    }

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

    for (int i = 0; i < ntail; ++i) { //проверяем не съела ли змея хвост, делаем это в цикле, потому что элементов много
    
        if (tailX[i] == x && tailY[i] == y)

            GameOver = true;

    }

    if (x == fruitX && y == fruitY) {
        score = score + 10;
        fruitX = rand() % shirina; // меняем положение фрукта, после съедения  
        fruitY = rand() % visota;
        ++ntail; //хвост растет с поеданием фрукта
    }
}

int main()
{
    system("color 02");

    cout << "  #####   #      #    ##    #      #  #######\n";
    cout << " #     #  # #    #  #    #  #    #    #\n";
    cout << "  # #     #   #  #  # ## #  # # #     #######\n";
    cout << "#     #   #    # #  #    #  #    #    #\n";
    cout << " #####    #      #  #    #  #     #   #######\n";

    system("pause");

    Setup(); // вызов для настройки игры при включении

    while (!GameOver) { // пока игра не завершена
    
        Draw();
        vvod();
        logic();
        Sleep(100); //замедляет
    }
    system("cls");
    cout << " #####      ##       ##   ##   #######\n";
    cout << "#         #    #   #   # #  #  #\n";
    cout << "#  ##     # ## #   #    #   #  #######\n";
    cout << "#    #    #    #   #        #  #\n";
    cout << "#####     #    #   #        #  #######\n";
    cout << "\n";

    cout << "  #####   #        #    #######   ####\n";
    cout << " #     #   #      #     #         #    #\n";
    cout << " #     #    #    #      #######   ####\n";
    cout << " #     #     #  #       #         ###\n";
    cout << "  #####       ##        #######   #   #\n";
    system("pause");
    return 0;
}

