/* Copyright 2019 Jeremy S Lewis CSCE240 Dynamic Array */

#include <cassert>
// using assert
#include <iostream>
using std::cout;
using std::endl;

#include <matrix.h>  // NOLINT

#ifndef _HW5_TEST_MATRIX_H_ // NOLINT
#define _HW5_TEST_MATRIX_H_ // NOLINT


class MatrixTester {
 public:
  bool Test_CopyConstructor() const;

  bool Test_Get() const;

  bool Test_AssignOp() const;

  bool Test_MulAssignOp() const;

  bool Test_AddOp() const;
};
#endif // NOLINT