#include <iostream>
using namespace std;

int main()
{
  int m;
  cin >> m;
  int n[m][m];
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int input;
      cin >> input;
      n[i][j] = input;
    }
  }
  int mid = m / 2;
  int sum = 0;
  cout << endl;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (j == mid || i == mid)
      {
        sum += n[i][j];
      }
      if ((i < mid && j == m - 1) || (i == 0 && j < mid) || (i == m - 1 && j > mid) || (i > mid && j == 0))
      {
        sum += n[i][j];
      }
    }
  }

  cout << sum << endl;
}