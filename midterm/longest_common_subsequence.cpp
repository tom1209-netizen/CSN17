#include <iostream>
#include <vector>
using namespace std;

//  Question 2:
//  Using Dynamic Programming, for two character strings 'X' and 'Y', find the length of the longest common subsequence.
//  A common subsequence is a sequence of characters that appears in both strings in the same order

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Using recursion
int find_sequence(char* X, char* Y, int m, int n, vector<char>& lcs) {
    if (m == 0 || n == 0) {
        return 0;
    }

    if (X[m - 1] == Y[n - 1]) {
        lcs.push_back(X[m - 1]);
        return 1 + find_sequence(X, Y, m - 1, n - 1, lcs);
    } else {
        vector<char> lcs1 = lcs;
        vector<char> lcs2 = lcs;
        int len1 = find_sequence(X, Y, m - 1, n, lcs1);
        int len2 = find_sequence(X, Y, m, n - 1, lcs2);

        if (len1 > len2) {
            lcs = lcs1;
            return len1;
        } else {
            lcs = lcs2;
            return len2;
        }
    }
}

// Using dynamic programming
pair<int, char*> find_sequence_dp(char* X, char* Y, int m, int n) {
    vector<vector<int>> LCS_table(m + 1, vector<int>(n + 1));

    // Build the table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                LCS_table[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
            } else {
                LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
            }
        }
    }

    // Get the string back
    int index = LCS_table[m][n];
    char* result = new char[index + 1];
    result[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            result[index - 1] = X[i - 1];
            index--;

            // Move in diagonal direction
            i--;
            j--;
        } else if (LCS_table[i - 1][j] > LCS_table[i][j - 1]) {
            i--; // Move in horizontal direction
        } else {
            j--; // Move in vertical direction
        }
    }

    return {LCS_table[m][n], result};
}

//int main() {
//    char X[] = "HarryDepTrai";
//    char Y[] = "HarryPro";
//    int m = sizeof(X)/sizeof(X[0]) - 1; // Remove terminating character
//    int n = sizeof(Y)/sizeof(Y[0]) - 1; // Remove terminating character
//
//    vector<char> lcs;
//    int length = find_sequence(X, Y, m, n, lcs);
//    cout << "Length of LCS (find_sequence): " << length << endl;
//    cout << "LCS (find_sequence): ";
//    for (auto it = lcs.rbegin(); it != lcs.rend(); ++it) {
//        cout << *it;
//    }
//    cout << endl;
//    cout << endl;
//
//    pair<int, char*> result = find_sequence_dp(X, Y, m, n);
//    cout << "Length of LCS (find_sequence_dp): " << result.first << endl;
//    cout << "LCS (find_sequence_dp): " << result.second << endl;
//}
