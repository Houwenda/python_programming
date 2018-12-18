using namespace std;
#include <iostream>
#define ELEMENT_TYPE int

struct BiTNode{
	ELEMENT_TYPE data;
	BiTNode* lchild;
	BiTNode* rchild;
};

void swap(BiTNode p) {
	BiTNode* tmp;
	tmp = p.lchild;
	p.lchild = p.rchild;
	p.rchild = tmp;
	if(p.lchild != NULL) swap(*p.lchild);
	if(p.rchild != NULL) swap(*p.rchild);
}

int depth(BiTNode p) {
	int x=0,y=0;
	if(p.lchild != NULL) x = depth(*p.lchild);
	if(p.rchild != NULL) y = depth(*p.rchild);
	if(x > y) return x+1;
	else return y+1;
}

int main() {
	return 0;
}
