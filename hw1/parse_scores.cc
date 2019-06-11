/*
 * Copyright 2019 XiaoyiLiu
 */
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  /* The following input
   *
   *   2 1234 3 98.7 87.92 77.32 2345 3 93.1 90.23 81.21
   *
   * would result in the following output.
   */
    double max_score;
    int number_of_students;
    cin >> number_of_students;
    cout << "{" << endl;
    cout << "  \"students\" : [" << endl;

    int max_id = 0;
    for (int i = 0; i < number_of_students; ++i) {
        int student_id;
        cin >> student_id;
        cout << "    { \"id\" : " << student_id << "," << " \"grades\" : [ ";
        int number_of_scores;
        double current_max_score = 0.0;
        cin >> number_of_scores;
        for (int j = 0; j < number_of_scores; ++j) {
            double scores;
            cin >> scores;
            cout << scores;
            if (current_max_score < scores) {
               current_max_score = scores;
            }
            if ( j < number_of_scores-1)
              cout << ",";
        }
         cout << " ] }";
         

         if (i < number_of_students-1) {
           cout << "," << endl;
          }
            if (max_score < current_max_score) {
                  max_score = current_max_score;
                  max_id = student_id;
            }
    }
    cout << endl;
    cout << "]," << endl;

        cout << "  \"max_id\" : " << max_id << ", " << endl;
        cout << "  \"max_score\" : " << max_score << endl;
        cout << "}";
}


