/* Copyright 2019 Jeremy S Lewis CSCE240 Dynamic Array */

#include "matrix.h"  // NOLINT
template<class T>
Matrix<T>::Matrix() : m_(nullptr), rows_(0), cols_(0) {}

template<class T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols) :
    rows_(rows), cols_(cols) {
  assert(rows > 0);
  assert(cols > 0);

  m_ = new T *[rows_];
  for (unsigned int i = 0; i < rows_; ++i) {
    m_[i] = new T[cols_];
    for (unsigned int j = 0; j < cols_; ++j) {
      m_[i][j] = 0.0;
    }
  }
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& that) {
  this->rows_ = that.rows_;
  this->cols_ = that.cols_;
  m_ = new T *[rows_];
  for (unsigned int i = 0; i < rows_; ++i) {
    m_[i] = new T[cols_];
    for (unsigned int j = 0; j < cols_; ++j) {
      m_[i][j] = that.m_[i][j];
    }
  }
}

template<class T>
Matrix<T>::~Matrix() {
  if (m_) {
    for (unsigned int i = 0; i < rows_; ++i)
    delete [] m_[i];
    delete [] m_;
  }
}

template<class T>
T Matrix<T>::Get(unsigned int row, unsigned int col) const {
  return m_[row][col];
}

template<class T>
const Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) {
  if (this == &rhs) {
    return *this;
  }
  if (this->rows_ != rhs.rows_ || this->cols_ != rhs.cols_) {
    if (this->m_ != nullptr) {
      delete [] this->m_;
    }
    this->rows_ = rhs.rows_;
    this->cols_ = rhs.cols_;
    m_ = new T *[rows_];
    for (unsigned int i = 0; i < rows_; ++i) {
      m_[i] = new T[cols_];
      for (unsigned int j = 0; j < cols_; ++j) {
        m_[i][j] = 0;
      }
    }
  }
  for (unsigned int i = 0; i < rows_; ++i) {
    for (unsigned int j = 0; j < cols_; ++j) {
      m_[i][j] = rhs.m_[i][j];
    }
  }
  return *this;
}

template<class T>
const Matrix<T>& Matrix<T>::operator*=(T rhs) {
  for (unsigned int i = 0; i < rows_; ++i) {
    for (unsigned int j = 0; j < cols_; ++j) {
      this->m_[i][j] = this->m_[i][j]*rhs;
    }
  }
     return *this;
}

template<class T>
const Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) const {
     Matrix sum(rows_, cols_);
     for (unsigned int i = 0; i < rows_; ++i) {
       for (unsigned int j = 0; j < cols_; ++j) {
         sum.m_[i][j]= this->m_[i][j] + rhs.m_[i][j];
       }
     }
     return sum;
    }
