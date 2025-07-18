#include <bits/stdc++.h>

using namespace std;

ifstream fin ("grass.in");
ofstream fout("grass.out");

const int N_MAX = 100000;


int n, m;
bool vis[N_MAX + 5];
int comp[N_MAX + 5];
long long int dp_from[N_MAX + 5], dp_to[N_MAX + 5], sumComp[N_MAX + 5];

void DFS(int node, vector<int> G[], int curr_comp)
{
    comp[node] = curr_comp;
    for(auto next: G[node])
    {
        if(comp[next] == 0)
            DFS(next, G, curr_comp);
    } 
}

vector<int> G[N_MAX + 5], grafConexe[N_MAX + 5], tgrafConexe[N_MAX + 5];
vector<int> Gt[N_MAX + 5];
vector<int> S;
vector<pair<int, int>> perechi;
vector<int> arr(N_MAX + 5);

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
    perechi.push_back({});
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        fin >> x >> y;
        perechi.push_back({x, y});
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


    vector<vector<int>> comps(num_comp + 1);
    for(int i = 1; i <= n; i++)
    {
        comps[comp[i]].push_back(i);
    }

    for(int i = 1; i <= m; i++)
    {
        if(comp[perechi[i].first] != comp[perechi[i].second])
        {
            grafConexe[comp[perechi[i].first]].push_back(comp[perechi[i].second]);
            tgrafConexe[comp[perechi[i].second]].push_back(comp[perechi[i].first]);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        sumComp[comp[i]]++;
    }

    long long int rez = 0;
    for(int i = comp[1] + 1; i <= n; i++)
        dp_from[i] = -1;

    dp_from[comp[1]] = sumComp[comp[1]] - 1;

    for(int i = comp[1] - 1; i >= 1; i--)
    {
        dp_from[i] = sumComp[i];
        for(auto prev: grafConexe[i])
            if(dp_from[prev] != -1)
                dp_from[i] = max(sumComp[i] + dp_from[prev], dp_from[i]);
    }

    for(int i = 1; i < comp[1]; i++)
        dp_to[i] = -1;

    dp_to[comp[1]] = sumComp[comp[1]] - 1;

    for(int i = comp[1] + 1; i <= n; i++)
    {
        dp_to[i] = sumComp[i];
        for(auto prev: tgrafConexe[i])
            if(dp_to[prev] != -1)
                dp_to[i] = max(sumComp[i] + dp_to[prev], dp_to[i]);
    }

    for(int i = 1; i <= m; i++)
    {
        int x = comp[perechi[i].first];
        int y = comp[perechi[i].second];

        {   
            long long int curr = max(dp_from[y] + dp_to[x], dp_from[x] + dp_to[y]);
            if(x == i && y == i)
                curr = 0;

            rez = max(curr, rez);
        }
    }

    fout << rez;

    return 0;
}