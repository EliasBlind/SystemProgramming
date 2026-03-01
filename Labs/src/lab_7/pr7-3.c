#include <stdio.h>
#include <stdlib.h>

struct Student {
  char name[50];
  int group;
  int grades[5];
};

int main(void) {
  int n;
  printf("Enter number of students: ");
  scanf("%d", &n);

  struct Student *st_ptr = (struct Student *)malloc(n * sizeof(struct Student));

  if (st_ptr == NULL)
    return 1;

  for (int i = 0; i < n; i++) {
    printf("Student %d name: ", i + 1);
    scanf("%s", st_ptr[i].name);
    printf("Group: ");
    scanf("%d", &st_ptr[i].group);
    printf("Enter 5 grades: ");
    for (int j = 0; j < 5; j++)
      scanf("%d", &st_ptr[i].grades[j]);
  }

  printf("\n--- Student List ---\n");
  for (int i = 0; i < n; i++) {
    printf("%s (Group: %d)\n", st_ptr[i].name, st_ptr[i].group);
  }

  free(st_ptr);
  return 0;
}
