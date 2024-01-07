#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <chrono>
#include <fstream>
#include <algorithm>
using namespace std;

long long int iterations;

class DisjointSet
{
public:
    vector<int> parent, size;
    DisjointSet(const int &n)
    {
        size.resize(n + 1, 1);
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int findParent(const int &node)
    {
        // ++iterations;

        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(const int &u, const int &v)
    {
        ++iterations;

        int uParent = findParent(u);
        int vParent = findParent(v);

        if (uParent == vParent)
            return;

        if (size[uParent] < size[vParent])
        {
            parent[uParent] = vParent;
            size[vParent] += size[uParent];
        }
        else
        {
            parent[uParent] = vParent;
            size[vParent] += size[uParent];
        }
    }
};

class Kruskal
{
public:
    int spanningTree(const vector<vector<pair<int, int>>> &adjList)
    {
        int n = adjList.size();

        vector<vector<int>> edges;
        for (int u = 0; u < n; ++u)
            for (auto &[v, wt] : adjList[u])
                edges.push_back({wt, u, v});

        sort(edges.begin(), edges.end());

        int E = edges.size();
        iterations += E * log2(E);

        DisjointSet ds(n);

        int mstWt = 0;

        for (auto &edge : edges)
        {
            int wt = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (ds.findParent(u) != ds.findParent(v))
            {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }

        return mstWt;
    }

    vector<vector<pair<int, int>>> generateAdjList(int V, int percent, int &E)
    {
        vector<vector<pair<int, int>>> adjList(V);

        int maxEdges = (V * (V - 1)) / 2;
        int numEdges = (percent * maxEdges) / 100;
        E = numEdges;

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(1, 100);

        for (int i = 0; i < numEdges; ++i)
        {
            int u = dis(gen) % V;
            int v = dis(gen) % V;
            int wt = dis(gen) % 100;

            adjList[u].emplace_back(v, wt);
            adjList[v].emplace_back(u, wt);
        }

        return adjList;
    }

    void runTestsAndStoreResults()
    {
        ofstream outputFile("2_Kruskal_Algorithm_Iterations.csv");

        outputFile << "V,E,ElogE,VlogV,ElogV,VlogE,Iterations\n";

        for (int V = 100; V <= 1000; ++V)
        {
            for (int percent = 40; percent <= 95; percent += 5)
            {
                iterations = 0;
                int E;

                vector<vector<pair<int, int>>> adjList = generateAdjList(V, percent, E);

                int mstWeight = spanningTree(adjList);

                outputFile << V << ", " << E << ", " << E * log2(E) << ", " << V * log2(V) << ", " << E * log2(V) << ", " << V * log2(E) << ", " << iterations << "\n";
            }
        }

        outputFile.close();
        cout << "Tests completed and results stored\n";
    }
};

int main()
{
    Kruskal kruskal;
    kruskal.runTestsAndStoreResults();
    return 0;
}