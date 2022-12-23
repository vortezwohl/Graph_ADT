#ifndef GS_GQ
#define GS_GQ
#include"../graph.h"
#include<string.h>
namespace wohl
{
	int GStack::g_push(int idx)
	{
		push(std::to_string(idx));
		return idx;
	}
	int GStack::g_pop()
	{
		char c[64]; 
		std::string str=pop(); 
		if(str == "NULL")
			return 0;
		else
		{
			strcpy(c,str.c_str()); 
			return atoi(c);
		}
	}
	int GQueue::g_enqueue(int idx)
	{
		enqueue(std::to_string(idx));
		return idx;
	}
	int GQueue::g_dequeue()
	{
		char c[64]; 
		std::string str=dequeue(); 
		if(str == "NULL")
			return 0;
		else
		{
			strcpy(c,str.c_str()); 
			return atoi(c);
		}
	}
}
#endif
