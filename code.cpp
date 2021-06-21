#include<iostream>
using namespace std;
class node{
	public:
	int val;
	node *right,*left;
	node(int val)
	{
		this->val=val;
		right=left=NULL;
	}
};
class tree{
	public:
	node *root;
	
		tree()
		{
			root=NULL;
		}
		void insert(int data)
		{
			if(root==NULL)
			{
				root=new node(data);
			}
			else
			{
				node *current=root;
				while(true)
				{
					if(current->val>data)
					{
						if(current->left==NULL)
						{
							current->left=new node(data);
							break;
						}
						else
						{
							current=current->left;
						}
					}
					else
					{
						if(current->right==NULL)
						{
							current->right=new node(data);
							break;
						}
						else
						{
							current=current->right;
						}	
					}
				}
			}
		}
		
		int sum_rep(node *rt)
		{
			if(rt==NULL){
				return 0;
			}
			else if(rt->left==NULL && rt->right==NULL)
			{
				return rt->val;
			}
			else
			{
				rt->val=rt->val+sum_rep(rt->left)+sum_rep(rt->right);
			}
			return rt->val;
		}
		int inorder(node *rt)
		{
			if(rt!=NULL)
			{
				inorder(rt->left);
				cout<<rt->val<<" ";
				inorder(rt->right);
			}
		}
		
};
int main()
{
	tree A;
	A.insert(10);
	A.insert(5);
	A.insert(15);
	A.insert(2);
	A.insert(6);
	A.insert(11);
	A.insert(16);
	A.inorder(A.root);
	cout<<endl;
	A.sum_rep(A.root);
	A.inorder(A.root);
}
