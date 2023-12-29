#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
void smena1(int** array, int row1, int row2, int N) {
    for (int j = 0; j < N; ++j) {
        swap(array[row1][j], array[row2][j]);
    }
}
void smena2(int** arr, int col1, int col2, int N) {
    for (int i = 0; i < N; ++i) {
        int temp = arr[i][col1];
        arr[i][col1] = arr[i][col2];
        arr[i][col2] = temp;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    int N = 0;
    int value = 0;
    cout << "Введите число N: ";
    cin >> N;
    while (cin.fail() == 1) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка. Введите число!" << endl;
        cin >> N;
    }
    while (N <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка. Число должно быть больше нуля!" << endl;
        cin >> N;
    }
    int** tablica = new int* [N];
    for (int i = 0; i < N; ++i) {
        tablica[i] = new int[N];
    }

    cout << "С какого угла вы хотите начать змейку?" << endl << "Введите соответствующее число: " << endl << "1 - с левого верхнего" << endl << "2 - с левого нижнего" << endl << "3 - с правого верхнего" << endl << "4 - с правого нижнего" << endl;
    cin >> value;
    while (cin.fail() == 1) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // чистка
        cout << "Ошибка. Введите число!" << endl;
        cin >> value;
    }
    while (value <= 0 && value > 4) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка. Число должно быть больше нуля!" << endl;
        cin >> value;
    }

    int num1 = 1;
    int num2 = 1;
    int a = 0;
    int b = N - 1;
    int num3 = 1;
    int num4 = N * N;

    switch (value)
    {
    case 1:
        for (int zmey = 0; zmey < N * 2; ++zmey) {
            for (int i = max(0, zmey - N + 1); i <= min(zmey, N - 1); ++i) {
                int j = zmey - i;
                if (zmey % 2 == 0) {
                    tablica[i][j] = num1;
                }
                else {
                    tablica[j][i] = num1;
                }
                ++num1;
            }
        }
        cout << "Полученный массив:" << endl;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << tablica[i][j] << '\t';
            }
            cout << endl;
        }
        cout << "Массив успешно сохранен в файл output.txt." << endl;
        break;
    case 2:
        for (int zmey = 0; zmey < N * 2; ++zmey) {
            for (int i = max(0, zmey - N + 1); i <= min(zmey, N - 1); ++i)
            {
                int j = zmey - i;
                if (zmey % 2 == 0)
                {
                    tablica[i][j] = num3;
                }
                else {
                    tablica[j][i] = num3;
                }
                ++num3;
            }
        }
        if (N % 2 == 0)
        {
            for (int i = 0; i < (N / 2); i++) {
                smena1(tablica, a, b, N);
                a++;
                b--;
            }
        }
        else
        {
            for (int i = 0; i < (N - 1) / 2; i++) {
                smena1(tablica, a, b, N);
                a++;
                b--;
            }
        }
        cout << "Полученный массив:" << endl;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << tablica[i][j] << '\t';
            }
            cout << endl;
        }
        cout << "Массив успешно сохранен в файл output.txt." << endl;
        break;
    case 3:
        for (int zmey = 0; zmey < N * 2; ++zmey) {
            for (int i = max(0, zmey - N + 1); i <= min(zmey, N - 1); ++i)
            {
                int j = zmey - i;
                if (zmey % 2 == 0)
                {
                    tablica[i][j] = num1;
                }
                else {
                    tablica[j][i] = num1;
                }
                ++num1;
            }
        }
        if (N % 2 == 0)
        {
            for (int i = 0; i < (N / 2); i++) {
                smena2(tablica, a, b, N);
                a++;
                b--;
            }
        }
        else
        {
            for (int i = 0; i < (N - 1) / 2; i++) {
                smena2(tablica, a, b, N);
                a++;
                b--;
            }
        }
        cout << "Полученный массив:" << endl;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << tablica[i][j] << '\t';
            }
            cout << endl;
        }
        cout << "Массив успешно сохранен в файл output.txt." << endl;
        break;
    case 4:
 
        for (int zmey = 0; zmey < N * 2; ++zmey) {
            for (int i = max(0, zmey - N + 1); i <= min(zmey, N - 1); ++i) {
                int j = zmey - i;
                if (zmey % 2 == 0) {
                    tablica[i][j] = num4;
                }
                else {
                    tablica[j][i] = num4;
                }
                --num4;
            }
        }
   
        cout << "Полученный массив:" << endl;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << tablica[i][j] << '\t';
            }
            cout << endl;
        }
        cout << "Массив успешно сохранен в файл output.txt." << endl;
        break;
    default:
        cout << "Введите число от 1 до 4!";
        break;
    }

    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cout << "Не удалось открыть файл для записи." << endl;
        return 1;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            outputFile << tablica[i][j] << '\t';
        }
        outputFile << '\n';
    }
    outputFile.close();
    for (int i = 0; i < N; ++i) {
        delete[] tablica[i];
    }
    delete[] tablica;
    return 0;
}