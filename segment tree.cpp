#include<bits/stdc++.h>

using namespace std;

#define lli long long int

lli a[200000],tree[1000000];

void limit(int node,int b,int e)
{
    if( b==e )
    {
        tree[node]=a[b];
        return;
    }
    int mid=(b+e)/2;
    int left=2*node;
    int right=2*node+1;
    limit(left,b,mid);
    limit(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
    return;
}

lli query(int node,int b,int e,int i,int j)
{
    if(j<b or i>e)
        return 0;
    if(b>=i and e<=j)
        return tree[node];
    lli left=node*2;
    lli right=left+1;
    lli mid=(b+e)/2;
    lli p1=query(left,b,mid,i,j);
    lli p2=query(right,mid+1,e,i,j);
    return p1+p2;
}

void update(lli node,lli b,lli e,lli i,lli newvalue)
{
    if(i>e or i<b)
        return;
    if(b>=i and e<=i)
    {
        tree[node]=newvalue;
        return;
    }
    lli left=node*2;
    lli right=left+1;
    lli mid=(b+e)/2;
    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
    tree[node]=tree[left]+tree[right];
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    limit(1,1,n);
    for(int i=1;i<2*n;i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    ///please enter the beginning and ending range..
    int start,ending;
    cin>>start>>ending;
    lli res;
    res = query(1,1,n,start,ending);
    cout<<res<<endl;
    lli pos,value;
    ///pree the pos and value to update the positioned value.
    cin>>pos>>value;
    update(1,1,7,pos,value);
    for(int i=1;i<2*n;i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    return 0;
}
