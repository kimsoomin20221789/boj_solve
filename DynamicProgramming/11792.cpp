// D[n] = D[n-1](오른쪽 한개만 더 붙이기) + D[n-2](D[n-1]과 겹치지 않으려면 가로로 두개 붙이기)
#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int D[n+1];
    D[1] = 1;
    D[2] = 2;
    for (int i=3; i<=n; i++) {
        D[i]=(D[i-1] + D[i-2])%10007;
    }
    cout << D[n];
}