// Problem C - Convoy
// https://open.kattis.com/contests/qd7hf2/problems/convoy

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> speeds;
    int currSpeed;
    for (int i = 0; i < n; i++) {
        cin >> currSpeed;
        speeds.push_back(currSpeed);
    }
    sort(speeds.begin(), speeds.end());
    
    vector<int> decisions;
    decisions.push_back(speeds[0]);
    int numPeople = 5;
    int countCars = 1;
    int itr = 0;
    while (numPeople < n && countCars < k && itr < n) {
        if (speeds[itr + 1] < 2 * speeds[itr]) {
            decisions.push_back(speeds[itr + 1]);
            countCars++;
        } else {
            decisions[itr] += 2 * speeds[itr];
        }
        numPeople += 5;
        itr++;
    }
    
    int max_element = 0;
    for (int i = 0; i < decisions.size(); i++) {
        if (decisions[i] > max_element)
            max_element = decisions[i];
    }
    cout << max_element << endl;
}
