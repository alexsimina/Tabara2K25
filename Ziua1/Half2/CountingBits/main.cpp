#include <bits/stdc++.h>

using namespace std;

long long int n;

int main()
{
    long long int rez = 0;
    cin >> n;
    n++;
    for(int i = 0; i < 60 && (1 << i) <= n; i++)
    {
        rez += 1ll * (n / (1ll << (i + 1))) * (1ll << i);
        rez += 1ll * max(0ll, (n % (1ll << (i + 1)) - (1ll << i)));
    }

    cout << rez;
    return 0;
}