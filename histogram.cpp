#include "histogram.h"
#include <iostream>

void find_minmax(const vector<double>& numbers, double& min, double& max) {
    if (numbers.empty()) return;
    min = numbers[0];
    max = numbers[0];
    for (double number : numbers) {
        if (number < min) {
            min = number;
        }
        if (number > max) {
            max = number;
        }
    }
}

vector<double> input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        std::cin >> result[i];
    }
    return result;
}

vector<size_t> make_histogram(const vector<double>& numbers, size_t bin_count) {
    double min, max;
    find_minmax(numbers, min, max);
    vector<size_t> bins(bin_count);
    for (double number : numbers) {
        size_t bin = static_cast<size_t>((number - min) / (max - min) * bin_count);
        if (bin == bin_count) {
            bin--;
        }
        bins[bin]++;
    }
    return bins;
}
