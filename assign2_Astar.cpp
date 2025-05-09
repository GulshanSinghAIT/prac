#include <bits/stdc++.h>
using namespace std;

// Heuristic: Number of misplaced tiles
int h(vector<vector<int>> currState, vector<vector<int>> &goal) {
    int misplaced = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (currState[i][j] != 0 && currState[i][j] != goal[i][j])
                misplaced++;
    return misplaced;
}

// Check if goal state is reached
bool isGoal(vector<vector<int>> state, vector<vector<int>> goalState) {
    return state == goalState;
}

// Convert matrix to string for hashing
string matToString(vector<vector<int>> mat) {
    string s;
    for (auto &row : mat)
        for (auto &cell : row)
            s += to_string(cell);
    return s;
}

// Swap two positions in matrix
vector<vector<int>> swapPos(vector<vector<int>> mat, pair<int, int> a, pair<int, int> b) {
    swap(mat[a.first][a.second], mat[b.first][b.second]);
    return mat;
}

// Print 3x3 matrix
void printMatrix(vector<vector<int>> mat) {
    for (auto &row : mat) {
        for (auto &cell : row)
            cout << cell << " ";
        cout << "\n";
    }
}

// A* Search
void solve(vector<vector<int>> initialState, vector<vector<int>> goalState) {
    priority_queue<pair<int, pair<vector<vector<int>>, int>>,
                   vector<pair<int, pair<vector<vector<int>>, int>>>,
                   greater<>> pq;

    set<string> visited;
    map<string, int> g_cost;

    string initialStr = matToString(initialState);
    g_cost[initialStr] = 0;
    pq.push({h(initialState, goalState), {initialState, 0}});

    vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    while (!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        auto currState = curr.second.first;
        int g = curr.second.second;
        int hn = h(currState, goalState);
        int fn = g + hn;
        string currStr = matToString(currState);

        if (visited.count(currStr)) continue;
        visited.insert(currStr);

        cout << "Current state:\n";
        printMatrix(currState);
        cout << "g(n): " << g << ", h(n): " << hn << ", f(n): " << fn << "\n\n";

        if (isGoal(currState, goalState)) {
            cout << "Final goal reached!\n";
            return;
        }

        pair<int, int> pos;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (currState[i][j] == 0)
                    pos = {i, j};

        for (auto dir : directions) {
            int newX = pos.first + dir.first;
            int newY = pos.second + dir.second;
            if (newX >= 0 && newX < 3 && newY >= 0 && newY < 3) {
                auto newState = swapPos(currState, pos, {newX, newY});
                string newStr = matToString(newState);
                int new_g = g + 1;

                if (!g_cost.count(newStr) || new_g < g_cost[newStr]) {
                    g_cost[newStr] = new_g;
                    int f = new_g + h(newState, goalState);
                    pq.push({f, {newState, new_g}});
                }
            }
        }
    }

    cout << "No solution found.\n";
}

// Input matrix
vector<vector<int>> takeInput(string name) {
    cout << "Enter " << name << " state (3x3 matrix with numbers 0-8, 0 = blank):\n";
    vector<vector<int>> mat(3, vector<int>(3));
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> mat[i][j];
    return mat;
}

int main() {
    vector<vector<int>> initialState = takeInput("Initial");
    vector<vector<int>> goalState = takeInput("Goal");

    solve(initialState, goalState);
    return 0;
}
