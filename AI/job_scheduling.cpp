#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

// Comparator to sort jobs by profit (descending order)
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobScheduling(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compare);

    int n = jobs.size();
    vector<bool> slot(n, false);     // To track free time slots
    vector<char> result(n);          // To store result (sequence of jobs)

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        // Find a free slot from jobs[i].deadline-1 to 0
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "Scheduled Jobs: ";
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            cout << result[i] << " ";
        }
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    int numJobs;
    cout << "Enter number of jobs: ";
    cin >> numJobs;

    vector<Job> jobs(numJobs);
    cout << "Enter job details (ID deadline profit):" << endl;

    for (int i = 0; i < numJobs; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    jobScheduling(jobs);

    return 0;
}
