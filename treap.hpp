// UVA 536 Tree Recovery

class treap {
public:
	treap(int k, int p): key(k), pri(p), l(NULL), r(NULL){}
	~treap(){}
	int key, pri;
	node* l;
	node* r;
};

treap* merge(node* a, node* b)
{
	if(!a || !b) return a ? a : b;
	if(a->pri < b->pri) {
		a->r = merge(a->r, b);
		return a;
	} else {
		b->l = merge(a, b->l);
		return b;
	}
}

void print(treap* t) {
	if(!t) return;
	print(t->l);
	print(t->r);
	cout << in[t->key];
}

void del(treap* t) {
	if(!t) return;
	del(t->l);
	del(t->r);
	delete t;
}

void f() {
	string pre, in;
	int pri['Z' + 1] = {};
	treap* t = NULL;
	for(unsigned int i = 0; i < pre.length(); ++i) {
		pri[pre[i]] = i;
	}
	for(unsigned int i = 0; i < in.length(); ++i) {
		int j = pri[in[i]];
		t = merge(t, new node(i, j));
	}
	print(t);
	del(t);
	cout << endl;
}