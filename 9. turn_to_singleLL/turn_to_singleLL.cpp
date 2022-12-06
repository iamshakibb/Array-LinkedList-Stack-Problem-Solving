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

// insert at head
void insertAtHead(Node *&head, int val)
{
  Node *newNode = new Node(val);
  if (head == NULL)
  {
    head = newNode;
    return;
  }

  newNode->next = head;
  head = newNode;
}

// insertAtTail
void insertAtTail(Node *&head, int val)
{
  Node *newNode = new Node(val);
  if (head == NULL)
  {
    head = newNode;
    return;
  }
  Node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

// insert at position
void insertAtPosition(Node *&head, int val, int position)
{
  if (position == 1)
  {
    insertAtHead(head, val);
    return;
  }
  Node *temp = head;
  int count = 1;
  while (count < position - 1)
  {
    temp = temp->next;
    count++;
  }
  if (temp->next == NULL)
  {
    insertAtTail(head, val);
    return;
  }
  Node *newNode = new Node(val);
  newNode->next = temp->next;
  temp->next = newNode;
}

// insert element
void insert(Node *&head, int l, int i, int r)
{
  if (head == NULL)
  {
    insertAtHead(head, i);
  }
  Node *temp = head;
  Node *prev = NULL;
  Node *next = NULL;
  int count = 1;
  while (temp != NULL && temp->value != i && temp->next != NULL)
  {
    next = temp->next == NULL ? NULL : temp->next->next;
    prev = temp;
    temp = temp->next;
    count++;
  }
  if (count == 1 && temp->next != NULL)
    next = temp->next;

  // if value exist
  if (temp->value == i)
  {
    if ((prev == NULL || prev->value != l) && l != 0)
    {
      insertAtPosition(head, l, count);
    }
    if ((next == NULL || next->value != r) && r != 0)
    {
      insertAtPosition(head, r, count + 2);
    }
  }
  else if (temp->next == NULL || temp->value != i)
  {
    if (l == 0)
    {
      insertAtPosition(head, i, count + 1);
      if (r != 0)
        insertAtPosition(head, r, count + 2);
    }
    else
    {
      insertAtPosition(head, l, count + 1);
      insertAtPosition(head, i, count + 2);
      if (r != 0)
        insertAtPosition(head, r, count + 3);
    }
  }
}

// get prev and next value
void prevNext(Node *head, int arr[], int val)
{
  if (head == NULL)
  {
    cout << "List is empty";
    return;
  }
  int count = 1;
  Node *temp = head;
  Node *prev = NULL;
  Node *next = NULL;
  while (temp != NULL && temp->value != val)
  {
    next = temp->next == NULL ? NULL : temp->next->next;
    prev = temp;
    temp = temp->next;
    count++;
  }
  if (count == 1)
    next = temp->next;

  arr[0] = prev == NULL ? 0 : prev->value;
  arr[1] = next == NULL ? 0 : next->value;
}

// print the list
void printList(Node *&head, int n)
{
  if (head == NULL)
  {
    cout << "List is empty";
    return;
  }
  Node *temp = head;
  cout << endl;
  for (int i = 1; i <= n; i++)
  {
    int arr[2];
    prevNext(head, arr, i);
    cout << arr[0] << " " << arr[1] << endl;
  }
  cout << endl;
};

int main()
{
  Node *head = NULL;
  int n, l, r;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> l >> r;
    insert(head, l, i, r);
  }

  printList(head, n);

  return 0;
}