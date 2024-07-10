#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <vector>
#include <string>

using std::vector;
using std::string;

extern void find_minmax(const vector<double>& numbers, double& min, double& max);

vector<double> input_numbers(size_t count);

vector<size_t> make_histogram(const vector<double>& numbers, size_t bin_count);

string input_color(size_t bin_number);

#endif //HISTOGRAM_H
