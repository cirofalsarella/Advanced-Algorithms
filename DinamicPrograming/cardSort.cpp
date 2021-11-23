#include <iostream>

using namespace :: std;

#define MAX_CARDS 1000

int cards[MAX_CARDS];
int memo[MAX_CARDS];

int lis(int idx){
    int maxAt = 1;
    for (int i = 0; i < idx; i++) {
        if (cards[idx] > cards[i])
            maxAt = max(maxAt, memo[i] + 1);
    }

    return maxAt;
}

int main() {
    int nCards; cin >> nCards;

    for (int i=0; i<nCards; i++) {
        cin >> cards[i];
    }

    int maxLis = 0;
    for (int i=0; i<nCards; i++) {
        memo[i] = lis(i);
        maxLis = max(maxLis, memo[i]);
    }

    cout << nCards - maxLis << endl;

    return 0;
}