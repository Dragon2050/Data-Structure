#include<bits/stdc++.h>

using namespace std;

#define lli long long int

lli segment_tree[5000000];

lli get_max_value(lli *a,lli node,lli b,lli e,lli sr,lli er)
{
    if(sr>e or er<b)
        return -1;
    else if(sr<=b and er>=e)
        return segment_tree[node];
    lli mid=b+((e-b)/2);
    lli res=max(get_max_value(a,2*node+1,b,mid,sr,er),get_max_value(a,2*node+2,mid+1,e,sr,er));
    return res;
}

void update_segment_tree(lli *a,lli node,lli b,lli e,lli index,lli val)
{
    if(b==e)
    {
        a[index]=val;
        segment_tree[node]=val;
        return;
    }
    lli mid=b+((e-b)/2);
    if(index>=b and index<=mid)
        update_segment_tree(a,node*2+1,b,mid,index,val);
    else
        update_segment_tree(a,node*2+2,mid+1,e,index,val);
    segment_tree[node]=max(segment_tree[node*2+1],segment_tree[node*2+2]);
}

void construct_segment_tree(lli *a,lli node,lli b,lli e)
{
    if(b==e)
    {
        segment_tree[node]=a[b];
        return;
    }
    lli mid=b+((e-b)/2);
    construct_segment_tree(a,2*node+1,b,mid);
    construct_segment_tree(a,2*node+2,mid+1,e);
    segment_tree[node]=max(segment_tree[2*node+1],segment_tree[2*node+2]);
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
    construct_segment_tree(a,0,0,n-1);
    lli index;
    lli val;
    cin>>index>>val;
    update_segment_tree(a,0,0,n-1,index,val);
    for(int i=0;i<=(2*n);i++)
        cout<<i<<" = "<<segment_tree[i]<<endl;
    lli l,r;
    cin>>l>>r;
    lli res=get_max_value(a,0,0,n-1,l,r);
    cout<<"maximum = "<<res<<endl;
    return 0;
}
