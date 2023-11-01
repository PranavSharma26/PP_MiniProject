#include <iostream>
using namespace std;

void matrixAddition(int row1, int col1, int **Matrix1) // FOR ADDITION
{
    int row2 = row1, col2 = col1;

    cout << "Enter the second Matrix elements:" << endl;

    int Matrix2[row2][col2];
    for (int i = 0; i < row2; i++) // Matrix Elements Input
    {
        for (int j = 0; j < col2; j++)
        {
            cin >> Matrix2[i][j];
        }
    }
    cout << endl;

    int MatrixAdd[row2][col2];


    for (int i = 0; i < row1; i++) // Operation
    {
        for (int j = 0; j < col1; j++)
        {
            MatrixAdd[i][j] = Matrix1[i][j] + Matrix2[i][j];
        }
    }

    cout << "Result: " << endl;
    for (int i = 0; i < row2; i++) // Printing the Matrix
    {
        for (int j = 0; j < col2; j++)
        {
            cout << MatrixAdd[i][j] << " ";
        }
        cout << endl;
    }
}

void matrixSubtraction(int row1, int col1, int **Matrix1) // FOR SUBTRACTION
{
    int row2 = row1, col2 = col1;

    cout << "Enter the second Matrix elements:" << endl;

    int Matrix2[row2][col2];
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cin >> Matrix2[i][j];
        }
    }
    cout << endl;

    int MatrixSub[row2][col2];

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            MatrixSub[i][j] = Matrix1[i][j] - Matrix2[i][j];
        }
    }

    cout << "Result: " << endl;
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cout << MatrixSub[i][j] << " ";
        }
        cout << endl;
    }
}

void matrixMultiplication(int row1, int col1, int **Matrix1) // FOR MULTIPLICATION
{
    int row2, col2;
    cout << "Enter the number of rows of second Matrix: ";
    cin >> row2;
    cout << "Enter the number of columns of second Matrix: ";
    cin >> col2;

    if (col1 != row2)
    {
        cout << "Multiplication not possible";
        return;
    }

    cout << "Enter the second Matrix elements:" << endl;

    int Matrix2[row2][col2];
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cin >> Matrix2[i][j];
        }
    }
    cout << endl;

    int MatrixMulti[row1][col2];
    int tempSum;

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            tempSum = 0;
            for (int k = 0; k < row1; k++)
            {
                tempSum += Matrix1[i][k] * Matrix2[k][j];
            }
            MatrixMulti[i][j] = tempSum;
        }
    }

    cout << "Result: " << endl;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cout << MatrixMulti[i][j] << " ";
        }
        cout << endl;
    }
}

void matrixTranspose(int row1, int col1, int **Matrix1) // FOR TRANSPOSE
{
    int MatrixTranspose[col1][row1];

    for (int i = 0; i < col1; i++)
    {
        for (int j = 0; j < row1; j++)
        {
            MatrixTranspose[i][j] = Matrix1[j][i];
        }
    }

    cout << "Result: " << endl;
    for (int i = 0; i < col1; i++)
    {
        for (int j = 0; j < row1; j++)
        {
            cout << MatrixTranspose[i][j] << " ";
        }
        cout << endl;
    }
}

void matrixDeterminant2(int row1, int col1, int **Matrix1) // FOR 2x2 DETERMINANT
{
    if (row1 != 2 || col1 != 2)
    {
        cout << "Enter correct value !";
        return;
    }
    int determinant;

    determinant = Matrix1[0][0] * Matrix1[1][1] - Matrix1[0][1] * Matrix1[1][0];

    cout << "Result: " << determinant << endl;
}

void matrixDeterminant3(int row1, int col1, int **Matrix1) // FOR 3x3 DETERMINANT
{
    if (row1 != 3 || col1 != 3)
    {
        cout << "Enter correct value !";
        return;
    }
    int determinant;

    determinant = Matrix1[0][0] * (Matrix1[1][1] * Matrix1[2][2] - Matrix1[2][1] * Matrix1[1][2]) - Matrix1[0][1] * (Matrix1[1][0] * Matrix1[2][2] - Matrix1[2][0] * Matrix1[1][2]) + Matrix1[0][2] * (Matrix1[1][0] * Matrix1[2][1] - Matrix1[2][0] * Matrix1[1][1]);

    cout << "Result: " << determinant << endl;
}

