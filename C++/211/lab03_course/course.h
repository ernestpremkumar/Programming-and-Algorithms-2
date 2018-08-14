#ifndef COURSE_H
#define COURSE_H

#include <iostream>
using namespace std;

class Course {
public:
  Course(string , int , int );
  void print();

private:
  string m_dept;
  int m_number;
  int m_time;
};

#endif
