#include "video.h"

int main() {

  const int MAX = 100;
  Video *videos[MAX];
  string sort_crit;
  string title;
  string URL;
  string comment;
  float length;
  int rating;
  int count = 0;

  cin>>sort_crit;
  cin.ignore();
  if((sort_crit != "rating") && (sort_crit != "length") && (sort_crit != "title")) {
    cerr << sort_crit << " is not a legal sorting method, giving up." <<endl;
    return 1;
  }

  while(getline(cin,title)) {
    if(count >= 100) {
      cerr << "Too many videos, giving up." << endl;
      return 1;
    }
    getline(cin,URL);
    getline(cin,comment);
    cin>>length;
    cin>>rating;
    cin.ignore();

    videos[count] = new Video(title, URL, comment, length, rating);
    count++;
  }

  for(int i = count-1; i > 0; i--) {
    for(int j = 0; j < i; j++) {
      if(videos[j]->compare(videos[j+1], sort_crit)) {
        swap(videos[j],videos[j+1]);
      }
    }
  }


  for(int i=0; i<count; i++) {
    videos[i]->print();
  }



  return 0;
}
