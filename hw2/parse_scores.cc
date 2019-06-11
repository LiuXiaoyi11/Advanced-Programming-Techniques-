/*
* Copyright 2019 Xiaoyi Liu 
*/
#include "parse_scores.h" //NOLINT

bool check_format(const std::string values[], int size) {
  if (values == nullptr || size == 0) {
  return false;
}

int num_of_students = stoi(values[0]);
if (num_of_students == 0) {
  if (size == 1) {
    return true;
  } else {
    return false;
  }
}

if (size < num_of_students*2) {
  return false;
}

int counter_place_in_array = 1;
for (int i=0; i < num_of_students; ++i) {
  ++counter_place_in_array;
  if (counter_place_in_array > (size - 1)) {
    return false;
  }
int num_of_grades = stoi(values[counter_place_in_array]);
counter_place_in_array = counter_place_in_array + num_of_grades + 1;
if (i == num_of_students -1 && counter_place_in_array == size) {
  return true;
}
}
return false;
}

int get_num_grades(int id, const std::string values[], int size) {
  if (!check_format(values, size)) {
    return -10;
  }
  for (int i = 0; i < size; ++i) {
    if (id == stoi(values[i])) {
    int num_of_grades = stoi(values[i+1]);
    return num_of_grades;
    }
  }
  return -1;
}

int get_grades(int id, const std::string values[], int size, double grades[]) {
  if (!check_format(values, size)) {
    return -10;
  } else {
    int start_index_grades = 0;
      for (int i = 0; i < size; ++i) {
        if (id == stoi(values[i])) {
          int num_of_grades = stoi(values[i + 1]);
          start_index_grades = i + 2;
          for (int j = 0; j < num_of_grades; ++j) {
            grades[j] = stod(values[start_index_grades]);
            ++start_index_grades;
          }
        return num_of_grades;
        }
      }
      return -1;
    }
}

double get_grade(int id,
                   int grade_index, const std::string values[], int size) {
  int start_index_grade = 0;
  if (!check_format(values, size)) {
    return -10;
  }
  for (int i = 0; i < size; ++i) {
    if (id == stoi(values[i])) {
      int num_of_grades = stoi(values[i + 1]);
      start_index_grade = i + 2;
      if (grade_index < num_of_grades) {
        double grade = stod(values[start_index_grade + grade_index]);
        return grade;
     } else {
      return -2;
       }
    }
  }
  return -1;
}

int get_max_grade_id(const std::string values[], int size) {
  if (!check_format(values, size)) {
    return -10;
  }
  int num_of_students = stoi(values[0]);
  if (num_of_students == 0) {
    if (size == 1) {
      return -1;
    }
  }
  int max_id = 0;
  double max_grade = 0.0;
  for (int index = 1; index < size;) {
    int current_student_id = stoi(values[index]);
    ++index;
    if (index < size) {
    int num_of_grades = stoi(values[index]);
      if (num_of_grades != 0 && index + num_of_grades < size) {
        ++index;
        double current_max_grade = stod(values[index]);
        for (int i = 1; i < num_of_grades; ++i) {
          double current_score = stod(values[index + i]);
          if (current_max_grade < current_score) {
            current_max_grade = current_score;
          }
        }
        index = index + num_of_grades;
        if (max_grade < current_max_grade) {
          max_grade = current_max_grade;
          max_id = current_student_id;
        }
      }
    }
  }
  if (max_grade == 0.0) {
    return -2;
  }
  return max_id;
}

double get_max_grade(const std::string values[], int size) {
  if (!check_format(values, size)) {
    return -10;
  }
  int num_of_students = stoi(values[0]);
  if (num_of_students == 0) {
    return -1;
  }
  int max_id = 0;
  double max_grade = 0.0;
  for (int index = 1; index < size;) {
    int current_student_id = stoi(values[index]);
    index++;
    if (index < size) {
      int num_of_grades = stoi(values[index]);
      if (num_of_grades == 0) {
        return -2;
      }
      if (index + num_of_grades < size) {
      ++index;
      double current_max_grade = stod(values[index]);
      for (int i = 1; i < num_of_grades; i++) {
        double current_score = stod(values[index + i]);
        if (current_max_grade < current_score) {
          current_max_grade = current_score;
        }
      }
      index = index + num_of_grades;
      if (max_grade < current_max_grade) {
        max_grade = current_max_grade;
        max_id = current_student_id;
      }
      }
    }
  }
  max_id = max_id;
  return max_grade;
}

int get_student_ids(const std::string values[], int size, int ids[]) {
  if (!check_format(values, size)) {
    return -10;
  }
  int num_of_students = stoi(values[0]);
  for (int index = 1, ids_index = 0;
         index < size && ids_index < num_of_students; ++ids_index) {
    int student_id = stoi(values[index]);
    ids[ids_index] = student_id;
    int num_of_grades = get_num_grades(student_id, values, size);
    index = index + 1 + num_of_grades + 1;
  }
return num_of_students;
}
