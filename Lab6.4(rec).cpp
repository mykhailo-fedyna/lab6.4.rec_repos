#include <iostream>
using namespace std;

void inputArray(double* arr, int n, int i = 0) {
    if (i >= n) return;
    cin >> arr[i];
    inputArray(arr, n, i + 1);
}

int countPositiveElements(double* arr, int n, int i = 0) {
    if (i >= n) return 0;
    int isPositive = arr[i] > 0 ? 1 : 0;
    return isPositive + countPositiveElements(arr, n, i + 1);
}

double sumAfterLastZero(double* arr, int n, int i = -1) {
    if (i == -1) i = n - 1;
    if (i < 0) return 0;

    if (arr[i] == 0) return 0;
    return arr[i] + sumAfterLastZero(arr, n, i - 1);
}

void transformArray(double* arr, int n, double* transformedArr, int i = 0, int& transformedi = *(new int(0))) {
    if (i >= n) return;

    if (int(arr[i]) <= 1) {
        transformedArr[transformedi++] = arr[i];
    }
    transformArray(arr, n, transformedArr, i + 1, transformedi);

    if (i == 0) {
        for (int i = 0; i < n; i++) {
            if (int(arr[i]) > 1) {
                transformedArr[transformedi++] = arr[i];
            }
        }
    }
}

void printArray(double* arr, int n, int i = 0) {
    if (i >= n) {
        cout << endl;
        return;
    }
    cout << arr[i] << " ";
    printArray(arr, n, i + 1);
}

int main() {
    int n;
    cout << "Enter the number of array elements: ";
    cin >> n;

    double* arr = new double[n];

    inputArray(arr, n);

    int positiveCount = countPositiveElements(arr, n);
    cout << "The number of positive array elements: " << positiveCount << endl;

    double sum = sumAfterLastZero(arr, n);
    cout << "The sum of the elements after the last zero: " << sum << endl;

    double* transformedArr = new double[n];
    transformArray(arr, n, transformedArr);

    cout << "Converted array:\n";
    printArray(transformedArr, n);

    delete[] arr;
    delete[] transformedArr;

    return 0;
}
