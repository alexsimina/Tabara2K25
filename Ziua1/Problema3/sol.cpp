#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 100000;

int N;
int A[N_MAX + 5];
int freq[N_MAX + 5];

int main() {
    freq[0] = 1;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        A[i] = (A[i] + A[i - 1]) % N;
    }

    for(int i = 1; i <= N; i++) {
        cnt += freq[A[i]];
        freq[A[i]]++;
    }
    
    cout << cnt << "\n";
    return 0;
}