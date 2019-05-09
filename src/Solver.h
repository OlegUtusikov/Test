//
// Created by utusi on 08.05.19.
//

#pragma once
#include <iostream>
#include <vector>

class Solver {
public:
    static size_t find_duplicates_by_tree(std::vector<int> &v1, std::vector<int> &v2);
    static size_t find_duplicates_by_hash_table(std::vector<int> &v1, std::vector<int> &v2);
    static size_t find_duplicates_by_binary_search(std::vector<int> &v1, std::vector<int> &v2);
    static size_t find_duplicates_by_my_hash_table(std::vector<int> &v1, std::vector<int> &v2);

private:
    static void swap_vectors(std::vector<int> &v1, std::vector<int> &v2);
};

