#include <bits/stdc++.h>

using namespace std;

int arrFinal[100009], arrBegin[100009];
int freqFinal[100009], freqBegin[100009];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arrFinal[i];
        freqBegin[arrFinal[i]]++;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> arrBegin[i];
        freqFinal[arrFinal[i]]++;
    }

    int diff = 0, rez = 0;
    for(int i = 1; i <= n; i++)
    {
        diff = 0;
        freqBegin[arrBegin[i]]--;
        freqFinal[arrFinal[i]]--;
        if(freqFinal[arrBegin[i]])
            diff++;
        if(freqBegin[arrFinal[i]] == freqFinal[arrFinal[i]])
            diff--;

        rez += diff;
    }
    cout << rez;

    
    return 0;
}