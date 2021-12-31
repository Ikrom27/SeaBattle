#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>


// Перевод букв в цифры
int convert(char a) {
    return int(a - 65);
}


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
        }
    }
    return check;
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


int main() {

    setlocale(LC_ALL, "");


    // Создаем пустое поле битвы
    std::string field[13][12] = {
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
    /*int input_story[4][2]{
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
    }; */


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
    int x_story[20] = { 10 };
    int y_story[20] = { 10 };


    //Разрешаюищие переменные
    //bool invalidInput = 0;
    bool ignore_results = 0;
    bool check_coordinate = 0;
    bool set_check = 0;


    //объявление строк
    std::string playerInput;
    std::string block = "";
    std::string display = "-----------";


    for (int i = 0; i <= 19; i++) {
        y_story[i] += 0;
    }
    for (int i = 0; i <= 19; i++) {
        x_story[i] += 0;
    }


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
        std::cin >> playerInput;
        std::transform(playerInput.begin(), playerInput.end(), playerInput.begin(), ::toupper);

        /*if (playerInput == "DEL") {
            int y_del = input_story[decksNum-1][0];
            int x_del = input_story[decksNum-1][1];
            field[y_del][x_del] = " |";
            shipsNum++;
            y_story[20 - shipsNum] = 0;
            x_story[20 - shipsNum] = 0;
            decksNum--;
            input_story[decksNum][0] = 0;
            input_story[decksNum][1] = 0;
            playerInput = " ";
        } **/


        if (playerInput == "START") {
            break;
        }

        // Обозначает завершение построек палуб корабля
        else if (playerInput == "SET") {

       
            if (decksNum == 4 and x4_ship > 0) { set_check = 1; }
            if (decksNum == 3 and x3_ship > 0) { set_check = 1; }
            if (decksNum == 2 and x2_ship > 0) { set_check = 1; }
            if (decksNum == 1 and x1_ship > 0) { set_check = 1; }


            if (set_check) {
                //Обозначаем границы корабля
                for (int i = 0; i <= 12; i++) {
                    for (int j = 0; j <= 11; j++) {
                        if (field[i][j] == "O|") {
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
                x_story[19] = { 0 };
                y_story[19] = { 0 };
            }
            else {
                display = "Адмирал, таких кораблей больше нет!";
            }
        }


        //Если ввод правильный, начинаем расстановку корабля
        else if (inputCheck(playerInput) and decksNum < decksMax and shipsNum >0) {


            //Обрабатываем координаты
            for (int i = 0; i <= 1; i++) {

                char letter = playerInput[i];

                if (letter >= '0' and letter <= '9') {
                    y_coordinate = int(letter - '0');
                }
                else if (letter >= 'A' and letter <= 'J') {
                    x_coordinate = int(letter - 'A');
                }
                else {
                    //invalidInput = 1;
                    ignore_results = 1;
                    break;
                }
            }

            //Проверяем координаты
            if (check_coordinate) {
                ignore_results = 1;
                if (y_coordinate == y_story[20 - shipsNum] and block != "Y" and field[y_coordinate + 2][x_coordinate + 2] == " |") {

                    //Проверяем, есть ли у заданного координата сосед "O|", так же блокирует другую ось, чтобы корабли имели форму 4-х угольника
                    if (field[y_coordinate + 2][x_coordinate + 3] == "O|" or field[y_coordinate + 2][x_coordinate + 1] == "O|") {
                        block = "X";
                        ignore_results = 0;
                    }

                }
                else if ((x_coordinate == x_story[20 - shipsNum] and block != "X") and field[y_coordinate + 2][x_coordinate + 2] == " |") {

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
                y_story[20 - shipsNum] += y_coordinate;
                x_story[20 - shipsNum] += x_coordinate;
                check_coordinate = true;
                decksNum++;
            }
        }

    }
    std::cout << feildPaint(field) << "\n\n";
}