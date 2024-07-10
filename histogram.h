#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <vector>

using std::vector;

extern void find_minmax(const vector<double>& numbers, double& min, double& max);

vector<double> input_numbers(size_t count);

vector<size_t> make_histogram(const vector<double>& numbers, size_t bin_count);

#endif //HISTOGRAM_H
