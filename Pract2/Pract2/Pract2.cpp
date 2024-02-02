#include <iostream>
using namespace std;

//Одномерные массивы
bool checkMe(int* array)
{
    for (int i = 0; i < 4; i++)
    {
        if (array[i] == array[i + 1])
            return true;
    }
}

void input1(int* array)
{
    for (int i = 0; i < 5; i++)
    {
        cout << "a[" << i << "]=";
        cin >> array[i];
    }
}

//Многомерные массивы
const int rows = 3;
const int cols = 3;

void addMas(int mas1[rows][cols], int mas2[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = mas1[i][j] + mas2[i][j];
        }
    }
}

void printArray(int mas1[rows][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << mas1[i][j] << " ";
        }
        cout << std::endl;
    }
}




//Структуры
struct BankAccount {
    char accountNumber[50];
    double balance;
    char currency[5];
};

void Menu() {
    cout << "\nМеню\n";
    cout << "1. Информация об аккаунте\n";
    cout << "2. Внести\n";
    cout << "3. Снять\n";
    cout << "4. Выйти\n";
    cout << "Введите цифру 1,2,3 или 4: ";
}

void displayAccountInfo(const BankAccount& account) {
    cout << "\nНомер аккаунта: " << account.accountNumber << "\n";
    cout << "Баланс: " << account.balance << " " << account.currency << "\n";
}

void contribute(BankAccount& account, double amount) {
    account.balance += amount;
    cout << "Успешно!\n";
}

void takeoff(BankAccount& account, double amount) {
    if (amount > account.balance) {
        cout << "На вашем счете недостаточно средств!\n";
    }
    else {
        account.balance -= amount;
        cout << "Успешно!\n";
    }
}

//Классы
class Stack {
private:
    static const int MAX_SIZE = 100;
    int elements[MAX_SIZE];
    int top;


public:
    Stack() : top(-1) {}

    void push(int element) {
        if (top == MAX_SIZE - 1) {
            cout << "Стек переполнен!\n";
        }
        else {
            elements[++top] = element;
            cout << element << " элемент добавлен\n";
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Стек пуст!\n";
        }
        else {
            cout << elements[top] << " элемент удален\n";
            top--;
        }
    }
};



int main()
{
    setlocale(LC_ALL, "Russian");
    int z;
    cout << "Введите номер задания (1, 2, 3 или 4) \n";
    cin >> z;
    if (z == 1)
    {
        int a[5];
        input1(a);
        if (checkMe(a) == true)
            cout << "Не уникальны";
        else
            cout << "Уникальны";
    }
    else if (z == 2)
    {
        int massiv1[rows][cols] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
        int massiv2[rows][cols] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
        int result[rows][cols];

        addMas(massiv1, massiv2, result);

        cout << "Первый массив:" << std::endl;
        printArray(massiv1);

        cout << "\nВторой массив:" << std::endl;
        printArray(massiv2);

        cout << "\nРезультат сложения:" << std::endl;
        printArray(result);

        return 0;
    }
    else if (z == 3)
    {
        BankAccount userAccount = { "123", 5000.0, "RUB" };
        int choice;
        double amount;

        do {
            Menu();
            cin >> choice;

            switch (choice) {
            case 1:
                displayAccountInfo(userAccount);
                break;
            case 2:
                cout << "Введите сумму, которую хотите внести на ваш счет: ";
                cin >> amount;
                contribute(userAccount, amount);
                break;
            case 3:
                cout << "Введите сумму, которую хотите снять с вашего счета: ";
                cin >> amount;
                takeoff(userAccount, amount);
                break;
            case 4:
                cout << "Вы вышли из программы\n";
                break;
            default:
                cout << "Неккоректный ввод!\n";
            }
        } while (choice != 4);
        return 0;
    }
    else if (z == 4)
    {
        Stack stack;

        stack.push(10);
        stack.push(20);
        stack.push(30);

        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop();

        return 0;
    }
    else
    {
        cout << "Неправильный ввод! Введите номер задания (1, 2, 3 или 4) \n";
    }

}




