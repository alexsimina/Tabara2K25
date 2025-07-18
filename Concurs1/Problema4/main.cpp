#include <bits/stdc++.h>
#define x first
#define y second
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

pair<long long int, int> sums[250009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long int rez = 0;
    cin >> n;
    vector<int> arr(n + 9);
    AIB aib(n);
    long long int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        sums[i].x = sum;
        sums[i].y = i;

        if(sums[i].x > 0)
            rez++;
    }    


    sort(sums + 1, sums + n + 1, [](pair<long long int ,int>& a, pair<long long int, int>& b)
{
    if(a.x == b.x) return a.y > b.y;
    return a.x < b.x;
});

    for(int i = 1; i <= n; i++)
    {
        rez += aib.query(sums[i].y - 1);
        aib.update(sums[i].y, 1);
    }

    cout << rez;
    return 0;
}