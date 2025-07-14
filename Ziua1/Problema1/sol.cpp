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

    int ans = 1;
    int len = 0;
    for(int i = 1; i <= N; i++) {
        if(A[i] != A[i - 1] && A[i] == 0) {
            ans = max(ans, len);
            len = 0;
        }
        if(A[i] == 1) {
            len++;
        }
    }

    cout << ans << "\n";
    return 0;
}