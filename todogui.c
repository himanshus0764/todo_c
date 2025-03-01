#include "raylib.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>  // For atoi()

#define MAX_INPUT_LENGTH 256
#define MAX_TASKS 100  // Maximum possible tasks

typedef enum { INPUT_KEY, INPUT_TASK, SHOW_TASKS } AppState;

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Todo App");
    SetTargetFPS(60);

    AppState state = INPUT_KEY;

    char inputText[MAX_INPUT_LENGTH] = {0};
    int textLength = 0;

    char keyInput[MAX_INPUT_LENGTH] = {0};
    char tasks[MAX_TASKS][MAX_INPUT_LENGTH] = {0};
    int tasksCount = 0;  // Will be set dynamically

    bool finished[MAX_TASKS] = { false };

    while (!WindowShouldClose()) {
        int key = GetCharPressed();
        while (key > 0) {
            if ((key >= 32 && key <= 126) && textLength < MAX_INPUT_LENGTH - 1) {
                inputText[textLength++] = (char)key;
                inputText[textLength] = '\0';
            }
            key = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE) && textLength > 0) {
            inputText[--textLength] = '\0';
        }

        if (IsKeyPressed(KEY_ENTER)) {
            if (state == INPUT_KEY) {
                if (textLength > 0) {
                    strcpy(keyInput, inputText);
                    int keyValue = atoi(keyInput);  // Convert input to an integer

                    // Validate and set tasksCount
                    if (keyValue > 0 && keyValue <= MAX_TASKS) {
                        tasksCount = keyValue;
                    } else {
                        tasksCount = MAX_TASKS;  // Default if invalid input
                    }

                    memset(inputText, 0, MAX_INPUT_LENGTH);
                    textLength = 0;
                    state = INPUT_TASK;
                }
            } else if (state == INPUT_TASK) {
                if (textLength > 0) {
                    static int currentTask = 0;

                    if (currentTask < tasksCount) {  // Limit task addition
                        strcpy(tasks[currentTask], inputText);
                        currentTask++;
                    }

                    memset(inputText, 0, MAX_INPUT_LENGTH);
                    textLength = 0;
                } else {
                    state = SHOW_TASKS;
                }
            }
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);

            if (state == INPUT_KEY) {
                DrawText("Enter number of tasks:", 20, 20, 20, BLACK);
                DrawRectangle(20, 50, 500, 40, LIGHTGRAY);
                DrawRectangleLines(20, 50, 500, 40, BLACK);
                DrawText(inputText, 30, 60, 20, BLACK);
            } else if (state == INPUT_TASK) {
                DrawText("Enter task (press Enter on empty input to finish):", 20, 20, 20, BLACK);
                DrawRectangle(20, 50, 500, 40, LIGHTGRAY);
                DrawRectangleLines(20, 50, 500, 40, BLACK);
                DrawText(inputText, 30, 60, 20, BLACK);

                for (int i = 0; i < tasksCount; i++) {  // Fixed loop condition
                    char taskDisplay[300];
                    sprintf(taskDisplay, "%d: %s", i + 1, tasks[i]);
                    DrawText(taskDisplay, 20, 110 + i * 30, 20, DARKGRAY);
                }
            } else if (state == SHOW_TASKS) {
                DrawText("Key Entered:", 20, 20, 20, BLACK);
                DrawText(keyInput, 150, 20, 20, DARKGRAY);
                DrawText("All Tasks:", 20, 60, 20, BLACK);

                for (int i = 0; i < tasksCount; i++) {
                    char taskDisplay[300];
                    sprintf(taskDisplay, "%d: %s", i + 1, tasks[i]);
                    DrawText(taskDisplay, 30, 100 + i * 30, 20, DARKGRAY);
                }
            }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
