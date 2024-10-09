#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=0;
    unordered_map<ll,ll>rem;
    rem[0]=1;
    ll pref=0;
    for(int i=0;i<n;i++){
        pref+=a[i];
        ll curr=(pref%n +n)%n;
        ans+=rem[curr];
        rem[curr]++;
    }
    cout<<ans;
    return 0;
}