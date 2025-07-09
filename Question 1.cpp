#include<bits/stdc++.h>
using namespace std;

void convert_to_power(vector<int>& queries, int q) {   // To convert enchantments integer to 2*integer
   for (int i = 0; i<q; i++) {
      queries[i] = pow(2, queries[i]);
   }
}

int main() {
   int t, n, q;
   cin>>t;
   while(t--) {
      cin>>n;
      cin>>q;
      vector<int> arr(n);
      vector<int> queries(q);
      for (int i = 0; i<n; i++) {
         cin>>arr[i];
      }
      for (int i = 0; i<q; i++) {
         cin>>queries[i];
      }
      convert_to_power(queries, q);
      for (int i = 0; i<q; i++) {
         int query = queries[i];
         for (int j = 0; j<n; j++) {
            if (arr[j] % query == 0) {
               arr[j] += query/2;
            }
         }
      }
      for (int i = 0; i<n; i++) {
         cout<<arr[i]<<" ";
      }
      cout<<endl;

   }
}