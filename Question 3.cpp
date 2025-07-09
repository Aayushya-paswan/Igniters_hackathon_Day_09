#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10;
vector<bool> is_prime(MAX, true);

void precompute_primes() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX; i++) {
        if (is_prime[i]) {
            for (int j = i*i; j < MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int findP1(int d) {
    d++;
    while (true) {
        if (is_prime[d]) {
            return d;
        }
        d++;
    }
}

int findP2(int d, int p1) {
    int p2 = p1 + d;
    if (p2 == p1) {
        p2++; // ensure p2 ≠ p1
    }
    while (true) {
        if (is_prime[p2]) {
            return p2;
        }
        p2++;
    }
}

int main() {
    precompute_primes();
    int t, d, p1, p2;
    cin>>t;
    while (t--) {
        cin>>d;
        p1 = findP1(d);
        p2 = findP2(d, p1);
        cout<<p2*p1<<endl;
    }
}