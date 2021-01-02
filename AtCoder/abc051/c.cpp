#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  int dy = tx - sx;
  int dx = ty - sy;
  if(dx > 0) {
    for(int i = 0; i < dx; i++) {
      cout << "U";
    }
  } else {
    for(int i = 0; i > dx; i--) {
      cout << "D";
    }
  }
  if(dy > 0) {
    for(int i = 0; i < dy; i++) {
      cout << "R";
    }
  } else {
    for(int i = 0; i > dy; i--) {
      cout << "L";
    }
  }

  if(dx > 0) {
    for(int i = 0; i < dx; i++) {
      cout << "D";
    }
  } else {
    for(int i = 0; i > dx; i--) {
      cout << "U";
    }
  }
  if(dy > 0) {
    cout << "L";
    for(int i = 0; i < dy; i++) {
      cout << "L";
    }
  } else {
    cout << "R";
    for(int i = 0; i > dy; i--) {
      cout << "R";
    }
  }

  if(dx > 0) {
    cout << "U";
    for(int i = 0; i < dx; i++) {
      cout << "U";
    }
  } else {
    cout << "D";
    for(int i = 0; i > dx; i--) {
      cout << "D";
    }
  }
  if(dy > 0) {
    cout << "R";
    for(int i = 0; i < dy; i++) {
      cout << "R";
    }
  } else {
    cout << "L";
    for(int i = 0; i > dy; i--) {
      cout << "L";
    }
  }

  if(dx > 0) {
    cout << "D";
  } else {
    cout << "U";
  }

  if(dy > 0) {
    cout << "R";
  } else {
    cout << "L";
  }

  if(dx > 0) {
    cout << "D";
    for(int i = 0; i < dx; i++) {
      cout << "D";
    }
  } else {
    cout << "U";
    for(int i = 0; i > dx; i--) {
      cout << "U";
    }
  }
  if(dy > 0) {
    cout << "L";
    for(int i = 0; i < dy; i++) {
      cout << "L";
    }
  } else {
    cout << "R";
    for(int i = 0; i > dy; i--) {
      cout << "R";
    }
  }

  if(dx > 0) {
    cout << "U";
  } else {
    cout << "D";
  }

  cout << endl;
}
