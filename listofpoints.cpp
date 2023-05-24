#include "listofpoints.hpp"
#include "point.hpp"
#include <vector>


ListOfPoints::ListOfPoints() {
  // implement me
}

void ListOfPoints::addAfter(Point& newPt, string name) {
  int vec_len = m_points.size();
  // checking name and inserting point accordingly using vector function
  for (int i = 0; i < vec_len; i++) {
    string cur_name = m_points[i].getName();
    if (cur_name == name) {
      m_points.insert(m_points.begin()+i+1, newPt);
    }
  }
}

void ListOfPoints::addPoint(Point& newPt)  {
  m_points.push_back(newPt);
}

void ListOfPoints::deletePoint(int pos) {
  m_points.erase(m_points.begin()+pos);
}

Point& ListOfPoints::getPointAt(unsigned int i) {
  return m_points[i];
}

int ListOfPoints::getSize() const {
  return m_points.size();
}

void ListOfPoints::printList() const {
  int vec_len = m_points.size();
  // using printPoint function from point.hpp
  for (int i = 0; i < vec_len; i++) {
    m_points[i].printPoint();
  }
}

void ListOfPoints::draw() const {
  int vec_len = m_points.size();
  bool printed_name;
  // each dash mark represents a coordinate from 0 to 20 on x and y
  for (int i = 20; i >= 0; i--) {
    for (int j = 0; j < 21; j++) {
      printed_name = false;
      for (int k = 0; k < vec_len; k++) {
        if (m_points[k].getX() == j && m_points[k].getY() == i) {
          cout << m_points[k].getName() << " ";
          printed_name = true;
        }
      }
      if (printed_name == false)
        cout << "- ";
    }
    cout << endl;
  }
}
 
