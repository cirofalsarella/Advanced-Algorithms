#include <iostream>
#include <cstring>

using namespace :: std;

#define MAX_WEIGHT 50
#define MAX_OBJECTS 1000
#define MAX_PEOPLE 1000

// value, weight
pair<int,int> objects[MAX_OBJECTS];
int memo[MAX_OBJECTS+1][MAX_WEIGHT+1];

void iterativo(int n_objects) {
    for (int i=1; i<n_objects+1; i++) {
        for (int j=1; j<MAX_WEIGHT+1; j++) {
            int value = 0;

            // Se couber o objeto no espaço
            if (j >= objects[i].second) {
                value = memo[i-1][j-objects[i].second] + objects[i].first; 
            }

            // Se não
            memo[i][j] = max(value, memo[i-1][j]);
        }
    }
}

int main() {
    int n_cases;    cin >> n_cases;

    while (n_cases-- > 0) {

        int n_objects;  cin >> n_objects;
        for (int i=1; i<n_objects+1; i++) {
            cin >> objects[i].first >> objects[i].second;
        }
        
        int people[MAX_PEOPLE];
        int n_people;   cin >> n_people;
        for (int i=0; i<n_people; i++)  cin >> people[i];

        memset(memo, 0, sizeof(memo));
        iterativo(n_objects);

        int sum = 0;
        for (int i=0; i < n_people; i++) {
            sum += memo[n_objects][people[i]];
        }

        cout << sum << endl;
    }

    return 0;
}