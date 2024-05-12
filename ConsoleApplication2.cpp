#include <iostream>
#include <cmath>

using namespace std;

const int NUM = 147;

double F1(float x)
{
    if ((1 - NUM) / cos(x - NUM) > 0)
        return log((1 - NUM) / cos(x - NUM)) / log(21);
    else return -1;
}

double F2(float x)
{
    return (sin(x) / NUM);
}

double value()
{

    while (true)
    {
        double a;
        cin >> a;

        if (cin.fail()) {  //Проверка на число
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Вы ввели не число! " << endl;
        }
        else {
            return a;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "russian");

    double startX, endX, delta;

    cout << "Введите начальное значение: ";
    startX = value();

    cout << "Введите конечное значение: ";
    endX = value();

    cout << "Введите шаг: ";
    delta = value();

    if (!((endX - startX) * delta >= 0)) // проверяем корректность данных
    {
        cout << endl << "Введены неверные данные" << endl;
        return 0;
    }
    else
    {
        cout << endl << endl;

        printf("| %5s | %20s | %20s |\n", "num", "X", "Result");
        cout << "-----------------------------------------------------" << endl;

        if (startX == endX)
        {
            if (F1(startX) == -1)
                printf("| %5i | %20.5f | %20s |\n", 1, startX, "нет решения");
            else
                printf("| %5i | %20.5f | %20.5f |\n", 1, startX, min(F1(startX), F2(startX)));
        }
        else if (delta == 0)
        {

            if (F1(startX) == -1)
                printf("| %5i | %20.5f | %20s |\n", 1, startX, "нет решения");
            else
                printf("| %5i | %20.5f | %20.5f |\n", 1, startX, min(F1(startX), F2(startX)));

            if (F1(endX) == -1)
                printf("| %5i | %20.5f | %20s |\n", 2, endX, "нет решения");
            else
                printf("| %5i | %20.5f | %20.5f |\n", 2, endX, min(F1(endX), F2(endX)));
        }
        else
        {
            int i = 1;
            if (startX < endX)
                for (startX; startX <= endX; startX += delta)
                {
                    if (F1(startX) == -1)
                        printf("| %5i | %20.5f | %20s |\n", i, startX, "нет решения");
                    else
                        printf("| %5i | %20.5f | %20.5f |\n", i, startX, min(F1(startX), F2(startX)));
                    i++;
                }
            else
                for (startX; startX >= endX; startX += delta)
                {
                    if (F1(startX) == -1)
                        printf("| %5i | %20.5f | %20s |\n", i, startX, "нет решения");
                    else
                        printf("| %5i | %20.5f | %20.5f |\n", i, startX, min(F1(startX), F2(startX)));
                    i++;
                }
        }
    }
    return 0;
}

