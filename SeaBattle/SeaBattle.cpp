#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <ctime>

std::string userField[13][12] = {
            {"  ", " ", "A ", "B ","C ","D ","E ","F ","G ","H ","I ", "J "},
            {"  ", "#", "--", "--","--","--","--","--","--","--","--", "-#"},
            {" 0", "|", " |", " |"," |"," |"," |"," |"," |"," |"," |", " |"},
            {" 1", "|", " |", " |"," |"," |"," |"," |"," |"," |"," |", " |"},
            {" 2", "|", " |", " |"," |"," |"," |"," |"," |"," |"," |", " |"},
            {" 3", "|", " |", " |"," |"," |"," |"," |"," |"," |"," |", " |"},
            {" 4", "|", " |", " |"," |"," |"," |"," |"," |"," |"," |", " |"},
            {" 5", "|", " |", " |"," |"," |"," |"," |"," |"," |"," |", " |"},
            {" 6", "|", " |", " |"," |"," |"," |"," |"," |"," |"," |", " |"},
            {" 7", "|", " |", " |"," |"," |"," |"," |"," |"," |"," |", " |"},
            {" 8", "|", " |", " |"," |"," |"," |"," |"," |"," |"," |", " |"},
            {" 9", "|", " |", " |"," |"," |"," |"," |"," |"," |"," |", " |"},
            {"  ", "#", "--", "--","--","--","--","--","--","--","--", "-#"},
};
std::string botfield[13][12] = {
            {"  ", " ", "A ", "B ","C ","D ","E ","F ","G ","H ","I ", "J "},
            {"  ", "#", "--", "--","--","--","--","--","--","--","--", "-#"},
            {" 0", "|", " |", " |"," |"," |"," |"," |"," |"," |"," |", " |"},
            {" 1", "|", " |", " |"," |"," |"," |"," |"," |"," |"," |", " |"},
            {" 2", "|", " |", " |"," |"," |"," |"," |"," |"," |"," |", " |"},
            {" 3", "|", " |", " |"," |"," |"," |"," |"," |"," |"," |", " |"},
            {" 4", "|", " |", " |"," |"," |"," |"," |"," |"," |"," |", " |"},
            {" 5", "|", " |", " |"," |"," |"," |"," |"," |"," |"," |", " |"},
            {" 6", "|", " |", " |"," |"," |"," |"," |"," |"," |"," |", " |"},
            {" 7", "|", " |", " |"," |"," |"," |"," |"," |"," |"," |", " |"},
            {" 8", "|", " |", " |"," |"," |"," |"," |"," |"," |"," |", " |"},
            {" 9", "|", " |", " |"," |"," |"," |"," |"," |"," |"," |", " |"},
            {"  ", "#", "--", "--","--","--","--","--","--","--","--", "-#"},
};


//Проверка введеных данных
bool inputCheck(std::string Input) {
    bool check = 0;
    for (int LetterNum = 0; LetterNum <= 1; LetterNum++) {
        char letter = Input[LetterNum];
        if (letter >= '0' and letter <= '9') {
            check = 1;
        }
        else if (letter >= 'A' and letter <= 'J') {
            check = 1;
        }
        else {
            check = 0;
            break;
        }
    }
    return check;
}


//Получение координат
int get_y(std::string playerInput) {
    int y_coordinate = 0;
    for (int i = 0; i <= 1; i++) {
        char letter = playerInput[i];
        if (letter >= '0' and letter <= '9') {
            y_coordinate = int(letter - '0');
        }
    }
    return y_coordinate;
}
int get_x(std::string playerInput) {
    int x_coordinate = 0;
    for (int i = 0; i <= 1; i++) {
        char letter = playerInput[i];
        if (letter >= 'A' and letter <= 'J') {
            x_coordinate = int(letter - 'A');
        }
    }
    return x_coordinate;
}


