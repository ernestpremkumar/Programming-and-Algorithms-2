#include "course.h"
// #include <iostream>
// using namespace std;

Course::Course(string dept, int number, int time) {
  m_dept = dept;
  m_number = number;
  m_time = time;
}

void Course::print() {
  cout << m_dept << " " << m_number << " at " << m_time << endl;
}
