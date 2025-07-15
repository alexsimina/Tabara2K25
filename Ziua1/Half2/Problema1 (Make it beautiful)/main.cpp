#include <bits/stdc++.h>

using namespace std;

int t, arr[5009];
vector<int> bits;

int main()
{
    cin >> t;
    while(t--)
    {
        int n, rez = 0;
        long long int k;
        long long int op = 0;
        cin >> n >> k;
        for(int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            rez += __builtin_popcount(arr[i]);
        }

        for(int poz = 0; poz < 31; poz++)
            for (int i = 1; i <= n; i++)
                if((arr[i] & (1 << poz)) == 0)
                    bits.push_back(1 << poz);

        int i;
        for(i = 0; i < bits.size() && op + bits[i] <= k; i++)
        {
            rez++;
            op += bits[i];
        }
        if (i == bits.size())
        {
            int poz = 31;
            bool ok = true;
            while (ok)
            {
                for (i = 1; i <= n && ok; i++)
                {
                    if (op + (1ll << poz) > k)
                        ok = false;
                    else
                    {
                        op += (1ll << poz);
                        rez++;
                    }
                }

                poz++;
            }
        }

        cout << rez << '\n';

        bits.clear();
        for(int i = 1; i <= n; i++)
            arr[i] = 0;
    }
}