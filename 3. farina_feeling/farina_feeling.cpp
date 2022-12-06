#include <iostream>
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

void arrayOutput(int n, int arr[])
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
};

int arraySum(int n, int arr[])
{
  int sum = 0;
  for (int i = 0; i <= n; i++)
  {
    sum += arr[i];
  }
  return sum;
};

int main()
{
  int T, D, Q, x;
  cin >> T;
  for (int k = 0; k < T; k++)
  {
    cin >> D;
    int earn_per_day[D];
    int spent_per_day[D];
    arrayInput(D, earn_per_day);
    arrayInput(D, spent_per_day);
    cin >> Q;
    int result[Q];
    for (int i = 0; i < Q; i++)
    {
      cin >> x;
      int totalEarn = arraySum(x, earn_per_day);
      int totalSpent = arraySum(x, spent_per_day);
      result[i] = (totalEarn - totalSpent) < 0 ? 0 : 1;
    }
    cout << endl;
    // cout << "Answer for test " << k + 1 << endl;
    arrayOutput(Q, result);
    cout << endl;
  }
}