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
};

void removeNnode(Node *&head, int M, int N)
{
  Node *temp = head;
  int count = M;
  while (temp != NULL && count > 1)
  {
    temp = temp->next;
    count--;
  }
  count = N;
  while (temp != NULL && count > 0)
  {
    Node *deleteNode = temp->next;
    temp->next = temp->next == NULL ? NULL : temp->next->next;
    delete deleteNode;
    count--;
  }

  if (temp->next != NULL)
  {
    removeNnode(temp->next, M, N);
  }
};

int main()
{
  Node *head = NULL;
  int size, M, N;
  cin >> size >> M >> N;
  while (size > 0)
  {
    int value;
    cin >> value;
    insertAtTail(head, value);
    size--;
  }
  removeNnode(head, M, N);
  printList(head);
}