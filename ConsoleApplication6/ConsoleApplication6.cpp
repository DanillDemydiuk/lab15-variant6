#include <iostream>
#include <cmath>

using namespace std;

// Функція для перевірки, чи є число простим
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// Функція для сортування масиву бульбашковим методом у порядку спадання
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) { // Для сортування за спаданням
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Введіть ціле число: ";
    cin >> n;

    const int maxSize = 100; // Максимальний розмір масиву для зберігання простих дільників
    int primeDivisors[maxSize];
    int count = 0;

    // Знаходження простих дільників
    for (int i = 2; i <= abs(n); ++i) {
        if (n % i == 0 && isPrime(i)) {
            primeDivisors[count] = i;
            count++;
        }
    }

    // Сортування масиву у порядку спадання
    bubbleSort(primeDivisors, count);

    // Виведення відсортованого масиву
    cout << "Прості дільники у порядку спадання: ";
    for (int i = 0; i < count; i++) {
        cout << primeDivisors[i] << " ";
    }
    cout << endl;

    return 0;
}