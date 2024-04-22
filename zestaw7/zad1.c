#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert word to number
int wordToNumber(char *word) {
    if (strcmp(word, "zero") == 0) return 0;
    if (strcmp(word, "one") == 0) return 1;
    if (strcmp(word, "two") == 0) return 2;
    if (strcmp(word, "three") == 0) return 3;
    if (strcmp(word, "four") == 0) return 4;
    if (strcmp(word, "five") == 0) return 5;
    if (strcmp(word, "six") == 0) return 6;
    if (strcmp(word, "seven") == 0) return 7;
    if (strcmp(word, "eight") == 0) return 8;
    if (strcmp(word, "nine") == 0) return 9;
    return -1; // -1 for no match
}

// Function to calculate energy sum considering both front and back numbers
int calculateEnergySum2(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Cannot open file");
        exit(EXIT_FAILURE);
    }

    char *words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    int sum = 0;
    char line[80];

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0'; // Remove newline character

        int number_front = -1;
        int number_back = -1;
        int actual_line_len = 0;

        // Calculate actual line length
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] != '\0') {
                actual_line_len++;
            }
        }

        // Check from the beginning of the line
        for (int i = 0; i < actual_line_len; i++) {
            if (isdigit(line[i])) {
                number_front = line[i] - '0';
                break;
            } else {
                for (int j = 0; j < 10; j++) {
                    if (strncmp(&line[i], words[j], strlen(words[j])) == 0) {
                        number_front = wordToNumber(words[j]);
                        break;
                    }
                }
                if (number_front != -1) {
                    break;
                }
            }
        }

        // Check from the end of the line
        for (int i = actual_line_len; i >= 0; i--) {
            if (isdigit(line[i])) {
                number_back = line[i] - '0';
                break;
            } else {
                for (int j = 0; j < 10; j++) {
                    if (strncmp(&line[i], words[j], strlen(words[j])) == 0) {
                        number_back = wordToNumber(words[j]);
                        break;
                    }
                }
            }
            if (number_back != -1) {
                break;
            }
        }

        sum += (number_front * 10) + number_back;
    }

    fclose(file);
    return sum;
}

// Function to calculate energy sum considering only the front number
int calculateEnergySum1(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Cannot open file");
        exit(EXIT_FAILURE);
    }

    int sum = 0;
    char line[80];

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0'; // Remove newline character

        int number_front = -1;
        int number_back = -1;
        int actual_line_len = 0;

        // Calculate actual line length
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] != '\0') {
                actual_line_len++;
            }
        }

        // Check from the beginning of the line
        for (int i = 0; i < actual_line_len; i++) {
            if (isdigit(line[i])) {
                number_front = line[i] - '0';
                break;
            }
        }

        // Check from the end of the line
        for (int i = actual_line_len; i >= 0; i--) {
            if (isdigit(line[i])) {
                number_back = line[i] - '0';
                break;
            }
        }

        sum += (number_front * 10) + number_back;
    }

    fclose(file);
    return sum;
}

int main() {
    const char *filename = "tekstowy.txt";

    // Calculate energy sum considering both front and back numbers
    int energySum1 = calculateEnergySum1(filename);
    printf("I. Sum of energy values: %d\n", energySum1);

    // Calculate energy sum considering only the front number
    int energySum2 = calculateEnergySum2(filename);
    printf("II. Sum of energy values: %d\n", energySum2);

    return 0;
}
