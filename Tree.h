#include <iostream>
#include <queue>
#include <stack>
#include <string>
#define MaxSize 100
#include <cstdio>
using namespace std;
typedef char ElemType2;
typedef int ElemType;
typedef struct BiTNode
{
	ElemType2 data;
	struct BiTNode* lchild, * rchild;
} BiTNode, * BiTree;

// 字符串建立二叉树

void Creat_Tree(BiTree& BT)
{
	ElemType2 ch;
	cin >> ch;
	if (ch == '#')
	{
		BT = NULL;
	}
	else
	{
		BT = new BiTNode();
		BT->data = ch;
		cout << ch << "左孩子：";
		Creat_Tree(BT->lchild);
		cout << ch << "右孩子：";
		Creat_Tree(BT->rchild);
	}
}

void Visit(BiTNode* t)
{
	cout << t->data << " ";
}
void PreOrder(BiTree& BT)
{
	if (BT != NULL)
	{
		Visit(BT);
		PreOrder(BT->lchild);
		PreOrder(BT->rchild);
	}
}
void InOrder(BiTree& BT)
{
	if (BT != NULL)
	{
		InOrder(BT->lchild);
		Visit(BT);
		InOrder(BT->rchild);
	}
}

void PostOrder(BiTree& BT)
{
	if (BT != NULL)
	{
		PostOrder(BT->lchild);
		PostOrder(BT->rchild);
		Visit(BT);
	}
}
void LevelOrder(BiTree& BT)
{
	if (BT == NULL)
	{
		return ;
	}
	queue<BiTNode*> Q;
	BiTNode* q;
	Q.push(BT);
	while (!Q.empty())
	{
		q = Q.front();
		Q.pop();
		Visit(q);
		if (q->lchild!=NULL)
		{
			Q.push(q->lchild);
		}
		if (q->rchild!=NULL)
		{
			Q.push(q->rchild);
		}
	}
	cout << endl;
}

int LevelCount(BiTree& BT)
{
	int front = -1, rear = -1;
	int last = 0;
	int i = 0;
	BiTree Q[MaxSize];
	Q[++rear] = BT;
	BiTree q;
	while (front < rear)
	{
		q = Q[++front];
		if (q->lchild)
		{
			Q[++rear] = q->lchild;
		}
		if (q->rchild)
		{
			Q[++rear] = q->rchild;
		}
		if (last == front)
		{
			i++;
			last = rear;
		}
	}
	return i;
}

int* widthCount(BiTree& BT, int& count)
{
	int front = -1, rear = -1;
	int last = 0;
	int i = 0;
	BiTree Q[MaxSize];
	Q[++rear] = BT;
	int* Level;
	Level = new int[MaxSize];
	BiTree q;
	Level[0] = 0;
	while (front < rear)
	{
		q = Q[++front];
		Level[i]++;
		if (q->lchild!=NULL)
		{
			Q[++rear] = q->lchild;
		}
		if (q->rchild!= NULL)
		{
			Q[++rear] = q->rchild;
		}
		if (last == front)
		{
			i++;
			Level[i] = 0;
			last = rear;
		}
	}
	count = i;
	return Level;
}


void PostOrder2(BiTree& BT)
{
	stack<BiTNode*> S;
	BiTNode* r = NULL, * p;
	p = BT;
	while (p || !S.empty())
	{
		if (p != NULL)
		{
			S.push(p);
			p = p->lchild;
		}
		else
		{
			p = S.top();
			if (p->rchild && p->rchild != r)
			{
				p = p->rchild;
				S.push(p);
				p = p->lchild;
			}
			else
			{
				Visit(p);
				r = p;
				S.pop();
				p = NULL;
			}
		}
	}
}

bool Is_Sub(string str1, string str2)
{
	if (str1 == "" || str2 == "")
	{
		return false;
	}
	int i = 0, j = 0;
	stack<char> s;
	s.push(str1.at(0));
	while (str2.at(j)!='\0') {
		if (s.empty() && str1[i + 1] != '\0') {
			s.push(str1.at(++i));
		}
		else {
			char e = s.top();
			if (e!= str2.at(j)) {
				
				if (str1.at(i+1) != '\0') {
					i++;
					s.push(str1.at(i));
				}
			}
			else {
				++j;
				s.pop();
			}
		}
	}

	if (s.empty()) return false;
	else return true;

}


// 二叉排序数
bool BST_Insert(BiTree& T, ElemType k) {
	if (T == NULL) {
		T = new BiTNode();
		T->data = k;
		T->lchild = NULL;
		T->rchild = NULL;
		return true;
	}
	else if (T->data == k) {
		return false;
	}
	else if (T->data < k) {
		return BST_Insert(T->rchild, k);
	}
	else {
		return BST_Insert(T->lchild, k);
	}
}

void BST_creat(BiTree& T, int Inte[], int n) {
	T = NULL;
	int i = 0;
	while (i < n) {
		BST_Insert(T, Inte[i] + '0');
		i++;
	}
}


// 先序和中序确定一棵树
void CreateTreePI(BiTNode*& root, string pre, int l1, int r1, string in, int l2, int r2) {
	if (l1 <= r1 && l2 <= r2)
	{
		int key = pre[l1];
		int midIndex = in.find(key);
		root = new BiTNode();
		root->data = key;
		root->lchild = NULL;
		root->rchild = NULL;
		int llen = midIndex - l2;
		CreateTreePI(root->lchild, pre, l1 + 1, l1 + llen, in, l2, midIndex - 1);
		CreateTreePI(root->rchild, pre, l1 + llen + 1, r1, in, midIndex + 1, r2);
	}

}
// 后序和中序确定一棵树
void CreateTreeIP(BiTNode*& root, string in, int l1, int r1, string post, int l2, int r2) {
	if (l1 <= r1 && l2 <= r2)
	{
		int key = post[r1];
		int midIndex = in.find(key);
		root = new BiTNode();
		root->data = key;
		root->lchild = NULL;
		root->rchild = NULL;
		int llen = midIndex - l2;
		CreateTreeIP(root->lchild, in, l1, l1 + llen - 1, post, l2, midIndex - 1);
		CreateTreeIP(root->rchild, in, l1 + llen, r1 - 1, post, midIndex + 1, r2);
	}

}


void test_tree()
{
	string str1 = "1234567";
	string str2 = "3254176";
	bool s = Is_Sub(str1,str2);
	if (s) {
		cout << "yes";
	}
	else {
		cout << "no";
	}
	//string str3 = "3542761";
	//BiTNode* root = new BiTNode();

	//CreateTreePI(root, str1,0,str1.size()-1,str2,0,str2.size()-1);
	//CreateTreeIP(root, str2, 0, str2.size() - 1, str3, 0, str3.size() - 1);
	//PreOrder(root);
}