//
// Created by utusi on 08.05.19.
//
#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
#include <map>
#include <unordered_map>
#include "Solver.h"
#include "gtest/gtest.h"
#include <climits>


int get_value(bool flag) {
    if (flag) {
        srand(time(nullptr));
    }
    return (rand() % INT_MAX) - INT_MAX / 4;
}

std::vector<int> get_vector(size_t size) {
    std::vector<int> res(size);
    std::unordered_map<int, bool> repeat;
    for(size_t i = 0; i < size; i++) {
        while(true) {
            int value = get_value(false);
            if (repeat.find(value) == repeat.end()) {
                res[i] = value;
                repeat[res[i]] = true;
                break;
            }
        }
    }
    return res;
}


std::vector<int> get_dif_vector(size_t size, bool flag) {
    std::vector<int> res(size);
    for(size_t i = 0; i < size; i++) {
        res[i] = (flag ? i : size - i - 1);
    }
    return res;
}

size_t expect(std::vector<int> &v1, std::vector<int> &v2) {
    std::unordered_map<int, bool> is_number;
    for(int i : v1) {
        is_number[i] = true;
    }
    int ans = 0;
    for(int i : v2) {
        if (is_number.find(i) != is_number.end()) {
            ++ans;
        }
    }
    return ans;
}

TEST (test_on_tree, first_test) {
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> v2 = {0, -1, 4, 6, 2};
    EXPECT_EQ(3, Solver::find_duplicates_by_tree(v1, v2));
}

TEST (test_on_tree_empty, random_test_for_0_0) {
    std::vector<int> v1 = get_vector(0);
    std::vector<int> v2 = get_vector(0);
    size_t ans = expect(v1, v2);
    EXPECT_EQ(ans, Solver::find_duplicates_by_tree(v1, v2));
}

TEST (test_on_tree_small, random_test_for_1_0) {
    std::vector<int> v1 = get_vector(1);
    std::vector<int> v2 = get_vector(0);
    size_t ans = expect(v1, v2);
    EXPECT_EQ(ans, Solver::find_duplicates_by_tree(v1, v2));
}

TEST (test_on_tree_middle, random_test_for_100_50) {
    std::vector<int> v1 = get_vector(100);
    std::vector<int> v2 = get_vector(50);
    size_t ans = expect(v1, v2);
    EXPECT_EQ(ans, Solver::find_duplicates_by_tree(v1, v2));
}

TEST (test_on_tree_middle, random_test_for_1000_100) {
    std::vector<int> v1 = get_vector(1000);
    std::vector<int> v2 = get_vector(100);
    size_t ans = expect(v1, v2);
    EXPECT_EQ(ans, Solver::find_duplicates_by_tree(v1, v2));
}

TEST (test_on_tree_large, random_test_for_1000_100000) {
    std::vector<int> v1 = get_vector(1000);
    std::vector<int> v2 = get_vector(100000);
    size_t ans = expect(v1, v2);
    double start = clock();
    EXPECT_EQ(ans, Solver::find_duplicates_by_tree(v1, v2));
    double finish = clock();
    std::cout << "Time is " << (finish - start) / (1.0 * CLOCKS_PER_SEC) << std::endl;
}

TEST (test_on_tree_large, random_test_for_1000000_1000000) {
    std::vector<int> v1 = get_vector(1000000);
    std::vector<int> v2 = get_vector(1000000);
    size_t ans = expect(v1, v2);
    double start = clock();
    EXPECT_EQ(ans, Solver::find_duplicates_by_tree(v1, v2));
    double finish = clock();
    std::cout << "Time is " << (finish - start) / (1.0 * CLOCKS_PER_SEC) << std::endl;
}

TEST (test_on_tree_extra_large, random_test_for_10000000_100000) {
    std::vector<int> v1 = get_vector(10000000);
    std::vector<int> v2 = get_vector(100000);
    size_t ans = expect(v1, v2);
    double start = clock();
    EXPECT_EQ(ans, Solver::find_duplicates_by_tree(v1, v2));
    double finish = clock();
    std::cout << "Time is " << (finish - start) / (1.0 * CLOCKS_PER_SEC) << std::endl;
}

TEST (test_on_tree_unreal, random_test_for_10000000_1000000) {
    std::vector<int> v1 = get_vector(10000000);
    std::vector<int> v2 = get_vector(1000000);
    size_t ans = expect(v1, v2);
    double start = clock();
    EXPECT_EQ(ans, Solver::find_duplicates_by_tree(v1, v2));
    double finish = clock();
    std::cout << "Time is " << (finish - start) / (1.0 * CLOCKS_PER_SEC) << std::endl;
}

