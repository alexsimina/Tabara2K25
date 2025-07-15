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
    cin >> n >> q;
    AIB aib(n);
    AIB smen(n);
    arr.resize(n + 9);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        aib.update(i, arr[i]);
    }

    for(int i = 1; i <= q; i++)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int a, b, u;
            cin >> a >> b >> u;
            smen.update(a, u);
            smen.update(b + 1, -u);
        }
        else
        {
            int x;
            cin >> x;
            cout << (aib.query(x) - aib.query(x - 1)) + (smen.query(x)) << '\n';
        }
    }
    return 0;
}