#include <bits/stdc++.h>
using namespace std;

ifstream fin ("elimin.in");
ofstream fout("elimin.out");

int main()
{
    unsigned int n, m, r, c;
    unsigned int maxSum = 0, initSum = 0;
    fin >> n >> m >> r >> c;
    vector<vector<unsigned int>> mat;
    if(n <= m)
    {
        mat = vector<vector<unsigned int>>(n + 9, vector<unsigned int>(m + 9));
        for(unsigned int i = 1; i <= n; i++)
        {
            for(unsigned int j = 1; j <= m; j++)
                fin >> mat[i][j];
        }
    }
    else
    {
        mat = vector<vector<unsigned int>>(m + 9, vector<unsigned int>(n + 9));
        vector<vector<unsigned int>> reverse(n + 9, vector<unsigned int>(m + 9));
        for(unsigned int i = 1; i <= n; i++)
        {
            for(unsigned int j = 1; j <= m; j++)
                fin >> reverse[i][j];
        }

        for(unsigned int i = 1; i <= m; i++)
        {
            for(unsigned int j = 1; j <= n; j++)
                mat[i][j] = reverse[j][i];
        }

        swap(n, m);
        swap(r, c);
    }

    vector<int> randuri(n + 9), coloane(m + 9);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            randuri[i] += mat[i][j];
            coloane[j] += mat[i][j];
            initSum += mat[i][j];
        }

    if(n <= m)
    {
        for(unsigned int i = 0; i < (1 << n); i++)
        {
            if(__builtin_popcount(i) == r)
            {
                vector<pair<unsigned int ,unsigned int>> sumCol(m);
                for(int i = 0; i < m; i++)
                {
                    sumCol[i].first = coloane[i + 1];
                    sumCol[i].second = i + 1;
                }
                unsigned int sum = initSum;
                vector modified = mat;
                for(unsigned int j = 0; j < n; j++)
                    if(i & (1 << j))
                    {
                        sum -= randuri[j + 1];
                        for(unsigned int j1 = 1; j1 <= m; j1++)
                        {
                            sumCol[j1 - 1].first -= mat[j + 1][j1];
                        }
                    }

                sort(sumCol.begin(), sumCol.end());
                for(unsigned int j = 0; j < c; j++)
                {
                    sum -= sumCol[j].first;
                }

                maxSum = max(sum, maxSum);
            }
        }
    }

    fout << maxSum;

    return 0;
}