// ---------------------------------------------------------------------------------

TEST (test_on_hash, first_test) {
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> v2 = {0, -1, 4, 6, 2};
    EXPECT_EQ(3, Solver::find_duplicates_by_hash_table(v1, v2));
}

TEST (test_on_hash_empty, random_test_for_0_0) {
    std::vector<int> v1 = get_vector(0);
    std::vector<int> v2 = get_vector(0);
    size_t ans = expect(v1, v2);
    EXPECT_EQ(ans, Solver::find_duplicates_by_hash_table(v1, v2));
}

TEST (test_on_hash_small, random_test_for_1_0) {
    std::vector<int> v1 = get_vector(1);
    std::vector<int> v2 = get_vector(0);
    size_t ans = expect(v1, v2);
    EXPECT_EQ(ans, Solver::find_duplicates_by_hash_table(v1, v2));
}

TEST (test_on_hash_middle, random_test_for_100_50) {
    std::vector<int> v1 = get_vector(100);
    std::vector<int> v2 = get_vector(50);
    size_t ans = expect(v1, v2);
    EXPECT_EQ(ans, Solver::find_duplicates_by_hash_table(v1, v2));
}

TEST (test_on_hash_middle, random_test_for_1000_100) {
    std::vector<int> v1 = get_vector(1000);
    std::vector<int> v2 = get_vector(100);
    size_t ans = expect(v1, v2);
    EXPECT_EQ(ans, Solver::find_duplicates_by_hash_table(v1, v2));
}

TEST (test_on_hash_large, random_test_for_1000_100000) {
    std::vector<int> v1 = get_vector(1000);
    std::vector<int> v2 = get_vector(100000);
    size_t ans = expect(v1, v2);
    double start = clock();
    EXPECT_EQ(ans, Solver::find_duplicates_by_hash_table(v1, v2));
    double finish = clock();
    std::cout << "Time is " << (finish - start) / (1.0 * CLOCKS_PER_SEC) << std::endl;
}

TEST (test_on_hash_large, random_test_for_1000000_1000000) {
    std::vector<int> v1 = get_vector(1000000);
    std::vector<int> v2 = get_vector(1000000);
    size_t ans = expect(v1, v2);
    double start = clock();
    EXPECT_EQ(ans, Solver::find_duplicates_by_hash_table(v1, v2));
    double finish = clock();
    std::cout << "Time is " << (finish - start) / (1.0 * CLOCKS_PER_SEC) << std::endl;
}

TEST (test_on_hash_extra_large, random_test_for_10000000_100000) {
    std::vector<int> v1 = get_vector(10000000);
    std::vector<int> v2 = get_vector(100000);
    size_t ans = expect(v1, v2);
    double start = clock();
    EXPECT_EQ(ans, Solver::find_duplicates_by_hash_table(v1, v2));
    double finish = clock();
    std::cout << "Time is " << (finish - start) / (1.0 * CLOCKS_PER_SEC) << std::endl;
}

TEST (test_on_hash_unreal, random_test_for_10000000_1000000) {
    std::vector<int> v1 = get_vector(10000000);
    std::vector<int> v2 = get_vector(1000000);
    size_t ans = expect(v1, v2);
    double start = clock();
    EXPECT_EQ(ans, Solver::find_duplicates_by_hash_table(v1, v2));
    double finish = clock();
    std::cout << "Time is " << (finish - start) / (1.0 * CLOCKS_PER_SEC) << std::endl;
}

// ---------------------------------------------------------------------------------

TEST (test_on_binary_search, first_test) {
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> v2 = {0, -1, 4, 6, 2};
    EXPECT_EQ(3, Solver::find_duplicates_by_binary_search(v1, v2));
}

TEST (test_on_binary_search_empty, random_test_for_0_0) {
    std::vector<int> v1 = get_vector(0);
    std::vector<int> v2 = get_vector(0);
    size_t ans = expect(v1, v2);
    EXPECT_EQ(ans, Solver::find_duplicates_by_binary_search(v1, v2));
}

TEST (test_on_binary_search_small, random_test_for_1_0) {
    std::vector<int> v1 = get_vector(1);
    std::vector<int> v2 = get_vector(0);
    size_t ans = expect(v1, v2);
    EXPECT_EQ(ans, Solver::find_duplicates_by_binary_search(v1, v2));
}

TEST (test_on_binary_search_middle, random_test_for_100_50) {
    std::vector<int> v1 = get_vector(100);
    std::vector<int> v2 = get_vector(50);
    size_t ans = expect(v1, v2);
    EXPECT_EQ(ans, Solver::find_duplicates_by_binary_search(v1, v2));
}

