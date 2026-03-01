#include <stdio.h>

struct Student {
  char name[50];
  int group;
  int grades[5];
};

void printStudent(struct Student s) {
  printf("Name: %-10s | Group: %d | ", s.name, s.group);
}

float getAverage(struct Student s) {
  float sum = 0;
  for (int i = 0; i < 5; i++) {
    sum += s.grades[i];
  }
  return sum / 5.0;
}

int main() {
  struct Student group[3] = {{"Ivanov", 101, {5, 5, 4, 5, 4}},
                             {"Petrov", 102, {3, 4, 3, 2, 4}},
                             {"Sidorov", 101, {5, 5, 5, 5, 5}}};

  for (int i = 0; i < 3; i++) {
    printStudent(group[i]);
    printf("Average: %.2f\n", getAverage(group[i]));
  }

  return 0;
}
