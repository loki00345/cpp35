#include <iostream>

using namespace std;
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int* removePrimes(int* arr, int size, int& newSize) {
    int countNonPrimes = 0;

    for (int i = 0; i < size; ++i) {
        if (!isPrime(arr[i])) {
            countNonPrimes++;
        }
    }

    int* result = new int[countNonPrimes];
    int index = 0;

    for (int i = 0; i < size; ++i) {
        if (!isPrime(arr[i])) {
            result[index++] = arr[i];
        }
    }

    newSize = countNonPrimes;
    return result;
}
int main() {

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter elements of the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    int newSize;
    int* result = removePrimes(arr, size, newSize);

    cout << "New array without prime numbers: ";
    for (int i = 0; i < newSize; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] result;

    int M, N;

    cout << "Enter the size of array A: ";
    cin >> M;
    cout << "Enter the size of array B: ";
    cin >> N;

    int* A = new int[M];
    int* B = new int[N];

    cout << "Enter elements of array A: ";
    for (int i = 0; i < M; ++i) {
        cin >> A[i];
    }
    cout << "Enter elements of array B: ";
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    cout << "Unique elements of array A not present in array B: ";
    bool found;
    for (int i = 0; i < M; ++i) {
        found = false;
        for (int j = 0; j < N; ++j) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << A[i] << " ";
        }
    }
    delete[] A;
    delete[] B;
}