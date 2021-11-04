#include <iostream>
#include <cstring>

using namespace :: std;

int coins[100];
int memo[100][500];


int solve (int diff, int remainingCoins) {
    if (remainingCoins == -1)               return diff;
    if (memo[remainingCoins][diff] != -1)   return memo[remainingCoins][diff];

    memo[remainingCoins][diff] = min(
        solve(abs(diff + coins[remainingCoins]), remainingCoins-1),
        solve(abs(diff - coins[remainingCoins]), remainingCoins-1)
    );

    return memo[remainingCoins][diff];
}

int main() {
    int n_cases;    cin >> n_cases;

    while (n_cases-- > 0) {
        memset(memo, -1, sizeof(memo));
        memset(coins, 0, sizeof(coins));
        int n_coins; cin >> n_coins;
        
        for (int i=0; i<n_coins; i++) {
            cin >> coins[i];
        }

        for (int i=0; i<10; i++) {
            for (int j=0; j<n_coins; j++) {
                solve(i, j);
            }
        }

        cout << solve(0, n_coins-1) << endl;

    }

    return 0;
}