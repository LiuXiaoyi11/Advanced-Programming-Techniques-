/*Copyright Xiaoyi Liu 04/09/2019*/


#include <matrix.h>  // NO LINT

Matrix::Matrix() : m_(nullptr), rows_(0), cols_(0) {}

Matrix::Matrix(unsigned int rows, unsigned int cols) :
    rows_(rows), cols_(cols) {
  assert(rows > 0);  // assert preconditions are true
  assert(cols > 0);  // assert preconditions are true

  m_ = new double *[rows_];  // create array of double pointers
  for (unsigned int i = 0; i < rows_; ++i) {
    m_[i] = new double[cols_];  // create array of doubles
    for (unsigned int j = 0; j < cols_; ++j) {
      m_[i][j] = 0.0;
    }
  }
}

Matrix::Matrix(const Matrix& that) {
  this->rows_ = that.rows_;
  this->cols_ = that.cols_;
  m_ = new double *[rows_];
  for (unsigned int i = 0; i < rows_; ++i) {
    m_[i] = new double[cols_];
    for (unsigned int j = 0; j < cols_; ++j) {
      m_[i][j] = that.m_[i][j];
    }
  }
}

Matrix::~Matrix() {
  if (m_) {
    for (unsigned int i = 0; i  <rows_; ++i)
    delete [] m_[i];
    delete [] m_;
  }
}

double Matrix::Get(unsigned int row, unsigned int col) const {
  return m_[row][col];
}

const Matrix& Matrix::operator=(const Matrix& rhs) {
  if (this == &rhs) {
    return *this;
  }
  if (this->rows_ != rhs.rows_ || this->cols_ != rhs.cols_) {
    if (this->m_ != nullptr) {
      delete [] this->m_;
    }
    this->rows_ = rhs.rows_;
    this->cols_ = rhs.cols_;
    m_ = new double *[rows_];
    for (unsigned int i = 0; i < rows_; ++i) {
      m_[i] = new double[cols_];
      for (unsigned int j = 0; j < cols_; ++j) {
        m_[i][j] = 0.0;
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

const Matrix& Matrix::operator*=(double rhs) {
  for (unsigned int i = 0; i < rows_; ++i) {
    for (unsigned int j = 0; j < cols_; ++j) {
      this->m_[i][j] = this->m_[i][j]*rhs;
    }
  }
     return *this;
}

  const Matrix Matrix::operator+(const Matrix& rhs) const {
     Matrix sum(rows_, cols_);
     for (unsigned int i = 0; i < rows_; ++i) {
       for (unsigned int j = 0; j < cols_; ++j) {
         sum.m_[i][j]= this->m_[i][j] + rhs.m_[i][j];
       }
     }
     return sum;
    }
