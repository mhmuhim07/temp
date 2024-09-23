#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 30000+7,b = 180,M = 200007;

struct query {
    int l,r,idx;
    bool operator < (const query &x)const {
        if(l/b == x.l/b)return ((l/b)&1)? r > x.r : r < x.r;
        else return l/b < x.l/b;
    }

} Q[M];
int cnt[(int)1e6+7],a[N],ans = 0,arr[M];
void add(int i) {
    if(cnt[a[i]] == 0)ans++;
    cnt[a[i]]++;
}
void del(int i) {
    if(cnt[a[i]] == 1)ans--;
    cnt[a[i]]--;
}
void solve(int cs) {
    int n;
    cin>>n;

    for(int i = 1; i <= n; i++)cin>>a[i];
    int q;
    cin>>q;
    for(int i = 1; i <= q; i++) {
        cin>>Q[i].l>>Q[i].r;
        Q[i].idx = i;
    }
    sort(Q+1,Q+q+1);

    int L = 1,R = 0;
    for(int i = 1; i <= q; i++) {
        int l = Q[i].l, r = Q[i].r;

        while(R<r)add(++R);
        while(L<l)del(L++);
        while(L>l)add(--L);
        while(R>r)del(R--);

        arr[Q[i].idx] = ans;
    }
    for(int i = 1; i <= q; i++)cout<< arr[i]<<'\n';

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1,cs=0;
    //cin >> t;
    while(t--)
    {
        solve(++cs);
    }

    return 0;
}
