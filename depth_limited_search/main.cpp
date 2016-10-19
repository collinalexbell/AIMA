#include <stdio.h>
#include <string>
#include <vector>

using namespace std;


struct Node{
	string data;
	vector<Node*> connections;
	Node(string data_){
		data = data_;
	}
	void add_connection(Node* c){
		connections.push_back(c);
	}
};


//Root is depth 0. If limit is 1 then it will find if the node is in depth 1
//Do not pass limit and depth and it just runs normally
//"Depth-first search can be viewed as a special case of depth-limited search with l = ∞."
void dfs(Node* root, string goal, int limit = -1, int depth = 0){
	//This could be a VERY expensive check.
	if(root->data == goal){
		printf("Found!!");
	}
	if(depth == limit){return;}

	for(auto i = root->connections.begin(); i != root->connections.end(); i++){
		dfs(*i, goal, limit, depth + 1);
	}
}


/*
               f
	   b---------|
 a---|         e
     c---d
*/
int main(){
	vector<Node*> nodes;
	nodes.push_back(new Node("a"));
	nodes.push_back(new Node("b"));
	nodes.push_back(new Node("c"));
	nodes.push_back(new Node("d"));
	nodes.push_back(new Node("e"));
	nodes.push_back(new Node("f"));

	nodes[0]->add_connection(nodes[1]);
	nodes[0]->add_connection(nodes[2]);
	nodes[2]->add_connection(nodes[3]);
	nodes[1]->add_connection(nodes[4]);
	nodes[1]->add_connection(nodes[5]);

	dfs(nodes[0], "f", 1);
}


