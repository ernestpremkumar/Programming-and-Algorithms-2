#include "vlist.h"

int main() {
  Vlist videos;
  string command;
  string title;
  string URL;
  string comment;
  float length;
  int rating;

  while(getline(cin,command)) {
    if(command == "insert") {
      getline(cin,title);
      getline(cin,URL);
      getline(cin,comment);
      cin>>length;
      cin>>rating;
      cin.ignore();
      Video *my_video = new Video(title, URL, comment, length, rating);
      if(!videos.insert(my_video)) {
        cerr<<"Could not insert video <"<<title<<">, already in list."<<endl;
      }
    }

    else if(command == "print") {
      videos.print();
    }

    else if(command == "length") {
      cout<<videos.length()<<endl;
    }

    else if(command == "lookup") {
      getline(cin,title);
      if(!videos.lookup(title)) {
        cerr<<"Title <"<<title<<"> not in list."<<endl;
      }
    }

    else if(command == "remove") {
      getline(cin,title);
      if(!videos.remove(title)) {
        cerr<<"Title <"<<title<<"> not in list, could not delete."<<endl;
      }
    }

    else {
      cerr<<"<"<<command<<"> is not a legal command, giving up."<<endl;
      return 1;
    }

  }
  return 0;
}
