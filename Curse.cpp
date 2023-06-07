#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

struct SparseMatrixElement
{
    int row;
    int col;
    double value;
};

double Random(double a, double b)
{
    return (double)rand() / RAND_MAX * (std::max(a, b) - std::min(a, b)) + std::min(a, b);
}

double** CreateMatrix(const int n, const int m)
{
    double** a = new double* [n];
    for (int i = 0; i < n; i++)
        a[i] = new double[m];

    return a;
}

void FillRandomMatrix(double** A, int n, int m, double start, double end)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; (j <= i); j++)
        {
            A[i][j] = Random(start, end);
            A[j][i] = A[i][j];
        }
    }
}

std::vector<SparseMatrixElement> FillRandomMatrix(const int n, double start, double end)
{
    std::vector<SparseMatrixElement> A;
    for (int i = 0; i < n; i++)
    {
        double R1 = Random(start, end), R2 = Random(start, end);
        if (i + 2 < n) A.push_back({ i + 2, i, R1 });
        if (i + 1 < n) A.push_back({ i + 1, i, R2 });
        A.push_back({ i, i, Random(start, end) * 100 });
        if (i + 1 < n) A.push_back({ i, i + 1, R2 });
        if (i + 2 < n) A.push_back({ i, i + 2, R1 });
    }
    return A;
}

void FillRandomMatrix(std::vector<SparseMatrixElement>& A, const int n, const int m, const double start, const double end)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; (j <= i); j++)
        {
            A.push_back({ i, j, Random(start, end) });
        }
    }
}

double* MatrixByVector(double** A, double* B, int n)
{
    double* AB = new double[n];
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            sum += B[j] * A[i][j];
        AB[i] = sum;
        sum = 0;
    }

    return AB;
}


std::vector<double> Mult(const std::vector<SparseMatrixElement>& A, const std::vector<double>& p) {
    int N = A.size();
    int n = p.size();
    std::vector<double> Ap(n, 0);
    for (int i = 0; i < N; i++)
        Ap[A[i].row] += (A[i].value) * p[A[i].col];

    return Ap;
}

double Get_norm(double* A, int n)
{
    double norma = 0;
    for (int j = 0; j < n; j++)
        norma += A[j] * A[j];

    return sqrt(norma);
}


double Get_norm(std::vector<double> A, const int n)
{
    double norma = 0;
    for (int j = 0; j < n; j++)
        norma += A[j] * A[j];

    return sqrt(norma);
}

std::vector<SparseMatrixElement> CholeskyDecompositionSparse(const std::vector<SparseMatrixElement>& A)
{
    // создаю матрицу L
    std::vector<SparseMatrixElement> L_elements;

    for (const auto& element : A)
    {
        if (element.col > element.row) continue; // Рассматриваем только элементы до главной диагонали

        double temp = 0.0;

        // Суммируем квадраты элементов, уже вычисленных для данной строки
        for (const auto& existing_element : L_elements)
        {
            if (existing_element.row == element.row && existing_element.col < element.col)
                temp += existing_element.value * existing_element.value;
            else if (existing_element.row == element.col)
                break; // Достигли главной диагонали L
        }

        // Находим значение диагонального элемента
        if (element.row == element.col)
        {
            double value = std::sqrt(element.value - temp);
            L_elements.push_back({ element.row, element.col, value });
        }
        // Вычисляем значение элемента L
        else
        {
            double L_col_col = 0;
            for (const auto& elem : L_elements)
            {
                if (elem.row == element.col && elem.col == element.col)
                {
                    L_col_col = elem.value;
                    break;
                }
            }
            double value = (element.value - temp) / L_col_col;
            L_elements.push_back({ element.row, element.col, value });
        }
    }

    return L_elements;
}


std::vector<SparseMatrixElement> IncompleteCholesky(const std::vector<SparseMatrixElement>& A, const double eps)
{
    // создаю матрицу L
    std::vector<SparseMatrixElement> L_elements;

    for (const auto& element : A)
    {
        if (element.col > element.row || element.value < eps) continue; // Рассматриваем только элементы до главной диагонали и больше порога

        double temp = 0.0;

        // Суммируем квадраты элементов, уже вычисленных для данной строки
        for (const auto& existing_element : L_elements)
        {
            if (existing_element.row == element.row && existing_element.col < element.col)
                temp += existing_element.value * existing_element.value;
            else if (existing_element.row == element.col)
                break; // Достигли главной диагонали L
        }

        // Находим значение диагонального элемента
        if (element.row == element.col)
        {
            double value = std::sqrt(element.value - temp);
            L_elements.push_back({ element.row, element.col, value });
        }
        // Вычисляем значение элемента L
        else
        {
            double L_col_col = 0;
            for (const auto& elem : L_elements)
            {
                if (elem.row == element.col && elem.col == element.col)
                {
                    L_col_col = elem.value;
                    break;
                }
            }
            double value = (element.value - temp) / L_col_col;
            L_elements.push_back({ element.row, element.col, value });
        }
    }

    return L_elements;
}


