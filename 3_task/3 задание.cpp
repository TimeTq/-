/* ДЛЯ ВСЕХ ЗАДАЧ : файл со входными данными пользователь должен указывать сам(без хардкода).
Задачи сдавать в виде : исходный код, примеры файлов с входными данными, и файл,
который можно сразу запускать - уже скомпилированный,
если язык того требует(если C#, C++ и т.д. - *.exe, если Java, Scala - *.jar и т.д.).
Будет плюсом, если зальете решение в github.

    3. В магазине 5 касс, в каждый момент времени к кассе стоит очередь некоторой длины.
Каждые 30 минут измеряется средняя длина очереди в каждую кассу и для каждой кассы это значение(число вещественное)
записывается в соответсвующий ей файл(всего 5 файлов), магазин работает 8 часов в день.
Рассматривается только один день.
На момент запуска приложения все значения уже находятся в файлах.Написать программу,
которая по данным замеров определяет интервал времени,
когда в магазине было наибольшее количество посетителей за день. */


#include <iostream>
#include <fstream>
#include <stdio.h>

// Простой вывод массива
void PrintArr(double arr[], int lenArr)
{
    for (int i = 0; i < lenArr; ++i)
    {
        std::cout << arr[i] << " | ";
    }
}

void Arrays (double a[16], std::string path) {

    std::ifstream file;
    file.open(path);

    if (!file.is_open())
    {
        std::cout << "no file\n" << std::endl;
       
    }
    else {

        // Ввод значений в массив
        double s = 0;
        int i = 0;
        for (file >> s; !file.eof(); file >> s)
        {
            //std::cout << s<<
            a[i] = s;
            i += 1;
        }

        file.close();
    };
}
int main()
{
    std::string path[5];

        // Ввод пути к файлу .txt
        for (int i = 0; i < 5; i++)
        {
            std::cout << "Enter path: ";
            std::cin >> path[i];
        }

    double a[5][16];

    for (int j = 0; j < 5; j++)
    {
        Arrays(a[j], path[j]);
    }

    double res[16] = { 0 };

    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            res[i] += a[j][i];
        }

    }

    double result = res[0];
    int section = 0;

    for (int i = 1; i < 16; i++)
    {
        if (result < res[i]) {
            result = res[i];
            section = i;
        }
    }

    int hourLeft = 8 + section / 2;
    int minuteLeft = 30 * (section % 2);

    int hourRight = 8 + (section + 1) / 2;
    int minuteRight = 30 * ((section + 1) % 2);

    //std::cout << section << " " << section / 2 << " " << section % 2 << std::endl;
   //std::cout << section << " " << hourLeft << " minuteRight" << minuteLeft << std::endl;

    printf("%d:%02d-%d:%02d", hourLeft, minuteLeft, hourRight, minuteRight);



}

