#include <iostream>
#include <string>
using namespace std;
int dp[1001][1001];
// dp[i][j] = 첫번째 i번째문자열(1)과 두번째 j번째 문자열(2)의 부분수열중 가장 긴것.
int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a1;
    string a2;
    cin >> a1 >> a2;
    for (int i=0; i<=a1.length(); i++) {
        for (int j=0; j<=a2.length(); j++) {
            if (i==0 || j==0) {
                dp[i][j] = 0; // 함수외부에서 선언되어있어서 0으로 이미 초기화됨 -> 생략가능~
            } else {
                if (a1[i-1] == a2[j-1]) {
                    // dp[i][j] = max(dp[i-1][j], dp[i][j-1])+1;
                    // 위의 주석 코드가 안되는 이유 
                    // = 새롭게 나오는 문자가 기존에 공통수열에 있는 문자와 똑같을 경우이면 취급하면 안되기때문
                    // ex(반례) = aabb, babb
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
    }
    cout << dp[a1.length()][a2.length()];
}