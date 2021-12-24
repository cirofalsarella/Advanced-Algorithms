#include <iostream>

using namespace :: std;

typedef long long ll;
#define LPN 131071

ll modSqPow(ll exp) {
	ll res = 1;
    ll num = 2;
	while (exp > 0) {
		if (exp % 2 == 1)
			res = (res * num) % LPN;
		num = (num*num) % LPN;
		exp = exp / 2;
	}

	return res;
}

int main() {
    string binary;
    while (cin >> binary) {
        ll value = 0;
        for (int i=binary.size()-2, j=0; i>=0; i--, j++) {
            if (binary[i] == '1') {
                value = (value + modSqPow(j)) % LPN;
            }
        }
        if (value != 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}