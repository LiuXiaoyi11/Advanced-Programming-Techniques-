/* Copyright 2019 Jeremy S Lewis CSCE240 Dynamic Array */

#include <test_matrix.h>


int main(int argc, char** argv) {
    cout << "before calling constructor" << endl;
  MatrixTester tester;

    cout << "after calling constructor" << endl;

  cout << "Testing Matrix::Matrix(Matrix&)" << endl;
  if (tester.Test_CopyConstructor()) {
    cout << "  PASSED" << endl;
    return 0;
  }

  cout << "  FAILED" << endl;
  return 1;
}



bool MatrixTester::Test_CopyConstructor() const {
  const int kRows = 3, kCols = 4;
  Matrix m1;
  m1.m_ = new double *[kRows];
  for (unsigned int i = 0; i < kRows; ++i) {
    m1.m_[i] = new double[kCols];

    for (unsigned int j = 0; j < kCols; ++j)
      m1.m_[i][j] = (i + 1.333)*(j + 1.667);
  }
  m1.rows_ = kRows;
  m1.cols_ = kCols;

    cout << "1" << endl;
  // TEST ASSIGNMENT OP DEEP COPY
  Matrix m2 = m1;
    cout << "2" << endl;
  if (m1.m_ == m2.m_) {
    cout << "  Expected Address of matrix 2's array: NOT " << m1.m_
      << ", Actual: " << m2.m_ << endl;
    return false;
  }
    cout << "3" << endl;
  // TEST ASSIGNMENT OP EQUALITY
  for (unsigned int i = 0; i < kRows; ++i)
    for (unsigned int j = 0; j < kCols; ++j)
        if (m1.m_[i][j] != m2.m_[i][j]) {
          cout << "  Expected Matrix 2[" << i << "][" << j << "]: "
              << m1.m_[i][j] << ", Actual: " << m2.m_[i][j] << endl;
          return false;
        }

  return true;}
