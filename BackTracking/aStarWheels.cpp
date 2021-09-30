#include <iostream>
#include <cstring>
#include <queue>

using namespace :: std;
int memo[10000];

class Config {
    public:
    int value;
    int depth;
    int distance;

    Config(int value, int depth, int distance)
        : value(value), depth(depth), distance(distance)
    {}

};
bool operator<(const Config& c1, const Config& c2) {
    return c1.depth + c1.distance > c2.depth + c2.distance;
}


int distance(int pos, int dest) {
    int dist = 0;

    for (int i=0; i<4; i++) {
        int at = abs((pos%10) - (dest%10));
        dist += min(at, 10-at);

        pos  /= 10;
        dest /= 10;
    }

    return dist;
}

void separate(int val, int* vec) {
    vec[0] = val%10;    val /=10;
    vec[1] = val%10;    val /=10;
    vec[2] = val%10;    val /=10;
    vec[3] = val%10;
}

int merge(int* vec) {
    int val = vec[0];
    val += vec[1]*10;
    val += vec[2]*100;
    val += vec[3]*1000;
    return val;
}

int read() {
    int val, aux;
    cin >> aux; val = aux*1000;
    cin >> aux; val += aux*100;
    cin >> aux; val += aux*10;
    cin >> aux; val += aux;

    return val;
}

bool aStar(int ini, int target) {
    priority_queue<Config> q;
    q.push(Config(ini, 0, distance(ini, target)) );

    while(!q.empty()) {
        // Take next value (lower distance + depht)
        Config pos = q.top(); q.pop();

        if (pos.value == target)  return true;

        // Trys every possible spin
        for (int i=0; i<4; i++) {
            int copy[4];    separate(pos.value, copy);
            int aux = copy[i];

            // Spin Foward
            copy[i] = (aux+1) % 10;
            int val = merge(copy);

            if (memo[val] == -1) {
                // If already used or forbidden skips
                memo[val] = memo[pos.value]+1;
                q.push(Config(val, pos.depth+1, distance(val, target)));
            }

            
            // Spin Backwards
            copy[i] = (aux+9) % 10;
            val = merge(copy);
            
            if (memo[val] == -1) {
                // If already used or forbidden skips
                memo[val] = memo[pos.value]+1;
                q.push(Config(val, pos.depth+1, distance(val, target)));
            }
        }
    }

    return false;;
}

int main() {
    int n_cases;    cin >> n_cases;
    while (n_cases-- > 0) {
        memset(memo, -1, sizeof(memo));

        // Get the main positions
        int ini = read();   memo[ini] = 0;
        int target = read();

        // Read the forbidden positions
        int n_forbidden; cin >> n_forbidden;
        while (n_forbidden-- > 0) {
            memo[read()] = -2;
        }

        // Find the best path
        if (aStar(ini, target)) {
            cout << memo[target] << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}