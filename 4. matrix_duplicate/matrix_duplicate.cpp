#include <iostream>
using namespace std;

int main()
{
  int m, x;
  cin >> m >> x;
  int n[m][x];
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < x; j++)
    {
      int input;
      cin >> input;
      n[i][j] = input;
    }
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < x; j++)
    {
      for (int t = m - 1; t >= i; t--)
      {
        for (int k = x - 1; k >= 0; k--)
        {
          if ((n[t][k] == n[i][j]) && j != k)
          {
            n[t][k] = -1;
          }
        }
      }
    }
  }
  cout << endl;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < x; j++)
    {
      cout << n[i][j] << " ";
    }
    cout << endl;
  }
}