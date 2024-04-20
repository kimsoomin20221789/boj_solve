#include <iostream>
using namespace std;

int main() {

    int N; cin >> N;
    int V[N];
    int T[N];

    for (int i=1; i<=N; i++) {
        cin >> V[i];
    }

    // T[i] = i개가 되기 위해 지불해야하는 금액
    // T[1] = 1개가 되기 위해 지불해야하는 금액 = V[1]
    // T[2] = 2개가 되기 위해 지불해야하는 금액 = max (V[2] + T[0], T[1] + T[1])
    // T[3] = 3개가 되기 위해 지불해야하는 금액 = max (V[3], T[2] + T[1]) 
    // T[4] = 4개가 되기 위해 지불해야하는 금액 = max (V[4], V[3] + V[1], V[2] + V[2]) 
    // T[i] = i개가 되기 위해 지불해야하는 금액 = max (V[i], V[i-1] + V[1], V[i-2] + V[2], ... V[(i+1)/2] + V[ i -(i+1)/2])
    
    V[0] = 0;
    T[0] = 0;
    T[1] = V[1];

    for (int i=2; i<=N; i++) {
        T[i] = V[i];
        int maxValue = T[i];
        for (int j=i; j>= (i+1)/2; j--) {
            maxValue = max(maxValue, T[j]+ T[i - j]);
        }
        T[i] = maxValue;
        // cout << "T[" <<  i << "]" << T[i] << endl;
    }

    cout << T[N]; 
}