#pragma once
#include<vector>
#include<string>
#include<stack>
#include<iostream>
#include<algorithm>
using namespace std;
class zuochengyun
{
	struct treenode{
		int val; treenode *left, *right;
		treenode(int x = 0, treenode *l = nullptr, treenode *r = nullptr) :val(x), left(l), right(r){}
	};
public:
	zuochengyun();
	~zuochengyun();
	
	//二叉树层序遍历
	void sequenceTraversesBinaryTree(treenode *root, vector<int> &v){
		if (!root) return;
		stack<treenode *> sta;
		sta.push(root);
		while (!sta.empty()){
			int count = sta.size();
			while (count--){
				treenode *top = sta.top();
				sta.pop();
				v.push_back(top->val);
				if (top->right) sta.push(top->right);
				if (top->left) sta.push(top->left);
			}
		}
	}
	//用双向链表把二叉树按中序遍历连接起来
	treenode *doubleListBinaryTreeConect(treenode *root){
		treenode *head=nullptr, *tail = nullptr;
		doubleListBinaryTreeConect(root, head, tail);
		return head;
	}
	void doubleListBinaryTreeConect(treenode *t, treenode *&head, treenode *&tail){
		if (t == nullptr) return;
		if (!t->left&&!t->right){
			head = t; tail = t;
		}
		else if (!t->left&&t->right){
			treenode *l = nullptr, *r = nullptr;
			doubleListBinaryTreeConect(t->right, l, r);
			t->right = l;
			l->left = t;
			head = t;
			tail = r;
		}
		else if (t->left&&!t->right){
			treenode *l = nullptr, *r = nullptr;
			doubleListBinaryTreeConect(t->left, l, r);
			t->left = r;
			r->right = t;
			head = l;
			tail = t;
		}
		else{
			treenode *ls = nullptr, *le = nullptr, *rs = nullptr, *re = nullptr;
			doubleListBinaryTreeConect(t->left, ls, le);
			doubleListBinaryTreeConect(t->right, rs, re);
			le->right = t;
			t->left = le;
			t->right = rs;
			rs->left = t;
			head = ls;
			tail = re;
		}
	}
	void numberPatternPrint(int n){
		bool flag = true;
		int count = 0;
		for (int i = 1; i <= n; i++){
			int start, end;
			start = count+1;
			count += i;
			end = count;
			if (flag == true){
				int j = start;
				for (; j <= end - 1; j++){
					cout << j << '*';
				}
				cout << j << endl;
			}
			else{
				int j = end;
				for (; j >= start + 1; j--){
					cout << j << '*';
				}
				cout << j << endl;
			}
			
			flag = !flag;
		}
	}
};

