#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 100
#define MAX_LENGTH 5000

int main(void) {
    char input[16] = {0};
    char task[MAX_TASKS][MAX_LENGTH] = {0};
    int index = 0, done = 0, tasks = 0;

    printf("Enter the number of tasks: ");

    while (!done) {
        int key = getchar();
        if (key == '\n') {
            if (index > 0) {
                tasks = atoi(input);
                if (tasks > MAX_TASKS || tasks <= 0) {
                    printf("Invalid number of tasks!\n");
                    return 1;
                }
                done = 1;
            }
        } else if (key >= '0' && key <= '9' && index < 15) {
            input[index++] = (char)key;
            input[index] = '\0';
        } else if (key == 8 || key == 127) {
            if (index > 0) {
                index--;
                input[index] = '\0';
            }
        }
    }

    for (int i = 0; i < tasks; i++) {
        printf("Enter task %d: ", i + 1);
        fgets(task[i], MAX_LENGTH, stdin);
    }

    printf("\nYour Todo List:\n");
    for (int i = 0; i < tasks; i++) {
        printf("%d. %s", i + 1, task[i]);
    }

    return 0;
}
