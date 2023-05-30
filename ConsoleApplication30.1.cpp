// ConsoleApplication30.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include <iostream>
#include <ctime>
#include <vector>
using namespace std;
// Размеры поля
const int SIZE = 7;
// Структура клетки поля
struct cell
{
    int row;
    int col;
};
// Функция для вывода поля на экран.
void print_field(char field[SIZE][SIZE])
{
    cout << "   A B C D E F G\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << (i + 1) << "  ";
        for (int j = 0; j < SIZE; j++)
        {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}
// Функция для проверки корректности ввода координат. 
bool is_valid_input(char* input, int row, int col)
{
    return (strlen(input) == 2 && row >= 0 && row < SIZE&& col >= 0 && col < SIZE);
}
// Функция расстановки трехпалубного корабля игрока, возвращает указатель на массив, содержащий клетки, занятые трехпалубным кораблем игрока.
cell* three_deck_player_ship(int row, int col, cell* three_deck)
{
    while (true)
    {
        cout << "Выберите координату точки, где разместить нос 3-х палубного корабля (например, B2)" << endl;
        string input;
        cin >> input;
        row = input[1] - '1';
        col = input[0] - 'A';
        if (!is_valid_input(&input[0], row, col))
        {
            cout << "Некорректные координаты. Попробуйте еще раз." << endl << endl;
        }
        else
        {
            three_deck[0].row = row;
            three_deck[0].col = col;
            break;
        }
    }
    while (true)
    {
        cout << "Выберите направление, в котором разместить корму (up, down, left, right)" << endl;
        string input;
        cin >> input;
        if (input == "up" && row - 2 < 0)
        {
            cout << "Направление 'up' не доступно, нет места на поле. Попробуйте другое." << endl << endl;
        }
        else if (input == "down" && row + 2 >= SIZE)
        {
            cout << "Направление 'down' не доступно, нет места на поле. Попробуйте другое." << endl << endl;
        }
        else if (input == "left" && col - 2 < 0)
        {
            cout << "Направление 'left' не доступно, нет места на поле. Попробуйте другое." << endl << endl;
        }
        else if (input == "right" && col + 2 >= SIZE)
        {
            cout << "Направление 'right' не доступно, нет места на поле. Попробуйте другое." << endl << endl;
        }
        else if (input == "up")
        {
            three_deck[1].row = row - 1;
            three_deck[1].col = col;
            three_deck[2].row = row - 2;
            three_deck[2].col = col;
            break;
        }
        else if (input == "down")
        {
            three_deck[1].row = row + 1;
            three_deck[1].col = col;
            three_deck[2].row = row + 2;
            three_deck[2].col = col;
            break;
        }
        else if (input == "left")
        {
            three_deck[1].row = row;
            three_deck[1].col = col - 1;
            three_deck[2].row = row;
            three_deck[2].col = col - 2;
            break;
        }
        else if (input == "right")
        {
            three_deck[1].row = row;
            three_deck[1].col = col + 1;
            three_deck[2].row = row;
            three_deck[2].col = col + 2;
            break;
        }
        else
        {
            cout << "Некорректное направление. Попробуйте еще раз." << endl << endl;
        }
    }
    return three_deck;
}
// Функция расстановки двухпалубного корабля игрока, возвращает указатель на массив, содержащий клетки, занятые двухпалубным кораблем игрока.
cell* two_deck_player_ship(int row, int col, cell* two_deck, char player_field[SIZE][SIZE])
{
    while (true)
    {
        cout << "Выберите координату точки, где разместить нос 2-х палубного корабля (например, B5)" << endl;
        string input;
        cin >> input;
        row = input[1] - '1';
        col = input[0] - 'A';
        if (!is_valid_input(&input[0], row, col))
        {
            cout << "Некорректные координаты. Попробуйте еще раз." << endl << endl;
        }
        else if (player_field[row][col] == 'A')
        {
            cout << "На этом месте стоит другой корабль. Попробуйте еще раз." << endl << endl;
        }
        else if ((player_field[row + 1][col] == 'A' && row + 1 < SIZE) || (player_field[row - 1][col] == 'A' && row - 1 >= 0) || (player_field[row][col + 1] == 'A' && col + 1 < SIZE) || (player_field[row][col - 1] == 'A' && col - 1 >= 0))
        {
            cout << "Другой корабль слишком близко. Попробуйте еще раз." << endl << endl;
        }
        else
        {
            two_deck[0].row = row;
            two_deck[0].col = col;
            break;
        }
    }
    while (true)
    {
        cout << "Выберите направление, в котором разместить корму (up, down, left, right)" << endl;
        string input;
        cin >> input;
        if (input == "up" && row - 1 < 0)
        {
            cout << "Направление 'up' не доступно, нет места на поле. Попробуйте другое." << endl << endl;
        }
        else if (input == "down" && row + 1 >= SIZE)
        {
            cout << "Направление 'down' не доступно, нет места на поле. Попробуйте другое." << endl << endl;
        }
        else if (input == "left" && col - 1 < 0)
        {
            cout << "Направление 'left' не доступно, нет места на поле. Попробуйте другое." << endl << endl;
        }
        else if (input == "right" && col + 1 >= SIZE)
        {
            cout << "Направление 'right' не доступно, нет места на поле. Попробуйте другое." << endl << endl;
        }
        else if (input == "up" && ((player_field[row - 2][col] == 'A' && row - 2 >= 0) || (player_field[row - 1][col + 1] == 'A' && col + 1 < SIZE && row - 1 >= 0) || (player_field[row - 1][col - 1] == 'A' && col - 1 >= 0 && row - 1 >= 0)))
        {
            cout << "Направление 'up' не доступно, Другой корабль слишком близко. Попробуйте другое." << endl << endl;
        }
        else if (input == "down" && ((player_field[row + 2][col] == 'A' && row + 2 < SIZE) || (player_field[row + 1][col + 1] == 'A' && row + 1 < SIZE && col + 1 < SIZE) || (player_field[row + 1][col - 1] == 'A' && row + 1 < SIZE && col - 1 >= 0)))
        {
            cout << "Направление 'down' не доступно, Другой корабль слишком близко. Попробуйте другое." << endl << endl;
        }
        else if (input == "left" && ((player_field[row][col - 2] == 'A' && col - 2 >= 0) || (player_field[row + 1][col - 1] == 'A' && col - 1 >= 0 && row + 1 < SIZE) || (player_field[row - 1][col - 1] == 'A' && row - 1 >= 0)))
        {
            cout << "Направление 'left' не доступно, Другой корабль слишком близко. Попробуйте другое." << endl << endl;
        }
        else if (input == "right" && ((player_field[row][col + 2] == 'A' && col + 2 < SIZE) || (player_field[row + 1][col + 1] == 'A' && row + 1 < SIZE && col + 1 < SIZE) || (player_field[row - 1][col + 1] == 'A' && row - 1 >= 0 && col + 1 < SIZE)))
        {
            cout << "Направление 'right' не доступно, Другой корабль слишком близко. Попробуйте другое." << endl << endl;
        }
        else if (input == "up")
        {
            two_deck[1].row = row - 1;
            two_deck[1].col = col;
            break;
        }
        else if (input == "down")
        {
            two_deck[1].row = row + 1;
            two_deck[1].col = col;
            break;
        }
        else if (input == "left")
        {
            two_deck[1].row = row;
            two_deck[1].col = col - 1;
            break;
        }
        else if (input == "right")
        {
            two_deck[1].row = row;
            two_deck[1].col = col + 1;
            break;
        }
        else
        {
            cout << "Некорректное направление. Попробуйте еще раз." << endl << endl;
        }
    }
    return two_deck;
}
// Функция расстановки однопалубного корабля игрока, возвращает указатель на клетку, занятую однопалубным кораблем игрока.
cell* one_deck_player_ship(int row, int col, cell* one_deck, char player_field[SIZE][SIZE])
{
    while (true)
    {
        cout << "Выберите координату точки, где разместить третий однопалубный корабль (например, С2)" << endl;
        string input;
        cin >> input;
        row = input[1] - '1';
        col = input[0] - 'A';
        if (!is_valid_input(&input[0], row, col))
        {
            cout << "Некорректные координаты. Попробуйте еще раз." << endl << endl;
        }
        else if (player_field[row][col] == 'A')
        {
            cout << "На этом месте стоит другой корабль. Попробуйте еще раз." << endl << endl;
        }
        else if ((player_field[row + 1][col] == 'A' && row + 1 < SIZE) || (player_field[row - 1][col] == 'A' && row - 1 >= 0) || (player_field[row][col + 1] == 'A' && col + 1 < SIZE) || (player_field[row][col - 1] == 'A' && col - 1 >= 0))
        {
            cout << "Другой корабль слишком близко. Попробуйте еще раз." << endl << endl;
        }
        else
        {
            one_deck[0].row = row;
            one_deck[0].col = col;
            break;
        }
    }
    return one_deck;
}
// Функция расстановки трехпалубного компьютера, возвращает указатель на массив, содержащий клетки, занятые трехпалубным кораблем компьютера.
cell* three_deck_computer_ship(int row, int col, cell* three_deck, int random_direction)
{
    three_deck[0].row = row;
    three_deck[0].col = col;
    while (true)
    {
        random_direction = rand() % 4 + 1; //выбор случайного направления 1-вверх/2-вниз/3-влево/4-вправо
        if (random_direction == 1 && row - 2 >= 0)
        {
            three_deck[1].row = row - 1;
            three_deck[1].col = col;
            three_deck[2].row = row - 2;
            three_deck[2].col = col;
            break;
        }
        else if (random_direction == 2 && row + 2 <= SIZE)
        {
            three_deck[1].row = row + 1;
            three_deck[1].col = col;
            three_deck[2].row = row + 2;
            three_deck[2].col = col;
            break;
        }
        else if (random_direction == 3 && col - 2 >= 0)
        {
            three_deck[1].row = row;
            three_deck[1].col = col - 1;
            three_deck[2].row = row;
            three_deck[2].col = col - 2;
            break;
        }
        else if (random_direction == 4 && col + 2 <= SIZE)
        {
            three_deck[1].row = row;
            three_deck[1].col = col + 1;
            three_deck[2].row = row;
            three_deck[2].col = col + 2;
            break;
        }
    }
    return three_deck;
}
// Функция расстановки двухпалубного корабля компьютера, возвращает указатель на массив, содержащий клетки, занятые двухпалубным кораблем компьютера.
cell* two_deck_computer_ship(int row, int col, cell* two_deck, int random_direction, char computer_field_hidden[SIZE][SIZE])
{
    while (true)
    {
        row = rand() % SIZE;
        col = rand() % SIZE;
        if (computer_field_hidden[row][col] != 'A' && (computer_field_hidden[row + 1][col] != 'A' || row + 1 >= SIZE) && (computer_field_hidden[row - 1][col] != 'A' || row - 1 < 0) && (computer_field_hidden[row][col + 1] != 'A' || col + 1 >= SIZE) && (computer_field_hidden[row][col - 1] != 'A' || col - 1 < 0))
        {
            two_deck[0].row = row;
            two_deck[0].col = col;
            break;
        }
    }
    while (true)
    {
        random_direction = rand() % 4 + 1;
        if (random_direction == 1 && row - 1 >= 0 && (computer_field_hidden[row - 2][col] != 'A' || row - 2 < 0) && (computer_field_hidden[row - 1][col + 1] != 'A' || (row - 1 < 0 && col + 1 >= SIZE)) && (computer_field_hidden[row - 1][col - 1] != 'A' || (row - 1 < 0 && col - 1 < 0))) //up
        {
            two_deck[1].row = row - 1;
            two_deck[1].col = col;
            break;
        }
        else if (random_direction == 2 && row + 1 < SIZE && (computer_field_hidden[row + 2][col] != 'A' || row + 2 >= SIZE) && (computer_field_hidden[row + 1][col + 1] != 'A' || (row + 1 >= SIZE && col + 1 >= SIZE)) && (computer_field_hidden[row + 1][col - 1] != 'A' || (row + 1 >= SIZE && col - 1 < 0))) //down
        {
            two_deck[1].row = row + 1;
            two_deck[1].col = col;
            break;
        }
        else if (random_direction == 3 && col - 1 >= 0 && (computer_field_hidden[row][col - 2] != 'A' || col - 2 < 0) && (computer_field_hidden[row + 1][col - 1] != 'A' || (col - 1 < 0 && row + 1 >= SIZE)) && (computer_field_hidden[row - 1][col - 1] != 'A' || (row - 1 < 0 && col - 1 < 0))) //left
        {
            two_deck[1].row = row;
            two_deck[1].col = col - 1;
            break;
        }
        else if (random_direction == 4 && col + 1 < SIZE && (computer_field_hidden[row][col + 2] != 'A' || col + 2 >= SIZE) && (computer_field_hidden[row + 1][col + 1] != 'A' || (row + 1 >= SIZE && col + 1 >= SIZE)) && (computer_field_hidden[row - 1][col + 1] != 'A' || (col + 1 >= SIZE && row - 1 < 0))) //right
        {
            two_deck[1].row = row;
            two_deck[1].col = col + 1;
            break;
        }
    }
    return two_deck;
}
// Функция расстановки однопалубного корабля компьютера, возвращает указатель на клетку, занятую однопалубным кораблем компьютера.
cell* one_deck_computer_ship(int row, int col, cell* one_deck, char computer_field_hidden[SIZE][SIZE])
{
    while (true)
    {
        row = rand() % SIZE;
        col = rand() % SIZE;
        if (computer_field_hidden[row][col] != 'A' && (computer_field_hidden[row + 1][col] != 'A' || row + 1 >= SIZE) && (computer_field_hidden[row - 1][col] != 'A' || row - 1 < 0) && (computer_field_hidden[row][col + 1] != 'A' || col + 1 >= SIZE) && (computer_field_hidden[row][col - 1] != 'A' || col - 1 < 0))
        {
            one_deck[0].row = row;
            one_deck[0].col = col;
            break;
        }
    }
    return one_deck;
}
// Функция выбора режима
string game_mode()
{
    while (true)
    {
        cout << "Выберите количество игроков (1, 2)" << endl;        
        string input;
        cin >> input;
        if (input == "1" || input == "2")
        {
            return input;
            break;
        }
        else
        {
            cout << "Некорректное количество игроков. Попробуйте еще раз" << endl;
        }
    }
}
// Основная функция
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Добро пожаловать в “Консольный морской бой на C++”!" << endl;
    string gamemode = game_mode();
    if (gamemode == "1")
    {
        char player_field[SIZE][SIZE];  // Игровое поле игрока
        char computer_field_hidden[SIZE][SIZE];  // Игровое поле компьютера с кораблями, которое не видно игроку 
        char computer_field[SIZE][SIZE]; // Игровое поле компьютера с местами попаданий и промахов игрока
        char field_of_computer_shots[SIZE][SIZE]; // Игровое поле компьютера с выстрелами
        // Инициализируем поля пустыми клетками
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                player_field[i][j] = '-';
                computer_field_hidden[i][j] = '-';
                computer_field[i][j] = '-';
                field_of_computer_shots[i][j] = '-';
            }
        }
        // Размещение трехпалубного корабля игрока
        cout << "Ваше поле:" << endl;
        print_field(player_field);
        int row = 0;
        int col = 0;
        cell* three_deck = new cell[3];
        cell* player_three_deck = three_deck_player_ship(row, col, three_deck);
        player_field[player_three_deck[0].row][player_three_deck[0].col] = 'A';
        player_field[player_three_deck[1].row][player_three_deck[1].col] = 'A';
        player_field[player_three_deck[2].row][player_three_deck[2].col] = 'A';
        // Размещение двухпалубных кораблей игрока
        cout << "Ваше поле:" << endl;
        print_field(player_field);
        cell* two_deck = new cell[2];
        cell* player_two_deck = two_deck_player_ship(row, col, two_deck, player_field);
        player_field[player_two_deck[0].row][player_two_deck[0].col] = 'A';
        player_field[player_two_deck[1].row][player_two_deck[1].col] = 'A';
        cout << "Ваше поле:" << endl;
        print_field(player_field);
        cell* second_player_two_deck = two_deck_player_ship(row, col, two_deck, player_field);
        player_field[second_player_two_deck[0].row][second_player_two_deck[0].col] = 'A';
        player_field[second_player_two_deck[1].row][second_player_two_deck[1].col] = 'A';
        // Размещение однопалубных кораблей игрока
        cout << "Ваше поле:" << endl;
        print_field(player_field);
        cell* one_deck = new cell[1];
        cell* player_one_deck = one_deck_player_ship(row, col, one_deck, player_field);
        player_field[player_one_deck[0].row][player_one_deck[0].col] = 'A';
        cout << "Ваше поле:" << endl;
        print_field(player_field);
        cell* second_player_one_deck = one_deck_player_ship(row, col, one_deck, player_field);
        player_field[second_player_one_deck[0].row][second_player_one_deck[0].col] = 'A';
        cout << "Ваше поле:" << endl;
        print_field(player_field);
        cell* third_player_one_deck = one_deck_player_ship(row, col, one_deck, player_field);
        player_field[third_player_one_deck[0].row][third_player_one_deck[0].col] = 'A';
        // Размещение кораблей компьютера случайным образом
        srand(time(NULL)); // Изменение точки отсчета для функции rand(), для функции time необходима библиотека <ctime>
        // Размещение трехпалубного корабля компьютера
        row = rand() % (SIZE - 1);
        col = rand() % (SIZE - 1);
        int random_direction = 1;
        cell* computer_three_deck = three_deck_computer_ship(row, col, three_deck, random_direction);
        computer_field_hidden[computer_three_deck[0].row][computer_three_deck[0].col] = 'A';
        computer_field_hidden[computer_three_deck[1].row][computer_three_deck[1].col] = 'A';
        computer_field_hidden[computer_three_deck[2].row][computer_three_deck[2].col] = 'A';
        // Размещение двухпалубных кораблей компьютера
        cell* computer_two_deck = two_deck_computer_ship(row, col, two_deck, random_direction, computer_field_hidden);
        computer_field_hidden[computer_two_deck[0].row][computer_two_deck[0].col] = 'A';
        computer_field_hidden[computer_two_deck[1].row][computer_two_deck[1].col] = 'A';
        cell* second_computer_two_deck = two_deck_computer_ship(row, col, two_deck, random_direction, computer_field_hidden);
        computer_field_hidden[second_computer_two_deck[0].row][second_computer_two_deck[0].col] = 'A';
        computer_field_hidden[second_computer_two_deck[1].row][second_computer_two_deck[1].col] = 'A';
        // Размещение однопалубных кораблей компьютера
        cell* computer_one_deck = one_deck_computer_ship(row, col, one_deck, computer_field_hidden);
        computer_field_hidden[computer_one_deck[0].row][computer_one_deck[0].col] = 'A';
        cell* second_computer_one_deck = one_deck_computer_ship(row, col, one_deck, computer_field_hidden);
        computer_field_hidden[second_computer_one_deck[0].row][second_computer_one_deck[0].col] = 'A';
        cell* third_computer_one_deck = one_deck_computer_ship(row, col, one_deck, computer_field_hidden);
        computer_field_hidden[third_computer_one_deck[0].row][third_computer_one_deck[0].col] = 'A';
        bool game_over = false;
        bool player_turn = true;
        bool computer_turn = true;
        int player_score = 0;
        int computer_score = 0;
        vector<cell> successful_computer_shots;
        system("cls");
        while (!game_over)
        {
            // Выводим поля на экран
            cout << "Ваше поле:" << endl;
            print_field(player_field);
            cout << "Поле компьютера:" << endl;
            print_field(computer_field);
            if (player_turn)
            {
                // Ход игрока
                cout << "Ваш ход. Введите координаты выстрела (например, B3): ";
                string input;
                cin >> input;
                row = input[1] - '1';
                col = input[0] - 'A';
                if (!is_valid_input(&input[0], row, col))
                {
                    cout << "Некорректные координаты. Попробуйте еще раз." << endl;
                }
                else if (computer_field[row][col] == 'X' || computer_field[row][col] == 'O')
                {
                    cout << "Вы уже стреляли в эту клетку. Попробуйте еще раз." << endl;
                }
                else if (computer_field_hidden[row][col] == '-')
                {
                    cout << "Промах!" << endl;
                    computer_field[row][col] = 'O';
                    player_turn = false;
                }
                else if (computer_field_hidden[row][col] == 'A')
                {
                    cout << "Попадание!" << endl;
                    computer_field[row][col] = 'X';
                    player_score++;
                    //проверка на уничтожение кораблей
                    if (computer_field_hidden[row - 1][col] != 'A' && computer_field_hidden[row + 1][col] != 'A' && computer_field_hidden[row][col - 1] != 'A' && computer_field_hidden[row][col + 1] != 'A' && computer_field[row - 1][col] != 'X' && computer_field[row + 1][col] != 'X' && computer_field[row][col - 1] != 'X' && computer_field[row][col + 1] != 'X')
                    {
                        cout << "Вы потопили вражеский однопалубный корабль!" << endl;
                    }
                    else if ((computer_field[row][col] == 'X' && computer_field[row - 1][col] == 'X' && computer_field_hidden[row - 2][col] != 'A' && computer_field_hidden[row + 1][col] != 'A') || (computer_field[row][col] == 'X' && computer_field[row + 1][col] == 'X' && computer_field_hidden[row + 2][col] != 'A' && computer_field_hidden[row - 1][col] != 'A') ||
                        (computer_field[row][col] == 'X' && computer_field[row][col - 1] == 'X' && computer_field_hidden[row][col - 2] != 'A' && computer_field_hidden[row][col + 1] != 'A') || (computer_field[row][col] == 'X' && computer_field[row][col + 1] == 'X' && computer_field_hidden[row][col+2] != 'A' && computer_field_hidden[row][col-1] != 'A'))
                    {
                        cout << "Вы потопили вражеский двухпалубный корабль!" << endl;
                    }
                    else if ((computer_field[row][col] == 'X' && computer_field[row - 1][col] == 'X' && computer_field[row - 2][col] == 'X' && computer_field_hidden[row - 3][col] != 'A' && computer_field_hidden[row + 1][col] != 'A') || (computer_field[row][col] == 'X' && computer_field[row + 1][col] == 'X' && computer_field[row + 2][col] == 'X' && computer_field_hidden[row + 3][col] != 'A' && computer_field_hidden[row - 1][col] != 'A') ||
                        (computer_field[row][col] == 'X' && computer_field[row][col - 1] == 'X' && computer_field[row][col - 2] == 'X' && computer_field_hidden[row][col - 3] != 'A' && computer_field_hidden[row][col + 1] != 'A') || (computer_field[row][col] == 'X' && computer_field[row][col + 1] == 'X' && computer_field[row][col + 2] == 'X' && computer_field_hidden[row][col+3] != 'A' && computer_field_hidden[row][col-1] != 'A') ||
                        (computer_field[row][col] == 'X' && computer_field[row][col - 1] == 'X' && computer_field[row][col + 1] == 'X' && computer_field_hidden[row][col - 2] != 'A' && computer_field_hidden[row][col + 2] != 'A') || (computer_field[row][col] == 'X' && computer_field[row + 1][col] == 'X' && computer_field[row - 1][col] == 'X' && computer_field_hidden[row + 2][col] != 'A' && computer_field_hidden[row - 2][col] != 'A'))
                    {
                        cout << "Вы потопили вражеский трехпалубный корабль!" << endl;
                    }
                    if (player_score == 10)
                    {
                        cout << "Вы выиграли!" << endl;
                        game_over = true;
                    }
                }
            }
            else
            {
                while (computer_turn) //ход компьютера
                {
                    if (successful_computer_shots.size() == 1)
                    {
                        if (field_of_computer_shots[successful_computer_shots[0].row + 1][successful_computer_shots[0].col] != 'O' && field_of_computer_shots[successful_computer_shots[0].row + 1][successful_computer_shots[0].col] != 'X' && successful_computer_shots[0].row + 1 < SIZE)
                        {
                            row = successful_computer_shots[0].row + 1;
                            col = successful_computer_shots[0].col;
                        }
                        else if (field_of_computer_shots[successful_computer_shots[0].row - 1][successful_computer_shots[0].col] != 'O' && field_of_computer_shots[successful_computer_shots[0].row - 1][successful_computer_shots[0].col] != 'X' && successful_computer_shots[0].row - 1 >= 0)
                        {
                            row = successful_computer_shots[0].row - 1;
                            col = successful_computer_shots[0].col;
                        }
                        else if (field_of_computer_shots[successful_computer_shots[0].row][successful_computer_shots[0].col + 1] != 'O' && field_of_computer_shots[successful_computer_shots[0].row][successful_computer_shots[0].col + 1] != 'X' && successful_computer_shots[0].col + 1 < SIZE)
                        {
                            row = successful_computer_shots[0].row;
                            col = successful_computer_shots[0].col + 1;
                        }
                        else if (field_of_computer_shots[successful_computer_shots[0].row][successful_computer_shots[0].col - 1] != 'O' && field_of_computer_shots[successful_computer_shots[0].row][successful_computer_shots[0].col - 1] != 'X' && successful_computer_shots[0].col - 1 >= 0)
                        {
                            row = successful_computer_shots[0].row;
                            col = successful_computer_shots[0].col - 1;
                        }
                        else
                        {
                            row = rand() % SIZE;
                            col = rand() % SIZE;
                            successful_computer_shots.clear();
                        }
                    }
                    else if (successful_computer_shots.size() > 1)
                    {
                        cell first = successful_computer_shots[0];
                        cell last = successful_computer_shots[successful_computer_shots.size() - 1];
                        if (first.row == last.row)
                        {
                            if (first.col < last.col)
                            {
                                if (field_of_computer_shots[first.row][last.col + 1] != 'O' && field_of_computer_shots[first.row][last.col + 1] != 'X' && last.col + 1 < SIZE)
                                {
                                    row = last.row;
                                    col = last.col + 1;
                                }
                                else if (field_of_computer_shots[last.row][first.col - 1] != 'O' && field_of_computer_shots[last.row][first.col - 1] != 'X' && first.col - 1 >= 0)
                                {
                                    row = first.row;
                                    col = first.col - 1;
                                }
                                else
                                {
                                    row = rand() % SIZE;
                                    col = rand() % SIZE;
                                    successful_computer_shots.clear();
                                }
                            }
                            else if (first.col > last.col)
                            {
                                if (field_of_computer_shots[last.row][first.col + 1] != 'O' && field_of_computer_shots[last.row][first.col + 1] != 'X' && first.col + 1 < SIZE)
                                {
                                    row = first.row;
                                    col = first.col + 1;
                                }
                                else if (field_of_computer_shots[first.row][last.col - 1] != 'O' && field_of_computer_shots[first.row][last.col - 1] != 'X' && last.col - 1 >= 0)
                                {
                                    row = last.row;
                                    col = last.col - 1;
                                }
                                else
                                {
                                    row = rand() % SIZE;
                                    col = rand() % SIZE;
                                    successful_computer_shots.clear();
                                }
                            }
                        }
                        if (first.col == last.col)
                        {
                            if (first.row < last.row)
                            {
                                if (field_of_computer_shots[first.row - 1][last.col] != 'O' && field_of_computer_shots[first.row - 1][last.col] != 'X' && first.row - 1 >= 0)
                                {
                                    row = first.row - 1;
                                    col = first.col;
                                }
                                else if (field_of_computer_shots[last.row + 1][first.col] != 'O' && field_of_computer_shots[last.row + 1][first.col] != 'X' && last.row + 1 < SIZE)
                                {
                                    row = last.row + 1;
                                    col = last.col;
                                }
                                else
                                {
                                    row = rand() % SIZE;
                                    col = rand() % SIZE;
                                    successful_computer_shots.clear();
                                }
                            }
                            else if (first.row > last.row)
                            {
                                if (field_of_computer_shots[last.row - 1][first.col] != 'O' && field_of_computer_shots[last.row - 1][first.col] != 'X' && last.row - 1 >= 0)
                                {
                                    row = last.row - 1;
                                    col = last.col;
                                }
                                else if (field_of_computer_shots[first.row + 1][last.col] != 'O' && field_of_computer_shots[first.row + 1][last.col] != 'X' && first.row + 1 < SIZE)
                                {
                                    row = first.row + 1;
                                    col = first.col;
                                }
                                else
                                {
                                    row = rand() % SIZE;
                                    col = rand() % SIZE;
                                    successful_computer_shots.clear();
                                }
                            }
                        }
                    }
                    else
                    {
                        row = rand() % SIZE;
                        col = rand() % SIZE;
                    }
                    if (player_field[row][col] == '-' && field_of_computer_shots[row][col] != 'O' && field_of_computer_shots[row][col] != 'X')
                    {
                        cout << "Компьютер промахнулся!" << endl;
                        player_field[row][col] = 'O';
                        field_of_computer_shots[row][col] = 'O';
                        player_turn = true;
                        break;
                    }
                    else if (player_field[row][col] == 'A')
                    {
                        cout << "Компьютер попал!" << endl;
                        player_field[row][col] = 'X';
                        field_of_computer_shots[row][col] = 'X';
                        cout << "Ваше поле:" << endl;
                        print_field(player_field);
                        computer_score++;
                        cell cell_of_shot;
                        cell_of_shot.row = row;
                        cell_of_shot.col = col;
                        successful_computer_shots.push_back(cell_of_shot);
                        if (player_field[row - 1][col] != 'A' && player_field[row + 1][col] != 'A' && player_field[row][col - 1] != 'A' && player_field[row][col + 1] != 'A' && player_field[row - 1][col] != 'X' && player_field[row + 1][col] != 'X' && player_field[row][col - 1] != 'X' && player_field[row][col + 1] != 'X')
                        {
                            field_of_computer_shots[row - 1][col] = 'O';
                            field_of_computer_shots[row + 1][col] = 'O';
                            field_of_computer_shots[row][col - 1] = 'O';
                            field_of_computer_shots[row][col + 1] = 'O';
                        }
                        else if (player_field[row][col] == 'X' && player_field[row - 1][col] == 'X' && player_field[row + 1][col] != 'A' && player_field[row - 2][col] != 'A')
                        {
                            field_of_computer_shots[row + 1][col] = 'O';
                            field_of_computer_shots[row - 2][col] = 'O';
                            field_of_computer_shots[row][col - 1] = 'O';
                            field_of_computer_shots[row][col + 1] = 'O';
                            field_of_computer_shots[row - 1][col - 1] = 'O';
                            field_of_computer_shots[row - 1][col + 1] = 'O';
                        }
                        else if (player_field[row][col] == 'X' && player_field[row + 1][col] == 'X' && player_field[row - 1][col] != 'A' && player_field[row + 2][col] != 'A')
                        {
                            field_of_computer_shots[row - 1][col] = 'O';
                            field_of_computer_shots[row + 2][col] = 'O';
                            field_of_computer_shots[row][col - 1] = 'O';
                            field_of_computer_shots[row][col + 1] = 'O';
                            field_of_computer_shots[row + 1][col - 1] = 'O';
                            field_of_computer_shots[row + 1][col + 1] = 'O';
                        }
                        else if (player_field[row][col] == 'X' && player_field[row][col - 1] == 'X' && player_field[row][col + 1] != 'A' && player_field[row][col - 2] != 'A')
                        {
                            field_of_computer_shots[row - 1][col] = 'O';
                            field_of_computer_shots[row - 1][col - 1] = 'O';
                            field_of_computer_shots[row][col + 1] = 'O';
                            field_of_computer_shots[row][col - 2] = 'O';
                            field_of_computer_shots[row + 1][col] = 'O';
                            field_of_computer_shots[row + 1][col - 1] = 'O';
                        }
                        else if (player_field[row][col] == 'X' && player_field[row][col + 1] == 'X' && player_field[row][col - 1] != 'A' && player_field[row][col + 2] != 'A')
                        {
                            field_of_computer_shots[row - 1][col] = 'O';
                            field_of_computer_shots[row - 1][col + 1] = 'O';
                            field_of_computer_shots[row][col - 1] = 'O';
                            field_of_computer_shots[row][col + 2] = 'O';
                            field_of_computer_shots[row + 1][col] = 'O';
                            field_of_computer_shots[row + 1][col + 1] = 'O';
                        }
                        else if (player_field[row][col] == 'X' && player_field[row - 1][col] == 'X' && player_field[row - 2][col] == 'X' && player_field[row - 3][col] != 'A' && player_field[row + 1][col] != 'A')
                        {
                            field_of_computer_shots[row - 3][col] = 'O';
                            field_of_computer_shots[row + 1][col] = 'O';
                            field_of_computer_shots[row - 2][col - 1] = 'O';
                            field_of_computer_shots[row - 1][col - 1] = 'O';
                            field_of_computer_shots[row][col - 1] = 'O';
                            field_of_computer_shots[row - 2][col + 1] = 'O';
                            field_of_computer_shots[row - 1][col + 1] = 'O';
                            field_of_computer_shots[row][col + 1] = 'O';
                        }
                        else if (player_field[row][col] == 'X' && player_field[row + 1][col] == 'X' && player_field[row + 2][col] == 'X' && player_field[row + 3][col] != 'A' && player_field[row - 1][col] != 'A')
                        {
                            field_of_computer_shots[row + 3][col] = 'O';
                            field_of_computer_shots[row - 1][col] = 'O';
                            field_of_computer_shots[row + 2][col - 1] = 'O';
                            field_of_computer_shots[row + 1][col - 1] = 'O';
                            field_of_computer_shots[row][col - 1] = 'O';
                            field_of_computer_shots[row + 2][col + 1] = 'O';
                            field_of_computer_shots[row + 1][col + 1] = 'O';
                            field_of_computer_shots[row][col + 1] = 'O';
                        }
                        else if (player_field[row][col] == 'X' && player_field[row + 1][col] == 'X' && player_field[row - 1][col] == 'X' && player_field[row + 2][col] != 'A' && player_field[row - 2][col] != 'A')
                        {
                            field_of_computer_shots[row + 2][col] = 'O';
                            field_of_computer_shots[row - 2][col] = 'O';
                            field_of_computer_shots[row + 1][col + 1] = 'O';
                            field_of_computer_shots[row + 1][col - 1] = 'O';
                            field_of_computer_shots[row][col - 1] = 'O';
                            field_of_computer_shots[row - 1][col + 1] = 'O';
                            field_of_computer_shots[row - 1][col - 1] = 'O';
                            field_of_computer_shots[row][col + 1] = 'O';
                        }
                        else if (player_field[row][col] == 'X' && player_field[row][col - 1] == 'X' && player_field[row][col - 2] == 'X' && player_field[row][col - 3] != 'A' && player_field[row][col + 1] != 'A')
                        {
                            field_of_computer_shots[row][col - 3] = 'O';
                            field_of_computer_shots[row][col + 1] = 'O';
                            field_of_computer_shots[row + 1][col] = 'O';
                            field_of_computer_shots[row + 1][col - 1] = 'O';
                            field_of_computer_shots[row + 1][col - 2] = 'O';
                            field_of_computer_shots[row - 1][col] = 'O';
                            field_of_computer_shots[row - 1][col - 1] = 'O';
                            field_of_computer_shots[row - 1][col - 2] = 'O';
                        }
                        else if (player_field[row][col] == 'X' && player_field[row][col + 1] == 'X' && player_field[row][col + 2] == 'X' && player_field[row + 3][col] != 'A' && player_field[row - 1][col] != 'A')
                        {
                            field_of_computer_shots[row][col - 1] = 'O';
                            field_of_computer_shots[row][col + 3] = 'O';
                            field_of_computer_shots[row + 1][col] = 'O';
                            field_of_computer_shots[row + 1][col + 1] = 'O';
                            field_of_computer_shots[row + 1][col + 2] = 'O';
                            field_of_computer_shots[row - 1][col] = 'O';
                            field_of_computer_shots[row - 1][col + 1] = 'O';
                            field_of_computer_shots[row - 1][col + 2] = 'O';
                        }
                        else if (player_field[row][col] == 'X' && player_field[row][col - 1] == 'X' && player_field[row][col + 1] == 'X' && player_field[row][col - 2] != 'A' && player_field[row][col + 2] != 'A')
                        {
                            field_of_computer_shots[row][col - 2] = 'O';
                            field_of_computer_shots[row][col + 2] = 'O';
                            field_of_computer_shots[row + 1][col] = 'O';
                            field_of_computer_shots[row + 1][col + 1] = 'O';
                            field_of_computer_shots[row + 1][col - 1] = 'O';
                            field_of_computer_shots[row - 1][col] = 'O';
                            field_of_computer_shots[row - 1][col + 1] = 'O';
                            field_of_computer_shots[row - 1][col - 1] = 'O';
                        }
                        if (computer_score == 10)
                        {
                            cout << "Вы проиграли!" << endl;
                            game_over = true;
                        }
                    }
                }
            }
        }
        return 0;
    }
    else
    {
        char player_field_1[SIZE][SIZE]; //игровое поле игрока 1
        char player_field_2[SIZE][SIZE]; //игровое поле игрока 2   
        char player_field_1_shots[SIZE][SIZE]; //после с выстрелами игрока 1
        char player_field_2_shots[SIZE][SIZE]; //после с выстрелами игрока 2
        // Инициализируем поля пустыми клетками
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                player_field_1[i][j] = '-';
                player_field_2[i][j] = '-';
                player_field_1_shots[i][j] = '-';
                player_field_2_shots[i][j] = '-';
            }
        }
        // Размещение кораблей игрока 1
        // Размещение трехпалубного корабля игрока
        cout << "Поле игрока 1:" << endl;
        print_field(player_field_1);
        int row = 0;
        int col = 0;
        cell* three_deck = new cell[3];
        cell* player_1_three_deck = three_deck_player_ship(row, col, three_deck);
        player_field_1[player_1_three_deck[0].row][player_1_three_deck[0].col] = 'A';
        player_field_1[player_1_three_deck[1].row][player_1_three_deck[1].col] = 'A';
        player_field_1[player_1_three_deck[2].row][player_1_three_deck[2].col] = 'A';
        // Размещение двухпалубных кораблей игрока
        cout << "Поле игрока 1:" << endl;
        print_field(player_field_1);
        cell* two_deck = new cell[2];
        cell* player_1_two_deck = two_deck_player_ship(row, col, two_deck, player_field_1);
        player_field_1[player_1_two_deck[0].row][player_1_two_deck[0].col] = 'A';
        player_field_1[player_1_two_deck[1].row][player_1_two_deck[1].col] = 'A';
        cout << "Поле игрока 1:" << endl;
        print_field(player_field_1);
        cell* second_player_1_two_deck = two_deck_player_ship(row, col, two_deck, player_field_1);
        player_field_1[second_player_1_two_deck[0].row][second_player_1_two_deck[0].col] = 'A';
        player_field_1[second_player_1_two_deck[1].row][second_player_1_two_deck[1].col] = 'A';
        // Размещение однопалубных кораблей игрока
        cout << "Поле игрока 1:" << endl;
        print_field(player_field_1);
        cell* one_deck = new cell[1];
        cell* player_1_one_deck = one_deck_player_ship(row, col, one_deck, player_field_1);
        player_field_1[player_1_one_deck[0].row][player_1_one_deck[0].col] = 'A';
        cout << "Поле игрока 1:" << endl;
        print_field(player_field_1);
        cell* second_player_1_one_deck = one_deck_player_ship(row, col, one_deck, player_field_1);
        player_field_1[second_player_1_one_deck[0].row][second_player_1_one_deck[0].col] = 'A';
        cout << "Поле игрока 1:" << endl;
        print_field(player_field_1);
        cell* third_player_1_one_deck = one_deck_player_ship(row, col, one_deck, player_field_1);
        player_field_1[third_player_1_one_deck[0].row][third_player_1_one_deck[0].col] = 'A';
        system("cls");
        // Размещение кораблей игрока 2
        // Размещение трехпалубного корабля игрока 2
        cout << "Поле игрока 2:" << endl;
        print_field(player_field_2);
        cell* player_2_three_deck = three_deck_player_ship(row, col, three_deck);
        player_field_2[player_2_three_deck[0].row][player_2_three_deck[0].col] = 'A';
        player_field_2[player_2_three_deck[1].row][player_2_three_deck[1].col] = 'A';
        player_field_2[player_2_three_deck[2].row][player_2_three_deck[2].col] = 'A';
        // Размещение двухпалубных кораблей игрока 2
        cout << "Поле игрока 2:" << endl;
        print_field(player_field_2);
        cell* player_2_two_deck = two_deck_player_ship(row, col, two_deck, player_field_2);
        player_field_2[player_2_two_deck[0].row][player_2_two_deck[0].col] = 'A';
        player_field_2[player_2_two_deck[1].row][player_2_two_deck[1].col] = 'A';
        cout << "Поле игрока 2:" << endl;
        print_field(player_field_2);
        cell* second_player_2_two_deck = two_deck_player_ship(row, col, two_deck, player_field_2);
        player_field_2[second_player_2_two_deck[0].row][second_player_2_two_deck[0].col] = 'A';
        player_field_2[second_player_2_two_deck[1].row][second_player_2_two_deck[1].col] = 'A';
        // Размещение однопалубных кораблей игрока 2
        cout << "Поле игрока 2:" << endl;
        print_field(player_field_2);
        cell* player_2_one_deck = one_deck_player_ship(row, col, one_deck, player_field_2);
        player_field_2[player_2_one_deck[0].row][player_2_one_deck[0].col] = 'A';
        cout << "Поле игрока 2:" << endl;
        print_field(player_field_2);
        cell* second_player_2_one_deck = one_deck_player_ship(row, col, one_deck, player_field_2);
        player_field_2[second_player_2_one_deck[0].row][second_player_2_one_deck[0].col] = 'A';
        cout << "Поле игрока 2:" << endl;
        print_field(player_field_2);
        cell* third_player_2_one_deck = one_deck_player_ship(row, col, one_deck, player_field_2);
        player_field_2[third_player_2_one_deck[0].row][third_player_2_one_deck[0].col] = 'A';
        system("cls");
        bool game_over = false;
        bool player_1_turn = true;
        bool player_2_turn = false;
        int player_1_score = 0;
        int player_2_score = 0;
        while (!game_over)
        {
            if (player_1_turn == true)
            {
                // Ход игрока 1
                cout << "Поле игрока 1:" << endl;
                print_field(player_field_1);
                cout << "Поле с выстрелами игрока 1:" << endl;
                print_field(player_field_1_shots);
                cout << "Ход игрока 1. Введите координаты выстрела (например, B3): ";
                string input;
                cin >> input;
                row = input[1] - '1';
                col = input[0] - 'A';
                if (!is_valid_input(&input[0], row, col))
                {
                    cout << "Некорректные координаты. Попробуйте еще раз." << endl;
                }
                else if (player_field_1_shots[row][col] == 'X' || player_field_1_shots[row][col] == 'O')
                {
                    cout << "Вы уже стреляли в эту клетку. Попробуйте еще раз." << endl;
                }
                else if (player_field_2[row][col] == '-')
                {
                    cout << "Промах!" << endl;
                    player_field_1_shots[row][col] = 'O';
                    player_field_2[row][col] = 'O';
                    cout << "Переход хода игроку 2" << endl;
                    system("pause");
                    system("cls");
                    cout << "Ход игрока 2" << endl;
                    system("pause");
                    player_1_turn = false;
                    player_2_turn = true;
                }
                else if (player_field_2[row][col] == 'A')
                {
                    cout << "Попадание!" << endl;
                    player_field_1_shots[row][col] = 'X';
                    player_field_2[row][col] = 'X';
                    player_1_score++;
                    //проверка на уничтожение кораблей
                    if (player_field_2[row - 1][col] != 'A' && player_field_2[row + 1][col] != 'A' && player_field_2[row][col - 1] != 'A' && player_field_2[row][col + 1] != 'A' && player_field_2[row - 1][col] != 'X' && player_field_2[row + 1][col] != 'X' && player_field_2[row][col - 1] != 'X' && player_field_2[row][col + 1] != 'X')
                    {
                        cout << "Вы потопили вражеский однопалубный корабль!" << endl;
                    }
                    else if ((player_field_2[row][col] == 'X' && player_field_2[row - 1][col] == 'X' && player_field_2[row - 2][col] != 'A' && player_field_2[row + 1][col] != 'A' && player_field_2[row - 2][col] != 'X' && player_field_2[row + 1][col] != 'X') || (player_field_2[row][col] == 'X' && player_field_2[row + 1][col] == 'X' && player_field_2[row + 2][col] != 'A' && player_field_2[row - 1][col] != 'A' && player_field_2[row + 2][col] != 'X' && player_field_2[row - 1][col] != 'X') ||
                        (player_field_2[row][col] == 'X' && player_field_2[row][col - 1] == 'X' && player_field_2[row][col - 2] != 'A' && player_field_2[row][col + 1] != 'A' && player_field_2[row][col - 2] != 'X' && player_field_2[row][col + 1] != 'X') || (player_field_2[row][col] == 'X' && player_field_2[row][col + 1] == 'X' && player_field_2[row][col+2] != 'A' && player_field_2[row][col-1] != 'A' && player_field_2[row][col+2] != 'X' && player_field_2[row][col-1] != 'X'))
                    {
                        cout << "Вы потопили вражеский двухпалубный корабль!" << endl;
                    }
                    else if ((player_field_2[row][col] == 'X' && player_field_2[row - 1][col] == 'X' && player_field_2[row - 2][col] == 'X' && player_field_2[row - 3][col] != 'A' && player_field_2[row + 1][col] != 'A') || (player_field_2[row][col] == 'X' && player_field_2[row + 1][col] == 'X' && player_field_2[row + 2][col] == 'X' && player_field_2[row + 3][col] != 'A' && player_field_2[row - 1][col] != 'A') ||
                        (player_field_2[row][col] == 'X' && player_field_2[row][col - 1] == 'X' && player_field_2[row][col - 2] == 'X' && player_field_2[row][col - 3] != 'A' && player_field_2[row][col + 1] != 'A') || (player_field_2[row][col] == 'X' && player_field_2[row][col + 1] == 'X' && player_field_2[row][col + 2] == 'X' && player_field_2[row][col+3] != 'A' && player_field_2[row][col-1] != 'A') ||
                        (player_field_2[row][col] == 'X' && player_field_2[row][col - 1] == 'X' && player_field_2[row][col + 1] == 'X' && player_field_2[row][col - 2] != 'A' && player_field_2[row][col + 2] != 'A') || (player_field_2[row][col] == 'X' && player_field_2[row + 1][col] == 'X' && player_field_2[row - 1][col] == 'X' && player_field_2[row + 2][col] != 'A' && player_field_2[row - 2][col] != 'A'))
                    {
                        cout << "Вы потопили вражеский трехпалубный корабль!" << endl;
                    }
                    if (player_1_score == 10)
                    {
                        cout << "Выиграл игрок 1!" << endl;
                        game_over = true;
                    }
                }
            }
            else if (player_2_turn == true)
            {
                // Ход игрока 2
                cout << "Поле игрока 2:" << endl;
                print_field(player_field_2);
                cout << "Поле с выстрелами игрока 2:" << endl;
                print_field(player_field_2_shots);
                cout << "Ход игрока 2. Введите координаты выстрела (например, B3): ";
                string input;
                cin >> input;
                row = input[1] - '1';
                col = input[0] - 'A';
                if (!is_valid_input(&input[0], row, col))
                {
                    cout << "Некорректные координаты. Попробуйте еще раз." << endl;
                }
                else if (player_field_2_shots[row][col] == 'X' || player_field_2_shots[row][col] == 'O')
                {
                    cout << "Вы уже стреляли в эту клетку. Попробуйте еще раз." << endl;
                }
                else if (player_field_1[row][col] == '-')
                {
                    cout << "Промах!" << endl;
                    player_field_2_shots[row][col] = 'O';
                    player_field_1[row][col] = 'O';
                    cout << "Переход хода игроку 1" << endl;
                    system("pause");;
                    system("cls");
                    cout << "Ход игрока 1" << endl;
                    system("pause");
                    player_2_turn = false;
                    player_1_turn = true;
                }
                else if (player_field_1[row][col] == 'A')
                {
                    cout << "Попадание!" << endl;
                    player_field_2_shots[row][col] = 'X';
                    player_field_1[row][col] = 'X';
                    player_2_score++;
                    //проверка на уничтожение кораблей
                    if (player_field_1[row - 1][col] != 'A' && player_field_1[row + 1][col] != 'A' && player_field_1[row][col - 1] != 'A' && player_field_1[row][col + 1] != 'A' && player_field_1[row - 1][col] != 'X' && player_field_1[row + 1][col] != 'X' && player_field_1[row][col - 1] != 'X' && player_field_1[row][col + 1] != 'X')
                    {
                        cout << "Вы потопили вражеский однопалубный корабль!" << endl;
                    }
                    else if ((player_field_1[row][col] == 'X' && player_field_1[row - 1][col] == 'X' && player_field_1[row - 2][col] != 'A' && player_field_1[row + 1][col] != 'A' && player_field_1[row - 2][col] != 'X' && player_field_1[row + 1][col] != 'X') || (player_field_1[row][col] == 'X' && player_field_1[row + 1][col] == 'X' && player_field_1[row + 2][col] != 'A' && player_field_1[row - 1][col] != 'A' && player_field_1[row + 2][col] != 'X' && player_field_1[row - 1][col] != 'X') ||
                        (player_field_1[row][col] == 'X' && player_field_1[row][col - 1] == 'X' && player_field_1[row][col - 2] != 'A' && player_field_1[row][col + 1] != 'A' && player_field_1[row][col - 2] != 'X' && player_field_1[row][col + 1] != 'X') || (player_field_1[row][col] == 'X' && player_field_1[row][col + 1] == 'X' && player_field_1[row][col+2] != 'A' && player_field_1[row][col-1] != 'A' && player_field_1[row][col+2] != 'X' && player_field_1[row][col-1] != 'X'))
                    {
                        cout << "Вы потопили вражеский двухпалубный корабль!" << endl;
                    }
                    else if ((player_field_1[row][col] == 'X' && player_field_1[row - 1][col] == 'X' && player_field_1[row - 2][col] == 'X' && player_field_1[row - 3][col] != 'A' && player_field_1[row + 1][col] != 'A') || (player_field_1[row][col] == 'X' && player_field_1[row + 1][col] == 'X' && player_field_1[row + 2][col] == 'X' && player_field_1[row + 3][col] != 'A' && player_field_1[row - 1][col] != 'A') ||
                        (player_field_1[row][col] == 'X' && player_field_1[row][col - 1] == 'X' && player_field_1[row][col - 2] == 'X' && player_field_1[row][col - 3] != 'A' && player_field_1[row][col + 1] != 'A') || (player_field_1[row][col] == 'X' && player_field_1[row][col + 1] == 'X' && player_field_1[row][col + 2] == 'X' && player_field_1[row][col+3] != 'A' && player_field_1[row][col-1] != 'A') ||
                        (player_field_1[row][col] == 'X' && player_field_1[row][col - 1] == 'X' && player_field_1[row][col + 1] == 'X' && player_field_1[row][col - 2] != 'A' && player_field_1[row][col + 2] != 'A') || (player_field_1[row][col] == 'X' && player_field_1[row + 1][col] == 'X' && player_field_1[row - 1][col] == 'X' && player_field_1[row + 2][col] != 'A' && player_field_1[row - 2][col] != 'A'))
                    {
                        cout << "Вы потопили вражеский трехпалубный корабль!" << endl;
                    }
                    if (player_2_score == 10)
                    {
                        cout << "Выиграл игрок 2!" << endl;
                        game_over = true;
                    }
                }
            }
        }
        return 0;
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
