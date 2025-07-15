#include <bits/stdc++.h>

using namespace std;

ifstream fin ("permutariab.in");
ofstream fout("permutariab.out");

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

vector<int> arrBegin;


int main()
{
    int n;
    fin >> n;
    AIB aib(n);
    arrBegin.resize(n + 9);
    map<int, int> indexValFinal;
    for(int i = 1; i <= n; i++)
    {
        int x;
        fin >> x;
        indexValFinal[x] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        fin >> arrBegin[i];
    }

    vector<int> arr(n + 9);
    for(int i = 1; i <= n; i++)
    {
        arr[i] = indexValFinal[arrBegin[i]];
    }

    long long int rez = 0;
    for(int i = n; i >= 1; i--)
    {
        rez += aib.query(arr[i] - 1);
        aib.update(arr[i], 1);
    }
    fout << rez;

    return 0;
}