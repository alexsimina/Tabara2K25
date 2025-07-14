#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 100000;

int N;
int A[N_MAX + 5];

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        int sum = 0;
        for(int j = i; j <= N; j++) {
            sum += A[j];
            if(sum % N == 0) {
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
    return 0;
}