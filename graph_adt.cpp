//weighted digraph on adjacency list
//by wohl 2022 Nov.11
#ifndef GRAPH_ADT
#define GRAPH_ADT
#include"../graph.h"
namespace wohl
{
	//con/destructors
	vertex::vertex()
	{
		adjnext = NULL;
		head = new vertex(-1);
		tail = head;
		alter = NULL;
		next = NULL;
		prior = NULL;
		index = -1;
		weight = 0;
		traversed = 0;
	}
	vertex::~vertex()
	{}
	vertex::vertex(int idx,int weit)
	{
		adjnext = NULL;
		next = NULL;
		prior = NULL;
		index = idx;
		weight = weit;
		traversed = 0;
	}
	vertex::vertex(int idx)
	{
		adjnext = NULL;
		next = NULL;
		prior = NULL;
		index = idx;
		weight = MAXINT;
		traversed = 0;
	}
	//up there are constructors
	//methods below
	vertex* vertex::setv(int idx)
	{
		if(idx < 0)
		return NULL;
		//if this is the first node
		if(head->index == -1)
		{
			head->next = new vertex(idx);
			alter = head;
			head = head->next;
			tail = head;
			delete alter;
			alter = NULL;
		}
		//not the first node. do this
		else if(head->index >= 0)
		{
			alter = new vertex(idx);
			alter->next = head;
			head->prior = alter;
			head = alter;
		}
		return head;
	}
	vertex* vertex::setv(int* idxs)
	{
		int amount = 0;
		//get amount of elements in array
		for(;;)
		{
			if(MAXINT - *idxs)
			{
				amount++;
				idxs++;
			}
			else
			{
				idxs-=amount;//initialize
				break;
			}
		}
		//sort by bubbling a>b>c
		int *byn = NULL,*bym = NULL;
		int swap1 = 0,swap2 = swap1;
		for(int n=0; n<amount; n++)
		{
			byn = (idxs + n);
			for(int m=0; m<amount; m++)
			{
				bym = (idxs + m);
				if(*byn < *bym)
				{
					swap1 = *byn;
					swap2 = *bym;
					*(idxs + m) = swap1;
					*(idxs + n) = swap2;
				}
			}
		}
		//link to list
		for(int n=0; n<amount; n++)
		{
			setv(*idxs);
			idxs++;
		}
		return head;
	}
	vertex* vertex::sete(int idx1,int idx2,int weit)
	{
		bool idx1exist = 0,idx2exist = 0;
		vertex *idx1addr = NULL;
		//check if node idx2 and idx1 exist
		//from tail to head
		for(vertex* check1 = tail; check1 != NULL; check1 = check1->prior)
		{
			if(!(check1->index - idx1) && !idx1exist)
			{
				idx1addr = check1;
				idx1exist = 1;
			}
			if(!(check1->index - idx2) && !idx2exist)
			{
				idx2exist = 1;
			}
			else
			continue;
		}
		if(idx1exist && idx2exist)
		{
			alter = new vertex(idx2,weit);
			for(;;)
			{
				if(idx1addr->adjnext)
				{
					idx1addr = idx1addr->adjnext;
				}
				//link idx2 to idx1
				else
				{
					idx1addr->adjnext = alter;
					return alter;
				}
			}
		}
		else
		return NULL;
	}
	vertex* vertex::v_remove(vertex* vert)
	{
		if(vert->adjnext)
		{
			v_remove(vert->adjnext);
			delete vert;
		}
		if(!vert->adjnext)
		{
			return NULL;
		}
	}
	vertex* vertex::rmv(int idx)
	{
		//if is tail
		if(tail->index == idx)
		{
			alter = tail;
			tail = tail->prior;
			v_remove(alter);
			for(vertex* v=tail;v!=NULL;v=v->prior)
			rme(v->index,idx);
		}
		//if is head
		if(head->index == idx)
		{
			alter = head;
			head = head->next;
			v_remove(alter);
			for(vertex* v=tail;v!=NULL;v=v->prior)
			rme(v->index,idx);
		}
		//condition else
		for(vertex* v=tail;v!=NULL;v=v->prior)
		{
			//idx1 found
			if(v->index == idx)
			{
				v->prior->next = v->next;
				v->next->prior = v->prior;
				v_remove(v);
				for(vertex* v=tail;v!=NULL;v=v->prior)
				rme(v->index,idx);
			}
		}
	}
	vertex* vertex::rme(int idx1,int idx2)
	{
		vertex* alt = NULL;
		//from tail to head
		for(vertex* v=tail;v!=NULL;v=v->prior)
		{
			//idx1 found
			if(v->index == idx1)
			{
				alter = v;
				for(;;)
				{
					if(alter->adjnext)
					{
						//found
						if(alter->adjnext->index == idx2)
						{
							alt = alter->adjnext;
							alter->adjnext = alt->adjnext;
							delete alt;
							break;
						}
						else
						{
							if(alter->adjnext)
							alter = alter->adjnext;
							if(!alter->adjnext)
							break;
						}
					}
					else
					break;
				}
			}
		}
		return NULL;
	}
	//return an array storing addresses
	v_array vertex::edgeof(int idx)
	{
		int amount = 0;
		v_array nodes = NULL;
		for(vertex* v=tail;v!=NULL;v=v->prior)
		{
			alter = v;
			//idx found
			if(alter->index == idx)
			{
				if(alter->adjnext)
				{
					for(;;)
					{
						if(alter->adjnext)
						{
							alter = alter->adjnext;
							amount++;
						}
						else
						break;
					}
				}
				nodes = new vertex*[amount];
				alter = v->adjnext;
				for(int n=0; n<amount; n++)
				{
					nodes[n] = alter;
					alter = alter->adjnext;
				}
				return nodes;
			}
		}
		return NULL;
	}
	//return the address of current vertex in vertex list
	vertex* vertex::locate(int idx)
	{
		for(vertex* v=tail;v!=NULL;v=v->prior)
		{
			alter = v;
			//idx found
			if(alter->index == idx)
			return alter;
		}
	}
	//return the address of current vertex in adjacency list of vertex idx1
	vertex* vertex::locate(int idx1,int idx2)
	{
		vertex* alt = NULL;
		//from tail to head
		for(vertex* v=tail;v!=NULL;v=v->prior)
		{
			//idx1 found
			if(v->index == idx1)
			{
				alter = v;
				for(;;)
				{
					if(alter->adjnext)
					{
						//found
						if(alter->adjnext->index == idx2)
						{
							return alter->adjnext;
						}
					}
				}
			}
		}
	}
}
#endif
