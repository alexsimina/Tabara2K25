#include <bits/stdc++.h>

using namespace std;

ifstream fin ("ctc.in");
ofstream fout("ctc.out");

const int N_MAX = 100000;


int n, m;
bool vis[N_MAX + 5];
int comp[N_MAX + 5];

void DFS(int node , vector<int> G[], int curr_comp)
{
    comp[node] = curr_comp;
    for(auto next: G[node])
    {
        if(comp[next] == 0)
            DFS(next, G, curr_comp);
    } 
}

vector<int> G[N_MAX + 5];
vector<int> Gt[N_MAX + 5];
vector<int> S;

void sort_top(int node)
{
    vis[node] = true;
    for(auto next: G[node])
    {
        if (!vis[next])
            sort_top(next);
    }

    S.push_back(node);
}

int main()
{
    fin >> n >> m;
    while (m--)
    {
        int x, y;
        fin >> x >> y;
        G[x].push_back(y);
        Gt[y].push_back(x);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            sort_top(i);
        }
    }
    reverse(S.begin(), S.end());
    memset(vis, 0, sizeof(vis));

    int num_comp = 0;
    for(auto s: S)
    {
        if(comp[s] == 0)
        {
            DFS(s, Gt, ++num_comp);
        }
    }

    fout << num_comp << '\n';
    vector<vector<int>> comps(num_comp + 1);
    for(int i = 1; i <= n; i++)
    {
        comps[comp[i] - 1].push_back(i);
    }


    for(auto comp: comps)
    {
        for(auto node: comp)
        {
            fout << node << ' ';
        }
        fout << '\n';
    }


    return 0;
}