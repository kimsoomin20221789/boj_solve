#include <iostream>
using namespace std;
int DP[100001];

int main() {
    int N; cin >> N;
    DP[1] = 3;
    DP[2] = 7;
    for (int i=3; i<=N; i++) {
        // DP[i] = (DP[i-1] + 2*(DP[i-1] - (DP[i-1]-DP[i-2])/2));
        DP[i] = (2*DP[i-1] + DP[i-2])%9901;
    }
    cout << DP[N];
}