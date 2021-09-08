#include <iostream>
#include <algorithm>
#include <vector>

using namespace :: std;

/*          n0 + n1 ->      n1
    <- n0   n2 + n3 ->      n3 + n0
    <- n1   n0 + n1 ->      2*n1
    <- n0   n4 + n5 ->      n5 + n0
    <- n1   n0 + n1 ->      2*n1
    n=6; 5*n1 + 2*n0 + n3 + n5

    .       n0 + n1 ->      n1
    <- n0   n2 + n3 ->      n3 + n0
    <- n1   n0 + n1 ->      2*n1
    <- n0   n4 + n0 ->      n4 + n0
    n=5; 3*n1 + 2*n0 + n3 + n4

    even -> ((n/2)-1)*n0 + (n-1)*n1 + odds
    odd  -> ((n-1)/2)*n0 + (n-2)*n1 + odds (>1) + nk
*/

int main() {
    int n_cases;  cin >> n_cases;

    while (n_cases-- > 0) {
        int n_persons = 0;  cin >> n_persons;

        // Save the crossing time of each person in order
        vector<int> people;
        for (int i=0; i<n_persons; i++) {
            int person; cin >> person;
            people.push_back(person);
        }
        sort(people.begin(), people.end());

        // Calculates the total sum
        int sum = ((n_persons-1)/2) * people[0];
        sum += (n_persons-2) * people[1];
        for (int i=3; i<n_persons; i+=2)    sum += people[i];
        sum += people[n_persons-1];

        cout << sum << endl;

        for (int i=0; i<n_persons; i++) {
            if (i%2 == 0) {
                cout << people[0] << " " << people[1] << endl;
            } else {
                cout << people[i] << " " << people[i+1] << endl;
            }
            cout << people[i%2] << endl;
        }
    }

    return 0;
}