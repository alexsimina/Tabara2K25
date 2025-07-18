#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 100000;


int n, m;
bool vis[N_MAX + 5];
int comp[N_MAX + 5];
long long int dp[N_MAX + 5], sumComp[N_MAX + 5];

void DFS(int node, vector<int> G[], int curr_comp)
{
    comp[node] = curr_comp;
    for(auto next: G[node])
    {
        if(comp[next] == 0)
            DFS(next, G, curr_comp);
    } 
}

vector<int> G[N_MAX + 5], grafConexe[N_MAX + 5];
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
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    perechi.push_back({});
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
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
    for(int i = 1; i <= n; i++)
    {
        sumComp[comp[i]] += arr[i];
    }

    for(int i = 1; i <= m; i++)
    {
        if(comp[perechi[i].first] != comp[perechi[i].second])
            grafConexe[comp[perechi[i].first]].push_back(comp[perechi[i].second]);
    }

    long long int rez = 0;
    for(int i = num_comp; i >= 1; i--)
    {
        if(grafConexe[i].empty()) 
            dp[i] = sumComp[i];
        for(auto next: grafConexe[i])
        {
            dp[i] = max(sumComp[i] + dp[next], dp[i]);
        }
        rez = max(rez, dp[i]);
    }

    cout << rez;

    return 0;
}