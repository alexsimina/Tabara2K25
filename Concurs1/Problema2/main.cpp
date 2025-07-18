#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int queryBits(int i, long long int n)
{
    long long int rez = 0;
    n++;
    rez += 1ll * (n / ((1ll << (i + 1)))) * ((1ll << i) % MOD) % MOD;
    rez += 1ll * max(0ll, (n % ((1ll << (i + 1))) - ((1ll << i)))) % MOD;
    return rez % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    for(int i = 1; i <= q; i++)
    {
        long long int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int rez = 0;
        for(int j = 0; j < 63; j++)
        {
            int zerox = (queryBits(j, x2) - queryBits(j, x1 - 1) + MOD) % MOD;
            int unux = ((x2 - x1 + 1) - zerox + MOD) % MOD;

            int zeroy = (queryBits(j, y2) - queryBits(j, y1 - 1) + MOD) % MOD;
            int unuy = ((y2 - y1 + 1) - zeroy + MOD) % MOD;

            rez = (1ll * rez + 1ll * zerox * unuy % MOD * ((1ll << j) % MOD) % MOD + 
                               1ll * unux * zeroy % MOD * ((1ll << j) % MOD) % MOD) % MOD;
        }
        cout << rez << '\n';
    }
    

    return 0;
}