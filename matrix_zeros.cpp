#include <iostream>
#include <vector>
using namespace std;

// Better Approach 
vector<vector<int>> setZeroes(vector<vector<int>>& matrix, int n, int m) {
    vector<int> row(n, 0);
    vector<int> col(m, 0);

    // Mark rows and columns containing 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // Set elements to 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] == 1 || col[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

// Optimal Approach 
vector<vector<int>> zeros(vector<vector<int>>& matrix, int n, int m) {
    int col0 = 1;

    // Step 1: Mark rows and columns
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;

                if (j != 0) {
                    matrix[0][j] = 0;
                } else {
                    col0 = 0;
                }
            }
        }
    }

    // Step 2: Set matrix elements to 0 based on markers
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Step 3: Handle first row
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

    // Step 4: Handle first column
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

void printMatrix(vector<vector<int>>& matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;

    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    // Make copies for both approaches
    vector<vector<int>> matrix1 = matrix;
    vector<vector<int>> matrix2 = matrix;

    vector<vector<int>> result1 = setZeroes(matrix1, n, m);
    vector<vector<int>> result2 = zeros(matrix2, n, m);

    cout << "\nBetter Approach Output:\n";
    printMatrix(result1, n, m);

    cout << "\nOptimal Approach Output:\n";
    printMatrix(result2, n, m);

    return 0;
}