/*
linkedlist by Wohl
stack & queue
Oct4 2022
*/
#ifndef Linkedlist
#define Linkedlist
#include<iostream> 
namespace wohl
{
	//this is a node
	class linked_list
	{
		public:
		linked_list();
		linked_list(std::string str);
		//usual linked list
		linked_list* append(std::string str);
		std::string remove(std::string str);
		friend int len(linked_list target);
		friend void* print(linked_list target);
		//stack
		linked_list* push(std::string info);
		std::string pop();
		//queue
		linked_list* enqueue(std::string info);
		std::string dequeue();
		private:
		std::string info;
		linked_list* seek(std::string str);
		protected:
		linked_list* next;
		linked_list* prior;
		linked_list* head;
		linked_list* tail;
		linked_list* extra;
		int length;
	}; 
	
	class Stack:public linked_list
	{};
	class Queue:public linked_list
	{};
	
	//implement
	linked_list::linked_list()
	{
		head = new linked_list("(Wohl)");
		push("(Vortez)");
		head->prior = NULL;
	}
	
	linked_list::linked_list(std::string str)
	{
		info = str;
		next = NULL;
		prior = NULL;
	}
	
	linked_list* linked_list::append(std::string str)
	{
		length++;
		//front inserting
		extra = new linked_list(str);
		head->prior = extra;
		extra->next = head;
		head = extra;
		return head;
	}
	
	linked_list* linked_list::seek(std::string str)
	{
		//seek node item
		linked_list* seeker = head;
		for(;seeker; seeker = seeker->next)
		{
			if(seeker->info == str)
			{
				//return the address
				return seeker;
			}	
		}
	}
	
	std::string linked_list::remove(std::string str)
	{
		if(str == "(Vortez)" || str == "(Wohl)")
		{
		return 0;
		}
		
		if(!seek(str)->prior)
		return pop();
		
		if(seek(str)&&str!="(Vortez)"&&str!="(Wohl)")
		{
			linked_list* target = seek(str);
			if(target->next)
			{
				length--;
				std::string result = target->info;
				
				target->prior->next = target->next;
				target->next->prior = target->prior;
				delete target;
				return result;
			}
			else
			{
				if(str!="(Vortez)"&&str!="(Wohl)")
				{
					length--;
					std::string result = target->info;
					
					target->prior->next = NULL;
					delete target;
					return result;
				}
				else
				{
					return NULL;
				}
			}
		}
	}
	
	int len(linked_list target)
	{
		return target.length - 1;
	}
	
	void* print(linked_list target)
	{
		linked_list* read;
		read = target.head;
		if(target.head->info == "(Vortez)")
		{
			std::cout<<"(Vortez Wohl)";
		}
		else
		{
			for(;; read = read->next)
			{
				if(read->info!="(Vortez)")
				std::cout<<read->info;
				else
				{
					std::cout<<"(Vortez Wohl)";
					break;
				}
				if(read->next == NULL)
				{
					break;
				}
				std::cout<<"->";
			}
		}
		std::cout<<std::endl;
		return NULL;
	}
	
	//stack 
	linked_list* linked_list::push(std::string info)
	{
		//front inserting
		return append(info);
	}
	std::string linked_list::pop()
	{
		length--;
		if(head->info != "(Vortez)")
		{
			std::string result;
			result = head->info;
			
			extra = head;
			head = head->next;
			head->prior = NULL;
			delete extra;
			extra = NULL;
			return result;
		}
		else
		return "NULL";
	}
	
	//queue
	linked_list* linked_list::enqueue(std::string info)
	{
		return push(info);
	}
	std::string linked_list::dequeue()
	{
		tail = seek("(Vortez)")->prior;
		if(tail->prior)
		return remove(tail->info);
		if(!tail->prior)
		return pop();
	}
}
#endif
