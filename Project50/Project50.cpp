#include<iostream>
#include<string>
using namespace std;

struct node
{
	int info;
	int height;
	int equal;
	node* left;
	node* right;
};
int first = 0;
//====================================================================================================================================================================
node* makeNode(int info)
{
	node* childnode;
	childnode = new node;
	childnode->info = info;
	childnode->height = 0;
	childnode->equal = 0;
	childnode->left = NULL;
	childnode->right = NULL;
	return childnode;
}
struct queue
{
	node *du[60];
	int last = 0;
	void push(node*head)
	{
		du[last] = head;
		last++;
	}
	void pop()
	{
		int a = first; first++;

	}
	node*front()
	{
		int a = first;
		return du[a];
	}
	int em()
	{
		if (last == first)return 1;
		else return 0;
	}
};
//====================================================================================================================================================================
int max(int x, int y)
{
	if (x > y) return x;
	else return y;
}
//====================================================================================================================================================================
int height(node *N)
{
	if (N == NULL)
	return 0;
	return N->height;
}
//====================================================================================================================================================================
int getnodes(node *head)
{
	if (head == NULL)return 0;
	else return 1 + getnodes(head->left) + getnodes(head->right);
}
//====================================================================================================================================================================
node *rightRotate(node *y)
{
	node *x = y->left;
	node *T2 = x->right;
	x->right = y;
	y->left = T2;
	y->height = max(height(y->left),height(y->right)) + 1;
	x->height = max(height(x->left),height(x->right)) + 1;
	return x;
}
//====================================================================================================================================================================
node *leftRotate(node *x)
{
	node *y = x->right;
	node *T2 = y->left;
	y->left = x;
	x->right = T2;
	x->height = max(height(x->left),height(x->right)) + 1;
	y->height = max(height(y->left),height(y->right)) + 1;


	return y;
}
//====================================================================================================================================================================
void SinglerotateLeft(node * &T)
{
	node * p = T->right;
	node * q = p->left;
	p->left = T;
	T->right = q;
	T->height -= 2;
	T = p;
}
//====================================================================================================================================================================
void SinglerotateRight(node * &T)
{
	node * p = T->left;
	node * q = p->right;
	p->right = T;
	T->left = q;
	T->height -= 2;
	T = p;
}
//====================================================================================================================================================================
void DoublerotateRifgtLeft(node * &T)
{
	SinglerotateRight(T->right);
	T->right->height += 1;
	T->right->right->height += 1;
	SinglerotateLeft(T);
}
//====================================================================================================================================================================
void DoublerotateLeftRight(node * &T)
{
	SinglerotateLeft(T->left);
	T->left->height += 1;
	T->left->left->height += 1;
	SinglerotateRight(T);
}
//====================================================================================================================================================================
void BST(node * &Tree, int c)
{
	node * T;
	T = makeNode(c);
	if (!Tree) Tree = T;
	else
	{
		if (c < Tree->info)
		{
			BST(Tree->left, c);
			Tree->height = max(Tree->left->height + 1, Tree->height);
			if (Tree->right && Tree->left->height - Tree->right->height == 2 || !Tree->right &&Tree->height == 2)
			if (c < Tree->left->info)SinglerotateRight(Tree);
				else DoublerotateLeftRight(Tree);
		}
		else if (c > Tree->info)
		{
			BST(Tree->right, c);
			Tree->height = max(Tree->right->height + 1, Tree->height);
			if (Tree->left&&Tree->right->height - Tree->left->height == 2 || !Tree->left &&Tree->height == 2)
			{
				if (Tree->right->info < c)SinglerotateLeft(Tree);
				else DoublerotateRifgtLeft(Tree);
			}
		}
	}
}
//====================================================================================================================================================================
void inorder(node * Tree)
{
	if (!Tree) return;
	else
	{
		inorder(Tree->left);
		cout << Tree->info << "  " << endl;
		inorder(Tree->right);
	}

}
//====================================================================================================================================================================
int w = 0; int A[20]; int p = 0, j = 0, S[20]; int add = 0;
void print_tree(node *head)
{
	add = getnodes(head);
	int y = 0;
	int count = 0;
	queue q; first = 0;
	node *ip = new node;
	ip->left = ip->right = NULL;
	q.push(head); count++;
	q.push(ip);
	{
		while (y <= add)
		{
			y++;
			node*cu = q.front();
			q.pop();
			if (cu != ip && cu)
			{
				if (cu->left != NULL) 
				{
					q.push(cu->left);
					count++;
				}
				if (cu->left == NULL) 
				{
					q.push(NULL); count++;
				}
				if (cu->right != NULL) 
				{
					q.push(cu->right); count++;
				}
				if (cu->right == NULL) 
				{
					q.push(NULL); count++;
				}
			}
			else 
			{
				q.push(ip);
				count++;
			}
		}
		first = 0; 
		int o = count, space = 2, n = count - 3, m = 0, M = 0;
		for (size_t i = 0; i < count; i++)
		{
			cout << "  ";
		}
		cout << q.front()->info;
		q.pop();
		q.pop();
		o = o / 2; 
		cout <<endl <<endl;
		for (size_t i = 0; i < o; i++)
		{
			cout << "  ";
		}

		while (!q.em())
		{
			if (q.front() != NULL && q.front() != ip) {
				cout << q.front()->info;
				if (m % 2 == 0) 
				{
					for (int i = 0; i < count; i++)
						cout << "  ";
				}
				else 
				{
					for (int i = 0; i < o; i++)cout << "  ";
				}
				q.pop();

			}
			if (q.front() == NULL) 
			{
				//cout << " ";
				for (int i = 0; i < count; i++)
				cout << "  "; q.pop();
			}
			if (q.front() == ip) 
			{
				cout << endl <<endl;
				cout << endl <<endl; 
				q.pop();
				o = o / 2; count = count / 2;
				for (int i = 0; i < o; i++)cout << "  ";
			}
			M++;
		}
	}
}