//Обозначение границ корабля
std::string shipsBorder(std::string field[13][12], std::string trigger) {
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 12; j++) {
            if (field[i][j] == trigger) {
                if (field[i + 1][j] == " |") { field[i + 1][j] = "*|"; }
                if (field[i][j + 1] == " |") { field[i][j + 1] = "*|"; }
                if (field[i - 1][j] == " |") { field[i - 1][j] = "*|"; }
                if (field[i][j - 1] == " |") { field[i][j - 1] = "*|"; }
                if (field[i + 1][j + 1] == " |") { field[i + 1][j + 1] = "*|"; }
                if (field[i - 1][j - 1] == " |") { field[i - 1][j - 1] = "*|"; }
                if (field[i + 1][j - 1] == " |") { field[i + 1][j - 1] = "*|"; }
                if (field[i - 1][j + 1] == " |") { field[i - 1][j + 1] = "*|"; }
            }
        }
    }
    return  field[13][12];
}


//Рисуем Поле
std::string feildPaint(std::string field[13][12]) {
    std::string finalSTR = "";

    for (int i = 0; i <= 12; i++) {
        finalSTR += "\n                                     ";
        for (int j = 0; j <= 11; j++) {
            finalSTR += field[i][j];
        }
    }
    return finalSTR;
}






std::string userFieldBuilt(std::string field[13][12]) {

    //Корабли
    int shipsNum = 20;
    int x1_ship = 4;
    int x2_ship = 3;
    int x3_ship = 2;
    int x4_ship = 1;
    int decksNum = 0;
    int decksMax = 4;


    //Координаты
    int x_coordinate = 0;
    int y_coordinate = 0;
    int x_story = 0;
    int y_story = 0;


    //Разрешаюищие переменные
    bool ignore_results = 0;
    bool check_coordinate = 0;
    bool set_check = 0;
    bool botActive = 0;


    //объявление строк
    std::string userInput;
    std::string block = "";
    std::string display = "-----------";


    while (shipsNum > -1) {

        system("cls");  //чистка консоли
        ignore_results = 0;


        //Интерфейс
        std::cout << "#---------------------#" << "\n";
        std::cout << "| У вас осталось:     |" << "\n";
        std::cout << "|   4-х палубных: " << x4_ship << "   |" << "\n";
        std::cout << "|   3-х палубных: " << x3_ship << "   |" << "\n";
        std::cout << "|   2-х палубных: " << x2_ship << "   |" << "\n";
        std::cout << "|   1-х палубных: " << x1_ship << "   |" << "\n";
        std::cout << "#---------------------#" << "\n";
        std::cout << "| Макс длинна: " << decksMax << "      |" << "\n";
        std::cout << "| Текущий палубных: " << decksNum << " |" << "\n";
        std::cout << "#---------------------#" << "\n";
        std::cout << "| Сообщение: " << display << "\n";
        display = "-----------";

        std::cout << feildPaint(field) << "\n\n";


        // Получение хода игрока и трансформация букв в заглавные.
        std::cin >> userInput;
        std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);


        //Начинать бой
        if (userInput == "START") {
            break;
        }

        // Обозначает завершение построек палуб корабля
        else if (userInput == "SET") {


            if (decksNum == 4 and x4_ship > 0) { set_check = 1; }
            if (decksNum == 3 and x3_ship > 0) { set_check = 1; }
            if (decksNum == 2 and x2_ship > 0) { set_check = 1; }
            if (decksNum == 1 and x1_ship > 0) { set_check = 1; }


            if (set_check) {
                //Обозначаем границы корабля
                shipsBorder(field, "O|");


                //Корректируем колличество оставшихся кораблей
                switch (decksNum)
                {
                case 4:
                    x4_ship--;
                    break;
                case 3:
                    x3_ship--;
                    break;
                case 2:
                    x2_ship--;
                    break;
                case 1:
                    x1_ship--;
                    break;
                }

                if (x4_ship <= 0 and x3_ship > 0) { decksMax = 3; }
                else if (x4_ship <= 0 and x3_ship <= 0 and x2_ship > 0) { decksMax = 2; }
                else if (x4_ship <= 0 and x3_ship <= 0 and x2_ship <= 0 and x1_ship > 0) { decksMax = 1; }


                //Обнуление
                set_check = 0;
                decksNum = 0;
                check_coordinate = 0;
                block = "";
                x_story = 0;
                y_story = 0;
            }
            else {
                display = "Адмирал, таких кораблей больше нет!";
            }
        }


        //Если ввод правильный, начинаем расстановку корабля
        else if (inputCheck(userInput) and decksNum < decksMax and shipsNum >0) {


            //Обрабатываем координаты
            y_coordinate = get_y(userInput);
            x_coordinate = get_x(userInput);

            //Проверяем координаты
            if (check_coordinate) {
                ignore_results = 1;
                if (y_coordinate == y_story and block != "Y" and field[y_coordinate + 2][x_coordinate + 2] == " |") {

                    //Проверяем, есть ли у заданного координата сосед "O|", так же блокирует другую ось, чтобы корабли имели форму 4-х угольника
                    if (field[y_coordinate + 2][x_coordinate + 3] == "O|" or field[y_coordinate + 2][x_coordinate + 1] == "O|") {
                        block = "X";
                        ignore_results = 0;
                    }

                }
                else if ((x_coordinate == x_story and block != "X") and field[y_coordinate + 2][x_coordinate + 2] == " |") {

                    //Проверяем, есть ли у заданного координата сосед "O|", так же блокирует другую ось, чтобы корабли имели форму 4-х угольника
                    if (field[y_coordinate + 3][x_coordinate + 2] == "O|" or field[y_coordinate + 1][x_coordinate + 2] == "O|") {
                        block = "Y";
                        ignore_results = 0;
                    }
                }
                else {
                    ignore_results = 1;
                    display = "Адмирал, мы не можем разместить его здесь!";
                }
            }
            //Проверяем, свободно ли место
            if (field[y_coordinate + 2][x_coordinate + 2] != " |") {
                ignore_results = 1;
                if (field[y_coordinate + 2][x_coordinate + 2] != "*|") {
                    display = "Адмирал, это слишком опастно!";
                }
            }


            // размещаем корабль
            if (ignore_results == 0) {
                field[y_coordinate + 2][x_coordinate + 2] = "O|";
                shipsNum--;
                y_story = y_coordinate;
                x_story = x_coordinate;
                check_coordinate = true;
                decksNum++;
            }
        }

    }
    return field[12][11];
}


