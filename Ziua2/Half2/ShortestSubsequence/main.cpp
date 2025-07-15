#include <bits/stdc++.h>
 
using namespace std;
 
bool done;
string subsecv, DNA;
vector<int> pozitii[5];
int n, lastPoz;
int chToPoz[256];
char pozToCh[256];
 
int main()
{
    chToPoz['A'] = 1; pozToCh[1] = 'A';
    chToPoz['C'] = 2; pozToCh[2] = 'C';
    chToPoz['G'] = 3; pozToCh[3] = 'G';
    chToPoz['T'] = 4; pozToCh[4] = 'T';
    cin >> DNA;
    for(int i = 0; i < DNA.size(); i++)
    {
        pozitii[chToPoz[DNA[i]]].push_back(i + 1);
    }
    while(!done)
    {
        int poz[5]{}, maxPoz{};
        for(int i = 1; i <= 4; i++)
        {
            auto ph_poz = upper_bound(pozitii[i].begin(), pozitii[i].end(), lastPoz);
            if(ph_poz == pozitii[i].end())
            {
                subsecv += pozToCh[i];
                cout << subsecv;
                return 0;
            }
            poz[i] = *ph_poz;
            if(poz[i] > poz[maxPoz]) maxPoz = i;
        }
 
        subsecv += pozToCh[maxPoz];
        lastPoz = poz[maxPoz];
    }
 
    return 0;
}