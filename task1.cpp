
#include <iostream>
using namespace std;

class Node{
	public:
		int node;
		void Set_Node(int a);
		void showNode();

};

void Node::Set_Node(int a){
	    node = a;
};

void Node::showNode(){
	cout << "½ÚµãÎª£º"<<node<<endl; 
}

int main(){
	int a;
	Node node;
	cin>>a;
	node.Set_Node(a);
	node.showNode();
	return 0; 
}
