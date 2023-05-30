#include <memory>
#include "iostream"
#include "../include/Matrix.hpp"

Matrix::Matrix() {
    mat = Vector<int64_t>({0, 0});
    line_beginnings = Vector<size_t>();
}

std::istream &operator>>(std::istream &in, Matrix &a) {
    a.mat.pop_back();
    size_t m, n;
    int64_t value, m_i, n_i;
    in >> m_i >> n_i;
    m = (m_i < 0 ? 0 : m_i);
    n = (n_i < 0 ? 0 : n_i);
    a.m_sz = m;
    a.n_sz = n;
    a.line_beginnings.resize(a.m_sz + 1);
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            in >> value;
            if (value != 0) {
                if (a.mat.back() == 0) {
                    a.mat.push_back(i + 1);
                    a.line_beginnings[i + 1] = a.mat.size() - 1;
                }
                a.mat.push_back(j + 1);
                a.mat.push_back(value);
            }
        }
        if (a.mat.back() != 0) {
            a.mat.push_back(0);
        }
    }
    a.mat.push_back(0);
    return in;
}
std::ostream &operator<<(std::ostream &out, Matrix &a) {
    for (size_t i = 0; i < a.mat.size(); ++i) {
        out << a.mat[i] << "\t";
    }
    return out;
}

void Matrix::print() const {
    size_t row = 1, col = 1;
    for (size_t i = 0; i < mat.size(); ++i) {
        if (!mat[i]) {
            ++i;
            if (!mat[i]) {
                while (row <= m_sz) {
                    while (col <= n_sz) {
                        ++col;
                        std::cout << 0 << "\t";
                    }
                    std::cout << '\n';
                    ++row;
                    col = 1;
                }
                return;
            }
            while (row < mat[i]) {
                while (col <= n_sz) {
                    ++col;
                    std::cout << 0 << "\t";
                }
                std::cout << '\n';
                ++row;
                col = 1;
            }
        } else {
            while (col != mat[i]) {
                ++col;
                std::cout << 0 << "\t";
            }
            ++col;
            ++i;
            std::cout << mat[i] << "\t";
        }
    }
}

void Matrix::transpose() {
    Vector<int64_t> new_mat = Vector<int64_t>({0});
    Vector<size_t> new_line_beginnings = Vector<size_t>();
    new_line_beginnings.resize(n_sz + 1);

    for (size_t j = n_sz; j > 0; --j) {
        new_mat.push_back(n_sz - j + 1);

        bool line_has_elem = false;
        for (size_t i = m_sz; i > 0; --i) {

            size_t pos = line_beginnings[i];
            // search for element which has coords (i, j) in old mat
            if (pos != 0 and mat[pos] == i) {
                if (new_line_beginnings[n_sz - j + 1] == 0) {
                    new_line_beginnings[n_sz - j + 1] = new_mat.size() - 1;
                }

                ++pos;
                while (mat[pos] != 0) {
                    if (mat[pos] == j) {
                        // congrats! we found this element
                        ++pos;
                        new_mat.push_back(m_sz - i + 1);
                        new_mat.push_back(mat[pos]);
                        line_has_elem = true;
                        break;
                    }
                    pos += 2;
                }
            }
        }
        if (!line_has_elem) {
            new_mat.pop_back();
            new_line_beginnings[n_sz - j + 1] = 0;
            continue;
        }
        new_mat.push_back(0);
    }
    new_mat.push_back(0);
    std::swap(n_sz, m_sz);
    mat = new_mat;
    line_beginnings = new_line_beginnings;
}

// matrix is skew symmetric when A_transposed[i][j] == -A[i][j] for all elements
bool Matrix::is_skew_symmetric() const {
    if (m_sz != n_sz) return false;

    Vector<int64_t> new_mat = Vector<int64_t>({0});
    Vector<size_t> new_line_beginnings = Vector<size_t>();
    new_line_beginnings.resize(n_sz + 1);

    for (size_t j = 1; j <= n_sz; ++j) {
        new_mat.push_back(j);

        bool line_has_elem = false;
        for (size_t i = 1; i <= m_sz; ++i) {

            size_t pos = line_beginnings[i];
            // search for elem which has coords (i, j) in old mat
            if (pos != 0 and mat[pos] == i) {
                if (new_line_beginnings[j] == 0) {
                    new_line_beginnings[j] = new_mat.size() - 1;
                }

                ++pos;
                while (mat[pos] != 0) {
                    if (mat[pos] == j) {
                        ++pos;
                        // congrats! we found this element
                        new_mat.push_back(i);
                        new_mat.push_back(mat[pos]);
                        line_has_elem = true;
                        break;
                    }
                    pos += 2;
                }
            }
        }
        if (!line_has_elem) {
            new_mat.pop_back();
            new_line_beginnings[j] = 0;
            continue;
        }
        new_mat.push_back(0);
    }
    new_mat.push_back(0);

    for (size_t i = 1; i <= m_sz; ++i) {
        if (line_beginnings[i] == 0) continue;

        size_t pos = line_beginnings[i] + 1;
        while (true) {
            if (mat[pos] == 0) break;
            ++pos;
            // main check if matrix is not skew symmetric
            if (mat[pos] != -new_mat[pos]) return false;
            ++pos;
        }
    }
    return true;
}

size_t Matrix::get_m_sz() const {
    return m_sz;
}

size_t Matrix::get_n_sz() const {
    return n_sz;
}
