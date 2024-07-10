#include "histogram.h"
#include <cassert>
#include <vector>

void test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}

void test_negative() {
    double min = 0;
    double max = 0;
    find_minmax({-3, -2, -1}, min, max);
    assert(min == -3);
    assert(max == -1);
}

void test_same_numbers() {
    double min = 0;
    double max = 0;
    find_minmax({2, 2, 2}, min, max);
    assert(min == 2);
    assert(max == 2);
}

void test_single_number() {
    double min = 0;
    double max = 0;
    find_minmax({42}, min, max);
    assert(min == 42);
    assert(max == 42);
}

void test_empty() {
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}

void test_inpur() {
    vector<double> numbers = {1, 2, 3, 4, 5};
    vector<size_t> expected = {2, 1, 2};
    vector<size_t> res = make_histogram(numbers, 3);
    assert(res == expected);
}

int main() {
    test_positive();
    test_negative();
    test_same_numbers();
    test_single_number();
    test_empty();
    test_inpur();

    return 0;
}
