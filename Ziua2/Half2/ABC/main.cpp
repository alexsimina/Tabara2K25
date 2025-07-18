#include <bits/stdc++.h>

using namespace std;

ifstream fin ("abc.in");
ofstream fout("abc.out");

bool solvable(long long int n, long long int b, long long int c, pair<long long int, long long int> arr[], long long int sum, long long int lim, bool out)
{
    int d[30009];
    int op = 1;
    if(sum > c) op = -1;

        if(op == -1)
        {
            for(int i = 1; i <= n; i++)
            {
                int prev = 0;
                if(i != 1)
                    prev = d[i - 1];    
                d[i] = max({1ll * arr[i].first - lim, 1ll * prev + 1, 1ll, arr[i].first - (sum - c)});
                sum -= arr[i].first - d[i];
            }
        }
        else
        {
            for(int i = n; i >= 1; i--)
            {
                int next = b + 1;
                if(i != n)
                    next = d[i + 1];
                d[i] = min({1ll * arr[i].first + lim, 1ll * b, 1ll * next - 1, arr[i].first + (c - sum)});
                sum += d[i] - arr[i].first;
            }
        }
    
    if(out)
    {
        int initial[30009];
        for(int i = 1; i <= n; i++)
        {
            initial[arr[i].second] = d[i];
        }

        for(int i = 1; i <= n; i++)
            fout << initial[i] << ' ';
    }

    return sum == c;
}

long long int n, b;
pair<long long int, long long int> arr[30009];
long long int c;

int main()
{
    long long int sum = 0;
    fin >> n >> b >> c;
    for(int i = 1; i <= n; i++)
    {
        fin >> arr[i].first;
        sum += arr[i].first;
        arr[i].second = i;
    }
    sort(arr + 1, arr + n + 1);

    if(sum == c)
    {
        for(int i = 1; i <= n; i++)
            fout << arr[i].first << ' ';
    }
    else
    {
        long long int l = 0, r = b, best = b;
        while(l <= r)
        {
            long long int mij = (l + r) / 2;
            bool rez = solvable(n, b, c, arr, sum, mij, 0);
            if(rez)
            {
                r = mij - 1;
                best = mij;
            }
            else l = mij + 1;
        }
        solvable(n, b, c, arr, sum, best, 1);
    }


    return 0;
}