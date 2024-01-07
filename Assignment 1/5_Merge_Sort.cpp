#include <iostream>
#include <vector>
#include <fstream>
#include <complex>
#include <chrono>
using namespace std;

class MergeSort
{
private:
    int iterationCount;

public:
    MergeSort() : iterationCount(0) {}

    void merge(vector<int> &vec, const int &l, const int &m, const int &r)
    {
        vector<int> lvec(vec.begin() + l, vec.begin() + m + 1);
        vector<int> rvec(vec.begin() + m + 1, vec.begin() + r + 1);

        int i = 0, j = 0, k = l;

        while (i < lvec.size() && j < rvec.size())
        {
            if (lvec[i] <= rvec[j])
                vec[k++] = lvec[i++];
            else
                vec[k++] = rvec[j++];
        }

        while (i < lvec.size())
            vec[k++] = lvec[i++];

        while (j < rvec.size())
            vec[k++] = rvec[j++];
    }

    void mergeSort(vector<int> &vec, const int &l, const int &r)
    {
        if (l < r)
        {
            iterationCount++;

            int m = l + (r - l) / 2;
            mergeSort(vec, l, m);
            mergeSort(vec, m + 1, r);
            merge(vec, l, m, r);
        }
    }

    int getIterationCount() const
    {
        return iterationCount;
    }
};

vector<int> generateRandomArray(int size)
{
    vector<int> arr;
    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < size; ++i)
        arr.push_back(rand() % 100);

    return arr;
}

int main()
{
    MergeSort M;
    ofstream iterationOutputFile("5_Merge_Sort_Iterations.csv");
    iterationOutputFile << "N,Iterations" << endl;

    for (int N = 1; N <= pow(2, 13); ++N)
    {
        vector<int> arr = generateRandomArray(N);
        M.mergeSort(arr, 0, N - 1);
        int iterations = M.getIterationCount();
        iterationOutputFile << N << ", " << iterations << endl;
    }

    iterationOutputFile.close();
    cout << "Data written to file." << endl;

    return 0;
}