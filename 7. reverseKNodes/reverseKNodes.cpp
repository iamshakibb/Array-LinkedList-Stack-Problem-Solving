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

Node *reverseKNodes(Node *head, int k)
{
  if (head == NULL)
  {
    return head;
  }

  Node *next = NULL;
  Node *current = head;
  Node *prev = NULL;
  int count = 0;

  while (current != NULL && count < k)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
    count++;
  }

  if (next != NULL)
  {
    head->next = reverseKNodes(next, k);
  }

  return prev;
};

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
  int k;
  cin >> k;
  Node *reverse = reverseKNodes(head, k);
  printList(reverse);
}