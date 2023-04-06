#include <iostream>
#include <vector>
#include<Windows.h>

using namespace std;

vector<vector<double>> multiply_matrices(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    if (A[0].size() != B.size()) {
        throw invalid_argument("Матриці несумісні для множення");
    }

    vector<vector<double>> result(A.size(), vector<double>(B[0].size(), 0));

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B[0].size(); j++) {
            for (int k = 0; k < B.size(); k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

int main() {
    vector<vector<double>> A = { {1, 2}, {3, 4} };
    vector<vector<double>> B = { {5, 6}, {7, 8} };

    try {
        vector<vector<double>> C = multiply_matrices(A, B);

        for (int i = 0; i < C.size(); i++) {
            for (int j = 0; j < C[0].size(); j++) {
                cout << C[i][j] << " ";
            }
            cout << endl;
        }
    }
    catch (const invalid_argument& e) {
        cout << "Помилка: " << e.what() << endl;
    }

    return 0;
}

