#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void print(vector<vector<int>> matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      cout << matrix[i][j] << ' ';
    }
    cout << endl;
  }
}

void rotate(vector<vector<int>> &m) {
  int n = m.size();
  for (int i = 0; i < n / 2; i++) {
    for (int j = i; j < n - i - 1; j++) {
      vector<int> buff = { m[i][j], m[j][n - i - 1], m[n - i - 1][n - j - 1], m[n - j - 1][i] };
      m[i][j] = buff[3];
      m[j][n - i - 1] = buff[0];
      m[n - i - 1][n - j - 1] = buff[1];
      m[n - j - 1][i] = buff[2];
    }
  }
}

int main() {
  vector<vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };
  print(matrix);
  rotate(matrix);
  print(matrix);
  return 0;
}
