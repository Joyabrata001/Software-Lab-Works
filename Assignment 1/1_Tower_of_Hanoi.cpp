#include <iostream>
#include <fstream>
#include <cmath>
#include <chrono>

typedef long long int ll;
using namespace std;

class TowerOfHanoi
{
public:
    void toh(ll N, int from, int to, int aux, ll &count)
    {
        if (N == 0)
            return;
        toh(N - 1, from, aux, to, count);
        count++;
        toh(N - 1, aux, to, from, count);
    }
};

int main()
{
    TowerOfHanoi tower;
    ll count = 0;
    ofstream movesOutputFile("1_Tower_of_Hanoi_Iterations.csv");
    movesOutputFile << "Discs,Moves" << endl;

    ofstream runtimeOutputFile("1_Tower_of_Hanoi_Runtime.csv");
    runtimeOutputFile << "Discs,Runtime(ms)" << endl;

    for (ll N = 1; N <= pow(2, 5); ++N)
    {
        // cout << "For " << N << " discs:" << endl;

        auto start = chrono::high_resolution_clock::now();

        count = 0;
        
        tower.toh(N, 1, 3, 2, count);
        
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        
        // cout << "Total number of moves: " << count << endl;
        // cout << "Runtime: " << duration.count() << " milliseconds" << endl;

        movesOutputFile << N << "," << count << endl;
        runtimeOutputFile << N << "," << duration.count() << endl;
    }

    movesOutputFile.close();
    runtimeOutputFile.close();

    cout << "Data written to files." << endl;
    return 0;
}