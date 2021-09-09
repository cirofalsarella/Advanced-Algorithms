#include <iostream>
#include <algorithm>

#include <vector>
#include <queue>


using namespace :: std;

int main() {
    int n_cases;  cin >> n_cases;

    while (n_cases-- > 0) {
        int n_persons = 0;  cin >> n_persons;

        if (n_persons == 0){
            cout << 0 << endl << endl;  // time => 0
            continue;
        }


        // Saves the crossing time of each person in crescent order
        deque<int> people;
        for (int i=0; i<n_persons; i++) {
            int person; cin >> person;
            people.push_back(person);
        }


        // Exception treatment
        if (n_persons == 1) {
            cout << people[0] << endl;
            cout << people[0] << endl << endl;
            continue;
        }

        int time = 0;
        vector<vector<int>> crosses;
        priority_queue< int, vector<int>, greater<int> > crossed;

        // Cross almost everybody
        sort(people.begin(), people.end());
        while (people.size() > 2) {
            // Set A takes the 2 slow guys separately
            int set_A = people[0] + people[people.size()-2];                 // + people[people.size()-1]

            // Set B takes them together (takes the fastest 2)
            int set_B = crossed.empty() ? (set_A + 1) : (2 * crossed.top()); // + people[people.size()-1]
            
            if (set_A < set_B) {
                // Cross the 2 fastest guys
                int fast = min(people[0], people[1]);
                int slow = max(people[0], people[1]);

                time += slow;
                crosses.push_back({fast, slow});

                crossed.push(people.front());   people.pop_front();
                crossed.push(people.front());   people.pop_front();
            } else {
                // Cross the 2 slowest guys
                int fast = min(people[people.size()-2], people[people.size()-1]);
                int slow = max(people[people.size()-2], people[people.size()-1]);

                time += slow;
                crosses.push_back({fast, slow});

                crossed.push(people.back());    people.pop_back();
                crossed.push(people.back());    people.pop_back();
            }

            // Return the flashlight
            time += crossed.top();
            crosses.push_back({crossed.top()});

            people.push_front(crossed.top());   crossed.pop();
        }

        // Cross the last 2
        int fast = min(people[0], people[1]);
        int slow = max(people[0], people[1]);

        time += slow;
        crosses.push_back({fast, slow});


        cout << time << endl;
        int size = crosses.size();
        for (int i=0; i<size; i++) {
            if (i%2 == 0) {
                cout << crosses[i][0] << " " << crosses[i][1] << endl;
            } else {
                cout << crosses[i][0] << endl;
            }
        }

        if (n_cases > 0)    cout << endl;
    }

    return 0;
}