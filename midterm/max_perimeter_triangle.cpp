#include <iostream>
using namespace std;

//  Question 1:
//  Given an array of non-negative integers, find three elements in the array
//  that form a triangle with the largest perimeter.

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int findTriangle(int arr[], int n) {
    // Sort the array
    bubbleSort(arr, n);

    // Check for largest triangle perimeter
    for (int i = n - 1; i >= 2; i--) {
        if (arr[i] < arr[i - 1] + arr[i - 2]) {
            return (arr[i] + arr[i - 1] + arr[i - 2]);
        }
    }

    // No triangle combination
    throw std::runtime_error("Triangle formation is not possible.");
}

//int main() {
//    int arr[] = {33, 6, 20, 1, 8, 12, 5, 55, 4, 9};
//    int n = sizeof(arr)/sizeof(arr[0]);
//
//    cout << findTriangle(arr, n);
//}
