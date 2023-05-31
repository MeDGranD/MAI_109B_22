#include "../include/Table.hpp"
template<typename T>
void Table<T>::push_back(const T &key, const std::string &input_data)
{
    keys.push_back(key);
    lines.push_back(input_data);
}
template<typename T>
void Table<T>::sort(const T &inf)
{
    size_t n;
    Vector<T> t_keys;
    Vector<std::string> t_lines;
    Vector<size_t> win_match;


    n = keys.size();
    if (n <= 1) {
        return;
    }
    t_keys.resize(n + 1);
    t_lines.resize(n + 1);
    win_match.resize(2 * n + 2);

    //creating TOURNAMENT tree
    for (size_t i = 0; i < n; ++i) {
        t_keys[i] = keys[i];
        t_lines[i] = lines[i];
        win_match[n + i] = i;
    }
    for (int64_t i = 2 * n - 1; i > 1; i -= 2) {
        int64_t winner_place = i / 2;
        win_match[winner_place] = winner(i, i - 1, n, win_match, t_keys);
    }


    keys[0] = t_keys[win_match[win_match[1]]];
    lines[0] = t_lines[win_match[win_match[1]]];
    t_keys[win_match[win_match[1]]] = inf;
    //end of creating TOURNAMENT tree
    for (size_t iteration = 1; iteration < n; ++iteration) {
        //rematching
        int64_t i = win_match[1];
        while (i > 1) {
            int64_t winner_place = i / 2;
            int64_t challenger;
            if (i % 2 == 0 && i < 2 * n - 1) {//if the index is even and is not the last in win_match, then its "rival" is on the odd index after it(i+1), otherwise before it(i-1)
                challenger = i + 1;
            }
            else {
                challenger = i - 1;
            }
            win_match[winner_place] = winner(i, challenger, n, win_match, t_keys);
            i = winner_place;
        }
        keys[iteration] = t_keys[win_match[win_match[1]]];
        lines[iteration] = t_lines[win_match[win_match[1]]];
        t_keys[win_match[win_match[1]]] = inf;
        //end of rematching
    }

}
template<typename T>
std::string Table<T>::search(const T &key, const T &inf)
{
    this->sort(inf);
    size_t left = 0, right = keys.size();
    while (left < right) {
        size_t middle = (left + right) / 2;
        if (keys[middle] < key) {
            left = middle + 1;
        }
        else if (keys[middle] > key) {
            right = middle;
        }
        else {
            return lines[middle];
        }
    }
    if (keys[left] == key) {
        return lines[left];
    }
    return "";
}
template<typename T>
std::ostream &operator<<(std::ostream &out, Table<T> &x)
{
    for (size_t y = 0; y < x.keys.size(); ++y) {
        out << x.keys[y] << " " << x.lines[y] << '\n';
    }
    out << '\n';
    return out;
}
template<typename T>
std::istream &operator>>(std::istream &in, Table<T> &x)
{
    int64_t o = 0;
    in >> o;

    for (int64_t y = 0; y < o; ++y) {
        T in_key;
        std::string in_data;
        in >> in_key >> in_data;
        x.push_back(in_key, in_data);
    }
    return in;
}
template<typename T>
size_t Table<T>::winner(const size_t pos_a, const size_t pos_b, const size_t n, Vector<size_t> &win_match, Vector<T> &t_keys)
{
    size_t u = pos_a >= n ? pos_a : win_match[pos_a];
    size_t v = pos_b >= n ? pos_b : win_match[pos_b];
    if (t_keys[win_match[u]] <= t_keys[win_match[v]]) return u;
    return v;
}
