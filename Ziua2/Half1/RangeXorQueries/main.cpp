#include <bits/stdc++.h>

using namespace std;

vector<long long int> aib;
vector<int> arr;

int lsb(int x)
{
    return x & (-x);
}

long long int query(int x)
{
    long long int sum = 0;
    for(int i = x; i > 0; i -= lsb(i))
        sum ^= aib[i];

    return sum;
}

void update(int x, int add)
{
    for(int i = x; i < aib.size(); i += lsb(i))
        aib[i] ^= add;
}

int main()
{
    int n, q;
    cin >> n >> q;
    aib.resize(n + 9);
    arr.resize(n + 9);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        update(i, arr[i]);
    }

    for(int i = 1; i <= q; i++)
    {
        
        int l, r;
        cin >> l >> r;
        cout << (query(r) ^ query(l - 1)) << '\n';
        
    }
    return 0;
}