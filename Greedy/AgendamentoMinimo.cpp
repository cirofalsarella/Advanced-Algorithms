#include <iostream>
#include <cstring>

#include <queue>

using namespace :: std;

struct jobs_sort {
    template<typename T, typename U>
    bool operator()(T const& lhs, U const& rhs) const {
        return rhs.first * lhs.second > rhs.second * lhs.first;
    }

/*  min (
        profit_a*(deadline_a + deadline_b) + profit_b*(deadline_b),
        profit_a*(deadline_a) + profit_b*(deadline_b + deadline_a)
    )

    min (
        profit_a * deadline_b,
        profit_b * deadline_a
    )
*/

};


int main() {
    int n_cases;  cin >> n_cases;

    while (n_cases-- > 0) {
        int n_jobs;  cin >> n_jobs;

        // Get the elements already sorted
        priority_queue< pair<int, int>, vector< pair<int, int> >, jobs_sort > jobs;
        for (int i=0; i<n_jobs; i++) {
            int profit;   cin >> profit;
            int deadline; cin >> deadline;

            jobs.push(make_pair(profit, deadline));
        }

        // Calculates the minimum job total time
        int total = 0;
        int time = 0;
        while (!jobs.empty()) {
            int profit = jobs.top().first;
            int deadline = jobs.top().second;
            jobs.pop();

            time += deadline;
            total += time * profit;
        }

        // Prints the value
        cout << total << endl;
    }

    return 0;
}