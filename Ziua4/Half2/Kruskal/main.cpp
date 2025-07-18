#include <bits/stdc++.h>

using namespace std;

ifstream fin ("kruskal.in");
ofstream fout("kruskal.out");

struct DSU
{
    vector<int> T;
    vector<int> size;

    DSU(int N)
    {
        T.resize(N + 1);
        size.resize(N + 1);
        iota(T.begin(), T.end(), 0);
    }

    int find(int a)
    {
        if(a == T[a])
            return a;
        return T[a] = find(T[a]);
    }

    void join(int a, int b)
    {
        a = find(a);
        b = find(b);

        if(size[a] > size[b])
            swap(a,  b);

        size[b] += size[a];
        T[a] = b;
    }

    bool query(int a, int b)
    {
        a = find(a);
        b = find(b);

        return a == b;
    }
};

struct Edge
{
    int x, y, cost;
};

int main()
{
    int n, m;
    fin >> n >> m;
    DSU dsu(n);
    vector<Edge> edges(m);
    for(auto &a: edges)
        fin >> a.x >> a.y >> a.cost;

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b)
    {
        return a.cost < b.cost;
    });

    int cost = 0;
    vector<Edge> ans;
    for(auto e: edges)
    {
        if(dsu.query(e.x, e.y) == false)
        {
            cost += e.cost;
            ans.push_back(e);
            dsu.join(e.x, e.y);
        }
    }

    fout << cost << '\n';
    for(auto e: ans)
        fout << e.x << ' ' << e.y << '\n';
    

    return 0;
}