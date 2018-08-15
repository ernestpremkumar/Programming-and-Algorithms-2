// demonstrate a simple linked-list of integers
#ifndef VLIST_H
#define VLIST_H
#include "video.h"

class Vlist
{
    public:
        Vlist();
        ~Vlist();
        bool insert(Video *); // insert at beginning of list
        void print();
        int length();
        bool lookup(string);
        bool remove(string);
    private:
        class Node
        {
            public:
                // small functions can be inserted into the class definition
                // don't put large functions in the class definition
                Node(Video *video, Node *next)
                {m_video = video; m_next = next;}
                Video *m_video;
                Node *m_next;
        };
        Node *m_head;
};

#endif
