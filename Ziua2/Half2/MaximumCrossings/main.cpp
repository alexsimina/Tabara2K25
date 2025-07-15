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
int t;

int main()
{
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        AIB aib(n);
        arr.resize(n + 9);
        vector<int> freq(n + 9);

        long long int rez = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            freq[arr[i]]++;
            
            rez += aib.query(n) - aib.query(arr[i]);
            aib.update(arr[i], 1);
        }
        for(int i = 1; i <= n; i++)
        {
            int k = freq[i];
            rez += 1ll * k * (k - 1) / 2;
        }
        cout << rez << '\n';
    }

    return 0;
}