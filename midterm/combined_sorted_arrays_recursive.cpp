#include <iostream>
#include <vector>
using namespace std;

//  Question 3:
//  Given two sorted arrays A and B, find all possible combined arrays such that the first element is taken from A,
//  followed by an element from B, then again from A, and so on until both arrays are empty.
//  These combined arrays must be sorted in ascending order and must end with an element from B.

struct FindCombinedContext {
    const vector<int>& A;
    const vector<int>& B;
    vector<int>& C;
    int m;
    int n;
    bool flag = true;

    FindCombinedContext(const vector<int>& a, const vector<int>& b, vector<int>& c)
        : A(a), B(b), C(c), m(static_cast<int>(a.size())), n(static_cast<int>(b.size())) {}
};

void printVector(const vector<int>& vec, int n) {
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void find_combined_sorted_vectors(FindCombinedContext& ctx, int i, int j, int len) {
    if (ctx.flag) {
        for (int k = i; k < ctx.m; k++) {
            if (len == 0 || ctx.A[k] > ctx.C[len - 1]) {
                ctx.C[len] = ctx.A[k];
                ctx.flag = !ctx.flag;
                find_combined_sorted_vectors(ctx, k + 1, j, len + 1);
                ctx.flag = !ctx.flag;
            }
        }
        return;
    }

    for (int k = j; k < ctx.n; k++) {
        if (len == 0 || ctx.B[k] > ctx.C[len - 1]) {
            ctx.C[len] = ctx.B[k];
            if (k == ctx.n - 1) {
                printVector(ctx.C, len + 1);
            }
            ctx.flag = !ctx.flag;
            find_combined_sorted_vectors(ctx, i, k + 1, len + 1);
            ctx.flag = !ctx.flag;
        }
    }
}

int main() {
    vector<int> A = {10, 15, 25};
    vector<int> B = {1, 5, 20, 30};

    vector<int> C(A.size() + B.size());

    FindCombinedContext ctx(A, B, C);

    find_combined_sorted_vectors(ctx, 0, 0, 0);

    return 0;
}