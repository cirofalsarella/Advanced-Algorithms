#include <iostream>
#include <vector>

using namespace :: std;

#define MAX_LEN 1000

int memo[MAX_LEN+1][MAX_LEN+1];

int lcs(string needle, string haystack) {
    int maxLCS = 0;

    int lenHay = haystack.size();
    int lenNed = needle.size();

    for (int i=1; i<=lenNed; i++) {
        for (int j=1; j<=lenHay; j++) {
            if (needle[i-1] == haystack[j-1]) {
                memo[i][j] = memo[i-1][j-1] + 1;
            } else {
                memo[i][j] = max(memo[i][j-1], memo[i-1][j]);
            }

            maxLCS = max(maxLCS, memo[i][j]);
        }
    }

    return maxLCS;
}


int main() {
    string haystack;
    string needle;

    while (cin >> haystack >> needle) {
        cout << lcs(haystack, needle) << endl;
    }

    return 0;
}