#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e5+12;
 
template <typename T> using o_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using _set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key (k) : Number of items strictly smaller/greater than k .
//find_by_order(k) : K-th element in a set (counting from zero).

void solve(int cs){
    int n;
    cin>>n;
    
}
   
int main()
{

    ios_base::sync_with_stdio(false);cin.tie(0);
    int t=1,cs=0;
    cin >> t;
    while(t--)
    {
        solve(++cs);
    }

    return 0;
}
