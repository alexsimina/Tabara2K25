#include <bits/stdc++.h>

using namespace std;

ifstream fin ("inversiuni.in");
ofstream fout("inversiuni.out");

int arr[200009];
deque<int> dq;

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

    int query(int x)
    {
        long long int sum = 0;
        for(int i = x; i > 0; i -= lsb(i))
        {
            sum += aib[i];
        }

        return sum;
    }

    void update(int k, int add)
    {
        for(int i = k; i < aib.size(); i += lsb(i))
        {
            aib[i] += add;
        }
    }
};

int main()
{
    long long int n, rez = 0;
    fin >> n;
    AIB aibmic(n);
    AIB aibmare(n);
    for(int i = 1; i <= n; i++)
    {
        fin >> arr[i];

        rez += min(aibmare.query(n - arr[i] + 1), aibmic.query(arr[i]));

        aibmare.update(n - arr[i] + 1, 1);
        aibmic.update(arr[i], 1);
    }
    fout << rez;
    return 0;
}