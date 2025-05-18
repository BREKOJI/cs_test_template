#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixMultiply(const vector<vector<int>> & A, const vector<vector<int>> & B) {
    int rows_A = A.size();
    int cols_A = A[0].size();
    int cols_B = B[0].size();
    vector C(rows_A, vector<int> (cols_B));
    for (int i = 0; i < rows_A; i ++ )
        for (int j = 0; j < cols_B; j ++ )
            for (int k = 0; k < cols_A; k ++ )
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

void matrixPrint(const vector<vector<int>> & C) {
    int rows_C = C.size();
    int cols_C = C[0].size();
    for (int i = 0; i < rows_C; i ++ ){
        for (int j = 0; j < cols_C; j ++ )
            cout << C[i][j] << ' ';
        puts("");
    }
}

int main() {
    int n1, m1, n2, m2;
    cin >> n1 >> m1 >> n2 >> m2;
    vector A(n1, vector<int> (m1));
    vector B(n2, vector<int> (m2));
    for (int i = 0; i < n1; i ++ )
        for (int j = 0; j < m1; j ++ ) cin >> A[i][j];
    for (int i = 0; i < n2; i ++ )
        for (int j = 0; j < m2; j ++ ) cin >> B[i][j];
    vector<vector<int>> C = matrixMultiply(A, B);
    matrixPrint(C);
    return 0;
}