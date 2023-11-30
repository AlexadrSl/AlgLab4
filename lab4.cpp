#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Lab4
{
public:
    float x, y;
    float lab1(float x)
    {
        if (x <= -3)
        {
            y = 1;
        }
        else if (x > -3 && x <= -1)
        {

            y = -sqrt(4 - pow(x + 1, 2));
        }
        else if (x > -1 && x <= 2)
        {

            y = -2;
        }
        else if (x > 2)
        {

            y = x - 4;
        }
        return y;
    }

    void lab11()
    {
        lab1(x);
        cout << "y = " << y << endl;
    }

    void lab2()
    {
        int str;
        int stol;

        cout << "Введите количетво строк: ";
        cin >> str;
        cout << "Введите количество столбцов: ";
        cin >> stol;

        int **arr = new int *[str];

        for (int i = 0; i < str; i++)
        {
            arr[i] = new int[stol];
        }

        for (int i = 0; i < str; i++)
        {
            for (int j = 0; j < stol; j++)
            {
                arr[i][j] = rand() % 50;
            }
        }

        for (int i = 0; i < str; i++)
        {
            for (int j = 0; j < stol; j++)
            {
                cout << arr[i][j] << '\t';
            }
            cout << endl;
        }

        for (int i = 0; i < str; i++)
        {
            delete[] arr[i];
        }

        delete[] arr;
    }

    void lab3()
    {
        ifstream in("lab3.txt");
        ofstream out("lab3.txt");

        string text1;
        string text2;
        cout << "Ввод: ";
        cin >> text1;
        out << text1;
        out.close();

        getline(in, text2);
        cout << "Вывод: " << text2 << endl;
        in.close();
    }

    void lab32()
    {

        ifstream fin("text.txt");  // вывод данных из файл
        ofstream fout("text.txt"); // ввод данных в файла
        string b;
        int q = 0, w =0;

        for (int x = -4; x < 7; x++)
        {
            q++;
            lab1(x);
            fout << y;
            fout << "\n";
        }


        fout.close();

        float *data = new float[q];
        while (getline(fin, b))
        {
            float c = stof(b);
            data[w] = c;
            w++;
        }
        for (int i = 0; i < q; i++)
        {
            cout << data[i] << "\n";
        }
        fin.close(); // закрываем файл
    }
};

int main()
{
    setlocale(LC_ALL, "RU");
    setlocale(LC_ALL, ".UTF8");

    Lab4 lab;
    cout << "Введите x: ";
    cin >> lab.x;
    lab.lab11();
    lab.lab2();
    lab.lab3();
    lab.lab32();
}