void matrixCofactor(int row1, int col1, int **Matrix1) // FOR COFACTOR
{
    if (row1 != 3 || col1 != 3)
    {
        cout << "Enter correct value !";
        return;
    }

    int cofactMatrix[3][3];

    cofactMatrix[0][0] = Matrix1[2][2] * Matrix1[1][1] - Matrix1[2][1] * Matrix1[1][2];
    cofactMatrix[0][1] = (Matrix1[2][2] * Matrix1[1][0] - Matrix1[2][0] * Matrix1[1][2]) * -1;
    cofactMatrix[0][2] = Matrix1[2][1] * Matrix1[1][0] - Matrix1[2][0] * Matrix1[1][1];
    cofactMatrix[1][0] = (Matrix1[2][2] * Matrix1[0][1] - Matrix1[2][1] * Matrix1[0][2]) * -1;
    cofactMatrix[1][1] = Matrix1[2][2] * Matrix1[0][0] - Matrix1[2][0] * Matrix1[0][2];
    cofactMatrix[1][2] = (Matrix1[2][1] * Matrix1[0][0] - Matrix1[2][0] * Matrix1[0][1]) * -1;
    cofactMatrix[2][0] = Matrix1[1][2] * Matrix1[0][1] - Matrix1[1][1] * Matrix1[0][2];
    cofactMatrix[2][1] = (Matrix1[1][2] * Matrix1[0][0] - Matrix1[1][0] * Matrix1[0][2]) * -1;
    cofactMatrix[2][2] = Matrix1[1][1] * Matrix1[0][0] - Matrix1[1][0] * Matrix1[0][1];

    cout << "Result: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << cofactMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void matrixAdjoint(int row1, int col1, int **Matrix1) // FOR ADJOINT
{
    if (row1 != 3 || col1 != 3)
    {
        cout << "Enter correct value !";
        return;
    }

    int cofactMatrix[3][3];

    cofactMatrix[0][0] = Matrix1[2][2] * Matrix1[1][1] - Matrix1[2][1] * Matrix1[1][2];
    cofactMatrix[0][1] = (Matrix1[2][2] * Matrix1[1][0] - Matrix1[2][0] * Matrix1[1][2]) * -1;
    cofactMatrix[0][2] = Matrix1[2][1] * Matrix1[1][0] - Matrix1[2][0] * Matrix1[1][1];
    cofactMatrix[1][0] = (Matrix1[2][2] * Matrix1[0][1] - Matrix1[2][1] * Matrix1[0][2]) * -1;
    cofactMatrix[1][1] = Matrix1[2][2] * Matrix1[0][0] - Matrix1[2][0] * Matrix1[0][2];
    cofactMatrix[1][2] = (Matrix1[2][1] * Matrix1[0][0] - Matrix1[2][0] * Matrix1[0][1]) * -1;
    cofactMatrix[2][0] = Matrix1[1][2] * Matrix1[0][1] - Matrix1[1][1] * Matrix1[0][2];
    cofactMatrix[2][1] = (Matrix1[1][2] * Matrix1[0][0] - Matrix1[1][0] * Matrix1[0][2]) * -1;
    cofactMatrix[2][2] = Matrix1[1][1] * Matrix1[0][0] - Matrix1[1][0] * Matrix1[0][1];

    int MatrixTranspose[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            MatrixTranspose[i][j] = cofactMatrix[j][i];
        }
    }

    cout << "Result: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << MatrixTranspose[i][j] << " ";
        }
        cout << endl;
    }
}

