#include "../include/Matrix.hpp"

Matrix::Matrix()
{
    matrix_in_line.push_back(0);
    matrix_in_line.push_back(0);
    msz = 0;
    nsz = 0;
}
std::istream &operator>>(std::istream &in, Matrix &x)
{
    x.matrix_in_line.pop_back();
    size_t m, n;
    int64_t insert_values, m_i, n_i;
    in >> m_i >> n_i;
    m = (m_i < 0 ? 0 : m_i);
    n = (n_i < 0 ? 0 : n_i);
    x.msz = m;
    x.nsz = n;
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) {
            in >> insert_values;
            if (insert_values != 0) {
                if (x.matrix_in_line.back() == 0) {
                    x.matrix_in_line.push_back(i + 1);
                }
                x.matrix_in_line.push_back(j + 1);
                x.matrix_in_line.push_back(insert_values);
            }
        }
        if (x.matrix_in_line.back() != 0) {
            x.matrix_in_line.push_back(0);
        }
    }
    x.matrix_in_line.push_back(0);
    return in;
}
std::ostream &operator<<(std::ostream &out, Matrix &x)
{
    for (size_t y = 0; y < x.matrix_in_line.size(); y++) {
        out << x.matrix_in_line[y] << " ";
    }
    return out;
}
void Matrix::divide(int64_t &cur_max_column, int64_t &max_elem)
{
    int64_t elem_from_div = 0;
    Vector<int64_t> temp_vector;

    for (size_t y = 0; y < matrix_in_line.size(); ++y) {
        if (!matrix_in_line[y]) {
            if (y != 0 && !temp_vector[temp_vector.size() - 2]) {
                temp_vector.pop_back();
                temp_vector.pop_back();
            }
            temp_vector.push_back(0);
            ++y;
            temp_vector.push_back(matrix_in_line[y]);
        }
        else if (matrix_in_line[y] == cur_max_column) {
            temp_vector.push_back(matrix_in_line[y]);
            ++y;
            elem_from_div = matrix_in_line[y] / max_elem;
            if (elem_from_div == 0) {
                temp_vector.pop_back();
            }
            else {
                temp_vector.push_back(elem_from_div);
            }
        }
        else {
            temp_vector.push_back(matrix_in_line[y]);
            ++y;
            temp_vector.push_back(matrix_in_line[y]);
        }
    }

    matrix_in_line.clear();
    for (size_t i = 0; i < temp_vector.size(); ++i) {
        matrix_in_line.push_back(temp_vector[i]);
    }
}
void Matrix::normalization()
{
    int64_t cur_max_column = 0, prev_max_column = 0, cur_column = 0, max_elem = 0, mod_max_elem = 0;
    for (size_t y = 0; y < matrix_in_line.size(); ++y) {
        if (!matrix_in_line[y]) {
            ++y;
            if (!matrix_in_line[y]) {
                break;
            }
        }
        else {
            cur_column = matrix_in_line[y];
            ++y;
            if (mod_max_elem < std::abs(matrix_in_line[y])) {
                max_elem = matrix_in_line[y];
                mod_max_elem = std::abs(matrix_in_line[y]);
                prev_max_column = 0;
                cur_max_column = cur_column;
            }
            else if (mod_max_elem == std::abs(matrix_in_line[y])) {
                prev_max_column = cur_max_column;
                cur_max_column = cur_column;
                max_elem = matrix_in_line[y];
            }
        }
    }
    cur_max_column = (prev_max_column != 0 ? prev_max_column : cur_max_column);
    divide(cur_max_column, max_elem);
}

void Matrix::print()
{
    size_t row = 1, column = 1;
    for (size_t y = 0; y < matrix_in_line.size(); ++y) {

        if (!matrix_in_line[y]) {
            ++y;
            if (!matrix_in_line[y]) {
                while (row <= msz) {
                    while (column <= nsz) {
                        column++;
                        std::cout << 0 << " ";
                    }
                    std::cout << '\n';
                    row++;
                    column = 1;
                }
                return;
            }
            while (row < matrix_in_line[y]) {
                while (column <= nsz) {
                    column++;
                    std::cout << 0 << " ";
                }
                std::cout << '\n';
                row++;
                column = 1;
            }
        }
        else {
            while (column != matrix_in_line[y]) {
                column++;
                std::cout << 0 << " ";
            }
            ++y;
            column++;
            std::cout << matrix_in_line[y] << " ";
        }
    }
}
