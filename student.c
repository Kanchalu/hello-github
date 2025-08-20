#include <stdio.h>
#include <stdlib.h>
void inputMarks(int marks[], int n) {
  for (int i = 0; i < n; i++) {
    printf("Enter marks for student %d: " , i +1);
    scanf("%d", &marks[i]);
  }
}

void displayMarks(int marks[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Student %d: %d\n", i + 1, marks[i]);
    }
}

float calculateAverage(int marks[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += marks[i];
    }
    return (float)sum / n;
}


int findHighest(int marks[], int n) {
  int highest = marks[0];
  for (int i = 1; i < n; i++) {
    if (marks[i] > highest){
        highest = marks[i];
    }
  }
  return highest;
}

int findLowest(int marks[], int n) {
  int lowest = marks[0];
  for (int i = 1; i < n; i++) {
    if(marks[i] < lowest) {
        lowest = marks[i];
    }
  }
  return lowest;
}
int main()
{
    int n, repeat;
    int marks [100];

    do {
        printf("Enter number of students: ");
        scanf("%d", &n);

        inputMarks(marks, n);
        printf("\nMarks entered: ");
        displayMarks(marks, n);

        printf("\nAverage mark: %.2f", calculateAverage(marks, n));
        printf("\nHighest mark: %d", findHighest(marks, n));
        printf("\nLowest mark: %d\n", findLowest(marks, n));

        printf("\nDo you want to enter marks for another class? (1-Yes, 0-No): ");
        scanf("%d", &repeat);
        printf("\n");
    } while (repeat == 1);


    return 0;
}
