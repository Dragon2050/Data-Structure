#include<bits/stdc++.h>

using namespace std;

#define lli long long int

lli segment_tree[500005];

void construct_tree(lli *a,lli node,lli ss,lli se)
{
    if(ss==se)
    {
        segment_tree[node]=a[ss];
        return;
    }
    lli mid=ss+((se-ss)/2);
    construct_tree(a,2*node+1,ss,mid);
    construct_tree(a,2*node+2,mid+1,se);
    segment_tree[node]=segment_tree[2*node+1]^segment_tree[2*node+2];
}

void update_value(lli *a,lli node,lli ss,lli se,lli temp,lli index,lli val)
{
    if(index<ss or index>se)
        return;
    segment_tree[node]=(segment_tree[node]^temp)^val;
    if(ss!=se)
    {
        lli mid=ss+((se-ss)/2);
        update_value(a,node*2+1,ss,mid,temp,index,val);
        update_value(a,node*2+2,mid+1,se,temp,index,val);
    }
}

lli get_xor_value(lli *a,lli node,lli ss,lli se,lli l,lli r)
{
    if(l>se or r<ss)
        return 0;
    if(l<=ss and r>=se)
    {
        return segment_tree[node];
    }
    lli mid=ss+((se-ss)/2);
    return get_xor_value(a,2*node+1,ss,mid,l,r)^get_xor_value(a,2*node+2,mid+1,se,l,r);
}

int main()
{
    lli n;
    cin>>n;
    lli a[n+5];
    for(int i=0;i<n;i++)
        cin>>a[i];
    construct_tree(a,0,0,n-1);
    lli index,val;
    cin>>index>>val;
    lli temp=a[index];
    a[index]=val;
    update_value(a,0,0,n-1,temp,index,val);
    lli l,r;
    cin>>l>>r;
    lli ans=get_xor_value(a,0,0,n-1,l,r);
    cout<<ans<<endl;
    return 0;
}
