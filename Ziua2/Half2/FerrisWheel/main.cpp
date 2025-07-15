#include <bits/stdc++.h>

using namespace std;

multiset<int> arr;

int main()
{
    int n, maxx;
    cin >> n >> maxx;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        arr.insert(x);
    }

    int rez = 0;
    while(!arr.empty())
    {
        auto curr = prev(arr.end());
        int val = *curr;
        arr.erase(curr);
        if(arr.empty())
        {
            rez++;
            continue;
        }
        auto second = arr.upper_bound(maxx - val);
        if( (second == arr.begin()))
        {
            if(*arr.begin() + val <= maxx)
            {
                second = arr.begin();
            }
            else{
                                rez++;
                continue;
            }
        }
        else
        {
            second--;
            arr.erase(second);
        }
        rez++;
    }
    cout << rez;

    return 0;
}