#include <bits/stdc++.h>

using namespace std;

map<int, int> freqa;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        freqa.clear();
        int n;
        cin >> n;
        int a[200009], b[200009];
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            freqa[a[i]]++;
        }
        for(int i = 1; i <= n; i++)
        {
            cin >> b[i];
            while(b[i] % 2 == 0)
            {
                b[i] >>= 1;
            }
        }

        bool no = false;
        sort(b + 1, b + n + 1);
        for(int i = 1; i <= n; i++)
        {
            bool found = false;
            for(int x = b[i]; x <= (1 << 30) - 100; x <<= 1)
            {
                if(freqa[x])
                {
                    found = true;
                    freqa[x]--;
                    break;
                }
            }

            if(!found)
            {
                for(int x = b[i]; x >= 1; x >>= 1)
                {
                    if(freqa[x])
                    {
                        found = true;
                        freqa[x]--;
                        break;
                    }
                }
            }

            if(!found)
            for(int x = 1; x <= (1 << 30) - 100; x <<= 1)
            {
                if(freqa[x])
                {
                    found = true;
                    freqa[x]--;
                    break;
                }
            }

            if(!found)
            {
                no = true;
                break;
            }
        }
        if(!no) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}