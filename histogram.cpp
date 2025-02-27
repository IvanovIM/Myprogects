#include <iostream>
#include <vector>

#include "histogram.h"

using namespace std;

void
find_minmax(const vector<double>& numbers, double& min, double& max) {
    min = numbers[0];
    max = numbers[0];

    for (double x : numbers) {
        if (x < min) {
            min = x;
        }
        else if (x > max) {
            max = x;
        }
    }
};

vector <size_t>
make_histogram(const vector<double> numbers, size_t bin_count){

    vector <size_t> bins(bin_count);
    double min, max;
    find_minmax(numbers, min, max);

    double bin_size = (max - min) / bin_count;

    for (size_t i = 0; i < numbers.size(); i++) {
        bool found = false;
        for (size_t j = 0; (j < bin_count - 1) && !found; j++) {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] < hi)) {
                bins[j]++;
                found = true;
            }
        }

        if (!found) {
            bins[bin_count - 1]++;
        }
    }

    return bins;
}
