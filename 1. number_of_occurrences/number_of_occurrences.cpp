#include <iostream>
#include <algorithm>
using namespace std;

void arrayInput(int n, int arr[])
{
  for (int i = 0; i < n; i++)
  {
    int value;
    cin >> value;
    arr[i] = value;
  }
};

int firstOccurrenceIndex(int n, int arr[], int val)
{
  int start = 0;
  int end = n - 1;
  int mid = start + (end - start) / 2;
  int index = 0;
  while (start <= end)
  {
    if (arr[mid] == val)
    {
      index = mid;
      end = mid - 1;
    }
    else if (val > arr[mid])
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
    mid = start + (end - start) / 2;
  }
  return index;
};

int lastOccurrenceIndex(int n, int arr[], int val)
{
  int start = 0;
  int end = n - 1;
  int mid = start + (end - start) / 2;
  int index = 0;
  while (start <= end)
  {
    if (arr[mid] == val)
    {
      index = mid;
      start = mid + 1;
    }
    else if (val > arr[mid])
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
    mid = start + (end - start) / 2;
  }
  return index;
};

// this for sorted array
int removeDuplicates(int arr[], int n)
{
  if (n == 0 || n == 1)
  {
    return n;
  }
  int index = 0;
  for (int i = 0; i < n - 1; i++)
  {
    if (arr[i] != arr[i + 1])
    {
      arr[index++] = arr[i];
    }
  }
  arr[index++] = arr[n - 1];
  return index;
}

int main()
{
  int n;
  cin >> n;
  int arr[n];
  arrayInput(n, arr);
  sort(arr, arr + n);
  int copyArr[n];
  copy(arr, arr + n, copyArr);
  int newLength = removeDuplicates(copyArr, n);

  for (int i = 0; i < newLength; i++)
  {
    int numOfOccurences = (lastOccurrenceIndex(n, arr, copyArr[i]) - firstOccurrenceIndex(n, arr, copyArr[i])) + 1;
    cout << copyArr[i] << " => " << numOfOccurences << endl;
  }
  return 0;
}