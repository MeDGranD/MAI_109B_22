#include "../include/Matrix.hpp"

void Matrix::readingMatrix(const std::string &fileName)
{
    clearVectors();
    std::string a;
    std::ifstream fin(a = "../tests/alltests/" + fileName);
    if (!fin.is_open()) {
        std::cout << "File is not opened\n"
                  << std::endl;
        return;
    }
    int64_t numberOfRows = 0;
    int64_t numberOfColumns = 0;
    fin >> numberOfRows >> numberOfColumns;

    Item value;
    elementA push;
    for (int64_t i = 0; i < numberOfRows; ++i) {
        bool isFirstNonZero = true;
        for (int64_t j = 0; j < numberOfColumns; ++j) {
            fin >> value;
            if (value) {
                if (isFirstNonZero) {
                    M.push_back(A.size());
                    push.column = j;
                    push.value = value;
                    push.indexNext = 0;
                    A.push_back(push);
                    isFirstNonZero = false;
                    continue;
                }
                push.column = j;
                push.value = value;
                push.indexNext = 0;
                A.push_back(push);
                A[A.size() - 2].indexNext = j;
            }
        }

        if (isFirstNonZero) {
            M.push_back(-1);
        }
    }
}

void Matrix::multiplyMatrixByColumn(const std::string &fileName)
{
    std::ifstream fin("../tests/alltests/" + fileName);
    if (!fin.is_open()) {
        std::cout << "File is not opened\n"
                  << std::endl;
        return;
    }
    int64_t numberOfRows = 0;
    int64_t numberOfColumns = 0;
    fin >> numberOfRows >> numberOfColumns;
    fin.close();

    Vector<int64_t> vectorColumn;
    Item elem;
    std::cout << "Enter the required number of elements of the column" << std::endl;
    for (int64_t r = 0; r < numberOfColumns; ++r) {
        std::cin >> elem;
        vectorColumn.push_back(elem);
    }

    Item sum = 0;
    for (int64_t j = 0; j < M.size(); ++j) {
        if (M[j] == -1) {
            std::cout << "0" << std::endl;
            continue;
        }
        int64_t n = 0;
        while (true) {
            if (A[M[j] + n].indexNext == 0) {
                sum += vectorColumn[A[M[j] + n].column] * A[M[j] + n].value;
                break;
            }
            sum += vectorColumn[A[M[j] + n].column] * A[M[j] + n].value;
            ++n;
        }
        std::cout << sum << std::endl;
        sum = 0;
    }
}

void Matrix::printMatrix(const std::string& fileName)
{
    std::ifstream fin("../tests/alltests/" + fileName);
    if (!fin.is_open()) {
        std::cout << "File is not opened\n"
                  << std::endl;
        return;
    }
    int64_t numberOfRows = 0;
    int64_t numberOfColumns = 0;
    fin >> numberOfRows >> numberOfColumns;
    fin.close();

    int64_t n = 0;
    for (int64_t i = 0; i < numberOfRows; ++i) {
        if (M[i] == -1) {
            for (int64_t j = 0; j < numberOfColumns; ++j) {
                std::cout << "0 ";
            }
        }
        else {
            for (int64_t j = 0; j < numberOfColumns; ++j) {
                if (A[M[i]].column == j) {
                    std::cout << A[M[i]].value << " ";
                }
                else if (A[M[i] + n].indexNext == j && A[M[i]].column < A[M[i]].indexNext) {
                    std::cout << A[M[i] + n + 1].value << " ";
                    ++n;
                }
                else {
                    std::cout << "0 ";
                }
            }
            n = 0;
        }
        std::cout << std::endl;
    }
}

void Matrix::printA()
{
    for (int64_t i = 0; i < A.size(); ++i) {
        std::cout << A[i].column << " ";
        std::cout << A[i].value << " ";
        std::cout << A[i].indexNext << std::endl;
    }
}

void Matrix::printM()
{
    for (int64_t i = 0; i < M.size(); ++i) {
        std::cout << M[i] << " ";
    }
    std::cout << std::endl;
}

void Matrix::clearVectors()
{
    A.clear();
    M.clear();
}
