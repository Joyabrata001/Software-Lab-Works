#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <random>
#include <fstream>
#include <cmath>
using namespace std;

class Dijkstra
{
public:
    vector<int> dijkstraUsingPriorityQueue(vector<vector<pair<int, int>>> adjList, int src, long long int &steps)
    {
        int n = adjList.size();
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while (!pq.empty())
        {
            auto [distNode, node] = pq.top();
            steps += log2(pq.size());
            pq.pop();

            for (auto &it : adjList[node])
            {
                auto [adjNode, edgeWt] = it;
                if (distNode + edgeWt < dist[adjNode])
                {
                    dist[adjNode] = distNode + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                    steps += log2(pq.size());
                }
            }
        }
        return dist;
    }

    vector<int> dijkstraUsingSet(vector<vector<pair<int, int>>> adjList, int src, long long int &steps)
    {
        int n = adjList.size();
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        set<pair<int, int>> st;
        st.insert({0, src});
        while (!st.empty())
        {
            auto it = *(st.begin());
            auto [distNode, node] = it;
            ++steps;
            st.erase(it);

            for (auto &it : adjList[node])
            {
                auto [adjNode, edgeWt] = it;
                if (distNode + edgeWt < dist[adjNode])
                {
                    if (dist[adjNode] != INT_MAX)
                    {
                        st.erase({dist[adjNode], adjNode});
                        ++steps;
                    }
                    dist[adjNode] = distNode + edgeWt;
                    st.insert({dist[adjNode], adjNode});
                    ++steps;
                }
            }
        }
        return dist;
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
        ofstream outputFile("3_Dijkstra_Algorithm_Iterations.csv");

        outputFile << "V,E,ElogE,VlogV,ElogV,VlogE,StepsPQ,StepsSet\n";

        for (int V = 100; V <= 1000; ++V)
        {
            for (int percent = 10; percent <= 95; percent += 5)
            {
                int E;

                vector<vector<pair<int, int>>> adjList = generateAdjList(V, percent, E);

                for (int src = 0; src < V; ++src)
                {
                    long long int steps1 = 0, steps2 = 0;
                    dijkstraUsingPriorityQueue(adjList, src, steps1);
                    dijkstraUsingSet(adjList, src, steps2);
                    outputFile << V << ", " << E << ", " << E * log2(E) << ", " << V * log2(V) << ", " << E * log2(V) << ", " << V * log2(E) << ", " << steps1 << ", " << steps2 << "\n";
                }
            }
        }

        outputFile.close();
        cout << "Tests completed and results stored\n";
    }
};

int main()
{
    Dijkstra D;
    D.runTestsAndStoreResults();
    return 0;
}