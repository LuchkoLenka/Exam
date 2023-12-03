#include <iostream>
#include <cmath>

using namespace std;

// Функція для знаходження номеру мінімального елемента масиву
int findMinIndex(const double arr[], int size) {
    int minIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Функція для обчислення суми елементів масиву між першим і другим від'ємними елементами
double sumBetweenNegatives(const double arr[], int size) {
    int firstNegIndex = -1;
    int secondNegIndex = -1;

    // Знаходимо індекси першого і другого від'ємних елементів
    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) {
            if (firstNegIndex == -1) {
                firstNegIndex = i;
            }
            else {
                secondNegIndex = i;
                break;
            }
        }
    }

    // Обчислюємо суму елементів між першим і другим від'ємними елементами
    double sum = 0;
    if (firstNegIndex != -1 && secondNegIndex != -1) {
        for (int i = firstNegIndex + 1; i < secondNegIndex; ++i) {
            sum += arr[i];
        }
    }

    return sum;
}

int main() {

    const int size = 10;  // Задайте розмір масиву за потребою
    double arr[size];

    // Заповнення масиву дійсними числами (для прикладу)
    for (int i = 0; i < size; ++i) {
        cout << "Enter array element arr[" << i << "]: ";
        cin >> arr[i];
    }

    // Знаходження номеру мінімального елемента масиву
    int minIndex = findMinIndex(arr, size);
    cout << "Minimum element number: " << minIndex << std::endl;

    // Обчислення суми елементів масиву між першим і другим від'ємними елементами
    double sumBetweenNeg = sumBetweenNegatives(arr, size);
    cout << "The sum of elements between the first and second negative elements: " << sumBetweenNeg << std::endl;

    // Перетворення масиву
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (std::abs(arr[j]) <= 1) {
                // Обмін елементів, якщо модуль елемента не перевищує 1
                double temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Виведення результату перетворення масиву
    cout << "Converted array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
