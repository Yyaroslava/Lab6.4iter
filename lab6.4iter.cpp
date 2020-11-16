// Ітераційний спосіб

#include <iostream> 
#include <iomanip> 
#include <time.h> 
#include <math.h>

using namespace std;

void Create(int* c, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++)
        c[i] = Low + rand() % (High - Low + 1);
}

void Print(int* c, const int size) {
    for (int i = 0; i < size; i++)
        cout << setw(4) << c[i];
    cout << endl;
}

int AbsMin(int* c, const int size) {
    int absmin = c[0];
    for (int i = 1; i < size; i++) {
        if (abs(c[i]) < abs(absmin)) absmin = c[i];
    }
    return absmin;
}

int SumAfterZero(int* c, const int size) {
    int s = 0;
    for (int i = 0; i < size; i++) {
        if (c[i] == 0) {
            for (; i < size; i++) s += c[i];
            break;
        }
    }
    return s;
}

void Shuffle(int* c, const int size) {
    int* h = new int[size];
    int j = 0;
    for (int i = 0; 2 * i < size; i++, j++) {
        h[j] = c[2 * i];
    }
    for (int i = 0; 2 * i + 1 < size; i++, j++) {
        h[j] = c[2 * i + 1];
    }
    for (int i = 0; i < size; i++) {
        c[i] = h[i];
    }
}

int main() {
    srand((unsigned)time(NULL));  // ініціалізація генератора випадкових чисел  
    int n;
    cout << "Number of elements = ";
    cin >> n;
    int *p = new int[n];

    int Low = -10;
    int High = 10;

    Create(p, n, Low, High);
    Print(p, n);
    cout << "Abs minimum = " << AbsMin(p, n) << endl;
    cout << "Sum after first zero = " << SumAfterZero(p, n) << endl;
    Shuffle(p, n);
    Print(p, n);

    return 0;
}
