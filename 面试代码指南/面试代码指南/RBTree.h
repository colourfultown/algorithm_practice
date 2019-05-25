#pragma once
template <typename comparable>
class RBTree
{
public:
	RBTree();
	~RBTree();
	void insert(const comparable &x){
		insert(x, root);
	}
private:
	struct rbnode{
		comparable element;
		rbnode *left, *right, *father;
		char flag;
		rbnode(comparable &rhs, rbnode *l = nullptr, rbnode *r = nullptr, rbnode *fa = nullptr, char f = 'R')
			:element(rhs), left(l), right(r), father(fa), flag(f){}
	} *root;
	void insert(const comparable &x, rbnode * &t){
		if (t == nullptr) {
			t = new rbnode(x);
			return;
		}
		if (t->element == x){}
		else if (t->element > x){
			insert(x, t->left);

		}
		else if (t->element < x){
			insert(x, t->right);
		}

	}

};

