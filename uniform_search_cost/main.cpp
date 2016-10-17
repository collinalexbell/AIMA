#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

template<typename T>
struct Vertex;

template<typename D>
struct Node {
	int cost_to_here;
	vector< Vertex<D>* > vs;
	D data;
	Node(D data_){
		data = data_;
		cost_to_here = 0;
	}
	void add_vertex(Vertex<D>* v){
		vs.push_back(v);
	}
};

template<typename T>
struct Vertex {
	Node<T>* to;
	int cost;
	Vertex(Node<T>* to_, int cost_){
		to = to_;
		cost = cost_;
	}
};

struct VComparator {
	bool operator()(const Vertex<string>* a, const Vertex<string>* b){
		return a->cost > b->cost;
	}
};

void uniform_cost_search
(Node<string>* n,
 string goal,
 priority_queue< Vertex<string>*, vector< Vertex<string>*  >, VComparator> q,
 set< Node<string>* > v)
{
	printf("Expanded: %s with cost to here: %d\n", n->data.c_str(), n->cost_to_here);
	if(n->data == goal){
		printf("Found goal!\n");
		return;
	}

	//Add verticies to the frontier
	for(auto i = n->vs.begin(); i != n->vs.end(); i++){
		if(v.find((*i)->to) == v.end()){
			(*i)->cost += n->cost_to_here;
			q.push(*i);
		}
	}

	if(q.size() == 0){
		printf("Failure");
	}
	//Expand the first
	Node<string>* top = q.top()->to;
	top->cost_to_here = q.top()->cost;
	v.insert(top);
	q.pop();
	uniform_cost_search(top, goal, q, v);
}

int main(){
	vector< Node<string>* > nodes;
	nodes.push_back(new Node<string>("Sibiu"));
	nodes.push_back(new Node<string>("Fagaras"));
	nodes.push_back(new Node<string>("Rimnicu Vilcea"));
	nodes.push_back(new Node<string>("Pitesti"));
	nodes.push_back(new Node<string>("Bucharest"));
	nodes[0]->add_vertex(new Vertex<string>(nodes[1], 99));
	nodes[0]->add_vertex(new Vertex<string>(nodes[2], 80));
	nodes[1]->add_vertex(new Vertex<string>(nodes[4], 211));
	nodes[2]->add_vertex(new Vertex<string>(nodes[3], 97));
	nodes[3]->add_vertex(new Vertex<string>(nodes[4], 101));
	priority_queue< Vertex<string>*, vector< Vertex<string>* >, VComparator > q;
	set< Node<string>* > v;
	uniform_cost_search(nodes[0], "Bucharest", q, v);
}
