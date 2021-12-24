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

bool isPrime(ll n) {
    if (n <= crivoSize) return crivo[n];

    for (ll i=0; i <= prime_numbers.size() && n >= prime_numbers[i] * prime_numbers[i]; i++) {
        if (n % prime_numbers[i] == 0)  return false;
    }

    return true;
}

map<ll, int> primeFactors(ll n) {
    map<ll, int> factors;

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

void printFactors(map<ll, int> factors, int n) {
    cout << n << ":" << endl;
    for (auto const &val : factors) {
        cout << val.first << " -> " << val.second << endl;
    }
    cout << endl;
}

int main() {
    createCrivo(100);

    return 0;
}