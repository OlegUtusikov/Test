//
// Created by utusi on 08.05.19.
//

#include "Solver.h"
#include <algorithm>
#include <map>
#include <unordered_map>
#include <functional>

void Solver::swap_vectors(std::vector<int> &v1, std::vector<int> &v2) {
    if (v1.size() > v2.size()) {
        v1.swap(v2);
    }
}

size_t Solver::find_duplicates_by_tree(std::vector<int> &v1, std::vector<int> &v2) {
    swap_vectors(v1, v2);
    if (v1.empty()) {
        return 0;
    }
    std::map<int, bool> is_number;
    for(int i : v1) {
        is_number[i] = true;
    }
    size_t ans = 0;
    for(int i : v2) {
        if (is_number.find(i) != is_number.end()) {
            ++ans;
        }
    }
    return ans;
}

size_t Solver::find_duplicates_by_hash_table(std::vector<int> &v1, std::vector<int> &v2) {
    swap_vectors(v1, v2);
    if (v1.empty()) {
        return 0;
    }
    std::unordered_map<int, bool> is_number;
    for(int i : v1) {
        is_number[i] = true;
    }
    size_t ans = 0;
    for(int i : v2) {
        if (is_number.find(i) != is_number.end()) {
            ++ans;
        }
    }
    return ans;
}

size_t Solver::find_duplicates_by_binary_search(std::vector<int> &v1, std::vector<int> &v2) {
    swap_vectors(v1, v2);
    if (v1.empty()) {
        return 0;
    }
    std::sort(v1.begin(), v1.end());
    size_t ans = 0;
    for(int i : v2) {
        auto it = std::lower_bound(v1.begin(), v1.end(), i);
        if (it != v1.end() && (*it) == i) {
            ++ans;
        }
    }
    return ans;
}

size_t Solver::find_duplicates_by_my_hash_table(std::vector<int> &v1, std::vector<int> &v2) {
    swap_vectors(v1, v2);
    if (v1.empty()) {
        return 0;
    }
    size_t ans = 0;
    std::unordered_map<int, bool, std::function<size_t(const int& number)>> is_number(v1.size(),[](const int &number) {
        int key = number;
        key += ~(key << 16);
        key ^=  (key >>  5);
        key +=  (key <<  3);
        key ^=  (key >> 13);
        key += ~(key <<  9);
        key ^=  (key >> 17);
        return static_cast<size_t>(key);
    });
    for(int i : v1) {
        is_number[i] = true;
    }
    for(int i : v2) {
        if (is_number.count(i) > 0) {
            ++ans;
        }
    }
    return ans;
}
