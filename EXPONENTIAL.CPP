#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int expo(int a, int b){
  int result = 1;

  while (b){
    if (b%2==1){
      result *= a;
    }
    b /= 2;
    a *= a;
  }

  return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cout << expo(2,4);
    return 0;
}
