#ifndef BITREE_L
#define BITREE_L
#include"lib_bitree/bitree.linked.h"
//by wohl
namespace wohl
{
	bitree_l::bitree_l(char data)
	{
		Data = data;
		left = NULL;
		right = NULL;
	}
	
	bitree_l::bitree_l()
	{
		Data = '#';
		left = NULL;
		right = NULL;
	}

	//remenber the T pointer must be NULL or initialized already
	bitree_l* bitree_l::grow(int index,char data)
	{
		//count the operations
		int counter = 0;
		//push in a string and pop out a string
		//using a stack
		//path searching pointer
		bitree_l* target = this;
		//initialization
		if(target == NULL)
		target = new bitree_l;
		//if index is zero,quit
		while(index)
		{
			//calculate the operations
			//right child
			if(!(index % 2))
			{	
				//recall the parent
				index = (index - 2) / 2;
				stack.push("right");
				counter++;
			}
			//left child
			else
			{
				//recall the parent
				index  = (index - 1) / 2;
				stack.push("left");
				counter++;
			}
		}
		for(int n=0; n<counter+1; n++)
		{
			std::string signal;
			signal = stack.pop();
			if(signal == "right")//bug here
			{
				if(target->right == NULL)
				target->right = new bitree_l;
				target = target->right;
			}
			if(signal == "left")
			{
				if(target->left == NULL)
				target->left = new bitree_l;
				target = target->left;
			}
			//the target is located
			if(signal == "NULL")
			{
				target->Data = data;
				return target;
			}
		}
	}
	
	//looking for leaf? im here
	bitree_l* bitree_l::lookfor(int index)
	{
		//count the operations
		int counter = 0;
		//push in a string and pop out a string
		//using a stack
		//path searching pointer
		bitree_l* target = this;
		//initialization
		if(target == NULL)
		return 0;
		//if index is zero,quit
		while(index)
		{
			//calculate the operations
			//right child
			if(!(index % 2))
			{	
				//recall the parent
				index = (index - 2) / 2;
				stack.push("right");
				counter++;
			}
			//left child
			else
			{
				//recall the parent
				index  = (index - 1) / 2;
				stack.push("left");
				counter++;
			}
		}
		for(int n=0; n<counter+1; n++)
		{
			std::string signal;
			signal = stack.pop();
			if(signal == "right")//bug here
			{
				if(target->right == NULL)
				return 0;
				target = target->right;
			}
			if(signal == "left")
			{
				if(target->left == NULL)
				return 0;
				target = target->left;
			}
			//the target is located
			if(signal == "NULL")
			{
				return target;
			}
		}
	}
	
	//remove the whole tree
	bitree_l* bitree_l::destroy(bitree_l* target)
	{
		if(target->left)
		{
			destroy(target->left);
			delete target;
		}
		if(target->right)
		{
			destroy(target->right);
			delete target;
		}
		if(!target->left&&!target->right)
			return nullptr;
	}
	
	//read the data
	char bitree_l::tell(bitree_l* T)
	{
		if(T)
		return T->Data;
		else
		return 0;
	}
	
	void* bitree_l::pre(bitree_l* T)
	{
		using namespace std;
		if(!T)
		{
			return NULL;
		}
		cout<<T->Data;
		pre(T->left);
		pre(T->right);
		return NULL;
	}
	
	void* bitree_l::infix(bitree_l* T)
	{
		using namespace std;
		if(!T)
		{
			return NULL;
		}
		pre(T->left);
		cout<<T->Data;
		pre(T->right);
		return NULL;
	}
	
	void* bitree_l::post(bitree_l* T)
	{
		using namespace std;
		if(!T)
		{
			return NULL;
		}
		pre(T->left);
		pre(T->right);
		cout<<T->Data;
		return NULL;
	}
}
#endif
