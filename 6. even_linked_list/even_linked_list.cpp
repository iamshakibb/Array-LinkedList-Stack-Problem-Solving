#include <iostream>
using namespace std;

class Node
{
public:
  int value;
  Node *next;

  Node(int val)
  {
    this->value = val;
    this->next = NULL;
  }
};

void printList(Node *&head)
{
  if (head == NULL)
  {
    cout << "List is empty";
    return;
  }
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->value;
    if (temp->next != NULL)
    {
      cout << " -> ";
    }
    temp = temp->next;
  }
  cout << endl;
};

void insertAtTail(Node *&head, int value)
{
  Node *temp = head;
  Node *newNode = new Node(value);
  if (temp == NULL)
  {
    head = newNode;
    return;
  }

  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

void replaceEvenNum(Node *&head)
{
  if (head == NULL)
  {
    cout << "Sorry can't perform replace operation list is empty" << endl;
    return;
  }
  Node *temp = head;
  while (temp != NULL)
  {
    if (temp->value % 2 == 0)
    {
      temp->value = -1;
    }
    temp = temp->next;
  }
}

int main()
{
  Node *head = NULL;
  int size;
  cin >> size;
  while (size > 0)
  {
    int value;
    cin >> value;
    insertAtTail(head, value);
    size--;
  }
  replaceEvenNum(head);
  printList(head);
}