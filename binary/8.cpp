#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
#include <list>

using namespace std;
using byte = unsigned char;

void printBinary(byte n) {
  string s;
  int c = 8;
  while (c-- > 0) {
    s += to_string(n & 1);
    n >>= 1;
  }
  reverse(s.begin(), s.end());
  cout << s << ' ';
}

byte setOneInterval(byte x, byte y) {
  return ~(0xFF << y - x + 1) << 7 - y;
}

void drawLine(vector<byte>& screen, int width, int x1, int x2, int y) {
  int start = y * (width / 8);
  int p1 = start + floor(x1 / 8);
  int p2 = start + floor(x2 / 8);
  x1 %= 8;
  x2 %= 8;
  if (p2 - p1 < 0) return;

  if (p2 - p1 == 0) {
    screen[p1] = setOneInterval(x1, x2);
  } else {
    screen[p1] = setOneInterval(x1, 7);
    screen[p2] = setOneInterval(0, x2);

    for (int i = 1; i < p2 - p1; i++)
      screen[p1 + i] = 0xFF;
  }
}

int main() {
  int width = 32;
  vector<byte> screen = vector<byte>(32, 0);
  drawLine(screen, width, 5, 25, 2);

  for (int i = 0; i < screen.size(); i++) {
    printBinary(screen[i]);
    if ((i + 1) % (width / 8) == 0) cout << endl;
  }
  return 0;
}
