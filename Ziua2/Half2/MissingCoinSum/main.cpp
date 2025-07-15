#include <bits/stdc++.h>

using namespace std;

int arr[200009];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr + 1, arr + n + 1);

    long long int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum + 1 < arr[i + 1])
        {
            cout << sum + 1 << '\n';
            return 0;
        }
    }
    sum += arr[n];
    cout << sum + 1;
    return 0;
}