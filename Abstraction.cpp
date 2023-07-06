#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    int numRows;
    int numColumns;
    vector<vector<int>> data;

public:
    Matrix(int rows, int columns) : numRows(rows), numColumns(columns), data(rows, vector<int>(columns)) {}

    int getNumRows() const {
        return numRows;
    }

    int getNumColumns() const {
        return numColumns;
    }

    const vector<vector<int>>& getData() const {
        return data;
    }

    void setData(const vector<vector<int>>& newData) {
        if (newData.size() != numRows || newData[0].size() != numColumns) {
            cout << "Invalid matrix dimensions." << endl;
            return;
        }
        data = newData;
    }

    Matrix multiply(const Matrix& other) const {
        if (numColumns != other.getNumRows()) {
            cout << "Invalid matrix dimensions for multiplication." << endl;
            return Matrix(0, 0);
        }

        int resultRows = numRows;
        int resultColumns = other.getNumColumns();
        Matrix result(resultRows, resultColumns);

        for (int i = 0; i < resultRows; i++) {
            for (int j = 0; j < resultColumns; j++) {
                int sum = 0;
                for (int k = 0; k < numColumns; k++) {
                    sum += data[i][k] * other.data[k][j];
                }
                result.data[i][j] = sum;
            }
        }

        return result;
    }
};

int main() {
    Matrix matrix1(2, 3);
    matrix1.setData({{1, 2, 3},
                     {4, 5, 6}});

    Matrix matrix2(3, 2);
    matrix2.setData({{7, 8},
                     {9, 10},
                     {11, 12}});

    Matrix product = matrix1.multiply(matrix2);

    cout << "Product matrix:" << endl;
    const vector<vector<int>>& productData = product.getData();
    for (int i = 0; i < product.getNumRows(); i++) {
        for (int j = 0; j < product.getNumColumns(); j++) {
            cout << productData[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

