# Cash Flow Minimizer Project

The Cash Flow Minimizer project aims to optimize cash flow among a group of individuals using graph theory concepts. This project is implemented in C++ and utilizes an adjacency matrix to represent transactions between people.

## Project Overview

The project involves solving a cash flow optimization problem where each person in a group participates in financial transactions. The goal is to minimize the total number of transactions required to settle all debts among the individuals.

### Features

- **Graph Representation:** Transactions are represented using an adjacency matrix where each cell `graph[i][j]` contains the amount person `i` owes to person `j`.
- **Min Heap and Max Heap:** Utilizes priority queues (heaps) to efficiently manage and settle debts, ensuring minimal transactions.
- **Algorithm:** Implements a greedy algorithm to prioritize settling transactions with the largest imbalance first, minimizing subsequent transactions.

## How to Use

1. **Clone the Repository:**
   ```sh
   git clone https://github.com/your-username/cash-flow-minimizer.git
   cd cash-flow-minimizer
