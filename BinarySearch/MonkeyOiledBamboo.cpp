#include <iostream>
#include <vector>

using namespace :: std;

int minStrength(vector<int> steps) {
    int min_str = 0;
    int at_str = 0;

    long long unsigned int i=1;
    while (i < steps.size()) {
        int dif = steps[i] - steps[i-1];
        
        if (dif > at_str) {
            min_str = max(min_str+1, dif);
            at_str = min_str;
        }

        if (dif == at_str) {
            at_str--;
        }

        i++;
    }

    return min_str;
}

int main() {
    int n_cases;
    cin >> n_cases;
    

    for (int j=0; j < n_cases; j++) {
        int n_steps;
        cin >> n_steps;

        vector<int> steps;
        steps.push_back(0);
        for (int i=0; i<n_steps; i++) {
            int aux;
            cin >> aux;
            steps.push_back(aux);
        }

        cout << "Case " << j+1 << ": " << minStrength(steps) << endl;
    }

    return 0;
}