#include <iostream>
#include <cstdlib>

#include "point.hpp"
#include "listofpoints.hpp"
#include "tspsolver.hpp"
#include "tspcycle.hpp"

using namespace std;

void testPoint() {
  Point origin(0,0,"ORIGIN");
  cout << "--print using printPoint():" << endl;
  origin.printPoint();
  cout << "--print using toString():" << endl;
  cout << origin.toString() << endl;
  cout << "--print using << operator:" << endl;
  cout << origin << endl;
  

  Point q(3,4,"Q");
  //distance should be 5
  cout << "distance between ORIGIN and Q is " << q.getDistance(origin) << endl;

}

// gets a list of points and runs the solver on this list
// used in test1 and test2 below
void testSolver(ListOfPoints &input) {
  cout << "Running the solver..." << endl;
  TSPSolver solver(input);
  solver.solve();
  TSPCycle solution = solver.getSolution();

  cout << "Solution found is: " << endl;
  solution.printList();
  cout << "the length of the solution is: " << solution.getLength() << endl;
}


void test1() {
  Point p[4] = {Point(2,2,"A"),
                Point(2,6,"B"),
                Point(5,6,"C"),
                Point(5,9,"D")};
  
  cout << "Creating a list of points..." << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<4;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList(); 
  cout << "Drawing the points: " << endl;  
  inputTSP.draw();  
 
  testSolver(inputTSP);
}


void test2() {
  ListOfPoints inputTSP;
  Point p(0,0,"A");
  cout << "Creating a list of points..." << endl;

  for (int i=0;i<10;i++) {
    string s;
    s = 'A'+i;
    p = Point(i,0,s);
    inputTSP.addPoint(p);
  }

  cout << "Printing the list:" << endl;
  inputTSP.printList();
  cout << "Drawing the points: " << endl;  
  inputTSP.draw();  

  testSolver(inputTSP);
}


void test3() {
  ListOfPoints inputTSP;
  Point p(0,0,"O");
  cout << "Creating a list of points..." << endl;

  for (int i=0;i<50;i++) {
    p = Point(rand() % 1000, rand() % 1000,"P"+to_string(i));
    inputTSP.addPoint(p);
  }

  cout << "Printing the list:" << endl;
  inputTSP.printList();
  // some coordinates values more than 20, so we do not use draw here

  testSolver(inputTSP);
}


void test4() {
  Point p[4] = {Point(0,0,"A"),
                Point(0,2,"B"),
                Point(2,2,"C"),
                Point(2,0,"D")};

  cout << "Creating a list of points..." << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<4;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList(); 
  cout << "Drawing the points: " << endl;  
  inputTSP.draw();  
 
  testSolver(inputTSP);
}


void test5() {
  Point p[8] = {Point(10,13,"A"),
                Point(6,7,"B"),
                Point(3,8,"C"),
                Point(8,16,"D"),
                Point(0,3,"E"),
                Point(9,14,"F"),
                Point(0,1,"G"),
                Point(8,12,"H")};

  cout << "Creating a list of points..." << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<8;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList(); 
  cout << "Drawing the points: " << endl;  
  inputTSP.draw();  
 
  testSolver(inputTSP);
}


void test6() {
  Point p[5] = {Point(10,19,"A"),
                Point(6,19,"B"),
                Point(0,3,"C"),
                Point(4,17,"D"),
                Point(5,12,"E")};
  
  Point n = Point(3,7,"F");

  cout << "Creating a list of points..." << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<5;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Adding point after E..." << endl;
  inputTSP.addAfter(n, "E");
  
  cout << "Printing the list:" << endl;
  inputTSP.printList(); 
  cout << "Drawing the points: " << endl;  
  inputTSP.draw();  
 
  testSolver(inputTSP);
}


void test7() {
  Point p[15] = {Point(112,145,"A"),
                Point(84,134,"B"),
                Point(9,48,"C"),
                Point(1,60,"D"),
                Point(12,21,"E"),
                Point(59,114,"F"),
                Point(84,90,"G"),
                Point(24,170,"H"),
                Point(95,157,"I"),
                Point(107,137,"J"),
                Point(103,139,"K"),
                Point(39,120,"L"),
                Point(24,69,"M"),
                Point(111,180,"N"),
                Point(13,41,"O")};

  cout << "Creating a list of points..." << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<15;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
 
  testSolver(inputTSP);
}

void test8() {
  Point p[6] = {Point(1, 1, "A"),
                Point(8, 3, "B"),
                Point(6, 6, "C"),
                Point(5, 18, "D"),
                Point(2, 13, "E"),
                Point(7, 10, "F"),};

  cout << "Creating a list of points..." << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<6;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList(); 
  cout << "Drawing the points: " << endl;  
  inputTSP.draw();  
 
  testSolver(inputTSP);
}



int main() {

  // cout << "****Test point**" << endl;
  // testPoint();
  // cout << "****End of test point**" << endl << endl;

  cout << "****test1**:" << endl;
  test1();
  cout << "****end of test1**:" << endl << endl;
 
  cout << "****test2**:" << endl;
  test2();
  cout << "****end of test2**:" << endl << endl;

  cout << "****test3**:" << endl;
  test3();
  cout << "****end of test3**:" << endl << endl;

  cout << "****test4**:" << endl;
  test4();
  cout << "****end of test4**:" << endl << endl;

  cout << "****test5**:" << endl;
  test5();
  cout << "****end of test5**:" << endl << endl;

  cout << "****test6**:" << endl;
  test6();
  cout << "****end of test6**:" << endl << endl;

  cout << "****test7**:" << endl;
  test7();
  cout << "****end of test7**:" << endl << endl;

  cout << "****test8**:" << endl;
  test8();
  cout << "****end of test8**:" << endl << endl;

  return 0;
}
