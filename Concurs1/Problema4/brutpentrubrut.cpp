#include <bits/stdc++.h>

using namespace std;

long long int arr[250009];

int main()
{
    long long int rez = 0;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            long long int sum = 0;
            for(int k = j; k <= i; k++)
                sum += arr[k];

            if(sum > 0)
                rez++;
        }

    }
        cout << rez;

    return 0;
}