#include <iostream>
using namespace std;

int main() {
  int myNum;
  bool even = true;

  while (cin >> myNum) {
    if(myNum % 2 != 0)
    {
      even = false;
    }
  }

  if (even) {
    std::cout << "all even" << '\n';
    return 0;
  }
  else {
    std::cerr << "not all even" << '\n';
    return 1;
  }
}
