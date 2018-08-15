#include "video.h"

Video::Video(string title, string URL, string comment, float length, int rating) {
  m_title = title;
  m_URL = URL;
  m_comment = comment;
  m_length = length;
  m_rating = rating;
}

bool Video::compare(Video *other, string sort_crit) {
  if(sort_crit == "length") {
    return m_length > other->m_length;
  }
  else if(sort_crit == "title") {
    return m_title > other->m_title;
  }
  else if(sort_crit == "rating") {
    return m_rating < other->m_rating;
  }
  return false;
}

string Video::getTitle() {
  return m_title;
}

void Video::print() {
  switch (m_rating) {
    case 1:
      m_rstar = "*";
      break;
    case 2:
      m_rstar = "**";
      break;
    case 3:
      m_rstar = "***";
      break;
    case 4:
      m_rstar = "****";
      break;
    case 5:
      m_rstar = "*****";
      break;
    default:
      break;
  }
  cout << m_title << ", " << m_URL << ", " << m_comment << ", " << m_length << ", " << m_rstar << endl;
}
