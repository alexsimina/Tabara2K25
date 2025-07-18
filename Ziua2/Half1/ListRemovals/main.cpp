#include <bits/stdc++.h>

using namespace std;

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

int arr[200009], rez[200009];

int main()
{
    int n;
    cin >> n;
    AIB aib(n);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        aib.update(i, 1);
    }   

    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        rez[i] = aib.cibin(x);
        aib.update(rez[i], -1);

        cout << arr[rez[i]] << ' ';
    }
    return 0;
}