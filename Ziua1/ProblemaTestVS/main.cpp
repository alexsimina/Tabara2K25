#include <bits/stdc++.h>    

using namespace std;

bitset<32> ab, bb;

int operator+(bitset<32> &a, bitset<32> &b)
{
    return a.to_ulong() + b.to_ulong();
}

int a, b;

int main()
{
    cin >> a >> b;
    cout << (a + b);

    return 0;
}