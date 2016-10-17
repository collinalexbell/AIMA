#include<stdio.h>
#include<vector>
#include<queue>
#include<set>

struct Node{
	int data;
	std::vector<Node*> children;

	Node(int data_){
		data = data_;
	}

	void add_node(struct Node *node){
		children.push_back(node);
	}
};

void bfs(Node *root, std::queue<Node*> q, std::set<Node*> visited, int goal){
	if(root->data == goal){
		printf("GOAL!!\n");
	}


	//Add all of the roots children to q 
	for(auto i = root->children.begin(); i != root->children.end(); i++){
		if(visited.end() == visited.find(*i)){
			q.push(*i);
		}
	}

	//Try next item in queue
	if(q.size() == 0){
		return;
	}
	Node* next = q.front();
	q.pop();
	bfs(next, q, visited, goal);
	
}

int main(int argc, const char * argv[]){
	printf("A demo of bfs\n");
	Node *a = new Node(1);
	Node *b = new Node(2);
	Node *c = new Node(3);
	Node *d = new Node(4);

	a->add_node(b);
	a->add_node(c);
	b->add_node(d);
	
	bfs(a, std::queue<Node*>(), std::set<Node*>() , 4);
}
