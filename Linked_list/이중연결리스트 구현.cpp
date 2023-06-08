#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int data;
	Node* prev;
	Node* next;
};

class DoublyLinkedList
{
private:
	int count;
	Node* header;
	Node* trailer;

public:
	DoublyLinkedList()
	{
		count = 0;
		header = new Node {0, NULL, NULL};
		trailer = new Node {0, NULL, NULL};
		header->next = trailer;
		trailer->prev = header;
	}
	~DoublyLinkedList(){
		while(!empty())
		{
			pop_front();
		}
		delete header;
		delete trailer;
	}

	void insert(Node* p, int val)
	{
		Node* new_node = new Node {val, p->prev, p};
		new_node->prev->next = new_node;
		new_node->next->prev = new_node;
		count++;
	}
	void push_front(int val)
	{
		insert(header->next, val);
	}
	void push_back(int val)
	{
		insert(trailer, val);
	}

	bool empty()
	{
		return count == 0;
	}
	int size()
	{
		return count;
	}

	void erase(Node* p)
	{
		if(!empty())
		{
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
			count--;
		}
	}
	void pop_front()
	{
		erase(header->next);
	}
	void pop_back()
	{
		erase(trailer->prev);
	}

	void print_all()
	{
		Node* pri = header->next;
		while(pri != trailer)
		{
			cout << pri->data << ' ';
			pri = pri->next;
		}
		cout << endl;
	}
	void print_reverse()
	{
		Node* pri = trailer->prev;
		while(pri != header)
		{
			cout << pri->data << ' ';
			pri = pri->prev;
		}
		cout << endl;
	}
};

int main()
{
	DoublyLinkedList l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.print_all();
	l.print_reverse();

	l.pop_front();
	l.pop_back();
	l.print_all();

	l.push_front(100);
	l.push_back(400);
	l.print_all();
}
