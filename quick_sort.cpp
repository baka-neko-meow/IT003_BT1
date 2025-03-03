#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

const int MAX_LEN = 1e6 + 10;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
double arr[MAX_LEN];
long long sizeArr;

long long getRandomIndex(long long left, long long right) {
    return rng() % (right - left + 1) + left;
}

void quickSort(long long left, long long right) {
    if (left >= right) return;

    long long pivotIndex = getRandomIndex(left, right);
    swap(arr[pivotIndex], arr[right]);
    long long pivot = right, i = left, j = right - 1;

    while (i <= j) {
        while (i <= j && arr[i] <= arr[pivot]) i++;
        while (i <= j && arr[j] > arr[pivot]) j--;
        if (i <= j) swap(arr[i++], arr[j--]);
    }

    swap(arr[pivot], arr[i]);
    quickSort(left, i - 1);
    quickSort(i + 1, right);
}

void processFile(const string& filename) {
    vector<double> tempData;
    double num;
    while (inputFile >> num) {
        tempData.push_back(num);
    }
    inputFile.close();

    sizeArr = tempData.size();
  
    for (long long i = 0; i < sizeArr; i++) {
        arr[i] = tempData[i];
    }

    auto start = high_resolution_clock::now();
    quickSort(0, sizeArr - 1);
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
