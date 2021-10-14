#include <iostream>
#include <cstring>

#include <set>
#include <algorithm>

using namespace :: std;

int v[50010];


int calculate(int bot, int top, int min) {
    return (top - bot + 1) * min;
}

int subarray(set<pair<int,int>> &a, int bot, int top) {
    if (a.size() == 0) return 0;

    // The lowest value is the min (take and remove)
    pair<int,int> min = *(a.begin());
    a.erase({min.first, min.second});

    // Break the array
    set<pair<int, int>> left;
    for (int i=bot; i < min.second; i++) {
        pair<int, int> aux = {v[i], i};
        left.insert(aux);
        a.erase(aux);
    }

    // Call subarray for both sides
    int down = subarray(left, bot, min.second-1);
    int up = subarray(a, min.second+1, top);

    // Calculate value from current array
    int full = calculate(bot, top, min.first);

    // Return the biggest value from the three
    return max(full, max(up, down));
}

int main() {
    int n;  cin >> n;
    
    set<pair<int, int>> a;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        a.insert({v[i], i});
    }

    cout << subarray(a, 0, n-1);

    return 0;
}
