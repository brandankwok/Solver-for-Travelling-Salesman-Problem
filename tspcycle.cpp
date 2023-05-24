#include <iostream>

#include "tspcycle.hpp"

TSPCycle::TSPCycle() {
  // implement me
//  cout << "default TSPCycle constructor" << endl;
}

// returns the length of the cycle
float TSPCycle::getLength() const {
  int vec_len = m_points.size();
  float cycle_len = 0;
  // adding up length from beginning to end of vector
  for (int i = 1; i < vec_len; i++) {
    cycle_len += m_points[i].getDistance(m_points[i-1]);
  }
  // add length of last element to first element to complete the cycle length
  cycle_len += m_points[vec_len-1].getDistance(m_points[0]);

  return cycle_len;
}
