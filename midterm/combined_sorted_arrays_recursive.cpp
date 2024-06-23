#include <iostream>
using namespace std;

//  Question 3:
//  Given two sorted arrays A and B, find all possible combined arrays such that the first element is taken from A,
//  followed by an element from B, then again from A, and so on until both arrays are empty.
//  These combined arrays must be sorted in ascending order and must end with an element from B.

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//    State transition graph
//    State 0:
//      - If flag is true -> Transition to State A
//      - If flag is false -> Transition to State B
//
//    State A:
//      - For each k from i to m:
//        - If len == 0 or A[k] > C[len - 1]:
//          - Set C[len] = A[k]
//          - Transition to State B with (i = k + 1, j, m, n, len + 1, !flag)
//
//    State B:
//      - For each k from j to n:
//        - If len == 0 or B[k] > C[len - 1]:
//          - Set C[len] = B[k]
//          - If k == n - 1:
//            - Transition to State End
//          - Else:
//            - Transition to State A with (i, j = k + 1, m, n, len + 1, !flag)
//
//    State End:
//      - Print the array C
//      - End

int find_combined_sorted_arrays(int A[], int B[], int C[], int i, int j, int m, int n, int len, bool flag) {
    if (flag) {
        for (int k = i; k < m; k++) {
            if (len == 0 || A[k] > C[len - 1]) {
                C[len] = A[k];
                find_combined_sorted_arrays(A, B, C, k + 1, j, m, n, len + 1, !flag);
            }
        }
    } else {
        for (int k = j; k < n; k++) {
            if (len == 0 || B[k] > C[len - 1]) {
                C[len] = B[k];
                if (k == n - 1) {
                    printArray(C, len + 1);
                }
                find_combined_sorted_arrays(A, B, C, i, k + 1, m, n, len + 1, !flag);
            }
        }
    }
}

int main() {
    int A[] = {10, 15, 25};
    int B[] = {1, 5, 20, 30};

    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);

    int C[m + n];

    find_combined_sorted_arrays(A, B, C, 0, 0, m, n, 0, true);

    return 0;
}