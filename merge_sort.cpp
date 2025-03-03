#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

const int MAX_SIZE = 1e6 + 10;

double arr[MAX_SIZE];
long long dataSize;

void mergeArrays(long long left, long long mid, long long right) {
    long long size1 = mid - left + 1;
    long long size2 = right - mid;
    vector<double> leftPart(size1), rightPart(size2);

    for (long long i = 0; i < size1; i++)
        leftPart[i] = arr[left + i];
    for (long long i = 0; i < size2; i++)
        rightPart[i] = arr[mid + 1 + i];

    long long i = 0, j = 0, k = left;
    while (i < size1 && j < size2) {
        if (leftPart[i] <= rightPart[j]) {
            arr[k++] = leftPart[i++];
        } else {
            arr[k++] = rightPart[j++];
        }
    }

    while (i < size1) arr[k++] = leftPart[i++];
    while (j < size2) arr[k++] = rightPart[j++];
}

void mergeSort(long long left, long long right) {
    if (left >= right) return;
    long long mid = left + (right - left) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    mergeArrays(left, mid, right);
}

void processFile(const string& filename) {
    ifstream inputFile(filename);
    vector<double> tempData;
    double num;
  
    while (inputFile >> num) {
        tempData.push_back(num);
    }
    inputFile.close();

    dataSize = tempData.size();
  
    for (long long i = 0; i < dataSize; i++) {
        arr[i] = tempData[i];
    }

    auto start = high_resolution_clock::now();
    mergeSort(0, dataSize - 1);
    auto end = high_resolution_clock::now();

    double durationMs = duration_cast<microseconds>(end - start).count() / 1000.0;
    cout << filename << ": " << fixed << setprecision(3) << durationMs << " ms" << endl;
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
