#include <bits/stdc++.h>

using namespace std;

ifstream fin ("aib.in");
ofstream fout("aib.out");

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
        if(x >= aib.size()) return 0;
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


    int cibin(long long int s)
    {
        int ans = 0;
        long long int sum_ans = 0;
        for(int pas = (1 << 18); pas > 0; pas /= 2)
        {
            if(ans + pas >= aib.size()) continue;
            if((sum_ans + aib[ans + pas] < s))
            {
                ans += pas;
                sum_ans += aib[ans];
            }
        }

        if((query(ans + 1)) <= s)
            return ans + 1;
        else return -1;


    }
};

vector<int> arr;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    fin >> n >> q;
    AIB aib(n);
    arr.resize(n + 9);
    for(int i = 1; i <= n; i++)
    {
        fin >> arr[i];
        aib.update(i, arr[i]);
    }

    for(int i = 1; i <= q; i++)
    {
        int op;
        fin >> op;
        if(op == 0)
        {
            int poz;
            long long int val;
            fin >> poz >> val;
            aib.update(poz, val);
            arr[poz] += val;
        }
        else if(op == 1)
        {
            int l, r;
            fin >> l >> r;
            fout << aib.query(r) - aib.query(l - 1) << '\n';
        }
        else
        {
            int x;
            fin >> x;
            fout << aib.cibin(x) << '\n';
        }
    }
    return 0;
}