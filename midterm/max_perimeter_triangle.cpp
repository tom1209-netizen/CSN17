#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

//  Question 1:
//  Given an array of non-negative integers, find three elements in the array
//  that form a triangle with the largest perimeter.

// Custom exception for triangle formation errors
class TriangleFormationException : public std::logic_error {
public:
    using std::logic_error::logic_error;
};

void swap(int &a, int &b) noexcept {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(vector<int>& arr) {
    auto n = static_cast<int>(arr.size());
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int findTriangle(vector<int>& arr) {
    // Sort the array
    bubbleSort(arr);

    // Check for largest triangle perimeter
    auto n = static_cast<int>(arr.size());
    for (int i = n - 1; i >= 2; i--) {
        if (arr[i] < arr[i - 1] + arr[i - 2]) {
            return (arr[i] + arr[i - 1] + arr[i - 2]);
        }
    }

    // No triangle combination
    throw TriangleFormationException("Triangle formation is not possible.");
}