//====================================================================================================================================================================
void Search(node* root, int data) {
	if (root == NULL) {
		cout << data << " not found in tree" << endl;
	}
	else if (root->info == data) {
		cout << data << " found in tree" << endl;
	}
	else if (data <= root->info) {
		Search(root->left, data);
	}
	else {
		Search(root->right, data);
	}
}
//====================================================================================================================================================================
void Delete(node* & Tree, int c)
{
	node* p, *q, *r;
	if (!Tree) cout << "The value " << c << " Is not on the tree" << endl;
	else if (Tree->info > c) Delete(Tree->left, c);
	else if (Tree->info < c) Delete(Tree->right, c);
	else if (Tree->info == c)
	{
		if (!Tree->left && !Tree->right)
			Tree = NULL;
		else if (!Tree->left)
			Tree = Tree->right; //Tree has only left child
		else if (!Tree->right) //Tree has only right child
			Tree = Tree->left;
		else //Tree has two children 
		{
			r = Tree; p = Tree->left; q = p->right;
			while (q) // find the right most child in the left subtree to replace and fix the tree :D
			{
				r = p;	p = q; q = q->right;
			}
			Tree->info = p->info;
			if (r != Tree) r->right = p->left;
			else r->left = p->left;
		}
		cout << "The Value " << c << " has been deleted from tree" << endl;
	}
}
//====================================================================================================================================================================
int main()
{
	node * Tree = NULL;
	int choice;
	int a;
	int b;
	cout << "===============================================" << endl;
	cout << "1-Insert a number" << endl;
	cout << "2-Delete a number" << endl;
	cout << "3-Print The Tree" << endl;
	cout << "4-Exit the program" << endl;
	cout << "===============================================" << endl;
	cin >> choice;
	while (choice != 4)
	{
		switch (choice)
		{
		case 1:
			cout << "Enter a number "; cin >> a; BST(Tree, a);
			cout << "===============================================" << endl;
			cout << "1-Insert a number" << endl;
			cout << "2-Delete a number" << endl;
			cout << "3-Print The Tree" << endl;
			cout << "4-Exit the program" << endl;
			cout << "===============================================" << endl;
			break;

		case 2:
			cout << "Enter a number "; cin >> b; Delete(Tree, b);
			cout << "===============================================" << endl;
			cout << "1-Insert a number" << endl;
			cout << "2-Delete a number" << endl;
			cout << "3-Print The Tree" << endl;
			cout << "4-Exit the program" << endl;
			cout << "===============================================" << endl;
			break;

		case 3:
			print_tree(Tree);
			cout << endl;
			cout << "===============================================" << endl;
			cout << "1-Insert a number" << endl;
			cout << "2-Delete a number" << endl;
			cout << "3-Print The Tree" << endl;
			cout << "4-Exit the program" << endl;
			cout << "===============================================" << endl;
			break;
		}
		cout << endl;
		cin >> choice;
	}
}




