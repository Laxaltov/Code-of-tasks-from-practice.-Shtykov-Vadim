#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 40000000;
vector<int> spf(MAXN + 1); 
 
void build_spf() {
    for (int i = 0; i <= MAXN; i++) spf[i] = i;
    
    for (int i = 2; i * i <= MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}
 
int count_prime_divisors(int n) {
    if (n <= 1) return 0;
    
    int count = 0;
    int last = -1;
    
    while (n > 1) {
        int p = spf[n];
        if (p != last) {
            count++;
            last = p;
        }
        while (n % p == 0) n /= p;
    }
    
    return count;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    build_spf();
    
    int t;
    cin >> t;
    
    vector<int> nums(t);
    for (int i = 0; i < t; i++) {
        cin >> nums[i];
    }
    
    for (int i = 0; i < t; i++) {
        int n = nums[i];
        
        if (n <= 1) {
            cout << 0 << '\n';
            continue;
        }
        
        if (spf[n] == n) {
            cout << "Prime\n";
        } else {
            cout << count_prime_divisors(n) << '\n';
        }
    }
    
    return 0;
}