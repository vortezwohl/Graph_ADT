#ifndef TRAVERSAL_CPP
#define TRAVERSAL_CPP
#include"../graph.h"
namespace wohl
{
	static GStack stack_0;
	static int current_index = 0;
	void vertex::init_traversal_status()
	{
		for(vertex* check1 = tail; check1 != NULL; check1 = check1->prior)
		{
			check1->traversed = 0;
		}
		return;
	}
	inline void traverse_around(vertex& graph,vertex* target)
	{
		for(; target; target = target->adjnext)
		{
			if(!graph.locate(target->index)->traversed)
			{
				printf("%d ",target->index);
				stack_0.g_push(target->index);
				graph.locate(target->index)->traversed = 1;
			}
		}
	}
	void greedy_traversal(vertex& graph,vertex* target)
	{
		traverse_around(graph,target);
		current_index = stack_0.g_pop();
		if(!current_index)
			return;
		greedy_traversal(graph,graph.locate(current_index));
	}
	void DFS(vertex& graph,vertex* target)
	{
		for(; target; target = target->adjnext)
		{
			if(!graph.locate(target->index)->traversed)
			{
				printf("%d ",target->index);
				graph.locate(target->index)->traversed = 1;
				DFS(graph,graph.locate(target->index));
			}
		}
		return;
	}
}
#endif