TEST (test_on_binary_search_middle, random_test_for_1000_100) {
    std::vector<int> v1 = get_vector(1000);
    std::vector<int> v2 = get_vector(100);
    size_t ans = expect(v1, v2);
    EXPECT_EQ(ans, Solver::find_duplicates_by_binary_search(v1, v2));
}

TEST (test_on_binary_search_large, random_test_for_1000_100000) {
    std::vector<int> v1 = get_vector(1000);
    std::vector<int> v2 = get_vector(100000);
    size_t ans = expect(v1, v2);
    double start = clock();
    EXPECT_EQ(ans, Solver::find_duplicates_by_binary_search(v1, v2));
    double finish = clock();
    std::cout << "Time is " << (finish - start) / (1.0 * CLOCKS_PER_SEC) << std::endl;
}

TEST (test_on_binary_search_large, random_test_for_1000000_1000000) {
    std::vector<int> v1 = get_vector(1000000);
    std::vector<int> v2 = get_vector(1000000);
    size_t ans = expect(v1, v2);
    double start = clock();
    EXPECT_EQ(ans, Solver::find_duplicates_by_binary_search(v1, v2));
    double finish = clock();
    std::cout << "Time is " << (finish - start) / (1.0 * CLOCKS_PER_SEC) << std::endl;
}

TEST (test_on_binary_search_extra_large, random_test_for_10000000_100000) {
    std::vector<int> v1 = get_vector(10000000);
    std::vector<int> v2 = get_vector(100000);
    size_t ans = expect(v1, v2);
    double start = clock();
    EXPECT_EQ(ans, Solver::find_duplicates_by_binary_search(v1, v2));
    double finish = clock();
    std::cout << "Time is " << (finish - start) / (1.0 * CLOCKS_PER_SEC) << std::endl;
}

TEST (test_on_binary_search_unreal, random_test_for_10000000_1000000) {
    std::vector<int> v1 = get_vector(10000000);
    std::vector<int> v2 = get_vector(1000000);
    size_t ans = expect(v1, v2);
    double start = clock();
    EXPECT_EQ(ans, Solver::find_duplicates_by_binary_search(v1, v2));
    double finish = clock();
    std::cout << "Time is " << (finish - start) / (1.0 * CLOCKS_PER_SEC) << std::endl;
}

// ---------------------------------------------------------------------------------

TEST (test_on_my_hash, first_test) {
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> v2 = {0, -1, 4, 6, 2};
    EXPECT_EQ(3, Solver::find_duplicates_by_my_hash_table(v1, v2));
}

TEST (test_on_my_hash_empty, random_test_for_0_0) {
    std::vector<int> v1 = get_vector(0);
    std::vector<int> v2 = get_vector(0);
    size_t ans = expect(v1, v2);
    EXPECT_EQ(ans, Solver::find_duplicates_by_my_hash_table(v1, v2));
}

TEST (test_on_my_hash_small, random_test_for_1_0) {
    std::vector<int> v1 = get_vector(1);
    std::vector<int> v2 = get_vector(0);
    size_t ans = expect(v1, v2);
    EXPECT_EQ(ans, Solver::find_duplicates_by_my_hash_table(v1, v2));
}

TEST (test_on_my_hash_middle, random_test_for_100_50) {
    std::vector<int> v1 = get_vector(100);
    std::vector<int> v2 = get_vector(50);
    size_t ans = expect(v1, v2);
    EXPECT_EQ(ans, Solver::find_duplicates_by_my_hash_table(v1, v2));
}

TEST (test_on_my_hash_middle, random_test_for_1000_100) {
    std::vector<int> v1 = get_vector(1000);
    std::vector<int> v2 = get_vector(100);
    size_t ans = expect(v1, v2);
    EXPECT_EQ(ans, Solver::find_duplicates_by_my_hash_table(v1, v2));
}

TEST (test_on_my_hash_large, random_test_for_1000_100000) {
    std::vector<int> v1 = get_vector(1000);
    std::vector<int> v2 = get_vector(100000);
    size_t ans = expect(v1, v2);
    double start = clock();
    EXPECT_EQ(ans, Solver::find_duplicates_by_my_hash_table(v1, v2));
    double finish = clock();
    std::cout << "Time is " << (finish - start) / (1.0 * CLOCKS_PER_SEC) << std::endl;
}

TEST (test_on_my_hash_large, random_test_for_1000000_1000000) {
    std::vector<int> v1 = get_vector(1000000);
    std::vector<int> v2 = get_vector(1000000);
    size_t ans = expect(v1, v2);
    double start = clock();
    EXPECT_EQ(ans, Solver::find_duplicates_by_my_hash_table(v1, v2));
    double finish = clock();
    std::cout << "Time is " << (finish - start) / (1.0 * CLOCKS_PER_SEC) << std::endl;
}