double Scolar(const std::vector<double>& a, const std::vector<double>& b, const int n)
{
    double scolar_ab = 0;
    for (int i = 0; i < n; i++)
        scolar_ab += b[i] * a[i];

    return scolar_ab;
}

std::vector<double> Gradient(const std::vector<SparseMatrixElement>& A, const std::vector<double>& b, const std::vector<double>& X0, const int n, const double e)
{
    std::vector<double> X(n);
    std::vector<double> p(n); // разложение х по базису
    std::vector<double> r(n); // невязка
    std::vector<double> r_next(n);
    std::vector<double> AX0 = Mult(A, X0);
    // предпочёт (подготовка перед итерационным процессом)
    for (int i = 0; i < n; i++)
    {
        r[i] = b[i] - AX0[i];  // r1 = b-Ax0
        p[i] = r[i];          // p1 = r1
        X[i] = X0[i];        // начальное приближение
    }

    int k = 0;
    while (Get_norm(r, n) > e) /// Get_norm(b, n)
    {
        k++;
        std::vector<double> AP = Mult(A, p);
        double a = Scolar(r, r, n) / Scolar(AP, p, n);
        for (int i = 0; i < n; i++)
        {
            X[i] = X[i] + a * p[i];        // X_k+1 = X_k + a_k*p_k
            r_next[i] = r[i] - a * AP[i]; // r_k+1 = r_k - a_k*A*p_k
        }
        double beta = Scolar(r_next, r_next, n) / Scolar(r, r, n);
        for (int i = 0; i < n; i++)
        {
            p[i] = r_next[i] + beta * p[i]; // p_k+1 = r_k+1 + beta_k*p_k
        }

        for (int i = 0; i < n; i++)
            r[i] = r_next[i];
    }
    std::cout << k << std::endl;
    return X;
}

std::vector<double> GradientPreconditioned(const std::vector<SparseMatrixElement>& A, const std::vector<double>& b, const std::vector<double>& X0, const int n, const double e)
{
    std::vector<double> X(n);
    //std::vector<double> p(n); // разложение х по базису
    std::vector<double> r(n); // невязка
    std::vector<double> r_next(n);
    std::vector<double> AX0 = Mult(A, X0);
    // предпочёт (подготовка перед итерационным процессом)
    for (int i = 0; i < n; i++)
    {
        r[i] = b[i] - AX0[i];  // r1 = b-Ax0
        //p[i] = r[i];          // p1 = r1
        X[i] = X0[i];        // начальное приближение
    }

    std::vector<SparseMatrixElement> M = CholeskyDecompositionSparse(A);
    std::vector<double> p = Mult(M, r);


    int k = 0;
    while (Get_norm(r, n) > e) /// Get_norm(b, n)
    {
        k++;
        std::vector<double> AP = Mult(A, p);

        double a = Scolar(r, r, n) / Scolar(AP, p, n);

        for (int i = 0; i < n; i++)
        {
            X[i] = X[i] + a * p[i];        // X_k+1 = X_k + a_k*p_k
            r_next[i] = r[i] - a * AP[i]; // r_k+1 = r_k - a_k*A*p_k
        }

        std::vector<double> z = Mult(M, r_next);
        double beta = Scolar(z, r_next, n) / Scolar(r, r, n);
        for (int i = 0; i < n; i++)
        {
            p[i] = z[i] + beta * p[i]; // p_k+1 = r_k+1 + beta_k*p_k
        }

        for (int i = 0; i < n; i++)
            r[i] = r_next[i];
    }
    std::cout << k << std::endl;
    return X;
}

void SetkaX(const double a, const double b, const int n, std::vector<double>& X)
{
    for (int i = 0; i <= n; i++)
    {
        X[i] = a + (b - a) / n * i;
    }
}

double F(const double x, const double y)
{
    return 2 + 6 * y + 6 * x * y;
}

double u(const double x, const double y)
{
    return y * y + y * y * y * (1 + x);
}

