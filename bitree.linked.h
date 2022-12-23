#ifndef BITREE_LINKED_H
#define BITREE_LINKED_H
#include"linkedlist.h"
//by wohl
//binary tree by linked list
/*
tree look like
		0
	   / \
	  1   2
	 / \   \
	3   4   6
*/
namespace wohl
{
	class bitree_l
	{
		public:
		//constructor&destructor
		bitree_l(char data);
		bitree_l();
		//methods
		bitree_l* grow(int index,char data);
		bitree_l* lookfor(int index);
		//remove the whole tree
		bitree_l* destroy(bitree_l* target);
		char tell(bitree_l* T);
		void* pre(bitree_l* T);//pre order search
		void* infix(bitree_l* T);//infix order search
		void* post(bitree_l* T);//post order search
		protected:
		bitree_l* parent;
		bitree_l* left;
		bitree_l* right;
		Stack stack;
		Queue queue;
		private:
		char Data;
	};
	class bitree_t:public bitree_l
	{};
	class root_t:public bitree_l
	{};
}
#endif
