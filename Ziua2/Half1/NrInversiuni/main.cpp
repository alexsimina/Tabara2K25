#include <bits/stdc++.h>

using namespace std;

int lsb(int x)
{
    return x & (-x);
}

struct AIB
{
    vector<long long int> aib;

    AIB(int n)
    {
        aib.resize(n + 9);
    }

    long long int query(int x)
    {
        long long int sum = 0;
        for(int i = x; i > 0; i -= lsb(i))
            sum += aib[i];

        return sum;
    }

    void update(int x, int add)
    {
        for(int i = x; i < aib.size(); i += lsb(i))
            aib[i] += add;
    }
};

vector<int> arr;


int main()
{
    int n, q;
    cin >> n;
    AIB aib(n);
    vector<int> arr(n);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    long long int rez = 0;
    for(int i = n; i >= 1; i--)
    {
        rez += aib.query(arr[i] - 1);
        aib.update(arr[i], 1);
    }
    cout << rez;
    return 0;
}