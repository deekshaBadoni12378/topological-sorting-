
from collections import defaultdict

class Graph:
	def __init__(self,vert):
		self.graph = defaultdict(list) 
		self.V = vert

	
	def addEdge(self,u,v):
		self.graph[u].append(v)

	
	def topoUtil(self,v,visited,stack):

		
		visited[v] = True

		
		for i in self.graph[v]:
			if visited[i] == False:
				self.topoUtil(i,visited,stack)

		
		stack.insert(0,v)

	
	def topo(self):
		
		visited = [False]*self.V
		stack =[]

		
		for i in range(self.V):
			if visited[i] == False:
				self.topoUtil(i,visited,stack)

		
		print (stack)

g= Graph(8)
g.addEdge(5, 2);
g.addEdge(5, 0);
g.addEdge(4, 0);
g.addEdge(4, 1);
g.addEdge(2, 3);
g.addEdge(3, 1);
g.addEdge(2, 0);
g.addEdge(3, 0);

print (" Topological Sort ")
g.topo()

