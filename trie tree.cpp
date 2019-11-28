#include<bits/stdc++.h>

#define sc scanf
#define pf printf
#define scin(x) sc("%d",&(x))
#define scln(x) sc("%lld",&(x))
using namespace std;
struct TrieNode
{
    map<char, TrieNode*> children;
    int prefix;
    bool endofword;
    TrieNode()
    {
        prefix = 0;
        endofword = false;
    }
};

void insert(TrieNode *root, string s)
{
    TrieNode *current = root;
    int len = s.size();
    for(int i=0; i<len; i++)
    {
        int val = s[i]-'a';
        TrieNode *node = current->children[val];
        if(!node)
        {
            node = new TrieNode();
            current->children[val] = node;
        }
        current = node;
        current->prefix++;
    }
    current->endofword = true;
}

bool search(TrieNode *root,string word)
{
	TrieNode *current=root;
	for(int i=0;i<word.size();i++)
	{
		int ch=word[i]-'a';
		TrieNode *node=current->children[ch];
		if(!node)
			return false;
		current=node;
	}
	return current->endofword;
}

int count_prefix(TrieNode *root,string word)
{
	TrieNode *current=root;
	for(int i=0;i<word.size();i++)
	{
		int ch = word[i] - 'a';
		TrieNode *node=current->children[ch];
		if(!node)
		{
			return 0;
		}
		current=node;
	}
	return current->prefix;
}

void del(TrieNode* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->children[i])
            del(cur->children[i]);

    delete (cur);
}

int main()
{
    int test;
    scin(test);
    for(int t=1; t<=test; t++)
    {
        int n,q,p;
        scin(n);
        scin(q);
        scin(p);
        string s;
        TrieNode *root = new TrieNode();
        for(int i=0; i<n; i++)
        {
            cin>>s;
            insert(root,s);
        }
        for(int i=0; i<q; i++)
        {
            cin>>s;
            if(search(root,s))
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;
        }
        for(int i=0; i<p; i++)
        {
            cin>>s;
            int res = count_prefix(root,s);
            cout<<res<<endl;
        }
        del(root);
    }
    return 0;
}
