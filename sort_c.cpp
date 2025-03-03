#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

const int MAX_ARRAY_SIZE = 1e6 + 10;
double numbers[MAX_ARRAY_SIZE];
long long totalNumbers;

void processFile(const string& filename) {
    ifstream inputFile(filename);

    vector<double> data;
    double value;
    while (inputFile >> value) {
        data.push_back(value);
    }
    inputFile.close();

    totalNumbers = data.size();
    for (long long i = 0; i < totalNumbers; i++) {
        numbers[i] = data[i];
    }

    auto start = high_resolution_clock::now();
    sort(numbers, numbers + totalNumbers);
    auto end = high_resolution_clock::now();

    double elapsedTimeMs = duration_cast<microseconds>(end - start).count() / 1000.0;
    cout << filename << ": " << fixed << setprecision(3) << elapsedTimeMs << " ms" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 1; i <= 10; i++) {
        string filename = "sequence_" + to_string(i) + ".txt";
        processFile(filename);
    }
    return 0;
}
