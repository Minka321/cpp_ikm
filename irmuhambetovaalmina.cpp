#include <iostream>
#include <vector>
using namespace std;
vector<long long> ppff(long long n) {
    vector<long long> fs;
    // Проверка делимости на 2
    while (n % 2 == 0) {
        fs.push_back(2);
        n /= 2;
    }
    // Проверка делимости на нечетные числа
    for (long long i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            fs.push_back(i);
            n /= i;
        }
    }
    // Если n является простым числом больше 2
    if (n > 2) {
        fs.push_back(n);
    }
    return fs;
}
int main() {
    setlocale(LC_ALL, "RUS");
    long long number;
    cout << "Введите натуральное число: ";
    cin >> number;
    if ((number > 0) && ((number - int(number))!=0))  {
        vector<long long> fs = ppff(number);
        cout << "Разложение на простые множители: ";
        for (long long fr : fs) {
            cout << fr << " ";
        }
        cout << endl;
    }
    else {
        cout << "Ошибка! Проверьте введенные данные)";
    }
    return 0;
}
