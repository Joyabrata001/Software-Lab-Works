#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <chrono>

typedef long long int ll;
using namespace std;

class NQueen
{
    int n;

    vector<bool> leftRow;
    vector<bool> lowerDiagonal;
    vector<bool> upperDiagonal;
    vector<vector<string>> solutions;

    bool isValid(const int &r, const int &c, vector<string> &board)
    {
        if (leftRow[r] || lowerDiagonal[r + c] || upperDiagonal[n - 1 + c - r])
            return false;
        return true;
    }

    void solve(const int &c, vector<string> &board, vector<vector<string>> &solutions)
    {
        if (c == n)
        {
            solutions.push_back(board);
            return;
        }

        for (int r = 0; r < n; ++r)
        {
            if (isValid(r, c, board))
            {
                board[r][c] = 'Q';
                leftRow[r] = lowerDiagonal[r + c] = upperDiagonal[n - 1 + c - r] = true;

                solve(c + 1, board, solutions);

                board[r][c] = '.';
                leftRow[r] = lowerDiagonal[r + c] = upperDiagonal[n - 1 + c - r] = false;
            }
        }
    }

public:
    NQueen(const int &size)
    {
        n = size;
        leftRow.resize(n, false);
        lowerDiagonal.resize(2 * n - 1, false);
        upperDiagonal.resize(2 * n - 1, false);
    }

    void solveNQueen()
    {
        vector<string> board(n);
        string s(n, '.');
        for (auto &row : board)
            row = s;

        solve(0, board, solutions);
    }

    ~NQueen()
    {
        ;
    }
};

int main()
{
    ofstream runtimeOutputFile("4_N_Queen_Runtime.csv");
    runtimeOutputFile << "N,Runtime(ms)" << endl;
    for (int N = 1; N < pow(2, 5); ++N)
    {
        NQueen Q(N);
        auto start = chrono::high_resolution_clock::now();
        Q.solveNQueen();
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        runtimeOutputFile << N << ", " << duration.count() << endl;
    }
    runtimeOutputFile.close();

    cout << "Data written to file." << endl;
    return 0;
}