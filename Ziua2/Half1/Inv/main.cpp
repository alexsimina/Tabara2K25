#include <bits/stdc++.h>

using namespace std;

ifstream fin ("inv.in");
ofstream fout("inv.out");

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

pair<long long int, int> arr[200009];


int main()
{
    int n, q;
    fin >> n;
    AIB aib(n);
    for(int i = 1; i <= n; i++)
    {
        fin >> arr[i].first;

    }
    sort(arr + 1, arr + n + 1);

    long long int rez = 0;
    for(int i = n; i >= 1; i--)
    {
        rez += aib.query(arr[i].second - 1);
        aib.update(arr[i].second, 1);
    }
    fout << rez % 9917;
    return 0;
}