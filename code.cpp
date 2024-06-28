#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

// Function to add an edge to the graph
void addTransaction(vector<vector<int>>& graph, int giver, int taker, int amount) {
    graph[giver][taker] += amount;
}

// Function to minimize cash flow among friends using graph representation
void minimizeCashFlow(vector<vector<int>>& graph) {
    int N = graph.size();
    vector<int> netBalance(N, 0);

    // Calculate the net balance of each person
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            netBalance[i] -= graph[i][j];
            netBalance[j] += graph[i][j];
        }
    }

    // Create a min heap for those who need to give money
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    // Create a max heap for those who need to receive money
    priority_queue<pair<int, int>> maxHeap;

    for (int i = 0; i < N; ++i) {
        if (netBalance[i] < 0) {
            minHeap.push({netBalance[i], i});
        } else if (netBalance[i] > 0) {
            maxHeap.push({netBalance[i], i});
        }
    }

    // Minimize the number of transactions required to settle debts
    while (!minHeap.empty() && !maxHeap.empty()) {
        int debtor = minHeap.top().second;
        int creditor = maxHeap.top().second;

        int debtAmount = -minHeap.top().first;
        int creditAmount = maxHeap.top().first;

        minHeap.pop();
        maxHeap.pop();

        int settlement = min(debtAmount, creditAmount);

        debtAmount -= settlement;
        creditAmount -= settlement;

        cout << "Person " << debtor << " pays Person " << creditor << " an amount of " << settlement << endl;

        if (debtAmount > 0) {
            minHeap.push({-debtAmount, debtor});
        }
        if (creditAmount > 0) {
            maxHeap.push({creditAmount, creditor});
        }
    }
}

int main() {
    int N = 3; // Number of people

    // Initialize graph with N x N matrix
    vector<vector<int>> graph(N, vector<int>(N, 0));

    // Sample transactions (giver, taker, amount)
    addTransaction(graph, 0, 1, 1000);
    addTransaction(graph, 1, 2, 5000);
    addTransaction(graph, 2, 0, 2000);

    minimizeCashFlow(graph);

    return 0;
}
