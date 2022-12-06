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

int binarySearch(int n, int arr[], int val)
{
  int start = 0;
  int end = n - 1;
  int mid = start + (end - start) / 2;
  int ans = -1;
  while (start <= end)
  {
    if (arr[mid] == val)
    {
      ans = mid;
      end = mid - 1;
      return ans;
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
  return ans;
};

int main()
{
  int n, m;
  cin >> n;
  int A[n];
  arrayInput(n, A);
  cin >> m;
  int B[m];
  arrayInput(m, B);
  sort(B, B + m);

  for (int i = 0; i < n; i++)
  {
    if (binarySearch(m, B, A[i]) == -1)
    {
      cout << A[i] << " ";
    }
  }
  cout << endl;
  return 0;
}