#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

const int N = 1e6 + 10; // max

vector<double> a; 


void build(int size, int root) {
    int u = root;
    int l = 2 * root + 1;
    int r = 2 * root + 2;
    if (l < size && a[l] > a[u]) u = l;
    if (r < size && a[r] > a[u]) u = r;
    if (u != root) {
        swap(a[u], a[root]);
        build(size, u);
    }
}


void heap_sort() {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        build(n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        build(i, 0);
    }
}


void processFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: Cannot open file " << filename << endl;
        return;
    }

    a.clear(); 
    double num;
    while (inputFile >> num) {
        a.push_back(num);
    }
    inputFile.close();

    auto start = high_resolution_clock::now(); 
    heap_sort();
    auto end = high_resolution_clock::now(); 
    
    cout << filename << ": " 
         << duration_cast<microseconds>(end - start).count() 
         << " µs" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i <= 10; i++) {
        string filename = "sequence_" + to_string(i) + ".txt";
        processFile(filename);
    }
    
    return 0;
}
