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
  cout << endl;
}

void setZeroes(vector<vector<int>> &matr) {
  int n = matr.size();
  int m = matr[0].size();
  vector<bool> zrows = { false };
  vector<bool> zcols = { false };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matr[i][j] == 0) {
        zrows[i] = true;
        zcols[j] = true;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (zrows[i] || zcols[j]) matr[i][j] = 0;
    }
  }
}

int main() {
  vector<vector<int>> matrix = {
    {0, 2, 3, 15},
    {4, 5, 6, 0},
    {7, 6, 4, 42}
  };
  print(matrix);
  setZeroes(matrix);
  print(matrix);
  return 0;
}
