#include <bits/stdc++.h>
using namespace std;
 
const long long MOD = 1000000007LL;
 
long long modpow(long long a, long long e) {
    long long res = 1;
    while (e > 0) {
        if (e & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N;
    cin >> N;
 
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        sum += x;
  
    }
 
    long long pow2 = modpow(2, N - 1);
 
    long long ans = ((sum % MOD) + MOD) % MOD;
    ans = (ans * pow2) % MOD;
 
    cout << ans << "\n";
 
    return 0;
}