void matrixInverse(int row1, int col1, int **Matrix1) // FOR INVERSE
{
    if (row1 != 3 || col1 != 3)
    {
        cout << "Enter correct value !";
        return;
    }
    int determinant;

    determinant = Matrix1[0][0] * (Matrix1[1][1] * Matrix1[2][2] - Matrix1[2][1] * Matrix1[1][2]) - Matrix1[0][1] * (Matrix1[1][0] * Matrix1[2][2] - Matrix1[2][0] * Matrix1[1][2]) + Matrix1[0][2] * (Matrix1[1][0] * Matrix1[2][1] - Matrix1[2][0] * Matrix1[1][1]);

    if (determinant < 0)
    {
        determinant *= -1;
    }

    if (determinant == 0)
    {
        cout << "Inverse not Possible";
        return;
    }

    int cofactMatrix[3][3];

    cofactMatrix[0][0] = Matrix1[2][2] * Matrix1[1][1] - Matrix1[2][1] * Matrix1[1][2];
    cofactMatrix[0][1] = (Matrix1[2][2] * Matrix1[1][0] - Matrix1[2][0] * Matrix1[1][2]) * -1;
    cofactMatrix[0][2] = Matrix1[2][1] * Matrix1[1][0] - Matrix1[2][0] * Matrix1[1][1];
    cofactMatrix[1][0] = (Matrix1[2][2] * Matrix1[0][1] - Matrix1[2][1] * Matrix1[0][2]) * -1;
    cofactMatrix[1][1] = Matrix1[2][2] * Matrix1[0][0] - Matrix1[2][0] * Matrix1[0][2];
    cofactMatrix[1][2] = (Matrix1[2][1] * Matrix1[0][0] - Matrix1[2][0] * Matrix1[0][1]) * -1;
    cofactMatrix[2][0] = Matrix1[1][2] * Matrix1[0][1] - Matrix1[1][1] * Matrix1[0][2];
    cofactMatrix[2][1] = (Matrix1[1][2] * Matrix1[0][0] - Matrix1[1][0] * Matrix1[0][2]) * -1;
    cofactMatrix[2][2] = Matrix1[1][1] * Matrix1[0][0] - Matrix1[1][0] * Matrix1[0][1];

    int MatrixTranspose[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            MatrixTranspose[i][j] = cofactMatrix[j][i];
        }
    }

    float finalDeterminant = determinant;
    float finalMatrix[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            finalMatrix[i][j] = cofactMatrix[i][j] / finalDeterminant;
        }
    }

    cout << "Result: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << finalMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() // MAIN PROGRAM
{
    int Mode;
    int row1, col1;

    cout << "THIS IS A PROGRAM TO DO MATRIX ALGEBRA" << endl
         << endl;
    cout << "Enter 1 for Addition of two Matrices" << endl;
    cout << "Enter 2 for Subtraction of two Matrices" << endl;
    cout << "Enter 3 for Multiplication of two Matrices" << endl;
    cout << "Enter 4 for Transpose of the Matrix" << endl;
    cout << "Enter 5 for Determinant of 2x2 Matrix" << endl;
    cout << "Enter 6 for Determinant of 3x3 Matrix" << endl;
    cout << "Enter 7 for cofactor of 3x3 Matrix" << endl;
    cout << "Enter 8 for adjoint of 3x3 Matrix" << endl;
    cout << "Enter 9 for inverse of 3x3 Matrix" << endl;

    cout << "Enter the Mode: ";
    cin >> Mode;

    if (Mode == 5)
    {
        row1 = 2;
        col1 = 2;
    }
    else if (Mode == 6)
    {
        row1 = 3;
        col1 = 3;
    }
    else if (Mode == 7)
    {
        row1 = 3;
        col1 = 3;
    }
    else if (Mode == 8)
    {
        row1 = 3;
        col1 = 3;
    }
    else if (Mode == 9)
    {
        row1 = 3;
        col1 = 3;
    }
    else
    {
        cout << "Enter the number of rows of Matrix: ";
        cin >> row1;
        cout << "Enter the number of columns of Matrix: ";
        cin >> col1;
    }

    cout << "Enter the Matrix elements:" << endl;
    int **Matrix1 = new int *[row1];
    for (int i = 0; i < row1; i++)
    {
        Matrix1[i] = new int[col1];
    }

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            cin >> Matrix1[i][j];
        }
    }
    cout << endl;

    if (Mode == 1)
        matrixAddition(row1, col1, Matrix1);
    if (Mode == 2)
        matrixSubtraction(row1, col1, Matrix1);
    if (Mode == 3)
        matrixMultiplication(row1, col1, Matrix1);
    if (Mode == 4)
        matrixTranspose(row1, col1, Matrix1);
    if (Mode == 5)
        matrixDeterminant2(row1, col1, Matrix1);
    if (Mode == 6)
        matrixDeterminant3(row1, col1, Matrix1);
    if (Mode == 7)
        matrixCofactor(row1, col1, Matrix1);
    if (Mode == 8)
        matrixAdjoint(row1, col1, Matrix1);
    if (Mode == 9)
        matrixInverse(row1, col1, Matrix1);

    return 0;
}