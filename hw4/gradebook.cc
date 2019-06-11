/*
* Copyright Xiaoyi Liu 03/29/2019
*/
#include "../hw4/gradebook.h" //NOLINT 
#include <iostream>

void GradeBook::Add(double grade) {
  grades_.push_back(grade);
}
double GradeBook::Get(std::size_t index) const {
  return index < grades_.size() ? grades_[index] : NAN;
}

const GradeBook GradeBook::operator+(double rhs) const {
  GradeBook newGradeBook;
  for (unsigned int i = 0; i < grades_.size(); ++i) {
      newGradeBook.Add(grades_[i]);
  }
  newGradeBook.Add(rhs);
  return newGradeBook;
}

const GradeBook operator+(double lhs, const GradeBook& rhs) {
  GradeBook newGradeBook = rhs;
  newGradeBook.Add(lhs);
  return newGradeBook;
}

const GradeBook GradeBook::operator+(const GradeBook& rhs) const {
  GradeBook AddGradeBook;
    AddGradeBook.grades_.insert(AddGradeBook.grades_.end(),
                                grades_.begin(), grades_.end());
    AddGradeBook.grades_.insert(AddGradeBook.grades_.end(),
                                rhs.grades_.begin(), rhs.grades_.end());
    return AddGradeBook;
}

bool GradeBook::operator==(const GradeBook& rhs) const {
  if (grades_.empty() && rhs.grades_.empty()) {
    return true;
  }
     if (grades_.empty() || rhs.grades_.empty()) {
        return false;
    }
    double sum = 0.0;
     for (unsigned int i = 0; i < grades_.size(); ++i) {
         sum+= grades_[i];
     }
     double grades_agv = sum/grades_.size();

    sum = 0.0;
    for (unsigned int i = 0; i < rhs.grades_.size(); ++i) {
         sum+= rhs.grades_[i];
     }
     double rhs_grades_agv = sum/rhs.grades_.size();
     if (grades_agv > rhs_grades_agv) {
       if (grades_agv - rhs_grades_agv < 0.00001) {
           return true;
       } else {
           return false;
       }
     } else {
         if ((rhs_grades_agv - grades_agv) < 0.00001) {
            return true;
         } else {
             return false;
         }
       }
}

bool GradeBook::operator==(double rhs) const {
  if (grades_.empty()) {
    return false;
  }
  double sum = 0.0;
     for (unsigned int i = 0; i < grades_.size(); ++i) {
         sum+= grades_[i];
     }
     double grades_agv = sum/grades_.size();
     if (grades_agv > rhs) {
       if (grades_agv - rhs < 0.00001) {
           return true;
       } else {
           return false;
       }
     } else {
         if ((rhs - grades_agv) < 0.00001) {
            return true;
         } else {
             return false;
         }
       }
}

bool operator == (double lhs, const GradeBook& rhs) {
  GradeBook A;
  A.Add(lhs);
  return A == rhs;
}

bool GradeBook::operator < (const GradeBook& rhs) const {
  if (this->operator == (rhs)) {
  double max = 0.0;
     for (unsigned int i = 0; i < grades_.size(); ++i) {
         if (max < grades_[i]) {
             max = grades_[i];
         }
     }
     double A = max;
     max = 0.0;
     for (unsigned int i = 0; i < rhs.grades_.size(); ++i) {
         if (max < rhs.grades_[i]) {
             max = rhs.grades_[i];
         }
     }
     double B = max;
     return A <= B;
     } else {
       if (rhs.grades_.empty()) {
         return false;
    }
    if (grades_.empty()) {
      return true;
    }
    double sum = 0.0;
    for (unsigned int i = 0; i < grades_.size(); ++i) {
      sum+= grades_[i];
    }
    double A = sum/grades_.size();
    sum = 0.0;
    for (unsigned int i = 0; i < rhs.grades_.size(); ++i) {
      sum+= rhs.grades_[i];
    }
    double B = sum/rhs.grades_.size();
    return A < B;
  }
}

bool GradeBook::operator<(double rhs) const {
  if (grades_.empty()) {
    return true;
  }
  double sum = 0.0;
    for (unsigned int i = 0; i < grades_.size(); ++i) {
      sum+= grades_[i];
    }
    double A = sum/grades_.size();
  return A < rhs;
}

bool operator<(double lhs, const GradeBook& rhs) {
  if (rhs.getSize() == 0) {
    return false;
  }
  double sum = 0.0;
    for (unsigned int i = 0; i < rhs.getSize(); ++i) {
      sum+= rhs.Get(i);
    }
    double A = sum/rhs.getSize();
    return lhs < A;
}