void SLAY(std::vector<SparseMatrixElement>& slay, std::vector<double>& B, std::vector<double>& X, std::vector<double>& Y, const int n)
{

    // d^2u(x,y)/dy^2 = 1/h^2 * (u(x, y_j+1) - 2 * u(x, y_j) + u(x, y_j-1))
    // d^2u(x,y)/dx^2 = 1/h^2 * (u(x_i+1, y) - 2 * u(x_i, y) + u(x_i-1, y))
    // (U[i][j + 1] - 2 * U[i][j] + U[i][j - 1]) + (U[i + 1][j] - 2 * U[i][j] + U[i - 1][j]) = f(X[i], Y[i]);

    // граничные условия (4 границы)
    for (int j = 0; j <= n; j++)
    {
        slay.push_back({ 0, j, 1 }); // U[0][j] = 1;
        B.push_back(u(X[0], Y[j]));
    }

    for (int j = 0; j <= n; j++)
    {
        slay.push_back({ 1, (n + 1) * n + j, 1 }); // U[n^2][j] = 1;
        B.push_back(u(X[n], Y[j]));
    }

    for (int i = 1; i < n; i++)
    {
        slay.push_back({ 2, (n + 1) * i, 1 }); // U[i][0] = 1;
        B.push_back(u(X[i], Y[0]));
    }

    for (int i = 1; i < n; i++)
    {
        slay.push_back({ 3, (n + 1) * i + n, 1 }); // U[i][n^2] = 1;
        B.push_back(u(X[i], Y[0]));
    }

    // уравнения
    for (int k = 4; k < n; k++)
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                slay.push_back({ k, (n + 1) * i + (j + 1), 1 }); // U[i][j + 1] = 1;
                slay.push_back({ k, (n + 1) * i + (j - 1), 1 }); // U[i][j - 1] = 1;
                slay.push_back({ k, (n + 1) * i + j, -4 });      // U[i][j] = 4;
                slay.push_back({ k, (n + 1) * (i - 1) + j, 1 }); // U[i + 1][j] = 1;
                slay.push_back({ k, (n + 1) * (i + 1) + j, 1 }); // U[i - 1][j] = 1;
                B.push_back(F(X[i], Y[j]));
            }
        }
    }
}

void SlaySolve(const double a, const double b, const int n = 300)
{
    std::vector<double> X(n + 1), Y(n + 1);
    SetkaX(a, b, n, X);
    SetkaX(a, b, n, Y);
    const double h = (b - a) / n;

    std::vector<SparseMatrixElement> A;
    std::vector<double> B;
    SLAY(A, B, X, Y, n); // СЛАУ
    // имеем матричное уравнение A*U = B, где A размером (n+1)^2 на (n+1)^2, а U - матрица значений фукнций (но развёрнута в вектор)

}


int main()
{
    //std::vector<std::vector<double>> A = { {14, 1, 0, 0}, {1, 12, 0, 0}, {0, 0, 19, 5}, {0, 0, 5, 13} };
    //std::vector<std::vector<double>> L = CholeskyDecomposition(A);

    //    //14  1  0  0
    //    //1  12  0  0
    //    //0  0  19  5
    //    //0  0  5  13
    //std::vector<SparseMatrixElement> B = { {0, 0, 14}, {0, 1, 1}, {1, 0, 1},
    //                                   {1, 1, 12}, {2, 2, 19}, {2, 3, 5},
    //                                   {3, 2, 5}, {3, 3, 13}};

    //std::vector<SparseMatrixElement> L = CholeskyDecompositionSparse(B);
    ////double eps = 1e-3;
    ////std::vector<std::vector<double>> L = IncompleteCholesky(B, eps);

    //// Вывод результата
    //for (const auto& a : L)
    //{
    //    std::cout << a.row << " " << a.col << " " << a.value << " - ";
    //}


    setlocale(LC_ALL, "Russian");
    int n = 4;
    double e = 1e-5;
    //double** A = CreateMatrix(n, n);
    //std::vector<std::vector<double>> A = std::vector<std::vector<double>>(n, std::vector<double>(n,0));
    double start = 1.0, end = 10.0;
    std::vector<SparseMatrixElement> A = FillRandomMatrix(n, start, end);

    std::vector<double> X_t(n);
    for (int i = 0; i < n; i++) X_t[i] = 1;

    std::vector<double> B = Mult(A, X_t);\

    std::vector<double> X0(n);
    for (int i = 0; i < n; i++) X0[i] = X_t[i] * Random(0.5, 0.8); // начальные данные отличаются от точного решения на 20 - 50 %

    std::cout << "А:" << std::endl;
    for (const auto& a : A)
        std::cout << "{ " << a.row << ", " << a.col << ", " << a.value << " }" << std::endl;

    std::cout << "В:" << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << B[i] << std::endl;

    std::cout << "Точное значение Х:" << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << X_t[i] << std::endl;

    std::cout << "Начальное приближение:" << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << X0[i] << std::endl;

    std::cout << "Метод сопряжённых градиентов:" << std::endl;
    std::vector<double> X = Gradient(A, B, X0, n, e);
    for (int i = 0; i < n; i++)
        std::cout << X[i] << std::endl;

    std::cout << "Метод сопряжённых градиентов c предобуславливателем:" << std::endl;
    X = GradientPreconditioned(A, B, X0, n, e);
    for (int i = 0; i < n; i++)
        std::cout << X[i] << std::endl;

    return 0;
}


