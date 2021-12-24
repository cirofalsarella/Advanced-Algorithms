#include <iostream>

using namespace :: std;
typedef long long ll;

int GCD(ll a, ll b) {
    if (a % b == 0) return b;
    return GCD(b, a % b);
}

int LCM(ll a, ll b) {
    return (a * b) / GCD(a, b);
}

int main() {
    int n_cases;    cin >> n_cases;

    while (n_cases-- > 0) {
        int gcd, lcm;   cin >> gcd >> lcm;

        if (lcm % gcd == 0) {
            cout << gcd << " " << lcm << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}