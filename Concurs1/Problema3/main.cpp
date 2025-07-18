#include <bits/stdc++.h>

using namespace std;

multiset<int> setulMeu;
vector<int> scoase;
int arr[250009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
        setulMeu.insert(x);
    }

    for(int i = 1; i <= m; i++)
    {
        int k;
        cin >> k;
        for(int i = 1; i <= k; i++)
        {
            int x;
            cin >> x;
            int val = arr[x];
            scoase.push_back(val);
            setulMeu.extract(val);
        }

        cout << *setulMeu.begin() << '\n';
        for(auto x: scoase)
        {
            setulMeu.insert(x);
        }

        scoase.clear();
    }

    return 0;
}