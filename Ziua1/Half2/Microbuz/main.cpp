#include <bits/stdc++.h>

using namespace std;

int arr[12];

int main()
{
    int c, n;
    cin >> c;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    cin >> n;

    for(int i = 0; i < (1 << n); i++)
    {
        int currn = 0;
        for(int j = 0; j < n; j++)
        {

            if(i & (1 << j))
            {

            }
        }
    }
}