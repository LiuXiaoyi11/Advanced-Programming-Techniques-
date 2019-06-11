#include "parse_scores.h"

#include <cassert>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

std::string kValues[] = {
  "2",
  "1234", "3", "98.7", "87.92", "77.32", 
  "2345", "4", "93.1", "90.23", "81.21", "89.33" };
int kSize = 12;

bool TestGetGrades();
bool TestGetGradesNoMatch();
bool TestGetGradesCorrupt();


int main(int argc, char* argv[]) {
  int passed = 0;

  // test get_grades
  cout << "Testing get_student_ids" << endl;
  if (TestGetStudentIds())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }

  cout << "Testing get_student_ids with no matching id" << endl;
  if (TestGetStudentIdsNoMatch())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }

  cout << "Testing get_student_ids corrupt format" << endl;
  if (TestGetStudentIdsCorruptFormat())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }

  // test get_student_ids
  int ids[5];
  assert(get_student_ids(kValues, kSize, ids) == 2);
  assert(ids[0] == 1234);
  assert(ids[1] == 2345);

  return passed;
}

bool TestGetStudentIds() {
  int expected_ids[] = { 1234, 2345 };
  int actual_ids[5];
  double expected_num_ids = 2;

  int actual_num_ids = get_student_ids(kValues, kSize, actual_ids);
  if (expected_num_ids != actual_num_ids) {
    cout << "\tExpected: " << expected_num_ids << ", Actual: "
        << actual_num_ids << endl;
    return false;
  }

  for (int i = 0; i < expected_num_ids; ++i) {
    if (expected_ids[i] != actual_ids[i]) {
      cout << "\tExpected id at " << i << ": " << expected_ids[i]
          << "Actual id : " << actual_ids[i] << endl;
      return false;
    }
  }
  return true;
}

bool TestGetStudentIdsFormateCorrupt() {
  double dummy_data[5];
  int expected = -10;
  int actual = get_student_ids(kValues, kSize-4, dummy_data);
  if (expected != actual) {
    cout << "\tExpected id at " << i << ": " << expected
        << "Actual id: " << actual << endl;
    return false;
  }

  return true; 
}
