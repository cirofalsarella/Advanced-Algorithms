#include <iostream>
#include <cstring>

using namespace :: std;

#define MAX_STONE_NUM 1000000
#define MAX_REMOVAL_NUM 10

int memo[MAX_STONE_NUM + 10];
int removeAmmount[MAX_REMOVAL_NUM];
int n_removals;

bool win(int n_stones) {
    if (n_stones <= 0)  return false;

    if (memo[n_stones] != -1)   return (memo[n_stones] == 1);

    for (int i=0; i<n_removals; i++) {
        if (removeAmmount[i] > n_stones)    continue;

        if (!win(n_stones - removeAmmount[i])) {
            memo[n_stones] = 1;
            return true;
        }
    }

    memo[n_stones] = 0;
    return false;
}


int main() {
    int n_stones;

    while (cin >> n_stones >> n_removals) {
        memset(memo, -1, sizeof(memo));

        for (int i=0; i<n_removals; i++)
            cin >> removeAmmount[i];

        for (int i=0; i<n_stones; i++)
            win(i);

        if (win(n_stones)) {
            cout << "Stan wins" << endl;
        } else {
            cout << "Ollie wins" << endl;
        }
    }

    return 0;
}