#include <stdio.h>

struct Student {
  char name[50];
  int group;
  int grades[5];
};

int main(void) {
  struct Student students[3] = {{"Ivanov", 101, {5, 4, 5, 5, 4}},
                                {"Petrov", 102, {3, 4, 3, 5, 4}},
                                {"Sidorov", 101, {5, 5, 5, 4, 5}}};

  printf("Student: %s\nGroup: %d\nFirst Grade: %d\n", students[1].name,
         students[1].group, students[1].grades[0]);

  return 0;
}
