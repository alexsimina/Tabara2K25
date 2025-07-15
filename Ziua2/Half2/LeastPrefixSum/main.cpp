#include <bits/stdc++.h>

using namespace std;

int t;

int main()
{
    cin >> t;
    while(t--)
    {
        int n, m, rez = 0;
        cin >> n >> m;
        vector<int> arr(n + 9);
        multiset<int> part;
        for(int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        long long int sum = 0;
        for(int i = m; i >= 2; i--)
        {
            part.insert(arr[i]);
            sum += arr[i];

            if(sum > 0)
            {
                auto last = prev(part.end());
                sum -= 2 * (*last);
                part.erase(last);

                rez++;
            }
        }

        sum = 0;
        part.clear();
        for(int i = m + 1; i <= n; i++)
        {
            part.insert(arr[i]);
            sum += arr[i];

            if(sum < 0)
            {
                auto first = part.begin();
                sum -= 2 * (*first);
                part.erase(first);
                rez++;
            }
        }

        cout << rez << '\n';
    }
    return 0;
}