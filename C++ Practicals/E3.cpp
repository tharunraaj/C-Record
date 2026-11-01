#include <iostream>
#include <cassert>
using namespace std;

class Matrix
{
private:
    int data[2][2];

public:
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0)
    {
        data[0][0] = a;
        data[0][1] = b;
        data[1][0] = c;
        data[1][1] = d;
    }
    Matrix operator+(const Matrix &m)
    {
        Matrix result;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                result.data[i][j] = data[i][j] + m.data[i][j];
        return result;
    }
    Matrix operator*(const Matrix &m)
    {
        Matrix result;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result.data[i][j] = 0;
                for (int k = 0; k < 2; k++)
                    result.data[i][j] += data[i][k] * m.data[k][j];
            }
        }
        return result;
    }
    int* operator[](int index)
    {
        return data[index];
    }
    friend ostream& operator<<(ostream &out, const Matrix &m)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
                out << m.data[i][j] << " ";
            out << endl;
        }
        return out;
    }
};

void runTest(int testNo, int a, int b, int c, int d, int e, int f, int g, int h)
{
    cout << "===== Test Case " << testNo << " =====" << endl;

    Matrix A(a, b, c, d);
    Matrix B(e, f, g, h);

    Matrix sum = A + B;
    Matrix product = A * B;

    assert(sum[0][0] == a + e);
    assert(sum[0][1] == b + f);
    assert(sum[1][0] == c + g);
    assert(sum[1][1] == d + h);
    assert(product[0][0] == a * e + b * g);
    assert(product[0][1] == a * f + b * h);
    assert(product[1][0] == c * e + d * g);
    assert(product[1][1] == c * f + d * h);

    cout << "Matrix A:" << endl;
    cout << A;
    cout << "Matrix B:" << endl;
    cout << B;
    cout << "Addition of Matrices:" << endl;
    cout << sum;
    cout << "Multiplication of Matrices:" << endl;
    cout << product;
    cout << "All unit tests passed successfully." << endl;
    cout << endl;
}

int main()
{
    runTest(1, 2, 3, 4, 5, 1, 1, 1, 1);
    runTest(2, 0, 1, 2, 3, 4, 5, 6, 7);

    cout << "Program completed successfully." << endl;
    return 0;
}