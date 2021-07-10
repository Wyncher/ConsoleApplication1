#include <iostream>
#include <stdlib.h>
using namespace std;
float** Input(char S, char* N, float* SUM);
float** MultOnNumb(const char N, float** A, char M);
float** Subtraction(float** A, float** B, char M);
float** Multiplication(float** A, float** B, char M);
int main()
{
    float** A, ** B, ** pA, ** pB, ** pC, ** pD, ** pE, ** pF, ** pG, SUM;
    char Na, Nb, i, j, k;
    A = Input('A', &Na, &SUM);
    B = Input('B', &Nb, &SUM);
    cout <<  "\t" << SUM << "\t";
    cout << Nb << "\t" << SUM << "\t";
    if (Na == Nb)
    {
        pA = Subtraction(A, B, Nb);
        pD = MultOnNumb(3, B, Nb);
        pB = Subtraction(B, A, Nb);
        pC = MultOnNumb(2, pA, Nb);
        pE = Multiplication(pC, A, Nb);
        pF = Multiplication(pB, B, Nb);
        pG = Subtraction(pE, pF, Nb);

        for (i = 0; i < Nb; i++)
        {
            for (j = 0; j < Nb; j++)
            {
                cout << *(*(pG + i) + j) << "\t";
            }
            cout << endl;
        }
        for (i = 0; i < Nb; i++)
        {
            delete[] * (A + i);
            delete[] * (B + i);
            delete[] * (pC + i);
            delete[] * (pD + i);
            delete[] * (pE + i);
            delete[] * (pF + i);
            delete[] * (pG + i);
        }
        delete[] A;
        delete[] B;
        delete[] pC;
        delete[] pD;
        delete[] pE;
        delete[] pF;
        delete[] pG;
    }
    else
    {
        cout << "Invalid value";
        for (i = 0; i < Nb; i++)
        {
            delete[] * (A + i);
            delete[] * (B + i);
        }
        delete[] A;
        delete[] B;
    }
    return 0;
}
float** Input(char S, char* N, float* SUM)
{
    float** M;
    int i, j, Nm;
    cout << "Enter the size of the matrix " << S << ": ";
    cin >> Nm;
    M = new float* [Nm];
    for (i = 0; i < Nm; i++)
    {
        *(M + i) = new float[Nm];
        for (j = 0; j < Nm; j++)
        {
            cout << "Enter element[" << i << "][" << j << "]: ";
            cin >> *(*(M + i) + j);
            if (*(*(M + i) + j) > 0)
                *SUM += *(*(M + i) + j);
        }
    }
    *N = Nm;
    return M;
}

float** MultOnNumb(const char N, float** A, char M)
{
    float** C;
    int i, j;
    C = new float* [M];
    for (i = 0; i < M; i++)
    {
        *(C + i) = new float[M];
        for (j = 0; j < M; j++)
        {
            *(*(C + i) + j) = *(*(A + i) + j) * N;
        }
    }
    return C;
}

float** Subtraction(float** A, float** B, char M)
{
    float** C;
    int i, j;
    C = new float* [M];
    for (i = 0; i < M; i++)
    {
        *(C + i) = new float[M];
        for (j = 0; j < M; j++)
        {
            *(*(C + i) + j) = *(*(A + i) + j) - *(*(B + i) + j);
        }
    }
    return C;
}
float** Multiplication(float** A, float** B, char M)
{
    float** C;
    int i, j;
    C = new float* [M];
    for (i = 0; i < M; i++)
    {
        *(C + i) = new float[M];
        for (j = 0; j < M; j++)
        {
            *(*(C + i) + j) = *(*(A + i) + j) * *(*(B + i) + j);
        }
    }
    return C;
}