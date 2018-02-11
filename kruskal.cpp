#include<bits/stdc++.h>
using namespace std;
int parent[100005];
int s[100005];
vector<pair<int,pair<int,int> > >v;
vector<pair<int,pair<int,int> > >mst;
void addEdge(int x,int y,int w)
{
    v.push_back(make_pair(w,make_pair(x,y)));
}
void build(int n)
{
    int i;
    for(i=0;i<=n;i++)
    {
        parent[i]=i;
        s[i]=1;
    }
}
int find(int x)
{
	if (x!=parent[x])
		return parent[x]=find(parent[x]);
	return x;
}
int Union(int x,int y)
{
	int px= find(x);
	int py= find(y);
	if(px==py)
        return 0;
	if(s[px]>=s[py])
	{
	    parent[py]=parent[px];
	    s[px]+=s[py];
	    return 1;
	}
	else
	{
		parent[px]=parent[py];
	    s[py]+=s[px];
	    return 1;
	}
}
void kruskal(int n)
{
        int i;
        for(i=0;i<v.size();i++)
        {
            int x=v[i].second.first;
            int y=v[i].second.second;
            int weight=v[i].first;
            int p=Union(x,y);
            if(p==1)
            {
                mst.push_back(make_pair(x,make_pair(y,weight)));
            }
        }
}
int main()
{
    int n,e,i;
    cin>>n>>e;
    build(n);
    for(i=1;i<=e;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        addEdge(x,y,w);
    }
    sort(v.begin(),v.end());
    kruskal(n);
    for(i=0;i<mst.size();i++)
    {
        cout<<mst[i].first<<" "<<mst[i].second.first<<" "<<mst[i].second.second<<"\n";
    }
	return 0;
}

