/*ДЛЯ ВСЕХ ЗАДАЧ : файл со входными данными пользователь должен указывать сам(без хардкода).
Задачи сдавать в виде : исходный код, примеры файлов с входными данными, и файл,
который можно сразу запускать - уже скомпилированный,
если язык того требует(если C#, C++ и т.д. - *.exe, если Java, Scala - *.jar и т.д.).
Будет плюсом, если зальете решение в github.

1. Считать из файла последовательность целых чисел.Вычислить 90 персентиль, 
медиану, максимальное, минимальное и среднее значения.На вход программа получает 
файл с числами.Каждое число в файле находится на новой строке.
Вывод в консоль должен быть следующим :

90 percentile <значение>
median <значение>
average <значение>
max <значение>
min <значение> */

#include <iostream>
#include <math.h>
#include <fstream>


// Быстрая сортировка
void QuickSort(int s_arr[], int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = s_arr[(left + right) / 2];
        do
        {
            while (s_arr[left] < middle) left++;
            while (s_arr[right] > middle) right--;
            if (left <= right)
            {
                int tmp = s_arr[left];
                s_arr[left] = s_arr[right];
                s_arr[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        QuickSort(s_arr, first, right);
        QuickSort(s_arr, left, last);
    }
}

// Вычисление процентиля (определение из Вики)
int Percentile(int arr[], int lenArr , int percent)
{
    int k = floor((lenArr - 1) * percent / 100 ); 
    int result;

    if (k + 1 < lenArr * percent / 100 )
    {
        result = arr[k + 1];
    } else if (k + 1 == lenArr * percent / 100 ) {
        result = (arr[k + 1] + arr[k]) / 2;
    } else {
        result = arr[k];
    }

    return result;
}

// Простой вывод массива
void PrintArr(int arr[], int lenArr)
{
    for (int i = 0; i < lenArr; ++i)
    {
        std::cout << arr[i] << " | ";
    }
}


double Average(int arr[], int lenArr)
{
    double result = 0;

    for (int i = 0; i < lenArr; ++i)
    {
        result += arr[i];
    }

    return result/ lenArr;
}

int main()
{
   // Ввод пути к файлу .txt
    std::string path= "";
    std::cout << "Enter path: ";
    std::cin >> path;
  

    std::ifstream file;
    file.open(path);

    if (!file.is_open()) 
    {
        std::cout << "no file\n" << std::endl;
        return -1;
    };

   // Ввод значений в массив
   int s = 0;
   int i = 0;
   int lenArr = 0;

    // Подсчет элементов в файле
   for (file >> s; !file.eof(); file >> s)
   {
       
       lenArr += 1;
    }


   // Возврат в начало файла
   file.clear();
   file.seekg(0);

   // Создание массива
   int* a = new int[lenArr];
   for (file >> s; !file.eof(); file >> s)
   {
       a[i] = s;
       i += 1;
   }

   file.close();

    QuickSort(a, 0, lenArr - 1);

    // Решение
        std::cout << "90 percentile " << Percentile(a,lenArr, 90) << std::endl;;
        std::cout << "median " << Percentile(a, lenArr, 50) << std::endl;;
        std::cout << "average " << Average(a, lenArr) << std::endl;
        std::cout << "max " << a[lenArr - 1] << std::endl;;
        std::cout << "min " << a[0];

}

