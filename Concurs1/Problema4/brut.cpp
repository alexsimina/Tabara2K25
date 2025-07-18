#include <bits/stdc++.h>

using namespace std;

long long int sums[250009], arr[250009];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sums[i] += sums[i - 1] + arr[i];
    }

    long long int rez = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(sums[i] - sums[j] > 0)
                rez++;
        }
    }
    cout << rez;

    return 0;
}