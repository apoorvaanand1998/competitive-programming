#include <iostream>

using namespace std;

struct Node {
  int val;
  Node* next;

  Node(int v) : val { v }, next { nullptr } { }
};

class MyLinkedList {
private:
  Node* head;
  Node* tail;
  int length;
public:
  MyLinkedList() : head { new Node(-1) }, tail { new Node(-1) }, length { 0 }
  {
    // -1 because vals >= 0
  }
  
  ~MyLinkedList()
  {
    Node* curr = head;
    Node* toDelete = curr;
    while (curr) {
      toDelete = curr;
      curr = curr->next;
      delete toDelete;
    }
  }
  
  int get(int index)
  {
    if ((index < 0) || (index >= length))
      return -1;
    
    Node* curr = head;
    while (index != 0) {
      curr = curr->next;
      --index;
    }
    return (curr->val >= 0) ? curr->val : -1;
  }

  void addAtHead(int val)
  {
    Node* curr = new Node(val);
    if (length == 0) tail = curr;
    curr->next = head;
    head = curr;
    ++length;
  }

  void addAtTail(int val)
  {
    Node* curr = new Node(val);
    if (length == 0) head = curr;
    tail->next = curr;
    tail = curr;
    ++length;
  }

  void addAtIndex(int index, int val)
  {
    if ((index < 0) || (index > length))
      ;
    else if (index == 0)
      addAtHead(val);
    else if (index == length)
      addAtTail(val);
    else {
      Node* curr = new Node(val);

      Node* prev = head;
      while (index != 1) {
	prev = prev->next;
	--index;
      }

      curr->next = prev->next;
      prev->next = curr;
      ++length;
    }
  }

  void deleteAtIndex(int index)
  {
    if ((index >= 0) && (index < length)) {
      Node* toDelete;
      bool is_tail = false;
      
      if (index == 0) {
        toDelete = head;
	head = head->next;
	delete toDelete;
	--length;
	return;
      }

      if (index == length-1) is_tail = true;
      Node* prev = head;
      while (index != 1) {
	prev = prev->next;
	--index;
      }
      toDelete = prev->next;
      prev->next = prev->next->next;
      if (is_tail) tail = prev;
      delete toDelete;
      --length;
    }
  }
  
  void deets(void)
  {
    cout << head->val << ' ' << tail->val << ' ' << length << '\n';

    Node* curr = head;
    while (curr) {
      cout << curr->val << " -> ";
      curr = curr->next;
    }
    cout << '\n';
  }
};

int main()
{
  MyLinkedList mll;
  mll.addAtHead(1);
  mll.addAtHead(2);
  mll.addAtHead(3);
  mll.addAtTail(4);
  mll.addAtTail(5);
  mll.addAtIndex(2, 6);
  mll.addAtIndex(6, 9);
  mll.deets();
  mll.deleteAtIndex(0);
  mll.deets();
  mll.deleteAtIndex(2);
  mll.deets();
  mll.deleteAtIndex(4);
  mll.deets();
}
