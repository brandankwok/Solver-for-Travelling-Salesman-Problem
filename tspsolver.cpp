#include "tspsolver.hpp"


TSPSolver::TSPSolver(ListOfPoints &list) {
  m_list = list;
}


void TSPSolver::solve() {
  int vec_len = m_list.getSize();
  float temp_distance1, temp_distance2, temp_distance3;
  
  for (int i = 3; i < vec_len; i++) {
    // getting the distances for each cycle
    temp_distance1 = m_list.getPointAt(i-3).getDistance(m_list.getPointAt(i)) + m_list.getPointAt(i).getDistance(m_list.getPointAt(i-2)) - m_list.getPointAt(i-2).getDistance(m_list.getPointAt(i-3));
    temp_distance2 = m_list.getPointAt(i-2).getDistance(m_list.getPointAt(i)) + m_list.getPointAt(i).getDistance(m_list.getPointAt(i-1)) - m_list.getPointAt(i-1).getDistance(m_list.getPointAt(i-2));
    temp_distance3 = m_list.getPointAt(i-1).getDistance(m_list.getPointAt(i)) + m_list.getPointAt(i).getDistance(m_list.getPointAt(i-3)) - m_list.getPointAt(i-3).getDistance(m_list.getPointAt(i-1));
    // checking which distance is the lowest then moving the points accordingly and deleting extra point
    if (temp_distance1 < temp_distance2 && temp_distance1 < temp_distance3) {
      m_list.addAfter(m_list.getPointAt(i), m_list.getPointAt(i-3).getName());
      m_list.deletePoint(i+1);
    }
    else if (temp_distance2 < temp_distance1 && temp_distance2 < temp_distance3) {
      m_list.addAfter(m_list.getPointAt(i), m_list.getPointAt(i-2).getName());
      m_list.deletePoint(i+1);
    }
    else if (temp_distance3 < temp_distance1 && temp_distance3 < temp_distance2) {
      m_list.addAfter(m_list.getPointAt(i), m_list.getPointAt(i-1).getName());
      m_list.deletePoint(i+1);
    }
  }
}


TSPCycle& TSPSolver::getSolution() {
  int vec_len = m_list.getSize();
  // adding the points from solve function to the solution
  for (int i = 0; i < vec_len; i++) {
    m_solution.addPoint(m_list.getPointAt(i));
  }
  
  return m_solution;
}

