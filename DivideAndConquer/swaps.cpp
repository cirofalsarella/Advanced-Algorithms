#include <iostream>
#include <cstring>

using namespace :: std;

long long int v[500099];

long long int merge(long long int inf, long long int mid, long long int sup) {
    long long int aux[sup-inf+1] = {0};

    long long int i = inf;
    long long int m = mid+1;
    long long int k = 0;
    long long int swaps = 0;

    while (i <= mid && m <= sup) {
        if (v[i] <= v[m]) {
            aux[k++] = v[i++];
        } else {
            swaps += (mid - i + 1);  // Restantes da lista esquerda
            aux[k++] = v[m++];
        }
    }
    while (i <= mid)
        aux[k++] = v[i++];
    while (m <= sup)
        aux[k++] = v[m++];



    i = inf; k = 0;
    while (i <= sup) {
        v[i++] = aux[k++];
    }

    return swaps;
}

long long int countSwaps(long long int inf, long long int sup) {
    if (inf == sup) return 0;

    long long int mid = (inf+sup)/2;

    long long int nSwaps = countSwaps(inf, mid);
    nSwaps += countSwaps(mid+1, sup);
    nSwaps += merge(inf, mid, sup);

    return nSwaps;
}

int main() {
    long long int n_values;
    cin >> n_values;

    while (n_values > 0) {
        // Read the new values
        for (long long int i=0; i<n_values; i++) {
            cin >> v[i];
        }

        cout << countSwaps(0, n_values-1) << endl;

        // Get the next amount of data
        cin >> n_values;
    }
}