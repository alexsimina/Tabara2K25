#include <bits/stdc++.h>

using namespace std;

ifstream fin ("dezastru.in");
ofstream fout("dezastru.out");

int pascal[30][30];
double arr[30];
double rez;
void combinari(int& n, int& k, int lastPoz, double currSum, int dim)
{        
    if(dim == k)
        rez += currSum;
    else
    {
        for(int i = lastPoz + 1; i <= n; i++)
        {
            combinari(n, k, i, currSum * arr[i], dim + 1);
        }
    }
}

int main()
{
    for(int i = 0; i <= 26; i++)
    {
        pascal[i][0] = 1;
        pascal[i][i] = 1;
    }

    for(int i = 1; i <= 26; i++)
        for(int j = 1; j < i; j++)
        {
            pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
        }

    int n, k;
    fin >> n >> k;

    for(int i = 1; i <= n; i++)
        fin >> arr[i];

    combinari(n, k, 0, 1, 0);
    fout << rez / pascal[n][k];


    return 0;
}