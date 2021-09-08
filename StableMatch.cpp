#include <iostream>
#include <cstring>

#include <queue>
#include <map>

using namespace :: std;

int main() {
    int n_cases;  cin >> n_cases;

    while (n_cases-- > 0) {
        int n_persons;  cin >> n_persons;

        // Men priority as a queue
        queue<int> men_p[n_persons];
        
        // Women priority as a matrix
        int women_p[n_persons][n_persons];

        // Single men as a queue
        queue<int> single_men;

        // Matches as a list
        int matches_w[n_persons], matches_m[n_persons];
        memset(matches_w, -1, sizeof(matches_w));

        
        // Read women priorities (O(n^2))
        for (int j=0; j<n_persons; j++) {
            int person;  cin >> person;
            person -= 1;
            
            for (int k=0; k<n_persons; k++) {
                int match;  cin >> match;
                women_p[person][match-1] = k;
            }
        }


        // Read men priorities (O(n^2))
        for (int j=0; j<n_persons; j++) {
            int person;  cin >> person;
            person -= 1;
            
            for (int k=0; k<n_persons; k++) {
                int match;  cin >> match;
                men_p[person].push(match-1);
            }

            // Use the cicle to set him as single
            single_men.push(person);
        }


        // Mathches the couples (O(n^2))
        while (!single_men.empty()) {
            // Takes a copy of the next man
            int man = single_men.front();
            single_men.pop();

            // Takes the highest priority woman
            int woman = men_p[man].front();
            men_p[man].pop();

            // If she is dating
            if (matches_w[woman] != -1) {
                // If her actual date is worse than the new proposal
                if (women_p[woman][matches_w[woman]] > women_p[woman][man]) {
                    single_men.push(matches_w[woman]);
                    matches_w[woman] = man;
                    matches_m[man] = woman;
                } else {
                    single_men.push(man);
                }
            } else {
                // If she is single she is taking him
                matches_w[woman] = man;
                matches_m[man] = woman;
            }
        }

        // Print the dates (O(n))
        for (int j=0; j<n_persons; j++) {
            cout << j+1 << " " << matches_m[j]+1 << endl;
        }
    }

    return 0;
}