#include <bits/stdc++.h>

using namespace std;

int t, arr[200009];

int main()
{
    cin >> t;
    while(t--)
    {
        int n, biti[32]{};
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> arr[i];

            int x = arr[i];
            int curr = 0;
            while(x)
            {
                if(x & 1)
                    biti[curr]++;

                x /= 2;
                curr++;
            }
        }

        long long int rez = 0;
        for(int i = 1; i <= n; i++)
        {
            int curr = arr[i];
            long long int thisRez = 0;
            for(int j = 0; j < 31; j++)
            {
                int bit = (curr & 1);
                curr /= 2;

                if(bit == 1)
                {
                    thisRez += 1ll * (1 << j) * (n - biti[j]);
                }
                else thisRez += 1ll * (1 << j) * biti[j];
            }

            rez = max(rez, thisRez);
        }

        cout << rez << '\n';
    }
}
