#include "point.hpp"
#include "math.h"


float Point::getDistance(const Point &other) const { 
  float distance;
  distance = sqrt(pow((m_y - other.getY()), 2) + pow((m_x - other.getX()), 2));
  return distance;
}

string Point::toString() const {
  // examples how to create string from small parts
  string str(m_name);
  str += " = (";
  str += std::to_string(m_x);
  str.append(",").append(std::to_string(m_y)).append(")");
  return str;
}


void Point::printPoint() const {
  cout << toString() << endl;
}

// used for printing Point using << operator.
// For example, the following code will work
// Point origin(0,0,'O');
// cout << origin;
ostream& operator<<(ostream &os, const Point &p) {
  return os << p.toString();
}