//std::vector<std::vector<double>> CholeskyDecompositionSparse(const std::vector<SparseMatrixElement>& A)
//{
//     создаю матрицу L
//    const int size = A.back().row + 1; // последний диагональный элемент
//    std::vector<std::vector<double>> L(size, std::vector<double>(size, 0.0));
//
//    for (const auto& element : A)
//    {
//        if (element.col > element.row) continue; // считаем только до диагонали
//        double temp = 0.0;
//
//         Суммируем квадраты элементов, уже вычисленных для данной строки
//        for (int k = 0; k < element.row; k++)
//            temp += L[element.row][k] * L[element.col][k];
//
//         Находим значение диагонального элемента
//        if (element.row == element.col) 
//            L[element.row][element.col] = std::sqrt(element.value - temp);
//         Вычисляем значение элемента L
//        else 
//            L[element.row][element.col] = (element.value - temp) / L[element.col][element.col];
//    }
//
//    return L;
//}

//std::vector<std::vector<double>> IncompleteCholesky(const std::vector<SparseMatrixElement>& A, const double eps)
//{
//    // создаю матрицу L
//    const int size = A.back().row + 1; // последний диагональный элемент
//    std::vector<std::vector<double>> L(size, std::vector<double>(size, 0.0));
//
//    for (const auto& element : A)
//    {
//        if (element.col > element.row || element.value < eps) continue; // считаем только до диагонали
//        double temp = 0.0;
//
//        // Суммируем квадраты элементов, уже вычисленных для данной строки
//        for (int k = 0; k < element.row; k++)
//            temp += L[element.row][k] * L[element.col][k];
//
//        // Находим значение диагонального элемента
//        if (element.row == element.col)
//            L[element.row][element.col] = std::sqrt(element.value - temp);
//        // Вычисляем значение элемента L
//        else
//            L[element.row][element.col] = (element.value - temp) / L[element.col][element.col];
//    }
//
//    return L;
//}


//std::vector<std::vector<double>> CholeskyDecomposition(const std::vector<std::vector<double>>& A)
//{
//    std::vector<std::vector<double>> L(A.size(), std::vector<double>());
//
//    for (int i = 0; i < A.size(); i++)
//    {
//        L[i].resize(i + 1); // L - треугольная матрица, поэтому в i-ой строке i+1 элементов
//
//        double temp;
//        // Сначала вычисляем значения элементов слева от диагонального элемента,
//        // так как эти значения используются при вычислении диагонального элемента.
//        for (int j = 0; j < i; j++)
//        {
//            temp = 0;
//            for (int k = 0; k < j; k++)
//            {
//                temp += L[i][k] * L[j][k];
//            }
//            L[i][j] = (A[i][j] - temp) / L[j][j];
//        }
//
//        // Находим значение диагонального элемента
//        temp = A[i][i];
//        for (int k = 0; k < i; k++)
//        {
//            temp -= L[i][k] * L[i][k];
//        }
//        L[i][i] = std::sqrt(temp);
//    }
//
//    return L;
//}

//std::vector<std::vector<double>> CholeskyDecompositionSparse(const std::vector<std::vector<double>>& A)
//{
//    std::vector<std::vector<double>> L(A.size(), std::vector<double>());
//
//    for (int i = 0; i < A.size(); i++)
//    {
//        L[i].resize(i + 1); // L - треугольная матрица, поэтому в i-ой строке i+1 элементов
//
//        double temp;
//        // Сначала вычисляем значения элементов слева от диагонального элемента,
//        // так как эти значения используются при вычислении диагонального элемента.
//        for (int j = 0; j < i; j++)
//        {
//            temp = 0;
//            for (int k = 0; k < j; k++)
//            {
//                temp += L[i][k] * L[j][k];
//            }
//            L[i][j] = (A[i][j] - temp) / L[j][j];
//        }
//
//        // Находим значение диагонального элемента
//        temp = A[i][i];
//        for (int k = 0; k < i; k++)
//        {
//            temp -= L[i][k] * L[i][k];
//        }
//        L[i][i] = std::sqrt(temp);
//    }
//
//    return L;
//}


//std::vector<SparseMatrixElement> ConvertToSparseMatrix(double** A, int n)
//{
//    std::vector<SparseMatrixElement> sparseMatrix;
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            double value = A[i][j];
//            if (value != 0)
//            {
//                SparseMatrixElement element = { i, j, value };
//                sparseMatrix.push_back(element);
//            }
//        }
//    }
//
//    return sparseMatrix;
//}