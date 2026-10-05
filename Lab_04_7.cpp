#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h>

using namespace std;

int main() {
    // Налаштування UTF-8 для консолі Windows
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    double xp, xk, dx, eps, x, R, a, S;
    int n;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
        << setw(12) << "atan(x)" << " |"
        << setw(12) << "S" << " |"
        << setw(7) << "n" << " |" << endl;
    cout << "------------------------------------------------" << endl;

    x = xp;
    while (x <= xk + eps / 2.0) {
        n = 0;
        a = x;  // Перший доданок при n = 0
        S = a;  // Початкова сума

        do {
            n++;
            R = -(x * x * (2 * n - 1)) / (2 * n + 1);
            a *= R;
            S += a;
        } while (abs(a) >= eps);

        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(12) << setprecision(5) << atan(x) << " |"
            << setw(12) << setprecision(5) << S << " |"
            << setw(7) << n << " |" << endl;

        x += dx;
    }
    cout << "------------------------------------------------" << endl;

    return 0;
}