#include "vlist.h"

// on some machines member variables are not automatically initialized to 0
Vlist::Vlist()
{
  m_head = NULL;
}

// delete all Nodes in the list
// since they are dynamically allocated using new, they won't go away
// automatically when the list is deleted
// Rule of thumb: destructor deletes all memory created by member functions
Vlist::~Vlist()
{
  // cout << "Vlist::~Vlist() was called" << endl;

  Node *ptr = m_head;
  while (ptr != NULL)
  {
    Node *temp;

    temp = ptr;
    ptr = ptr->m_next;
    delete temp->m_video;
    delete temp;
  }
}

bool Vlist::insert(Video *video) {
  Node *ptr = m_head;
  if(m_head == NULL || (video->getTitle() < m_head->m_video->getTitle())) {
    m_head = new Node(video, m_head);
    return true;
  }
  if(ptr->m_next == NULL) {
    if(video->getTitle() == ptr->m_video->getTitle()){
      return false;
    }
    if(ptr->m_video->getTitle() > video->getTitle()) {
      ptr = new Node(video, ptr);
      return true;
    }
    else {
      ptr->m_next = new Node(video, NULL);
      return true;
    }
  }
  while (ptr->m_next != NULL && (video->getTitle() >= ptr->m_next->m_video->getTitle()))
  {
    if(video->getTitle() == ptr->m_next->m_video->getTitle()){
      return false;
    }
    ptr = ptr->m_next;
  }
  Node *temp = ptr->m_next;
  ptr->m_next = new Node(video, temp);
  return true;
}

void Vlist::print() {
  Node *ptr = m_head;
  while (ptr != NULL)
  {
    ptr->m_video->print();
    ptr = ptr->m_next;
  }
}

int Vlist::length() {
  int count = 0;
  Node *ptr = m_head;
  while (ptr != NULL)
  {
    count++;
    ptr = ptr->m_next;
  }
  return count;
}

bool Vlist::lookup(string title) {
  Node *ptr = m_head;
  while (ptr != NULL)
  {
    if(ptr->m_video->getTitle() == title) {
      ptr->m_video->print();
      return true;
    }
    ptr = ptr->m_next;
  }
  return false;
}


bool Vlist::remove(string title) {
  Node *ptr = m_head;
  if(m_head == NULL) {
    return false;
  }
  if(title == m_head->m_video->getTitle()) {
    if(m_head->m_next == NULL) {
      delete m_head->m_video;
      delete m_head;
      m_head = NULL;
      return true;
    }
    Node *temp = m_head;
    m_head = m_head->m_next;
    delete temp->m_video;
    delete temp;
    return true;
  }
  while (ptr->m_next != NULL && (title >= ptr->m_next->m_video->getTitle()))
  {
    if(title == ptr->m_next->m_video->getTitle()){
      Node *temp = ptr->m_next;
      if(ptr->m_next->m_next != NULL) {
        ptr->m_next = ptr->m_next->m_next;
      }
      else {
        ptr->m_next = NULL;
      }
      delete temp->m_video;
      delete temp;
      return true;
    }
    ptr = ptr->m_next;
  }
  return false;
}
