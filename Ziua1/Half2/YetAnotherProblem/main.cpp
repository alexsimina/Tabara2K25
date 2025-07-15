#include <bits/stdc++.h>

using namespace std;

int t;

int main()
{
    {
        int n, q, sumPrefix[200009], arr[200009], lastXORPrefix[200009], esteZero[200009];
        map<int, int> lastOddXORPrefix, lastEvenXORPrefix;
        cin >> n >> q;
        sumPrefix[0] = 0;

        for(int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            sumPrefix[i] = sumPrefix[i - 1] ^ arr[i];
            if(arr[i] == 0)
                esteZero[i] = 1;

            if(i % 2 == 0)
            {
                lastEvenXORPrefix[sumPrefix[i]] = i;
                lastXORPrefix[i] = lastOddXORPrefix[sumPrefix[i]];
            }
            else
            {
                lastOddXORPrefix[sumPrefix[i]] = i;
                lastXORPrefix[i] = lastEvenXORPrefix[sumPrefix[i]];
            }
        }
        for(int i = 1; i <= n; i++)
            esteZero[i] += esteZero[i - 1];

        while(q--)
        {
            int l, r;
            cin >> l >> r;
            if((sumPrefix[r] != sumPrefix[l - 1])) //ca sume partiale
            {
                if(esteZero[r] - esteZero[l - 1] == r - l + 1)
                    cout << "0\n";
                else if((r - l + 1) % 2 == 1)
                    cout << "1\n";
                else if(lastXORPrefix[r] >= 1)
                    cout << "2\n";
                else cout << "-1\n";
            }
            else cout << "-1\n";
        }
    }


    return 0;
}