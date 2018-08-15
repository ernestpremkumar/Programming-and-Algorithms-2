#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
#include <string>
using namespace std;

class Video {
public:
  Video(string, string, string, float, int);
  void print();
  bool compare(Video *, string);
  string getTitle();

private:
  string m_title;
  string m_URL;
  string m_comment;
  float m_length;
  int m_rating;
  string m_rstar;
};

#endif
