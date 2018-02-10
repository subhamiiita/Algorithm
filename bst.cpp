#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};
struct node *addnode(int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node *insert(struct node *root,int data)
{
    if(root==NULL)
        return addnode(data);
    if(data>root->data)
        root->right=insert(root->right,data);
    else
        root->left=insert(root->left,data);
    return root;
}
struct node *lca(struct node *root,int n1,int n2)
{
   if(root->data > max(n1,n2))
        return lca(root->left,n1,n2);
   else if(root->data<max(n1,n2))
        return lca(root->right,n1,n2);
   else
        return root;
}
void print(struct node *root)
{
    if(root!=NULL)
    {
        print(root->left);
        printf("%d ",root->data);
        print(root->right);
    }
}
int main()
{
    int n,i;
    cin>>n;
    int a[n];
    struct node *root=NULL;
    for(i=0;i<n;i++)
    {
        int data;
        cin>>data;
        if(root==NULL)
            root=insert(root,data);
        else
            insert(root,data);
    }
    print(root);
    int n1,n2;
    cin>>n1>>n2;
    struct node *temp=lca(root,n1,n2);
    cout<<temp->data<<"\n";
}
