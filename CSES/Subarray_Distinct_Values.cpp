#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=0;
    ll cnt=0;
    ll left=0,right=0;
    map<ll,ll>hash;
    for( right=0;right<n;right++){
        if(hash[a[right]]==0){
            cnt++;
        }
        hash[a[right]]++;
        while(cnt>k){
            hash[a[left]]--;
            if(hash[a[left]]==0){
                cnt--;
            }
            left++;
        }
        ans+=(right-left+1);
    }
    cout<<ans;
    return 0;
}