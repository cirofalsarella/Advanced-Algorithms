#include <iostream>
#include <cstring>
#include <queue>

using namespace :: std;

int memo[10000];

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

bool BFS(int ini, int target) {
    queue<int> q;
    q.push(ini);

    while(!q.empty()) {
        // Take next value
        int pos = q.front(); q.pop();

        // A bfs, if equal is the lowest level equal
        if (pos == target)  return true;

        // Trys every possible spin
        for (int i=0; i<4; i++) {
            int copy[4];    separate(pos, copy);
            int aux = copy[i];

            // spin foward
            copy[i] = (aux+1) % 10;
            int val = merge(copy);

            if (memo[val] == -1) {
                // If already used or forbidden skips
                memo[val] = memo[pos]+1;
                q.push(val);
            }

            
            // spin backwards
            copy[i] = (aux+9) % 10;
            val = merge(copy);
            
            if (memo[val] == -1) {
                // If already used or forbidden skips
                memo[val] = memo[pos]+1;
                q.push(val);
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
        if (BFS(ini, target)) {
            cout << memo[target] << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}