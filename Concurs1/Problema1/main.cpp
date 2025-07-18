//de data aceasta nu voi mai viola memoria
#include <bits/stdc++.h>

using namespace std;

vector<int> skdnfkjswahfkjahfahf[250009];

bool trynnaSolve(int& n, int& m, int& k, int maxx)
{
    vector<pair<int, int>> sumPartCol(m + 9);
    int currK = 0, lastI = -1;
    for(int i = 1; i <= n; i++)
    {
        int currMax = 0;
        {
            for(auto y: skdnfkjswahfkjahfahf[i])
            {
                if(sumPartCol[y].second <= lastI + (i == (lastI + 1)))
                    sumPartCol[y].first = 0;
                sumPartCol[y].first++;
                sumPartCol[y].second = i;
                currMax = max(currMax, sumPartCol[y].first);
            }
        }

        if(currMax > maxx)
        {
            currK++;
            if(currK >= k)
                return false;
            i--;
            lastI = i;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;


    int perechi, k;
    cin >> k >> perechi;
    for(int i = 1; i <= perechi; i++)
    {
        int x, y;
        cin >> x >> y;
        skdnfkjswahfkjahfahf[x].push_back(y);
    }
    
    
    int l = 1, r = n, best = n;
    while(l <= r)
    {
        int mij = (l + r) / 2;
        int rez = trynnaSolve(n, m, k, mij);
        if(rez)
        {
            best = min(best, mij);
            r = mij - 1;
        }
        else
        {
            l = mij + 1;
        }
    }

    cout << best;

    return 0;
}