//Поле для Бота
std::string botFieldBuilt(std::string field[13][12]) {

    //Корабли
    int shipsNum = 10;
    int decksNum = 0;
    int decksMax = 4;


    //Координаты
    int x_coordinate = 0;
    int y_coordinate = 0;


    //Разрешаюищие переменные
    bool set = 0;

    while (shipsNum > 0) {

        time_t seconds = time(NULL) % 10;   //для рандомного результата


        //задаем рандомные координаты
        x_coordinate = abs(1 + (rand() + seconds) % 10) + 2;
        y_coordinate = abs(1 + (rand() + seconds) % 10) + 2;


        //Расставляем корабли правильных размеров и формы
        int n = 0;
        if (field[y_coordinate][x_coordinate] == " |") {

            for (int i = 0; i < decksMax; i++) {
                if (field[y_coordinate + i][x_coordinate] == " |") {
                    n++;
                    if (n == decksMax) {
                        for (int i = 0; i < decksMax; i++) {
                            field[y_coordinate + i][x_coordinate] = "O|";
                            set = 1;
                        }
                    }
                }
                else
                {
                    n = 0;
                    for (int i = 0; i < decksMax; i++) {
                        if (field[y_coordinate][x_coordinate + i] == " |") {
                            n++;
                            if (n == decksMax) {
                                for (int i = 0; i < decksMax; i++) {
                                    field[y_coordinate][x_coordinate + i] = "O|";
                                    set = 1;
                                }
                            }
                        }
                        else
                        {
                            n = 0;
                            break;
                        }
                    }
                }
            }

            if (set) {
                shipsNum--;
                switch (shipsNum)
                {
                case 9:
                    decksMax = 3;
                    break;
                case 7:
                    decksMax = 2;
                    break;
                case 4:
                    decksMax = 1;
                    break;
                }
                set = 0;
            }

            shipsBorder(botfield, "O|");
        }
    }
    return field[12][11];
}


int main() {

    setlocale(LC_ALL, "");


    botFieldBuilt(botfield);
    userFieldBuilt(userField);

    std::cout << feildPaint(userField) << "\n\n";
    std::cout << feildPaint(botfield) << "\n\n";
}