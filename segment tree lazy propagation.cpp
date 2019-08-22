#include<bits/stdc++.h>

using namespace std;

#define lli long long int

lli a[2000005];

struct info
{
    lli prop,sum;
} tree[2000005];

void create_tree(lli node,lli b,lli e)
{
    if(b==e)
    {
        tree[node].sum=a[b];
        return;
    }
    lli left=node << 1;
    lli right=(node << 1)+1;
    lli mid=(b+e) >> 1;
    create_tree(left,b,mid);
    create_tree(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
    return;
}

void update(lli node,lli b,lli e,lli i,lli j,lli x)
{
    if(i>e or j<b)
    {
        return;
    }
    if(b<=i and e>=j)
    {
        tree[node].sum+=((e-b+1)*x);
        tree[node].prop+=x;
        return;
    }
    lli left = node << 1;
    lli right = node << 1 + 1;
    lli mid = (left + right)/2;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].sum=tree[left].sum+tree[right].sum+((e-b+1)*tree[node].prop);
    return;
}

lli query(lli node, lli b, lli e, lli i, lli j, lli carry = 0)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum + carry * (e - b + 1);

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;

    lli p1 = query(Left, b, mid, i, j, carry + tree[node].prop);
    lli p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}


int main()
{
    int n,number_of_time;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    create_tree(1,1,n);
    cin>>number_of_time;
    for(int i=1; i<=number_of_time; i++)
    {
        lli sr,er,x;/// sr = starting range.. er = ending range..
        cin>>sr>>er>>x;
        update(1,1,n,sr,er,x);
    }
    lli srange,erange;
    cin>>srange>>erange;
    lli val = query(1,1,n,srange,erange);
    cout<<val<<endl;
    return 0;
}
