#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ifstream fin ("flip.in");
ofstream fout("flip.out");

int n, m, mat[20][20];

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            fin >> mat[i][j];
        }

    int rez = 0;
    for(int i = 0; i < (1 << n); i++)
    {
        int newMat[20][20];
        memcpy(newMat, mat, sizeof(mat));
        for(int j = 0; j < n; j++)
        {
            if((i & (1 << j)))
            {
                for(int k = 1; k <= m; k++)
                    newMat[j][k] = -newMat[j][k];
            }
        }

        int curr = 0;
        for(int j1 = 1; j1 <= m; j1++)
        {
            int sum = 0;
            for(int i1 = 1; i1 <= n; i1++)
            {
                sum += newMat[i1][j1];
            }

            if(sum < 0)
                sum = -sum;
            curr += sum;
        }

        rez = max(curr, rez);
    }

    fout << rez;
}