#include <iostream>

using namespace std;

struct StackItem
{
  int data;
  StackItem *next = nullptr;
};

struct Queue
{
  int data;
  Queue *next;
};

StackItem *
pushSTACK (StackItem * head, int x)
{
  StackItem *new_top = new StackItem;
  new_top->data = x;
  new_top->next = head;
  head = new_top;
  return head;
}

void
pushQUEUE (Queue * &head, Queue * &tail, int x)
{
  Queue *element = new Queue;
  element->data = x;
  element->next = nullptr;
  if (head == nullptr)
	head = element;
  else
	tail->next = element;
  tail = element;
}

void
popQUEUE (Queue * &head)
{
  head = head->next;
}

StackItem *
popSTACK (StackItem * head)
{
  if (head == nullptr)
	return nullptr;
  StackItem *old_top = head;
  head = old_top->next;
  delete old_top;
  return head;
}

void
printSTACK (StackItem * head)
{
  cout << "Stack:\n";
  StackItem *element = head;
  while (element != nullptr)
	{
	  cout << element->data << ' ';
	  element = element->next;
	}
  cout << '\n';
}

void
printQUEUE (Queue * head)
{
  Queue *element = head;
  if (head == nullptr)
	cout << "Queue is empty\n";
  else
	{
	  cout << "Queue:\n";
	  while (element != nullptr)
		{
		  cout << element->data << ' ';
		  element = element->next;
		}
	  cout << '\n';
	}
}

int main ()
{
  Queue *q_head = nullptr, *q_tail = nullptr;
  for (int i = 3; i <= 55; i += 2)
	pushQUEUE (q_head, q_tail, i);
  printQUEUE (q_head);

  StackItem *s_top = nullptr;

  while (q_head != nullptr)
	{
	  s_top = pushSTACK (s_top, q_head->data);
	  popQUEUE (q_head);
	}

  cout << "Stack numbers devidable by 3:\n";
  StackItem *element = s_top;
  while (element != nullptr)
	{
	  if (element->data % 3 == 0)
		cout << element->data << ' ';
	  element = element->next;
	}
  cout << '\n';

  return 0;
}
