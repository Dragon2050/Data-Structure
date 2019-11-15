#include<bits/stdc++.h>

using namespace std;

#define lli long long int

lli segment_tree[5000000],mx=1000000000000;

void construct_tree(lli *a,lli node,lli b,lli e)
{
    if(b==e)
    {
        segment_tree[node]=a[b];
        return;
    }
    lli mid=b+((e-b)/2);
    construct_tree(a,(2*node+1),b,mid);
    construct_tree(a,(2*node+2),mid+1,e);
    segment_tree[node]=min(segment_tree[2*node+1],segment_tree[2*node+2]);
    return;
}

lli RMQ(lli node,lli b,lli e,lli qs,lli qe)
{
    if(qe<b or qs>e)
        return mx;
    if(qs<=b and qe>=e)
    {
        return segment_tree[node];
    }
    lli mid=b+((e-b)/2);
    lli val = min(RMQ(2*node+1,b,mid,qs,qe),RMQ(2*node+2,mid+1,e,qs,qe));
    return val;
}

int main()
{
    int n;
    cin>>n;
    lli a[n+5];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    construct_tree(a,0,0,n-1);
    int val=2*n-1;
    /*for(int i=0;i<25;i++)
        cout<<segment_tree[i]<<" ";
    cout<<endl;*/
    lli qs,qe;
    cin>>qs>>qe;
    lli res = RMQ(0,0,n-1,qs,qe);
    cout<<res<<endl;
    return 0;
}
