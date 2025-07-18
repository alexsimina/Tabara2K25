#include <bits/stdc++.h>

using namespace std;

ifstream fin("microbuz.in");
ofstream fout("microbuz.out");

int arr[12];
vector<int> freqSum[200];

int main()
{
    int c, n;
    n = 10;

    fin >> c;
    for(int i = 1; i <= n; i++)
    {
        fin >> arr[i];
    }
    int toGet;
    fin >> toGet;

    if(c != 3)
    {
    int costMin = 1e9;
    vector<int> pozMin;
    for(int i = 0; i < (1 << n); i++)
    {
        vector<int> curr;
        curr.push_back(0);
        int currSum = 0, km = 0;
        for(int j = 0; j < n; j++)
        {

            if(i & (1 << j))
            {
                km += j + 1;
                currSum += arr[j + 1];
                curr.push_back(j + 1);
            }

        }
        curr[0] = currSum;
        if(freqSum[km].empty() || freqSum[km][0] > curr[0])
            freqSum[km] = curr;
    }

    for(int i1 = 0; i1 < (1 << n); i1++)
    {
        vector<int> curr1;
        int currSum1 = 0, km1 = 0;
        for(int j1 = 0; j1 < n; j1++)
        {
            if(i1 & (1 << j1))
            {
                km1 += j1 + 1;
                currSum1 += arr[j1 + 1];
                curr1.push_back(j1 + 1);
            }
        }

        for(int i2 = 0; i2 < (1 << n); i2++)
        {
            int currSum2 = 0, km2 = 0;
            for(int j2 = 0; j2 < n; j2++)
            {
                if(i2 & (1 << j2))
                {
                    km2 += j2 + 1;
                    currSum2 += arr[j2 + 1];
                }
            }

            int left = toGet - (km1 + km2);
            if(left >= 0 && (!freqSum[left].empty() && (freqSum[left][0] > 0 || km1 + km2 == toGet)))
            {
                if(costMin > currSum1 + currSum2 + freqSum[left][0])
                {
                    vector<int> curr2;
                    for(int j2 = 0; j2 < n; j2++)
                    {
                        if(i2 & (1 << j2))
                        {
                            curr2.push_back(j2 + 1);
                        }
                    }
                    costMin = currSum1 + currSum2 + freqSum[left][0];
                    for(auto x: curr1)
                        curr2.push_back(x);

                    for(int x = 1; x < freqSum[left].size(); x++)
                        curr2.push_back(freqSum[left][x]);
                
                    pozMin = curr2;
                }
            }
        }

    }

        if(c == 1)
            fout << costMin;
        else if(c == 2)
        {
            for(auto x: pozMin)
                fout << x << ' ' << arr[x] << '\n';
        }
    }

    else 
    {
        vector<int> set1, bestset1;
        vector<int> set2, bestset2;
        int maxxSum = 0;

        for(int i1 = 1; i1 < (1 << n); i1++)
        {
            set1.clear();
            int sum1 = 0, sum2 = 0, poz = 0;
            int ramase[11]{};

            for(int j1 = 0; j1 < n; j1++)
            {
                if(i1 & (1 << j1))
                {
                    sum1 += arr[j1 + 1];
                    set1.push_back(j1 + 1);
                }
                else
                {
                    ramase[poz] = j1;
                    poz++;
                }
            }

            for(int i2 = 1; i2 < (1 << poz); i2++)
            {
                sum2 = 0;
                for(int j2 = 0; j2 < poz; j2++)
                {
                    if(i2 & (1 << j2))
                    {
                        sum2 += arr[ramase[j2] + 1];
                    }

                                if(sum1 == sum2 && sum1 > maxxSum)
                                {
                                    set2.clear();
                                    {
                                        for(int j2 = 0; j2 < poz; j2++)
                                        {
                                            if(i2 & (1 << j2))
                                            {
                                                set2.push_back(ramase[j2] + 1);
                                            }
                                        }
                                    }

                                    bestset1 = set1;
                                    bestset2 = set2;
                                    maxxSum = sum1;

                                }
                }
            }

        }

        fout << maxxSum << '\n';
        sort(bestset1.begin(), bestset1.end());
        sort(bestset2.begin(), bestset2.end());

        for(auto x: bestset1)
            fout << x << ' ';
        fout << '\n';
        for(auto x: bestset2)
            fout << x << ' ';
    }
}