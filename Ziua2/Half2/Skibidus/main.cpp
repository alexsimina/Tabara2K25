#include <bits/stdc++.h>

using namespace std;

int t;

int main()
{
    cin >> t;
    while(t--)
    {
        int n, m;


        pair<int, int> sums[200009];
        cin >> n >> m;
        vector<vector<int>> vcts(n + 1, vector<int>(m + 1));
        for(int i = 1; i <= n; i++)
        {
            int sum = 0;
            for(int j = 1; j <= m; j++)
            {
                cin >> vcts[i][j];
                sum += vcts[i][j];
            }

            sums[i].first = sum;
            sums[i].second = i;
        }

        sort(sums + 1, sums + n + 1);

        long long int rez = 0, sum = 0;
        int arr[200009];
        for(int i = n; i >= 1; i--)
        {
            int curr = sums[i].second;
            for(int j = 1; j <= m; j++)
            {
                sum += vcts[curr][j];
                rez += sum;
            }
        }

        cout << rez << '\n';
    }
    return 0;
}