TEST (test_on_my_hash_extra_large, random_test_for_10000000_100000) {
    std::vector<int> v1 = get_vector(10000000);
    std::vector<int> v2 = get_vector(100000);
    size_t ans = expect(v1, v2);
    double start = clock();
    EXPECT_EQ(ans, Solver::find_duplicates_by_my_hash_table(v1, v2));
    double finish = clock();
    std::cout << "Time is " << (finish - start) / (1.0 * CLOCKS_PER_SEC) << std::endl;
}

TEST (test_on_my_hash_unreal, random_test_for_10000000_1000000) {
    std::vector<int> v1 = get_vector(10000000);
    std::vector<int> v2 = get_vector(1000000);
    size_t ans = expect(v1, v2);
    double start = clock();
    EXPECT_EQ(ans, Solver::find_duplicates_by_my_hash_table(v1, v2));
    double finish = clock();
    std::cout << "Time is " << (finish - start) / (1.0 * CLOCKS_PER_SEC) << std::endl;
}

// ---------------------------------------------------------------------------------

TEST(test_on_copies, size_10) {
    const int value = get_value(true);
    std::vector<int> v1(10, value);
    std::vector<int> v2(10, value);
    EXPECT_EQ(10, Solver::find_duplicates_by_tree(v1, v2));
    EXPECT_EQ(10, Solver::find_duplicates_by_hash_table(v1, v2));
    EXPECT_EQ(10, Solver::find_duplicates_by_binary_search(v1, v2));
    EXPECT_EQ(10, Solver::find_duplicates_by_my_hash_table(v1, v2));
}

TEST(test_on_copies, size_10000) {
    const int value = get_value(true);
    std::vector<int> v1(10000, value);
    std::vector<int> v2(10000, value);
    EXPECT_EQ(10000, Solver::find_duplicates_by_tree(v1, v2));
    EXPECT_EQ(10000, Solver::find_duplicates_by_hash_table(v1, v2));
    EXPECT_EQ(10000, Solver::find_duplicates_by_binary_search(v1, v2));
    EXPECT_EQ(10000, Solver::find_duplicates_by_my_hash_table(v1, v2));
}

TEST(test_on_copies, size_1000000) {
    const int value = get_value(true);
    std::vector<int> v1(1000000, value);
    std::vector<int> v2(1000000, value);
    EXPECT_EQ(1000000, Solver::find_duplicates_by_tree(v1, v2));
    EXPECT_EQ(1000000, Solver::find_duplicates_by_hash_table(v1, v2));
    EXPECT_EQ(1000000, Solver::find_duplicates_by_binary_search(v1, v2));
    EXPECT_EQ(1000000, Solver::find_duplicates_by_my_hash_table(v1, v2));
}

TEST(test_on_copies, size_10000000) {
    const int value = get_value(true);
    std::vector<int> v1(10000000, value);
    std::vector<int> v2(10000000, value + 1);
    EXPECT_EQ(0, Solver::find_duplicates_by_tree(v1, v2));
    EXPECT_EQ(0, Solver::find_duplicates_by_hash_table(v1, v2));
    EXPECT_EQ(0, Solver::find_duplicates_by_binary_search(v1, v2));
    EXPECT_EQ(0, Solver::find_duplicates_by_my_hash_table(v1, v2));
}

// ---------------------------------------------------------------------------------

TEST(test_on_incorrect_input, first) {
    std::vector<int> v1 = {1, 1, 2, 2};
    std::vector<int> v2 = {1, 1, 2};
    EXPECT_NE(2, Solver::find_duplicates_by_tree(v1, v2));
    EXPECT_NE(2, Solver::find_duplicates_by_hash_table(v1, v2));
    EXPECT_NE(2, Solver::find_duplicates_by_binary_search(v1, v2));
    EXPECT_NE(2, Solver::find_duplicates_by_my_hash_table(v1, v2));
}

TEST(test_on_incorrect_input, second) {
    std::vector<int> v1 = {0, 0, 0, 1, 1, 2};
    std::vector<int> v2 = {1, 0, 2, 0};
    EXPECT_NE(3, Solver::find_duplicates_by_tree(v1, v2));
    EXPECT_NE(3, Solver::find_duplicates_by_hash_table(v1, v2));
    EXPECT_NE(3, Solver::find_duplicates_by_binary_search(v1, v2));
    EXPECT_NE(3, Solver::find_duplicates_by_my_hash_table(v1, v2));
}

