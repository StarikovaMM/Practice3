#include "histogram.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void show_histogram_text(const vector<size_t>& bins) {
    for (size_t i = 0; i < bins.size(); ++i) {
        cout << i << ": ";
        for (size_t j = 0; j < bins[i]; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}

void svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end() {
    cout << "</svg>\n";
}

void svg_text(double left, double baseline, string text) {
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>";
}

void svg_rect(double x, double y, double width, double height,
              string stroke = "black", string fill = "black") {
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' stroke='" << stroke << "' fill='" << fill << "' />";
}

void show_histogram_svg(const vector<size_t>& bins, const vector<string>& colors) {
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;

    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);

    double top = 0;
    for (size_t i = 0; i < bins.size(); i++) {
        const double bin_width = BLOCK_WIDTH * bins[i];
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bins[i]));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "black", colors[i]);
        top += BIN_HEIGHT;
    }

    svg_end();
}

int main() {
    size_t number_count;
    cout << "Enter number count: ";
    cin >> number_count;
    const auto numbers = input_numbers(number_count);

    size_t bin_count;
    cout << "Enter bin count: ";
    cin >> bin_count;

    vector<string> colors(bin_count);
    for (size_t i = 0; i < bin_count; i++) {
        colors[i] = input_color(i + 1);
    }

    const auto bins = make_histogram(numbers, bin_count);

    cout << "\nText Histogram:\n";
    show_histogram_text(bins);

    cout << "\nSVG Histogram:\n";
    show_histogram_svg(bins, colors);

    return 0;
}
