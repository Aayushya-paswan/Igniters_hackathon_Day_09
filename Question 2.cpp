#include<bits/stdc++.h>
using namespace std;
int cal_bit(const vector<int>& v, int i, int j) { // calculating total bitwise and of vector from i to j index
    int ans = v[i];
    for (int x = i; x<=j; x++) {
        ans = ans & v[x];
    }
    return ans;
}

int main() {
    int t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        vector<int> vec(n);
        for (int i = 0; i<n; i++) {
            cin>>vec[i];
        }
        if (vec.empty()) {
            cout<<"0"<<endl;
            continue;
        }
        int max_val = vec[0];
        for (int i = 0; i<n; i++) {
            for (int j = i; j<n; j++) {
                int ans = cal_bit(vec, i, j);
                if (ans > max_val) {
                    max_val = ans;
                }
            }
        }
        cout<<max_val<<endl;
    }
}