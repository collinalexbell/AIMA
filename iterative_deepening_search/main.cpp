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


//Returns 3 possible results
// 1 if found
// -1 if depth limit reached and not found
// 0 if not found
int dfs(Node* root, string goal, int limit = -1, int depth = 0){
	//This could be a VERY expensive check.
	int success = 0;
	if(root->data == goal){
		printf("Found!!");
		return 1;
	}
	if(depth == limit){return -1;}

	for(auto i = root->connections.begin(); i != root->connections.end(); i++){
		int result;
		result = dfs(*i, goal, limit, depth + 1);
		if(result == 1){
			return 1;
		}
		if(result < 0){
			success = result;
		}
	}

	return success;
}

int ids(Node* root, string goal){
	int success = -1;
	int limit = 0;
	//Run dfs increasing the limit until the depth limit is no longer reached or item found.
	while(success == -1){
		success = dfs(root, goal, limit);
		limit ++;
	}
	return success;
}


/*
	                 
               f---i---j
	   b---------|
 a---|         e---g---h
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

	int result;
	result = ids(nodes[0], "f");
}


