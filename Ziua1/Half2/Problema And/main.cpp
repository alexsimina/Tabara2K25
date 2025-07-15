#include <bits/stdc++.h>

using namespace std;

ifstream fin ("and.in");
ofstream fout("and.out");



int main()
{
    int n, arr[100009];
    fin >> n;
    for(int i = 1; i <= n; i++)
        fin >> arr[i];
    
    int rez = 1;
    for(int bit = 0; bit < 31; bit++)
    {
        int len = 0;
        for(int i = 1; i <= n; i++)
        {
            if((arr[i] & (1 << bit)))
            {
                len++;
            }
            else len = 0;
            
            rez = max(rez, len);
        }
        rez = max(rez, len);
    }
    fout << rez;

    return 0;
}