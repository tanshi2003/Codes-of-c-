#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *left;
	struct node *right;
	int lthread;
	int rthread;
};
struct node * createtree(int x)
{
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	p->info=x;
	p->left=NULL;  p->lthread=1;
	p->right=NULL; p->rthread=1;
	return p;
}
void setleft(struct node *p,int x)
{
	struct node *q;
	struct node *r;
	q=(struct node*)malloc(sizeof(struct node));
	q->info=x;
	r=p->left;
	p->left=q;  p->lthread=0;
	q->left=r;  q->lthread=1;
	q->right=p; q->rthread=1;
}
void setright(struct node *p,int x)
{
	struct node *q,*r;
	q=(struct node*)malloc(sizeof(struct node));  
	q->info=x;
	r=p->right;
	p->right=q;   p->rthread=0;
	q->left=p;    q->lthread=1;
	q->right=r;   q->rthread=1;
}
void insertnode(struct node *tree,int x)
{
	struct node *p,*q;
	if(tree==NULL)
		tree=createtree(x);
	else if(x>tree->info)
	{
		if(tree->rthread==1)
			setright(tree,x);
		else
			insertnode(tree->right,x);
	}
	else if(x<tree->info)
	{
		if(tree->lthread==1)
			setleft(tree,x);
		else
			insertnode(tree->left,x);
	}
	
}
struct node*searchnode(struct node *tree,int x)
{
	
	if((tree==NULL)||(tree->info==x))
		return tree;
	else if(x>tree->info)
	{
		if(tree->rthread==1)
			return(NULL);
		else
			return searchnode(tree->right,x);
	}
	else if(x<tree->info)
	{
		if(tree->lthread==1)
			return NULL;
		else
			return searchnode(tree->left,x);
	}
}
struct node * predecessor(struct node *p)
{
	struct node *pred;
	pred=p->left;
	if(p->lthread==0)
	{
		while(pred->rthread==0)
			pred=pred->right;
	}
	return pred;
}
struct node * successor(struct node *p)
{
	struct node *succ;
	succ=p->right;
	if(p->rthread==0)
	{
		while(succ->rthread==0)
			succ=succ->left;
	}
	return succ;
}
void inorder(struct node *tree)
{
	struct node *p,*q;  p=tree;
	do
	{
		q=p;
		while(p!=NULL && p->lthread==0)
		{
			p=p->left;  q=p;
		}
		if(q!=NULL)
		{
			printf("%d\t",q->info);
			p=q->right;
			while(p!=NULL && q->rthread==1)
			{
				printf("%d\t",p->info);
				q=p;
				p=p->right;
			}
		}
	}while(q!=NULL);
}
void preorder(struct node *tree)
{
	struct node *p,*q;  p=tree;
	do
	{
		q=p;
		while(p!=NULL && p->lthread==0)
		{
			printf("%d\t",p->info);
			p=p->left;   q=p;
		}
		if(q!=NULL)
		{
			printf("%d\t",p->info);
			p=q->right;
			while(p!=NULL && q->rthread==1)
			{
				q=p;  p=p->right;
			}
		}
	}while(q!=NULL);
}
main()
{
	struct node* tree=NULL;
	struct node* t=NULL;
	int ch,x,n,r,v,i;
	printf("Enter the no. of nodes:");
	scanf("%d",&n);
	printf("Enter root node:");
	scanf("%d",&r);
	tree=createtree(r);
	for(i=0;i<n-1;i++)
	{
		printf("Enter the value of other nodes:");
		scanf("%d",&x);
		insertnode(tree,x);
	}
	do
	{
		printf("\n1.Search\n2.Inorder\n3.Preorder\n4.Successor\n5.Predecessor\n6.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the value to be search:");
				scanf("%d",&v);
				t=searchnode(tree,v);
				if(t==NULL)
					printf("Element not found.");
				else
					printf("Element found!");
				break;
			case 2:
				printf("Inorder traversal:");
				inorder(tree);
				break;
			case 3:
				printf("preorder traversal:");
				preorder(tree);
				break;
			case 4:
				t=successor(tree);
				printf("%d",t->info);
				break;
			case 5:
				t=predecessor(tree);
				printf("%d",t->info);
				break;
		}
	}while(ch!=6);
}
