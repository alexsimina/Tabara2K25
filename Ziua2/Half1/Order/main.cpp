#include <bits/stdc++.h>

using namespace std;

ifstream fin ("order.in");
ofstream fout("order.out");

int lsb(int x)
{
    return x & (-x);
}

struct AIB
{
    vector<int> aib;

    AIB(int n)
    {
        aib.resize(n + 1);
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
        return ans + 1;
    }
};

int arr[30009];

int main()
{
    int n;
    fin >> n;
    AIB aib(n);
    for(int i = 1; i <= n; i++)
    {
        aib.update(i, 1);
        aib.update(i + n, 1);
    }

    int lastPoz = 2, ramase = n;
    for(int curr = 1; curr <= n; curr++)
    {
        
        int prev = aib.query(lastPoz - 1);
        int poz = curr + prev;
        if(poz > ramase)
        {
            poz = (poz - 1) % ramase + 1;
        }
        poz = aib.cibin(poz);
        aib.update(poz, -1);
        lastPoz = poz;
        
        ramase--;

        fout << poz << ' ';
    }

    return 0;
}