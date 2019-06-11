/* Copyright 2019 Jeremy S Lewis CSCE240 Dynamic Array */

#ifndef _TEST_MATRIX_H_  // NOLINT
#define _TEST_MATRIX_H_  // NOLINT

#include <cassert>  // NOLINT
// using assert
#include <iostream>  // NOLINT
using std::cout;
using std::endl;

#include <matrix.h>  // NOLINT

class MatrixTester {
 public:
  bool Test_CopyConstructor() const;

  bool Test_Get() const;

  bool Test_AssignOp() const;

  bool Test_MulAssignOp() const;

  bool Test_AddOp() const;
};
#endif  // NOLINT
