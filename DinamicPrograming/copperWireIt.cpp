#include <iostream>
#include <cstring>

using namespace :: std;

#define MAX_COINS 100
#define MAX_VALUE 500
#define MAX_DIFF MAX_VALUE * MAX_COINS

int coins[MAX_COINS];
int memo[MAX_COINS+1][MAX_DIFF+1];

void solve(int n_coins) {
    // For every coin
    for (int i=1; i<=n_coins; i++) {
        // For every initial difference
        for (int j=0; j<MAX_DIFF; j++) {
            // Calculate the minimal final difference
            memo[i][j] = min(
                memo[i-1][abs(j-coins[i-1])],
                memo[i-1][abs(j+coins[i-1])]
            );
        }
    }
}

int main() {
    for (int i=0; i<MAX_DIFF; i++)  memo[0][i] = i;

    int n_cases;    cin >> n_cases;
    while (n_cases-- > 0) {
        // Read the coins
        int n_coins; cin >> n_coins;
        for (int i=0; i<n_coins; i++)   cin >> coins[i];
        
        // Calculate the vector
        solve(n_coins);

        // Calculate the min for initial diff 0 and all coins
        cout << memo[n_coins][0] << endl;
    }

    return 0;
}