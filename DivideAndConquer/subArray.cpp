#include <iostream>
#include <cstring>
#include <set>

using namespace :: std;

int v[50010];

int calculate(int bot, int top, int min) {
    return (top - bot + 1) * min;
}

int subarray(int bot, int top) {
    if (bot >= top) return v[bot];

    // Break the array on the lowest value
    int min_pos = bot;
    for (int i=bot+1; i<=top; i++) {
        if (v[i] < v[min_pos])  min_pos = i;
    }

    // Call subarray for both sides
    int down = subarray(bot, min_pos-1);
    int up = subarray(min_pos+1, top);

    // Calculate value from current array
    int full = calculate(bot, top, v[min_pos]);

    // Return the biggest value from the three
    return max(full, max(up, down));
}

int main() {
    int n;  cin >> n;
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }

    cout << subarray(0, n-1);

    return 0;
}
