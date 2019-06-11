/*
* Copyright Xiaoyi Liu 03/05/2019
*/
#include <stdlib.h>
#include <cmath>
#include "gradebook.h" //NOLINT

void GradeBook::Add(double grade) {
      grades.push_back(grade);
}


double GradeBook::Get(size_t index) const {
     if (grades.empty() || index >= grades.size()) {
          return NAN;
      } else {
          return grades[index];
      }
}

const GradeBook GradeBook::Add(const GradeBook& that) const {
    GradeBook AddGradeBook;
    vector<double> grades1, grades2;
    grades1.insert(grades1.end(), grades.begin(), grades.end());
    grades2.insert(grades2.end(), that.grades.begin(), that.grades.end());
    grades1.insert(grades1.end(), grades2.begin(), grades2.end());
    for (unsigned int i=0; i < grades1.size(); ++i) {
        AddGradeBook.Add(grades1[i]);
    }
    return AddGradeBook;
}

double GradeBook::GetGPA() const {
     if (grades.empty()) {
         return NAN;
     }
     double sum = 0.0;
     for (unsigned int i = 0; i < grades.size(); ++i) {
         sum+= grades[i];
     }
     return sum/grades.size();
}

double GradeBook::GetMax() const {
      if (grades.empty()) {
         return NAN;
     }
     double max = 0.0;
     for (unsigned int i = 0; i < grades.size(); ++i) {
         if (max < grades[i]) {
             max = grades[i];
         }
     }
     return max;
}

const size_t GradeBook::GetSize() const {
    return grades.size();
}

bool GradeBook::Equals(const GradeBook& that) const {
    if (grades.empty() && that.grades.empty()) {
        return true;
    }
    if (grades.empty() || that.grades.empty()) {
        return false;
    }
    if ((this->GetGPA() > that.GetGPA())) {
       if ((this->GetGPA() - that.GetGPA()) < 0.00001) {
           return true;
       } else {
           return false;
       }
    } else {
        if ((that.GetGPA() - this->GetGPA()) < 0.00001) {
           return true;
        } else {
            return false;
        }
      }
}

bool GradeBook::LessThan(const GradeBook& that) const {
    if (grades.empty() && that.grades.empty()) {
        return false;
    }
    if (grades.empty()) {
        return true;
    }
    if (that.grades.empty()) {
        return false;
    }
    if (this->Equals(that)) {
        if (this->GetMax() < that.GetMax()) {
            return true;
        } else {
            return false;
        }
    } else {
        return this->GetMax() < that.GetMax();
    }
}

