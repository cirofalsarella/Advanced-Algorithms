#include <iostream>
#include <cstring>

using namespace :: std;

#define MAX_TIME 10000


class Scene {
    public:
    int nBurgers;
    int tBeer;

    Scene(int nBurgers, int tBeer)
        : nBurgers(nBurgers), tBeer(tBeer)
    {}

};

Scene compair(Scene s1, Scene s2) {
    if (s1.tBeer < s2.tBeer)
        return s1;
    if (s2.tBeer < s1.tBeer)
        return s2;
    
    if (s1.nBurgers < s2.nBurgers)
        return s2;
    return s1;
}


pair<int,int> memo[MAX_TIME];
int krusty, apu;

Scene calc(int t_left) {
    if (t_left < 0)
        return Scene(-1, MAX_TIME + 10);

    if (t_left == 0)
        return Scene(0, 0);
    
    if (memo[t_left].first != -1)
        return Scene(memo[t_left].first, memo[t_left].second);

    Scene res = Scene(-1, t_left);
    res = compair(res, calc(t_left-apu));
    res = compair(res, calc(t_left-krusty));

    res.nBurgers++;

        memo[t_left].first = res.nBurgers;
        memo[t_left].second = res.tBeer;

    return res;
}


int main() {
    int t_total;

    while (cin >> krusty >> apu >> t_total) {
        memset(memo, -1, sizeof(memo));
        Scene res = calc(t_total);

        cout << res.nBurgers;
        if (res.tBeer != 0)
            cout << " " << res.tBeer;
        cout << endl;
    }
    
    return 0;
}