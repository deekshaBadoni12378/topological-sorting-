#include <iostream>
#include <conio.h>
#include <list>
#include <stack>
using namespace std;
class Graph {
	int Vertx;


	list<int>* adj;


	void topoUtil(int v, bool visited[], stack<int>& Stack);

public:
	Graph(int Vertx);


	void addEdge(int v, int w);


	void topo();
};

Graph::Graph(int Vertx)
{
	this->Vertx = Vertx;
	adj = new list<int>[Vertx];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::topoUtil(int v, bool visited[],
								stack<int>& Stack)
{

	visited[v] = true;


	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			topoUtil(*i, visited, Stack);

	Stack.push(v);
}



void Graph::topo()
{
	stack<int> Stack;


	bool* visited = new bool[Vertx];
	for (int i = 0; i < Vertx; i++)
		visited[i] = false;


	for (int i = 0; i < Vertx; i++)
		if (visited[i] == false)
			topoUtil(i, visited, Stack);


	while (Stack.empty() == false) {
		cout << Stack.top() << " ";
		Stack.pop();
	}
}


int main()
{

	Graph g(8);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

	cout << " Topological Sort ";
	g.topo();

	return 0;
}
