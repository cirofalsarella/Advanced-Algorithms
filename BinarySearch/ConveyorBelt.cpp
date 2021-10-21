#include <iostream>
#include <vector>

using namespace :: std;

bool verify(vector<int> vessels, int n_containers, int container_capacity) {
    // Start a new container at the begin
    int used_capacity = container_capacity;
    int used_containers = 0;

    for (int vessel_capacity : vessels) {
        // Try to fill the container
        if ((used_capacity + vessel_capacity) > container_capacity) {
            // Goes to the next container
            used_capacity = vessel_capacity;
            used_containers++;

            // If there isnt a next container, break the code
            if (used_containers > n_containers) return false;
        } else {
            used_capacity += vessel_capacity;
        }
    }

    return true;
}

int BinarySearch(vector<int> vessels, int n_containers, int min_capacity, int max_capacity) {
    while (min_capacity < max_capacity) {
        int test_capacity = (max_capacity + min_capacity)/2;

        if (verify(vessels, n_containers, test_capacity)) {
            max_capacity = test_capacity;
        } else {
            min_capacity = test_capacity + 1;
        }
    }
    
    return min_capacity;
}

int main() {
    int n_vessels, n_containers;

    while (cin >> n_vessels >> n_containers) {
        vector<int> vessels;
        
        int sum = 0;
        int max_vessel = 0;

        for (int i=0; i<n_vessels; i++) {
            int aux;
            cin >> aux;
            vessels.push_back(aux);

            sum += aux;
            if (aux > max_vessel)   max_vessel = aux;
        }

        cout << BinarySearch(vessels, n_containers, max(sum/n_containers, max_vessel), sum) << endl;
    }
}