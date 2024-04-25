#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    int D[1001];

    D[1] = 1;
    D[2] = 3;
    if (N ==1 ) {cout << 1; return 0;}
    else if (N==2) {cout << 3; return 0;} 
    else {
        for (int i=3; i<=N; i++ ) {
            // D[i] = D[i-1]%10007 + (2*D[i-2])%10007; // => 오답
            D[i] = (D[i-1] + 2*D[i-2])%10007; // => 정답
        }
        cout << D[N];
    }
}