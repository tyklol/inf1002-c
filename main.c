#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256

char lines[100][MAX_LINE_LENGTH];
char records[100][MAX_LINE_LENGTH];
int menuLoop = 1;
void changeDatabaseName(const char* filename, const char* newDatabaseName) {
    FILE* file;
    errno_t err;

    // Open the file for reading
    err = fopen_s(&file, filename, "r");
    if (err != 0) {
        perror("Error opening file");
        return;
    }

    char lines[100][MAX_LINE_LENGTH];
    int lineCount = 0;

    // Read all lines from the file
    while (fgets(lines[lineCount], sizeof(lines[lineCount]), file)) {
        lineCount++;
    }

    fclose(file);

    // Modify the database name line
    snprintf(lines[0], sizeof(lines[0]), "Database Name: %s\n", newDatabaseName);

    // Open the file for writing
    err = fopen_s(&file, filename, "w");
    if (err != 0) {
        perror("Error opening file for writing");
        return;
    }

    // Write the updated lines back to the file
    for (int i = 0; i < lineCount; i++) {
        fputs(lines[i], file);
    }
    fclose(file);
}
void openFile(char* filename) {
    FILE* file;
    errno_t err;

    // Open the file for reading
    err = fopen_s(&file, filename, "r");
    if (err != 0) {
        perror("CMS: Error opening file");
        return;
    }
    else {
        printf("CMS: The database file \"%s\" is successfully opened.\n", filename);
    }
    int lineCount = 0;
    int skipLines = 5; // Number of lines to skip

    // Skip the first four lines
    while (skipLines > 0 && fgets(lines[0], sizeof(lines[0]), file)) {
        skipLines--;
    }
    while (fgets(records[lineCount], sizeof(records[lineCount]), file)) {
        lineCount++;
    }
    fclose(file);
}

void queryRecord() {
    chris
}

void insertRecord() {
    yekai
}

void updateRecord() {
    chris
}

void deleteRecord() {
    weihao
}

void saveFile() {
    yekai
}
int main() {
    char input[10];
    while (menuLoop) {
        printf("P9-9:");
        fgets(input, 10, stdin);

        // Convert input to lowercase
        for (int i = 0; input[i]; i++) {
            input[i] = tolower(input[i]);
        }
        input[strcspn(input, "\n")] = 0;
        if (strcmp(input, "open") == 0) {
            openFile("database.txt");
            printf("records[5]: %s\n", records[0]);
        }
        else if (strcmp(input, "query") == 0) {
            queryRecord();
        }
        else if (strcmp(input, "insert") == 0) {
            insertRecord();
        }
        else if (strcmp(input, "update") == 0) {
            updateRecord();
        }
        else if (strcmp(input, "delete") == 0) {
            deleteRecord();
        }
        else if (strcmp(input, "save") == 0) {
            saveFile();
        }
        else if (strcmp(input, "exit") == 0) {
            printf("CMS: Exiting program\n");
            menuLoop = 0;
        }
        else {
            printf("Invalid command\n");
        }
    }


    return 0;
}

