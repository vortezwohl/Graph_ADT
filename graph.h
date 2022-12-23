//weighted digraph on adjacent chain tables
//by wohl 2022 Nov.11
#ifndef GRAPH_H
#define GRAPH_H
#define MAXINT 2147483647
#define END MAXINT
#include<stdio.h>
#include"lib/bitree_l.cpp"
#include"lib/sorts.cpp"
namespace wohl
{
	class vertex
	{
		protected:
		//data
		int index;
		int weight;		
		bool traversed;							
		//pointers
		vertex* adjnext;
		vertex* head;
		vertex* tail;
		vertex* alter;
		vertex* next;
		vertex* prior;
		vertex* v_remove(vertex* vert);								//remove all edges of a vertex
		public:		
		//command line print methods
		void print_vertexes()									//which tells you the list of vertexes
		{
			printf("vertexes: ");
			for(vertex* v=tail;v!=NULL;v=v->prior)
			printf("v%d ",v->index);
		}
		void print_adjv(int idx,vertex* vert)							//print edges of vertex idx
		{
			printf("weight<v%d,v%d>=%d\n",idx,vert->index,vert->weight);
		}
		//con/destructors
		vertex();
		~vertex();
		vertex(int idx,int weit);								//adjnext
		vertex(int idx);									//next
		//methods of digraph
		vertex* setv(int idx);									//create a new node
		vertex* setv(int* idxs);								//create a series of nodes according to an array
		vertex* sete(int idx1,int idx2,int weit);						//set an edge linking idx2 to idx1
		vertex* rmv(int idx);									//remove an existing node
		vertex* rme(int idx1,int idx2);								//remove an existing edge <idx1,idx2>
		vertex** edgeof(int idx);								//return an array of address and weight
		vertex* locate(int idx);								//return the address of current vertex in vertex list
		vertex* locate(int idx1,int idx2);							//return the address of current vertex in adjacency list of vertex idx1
		void init_traversal_status();								//init_traversal_status
		friend void traverse_around(vertex& graph,vertex* target);				//traverse around a vertex
		friend void greedy_traversal(vertex& graph,vertex* target);				//greedily traverse the graph
		friend void DFS(vertex& graph,vertex* target);						//depth first search
		//friend void BFS_push_stack(vertex& graph,vertex* target);				//prepare the stack for BFS
		//friend void BFS(vertex& graph,vertex* target);					//breadth first search
		//more for developing...
	};
	class Graph:public vertex{};
	class GStack:private linked_list
	{
		public:
		GStack():linked_list(){};
		int g_push(int idx);
		int g_pop();
	};
	class GQueue:private linked_list
	{
		public:
		GQueue():linked_list(){};
		int g_enqueue(int idx);
		int g_dequeue();
	};
	typedef vertex** v_array;
}
#include"lib/graph_adt.cpp"
#include"lib/traversal.cpp"
#include"lib/GStack_GQueue.cpp"
#endif
