#include <iostream>     // For input/output
#include <vector>       // For storing jobs
#include <algorithm>    // For sort function
using namespace std;

// Structure to store each job's data
struct Job {
    char id;       // Job ID (can be a character)
    int deadline;  // Deadline to finish the job
    int profit;    // Profit if job is completed before or on deadline
};

// Comparator function to sort jobs by descending profit
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

// Function to perform job scheduling to maximize profit
void jobScheduling(vector<Job>& jobs, int n) {
    // Step 1: Sort jobs by descending order of profit
    sort(jobs.begin(), jobs.end(), compare);

    // Step 2: Find the maximum deadline among all jobs
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    // Step 3: Initialize slot availability and result array
    vector<bool> slot(maxDeadline + 1, false); // slots from 1 to maxDeadline
    vector<char> result(maxDeadline + 1, ' '); // store scheduled job IDs

    int totalProfit = 0; // To accumulate profit

    // Step 4: Iterate through all jobs
    for (int i = 0; i < n; i++) {
        // Try to schedule job at the latest available slot ≤ deadline
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (!slot[j]) { // If slot is free
                slot[j] = true;           // Mark slot as filled
                result[j] = jobs[i].id;   // Store job ID
                totalProfit += jobs[i].profit; // Add profit
                break; // Job scheduled, move to next job
            }
        }
    }

    // Step 5: Output scheduled jobs and total profit
    cout << "\nScheduled Jobs: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i]) {
            cout << result[i] << " ";
        }
    }

    cout << "\nTotal Profit: " << totalProfit << endl;
}

// Main function to take user input
int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    cout << "Enter Job ID, Deadline, and Profit for each job:\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    // Call the scheduling function
    jobScheduling(jobs, n);

    return 0;
}


// output
// Enter number of jobs: 5
// Enter Job ID, Deadline, and Profit for each job:
// a 2 100
// v 1 19
// c 2 27
// d 1 25
// e 3 15

// Scheduled Jobs: c a e 
// Total Profit: 142