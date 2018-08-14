#include <iostream>

int main() {
  const int MAX = 100;
  int myArray[MAX];
  int value;
  int count = 0;
  int largest = 0;
  int curr_largest = 0;

  std::cin >> value;
  curr_largest = value;

  while (value != 0) {
    if(value > 0) {
      myArray[count] = value;
      count++;

      if(curr_largest > largest) {
        largest = curr_largest;
      }
    }

    std::cin >> value;
    curr_largest = value;
  }

  for (int i=largest; i>0; i--){
    for(int j=0; j<count; j++){
      if(myArray[j] >= i) {
        std::cout << '*';
      }
      else {
        std::cout << ' ';
      }
    }
    std::cout << '\n';
  }

  std::cout << '\n';

  for (int i=1; i<=largest; i++){
    for(int j=0; j<count; j++){
      if(myArray[j] >= i) {
        std::cout << '*';
      }
      else {
        std::cout << ' ';
      }
    }
    std::cout << '\n';
  }

  std::cout << '\n';

  for (int i=0; i<count; i++){
    for(int j=1; j<=largest; j++){
      if(myArray[i] >= j) {
        std::cout << '*';
      }
      else {
        std::cout << ' ';
      }
    }
    std::cout << '\n';
  }

  std::cout << '\n';

  for (int i=0; i<count; i++){
    for(int j=largest; j>0; j--){
      if(myArray[i] >= j) {
        std::cout << '*';
      }
      else {
        std::cout << ' ';
      }
    }
    std::cout << '\n';
  }


  // std::cout << "Current Largest = " << largest << '\n';

  return 0;
}
