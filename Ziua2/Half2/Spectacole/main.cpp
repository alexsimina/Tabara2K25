#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

pair<int, int> arr[200009];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i].x >> arr[i].y;

    sort(arr + 1, arr + n + 1, [](pair<int, int>& a, pair<int, int>& b)
    {
        if(a.y == b.y) return a.x < b.x;
        return a.y < b.y;
    });

    int lastEnd = -1, rez = 0;
    for(int i = 1; i <= n; i++)
    {
        if(lastEnd <= arr[i].x)
        {
            rez++;
            lastEnd = arr[i].y;
        }
    }

    cout << rez;

    return 0;
}