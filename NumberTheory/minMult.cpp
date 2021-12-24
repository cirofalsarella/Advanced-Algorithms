// STILL WRONG

#include <iostream>
#include <bitset>
#include <vector>
#include <map>

using namespace :: std;

typedef long long ll;
#define CRIVO_MAX 1000000

bitset<CRIVO_MAX> crivo;
vector<ll> prime_numbers;
ll crivoSize;

void createCrivo(ll N) {
    crivoSize = N+1;

    crivo.set();
    crivo[0] = crivo[1] = false;

    for (int i=2; i <= crivoSize; i++) {
        if (crivo[i]) {
            prime_numbers.push_back(i);
            for (int j=i+i; j <= crivoSize; j += i) crivo[j] = false;
        }
    }
}

map<ll, int> primeFactors(ll n) {
    map<ll, int> factors;

    if (n == 1) factors[1] = 1;

    int idx = 0;
    ll FP = prime_numbers[idx];
    while (n >= FP * FP) {
        if (n % FP == 0) {
            factors[FP]++;
            n /= FP;
        } else {
            idx++;
        }

        FP = prime_numbers[idx];
    }

    if (n != 1) factors[n]++;
    return factors;
}

int main() {
    createCrivo(CRIVO_MAX-2);

    int n_cases;    cin >> n_cases;
    while (n_cases-- > 0) {
        ll n;   cin >> n;
        map<ll, int> factors = primeFactors(n);

        string answ = "";
        for (auto const &val : factors) {
            if (val.first >= 10) {
                answ = "-1";
                break;
            }

            for (int i=0; i<val.second; i++){
                answ += to_string(val.first);
            }
        }

        cout << answ << endl;
    }

    return 0;
}