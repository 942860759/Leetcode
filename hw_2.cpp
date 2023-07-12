#include <cstdlib>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b, c;
    int N, m;
    cin >> a >> b;
    N = a;
    m = b;
    int line = 0;
    vector<int> w, v, q;
    while (cin >> a >> b >> c) { // 注意 while 处理多个 case
        if (line >= m)
            break;
        
        w.push_back(a);
        v.push_back(b);
        q.push_back(c - 1);
        // cout << a << b  << c << endl;
        line++;
    }
    vector<int> p_w(m, 0), p_v(m, 0);
    vector<int> a_w(m, 0), a_v(m, 0);
    vector<int> b_w(m, 0), b_v(m, 0);
    for (int i = 0; i < m; i++) {
        if (q[i] == -1) {
            p_w[i] = w[i];
            p_v[i] = v[i];
        } else if (a_w[i] == 0 && a_v[i] == 0) {
            a_w[i] = w[i];
            a_v[i] = v[i];
        } else {
            b_w[i] = w[i];
            b_v[i] = v[i];
        }
    }

    vector<int> weight(m);
    vector<int> value(m);
    // max w[i] * v[i]  w[i]->N    w[i] > -1 dependes  -1 no
    vector<vector<int>> dp(m + 1, vector<int> (N + 1, 0));
    for(int i = 0; i <= v.size(); i++) {    
        for(int j = 0; j <= N; j++) {
            for(int k = 0; k <= 2; k++) {
                if (j % 10 != 0) continue;
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (w[i - 1] <= j && (q[i] == -1)) {
                        dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i-1]] + w[i-1] * v[i-1]);
                } else if (w[i - 1] +  k * w[q[i-1]] <= j && (q[i] > -1)) {
                        dp[i][j] = max(dp[i-1][j], dp[i-1][j - k * w[q[i-1]] - w[i-1]] + k * w[i-1] * v[q[i-1]] + w[i-1] * v[i-1]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }  
    }
    printf("%lld", dp[m][N]);
}
// 64 位输出请用 printf("%lld")