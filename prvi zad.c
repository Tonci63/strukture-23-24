/*. Napisati program koji prvo pročita koliko redaka ima datoteka, tj. koliko ima studenata
zapisanih u datoteci. Nakon toga potrebno je dinamički alocirati prostor za niz struktura
studenata (ime, prezime, bodovi) i učitati iz datoteke sve zapise. Na ekran ispisati ime,
prezime, apsolutni i relativni broj bodova.
Napomena: Svaki redak datoteke sadrži ime i prezime studenta, te broj bodova na kolokviju.
relatvan_br_bodova = br_bodova/max_br_bodova*100
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_ERROR_OPEN -1
#define EXIT_SUCCESS 0
#define MAX_SIZE 50
#define max_br_bodova 120

typedef struct _student {
    char name[MAX_SIZE];
    char surname[MAX_SIZE];
    double score;
} Student;

int ReadNORowsInFile() {
    int counter = 0;
    FILE* filePointer = fopen("students.txt", "r");

    if (!filePointer) {
        printf("File is not open! Please check if 'students.txt' exists in the current directory.\n");
        return FILE_ERROR_OPEN;
    }

    while (fscanf(filePointer, "%s %s %lf", buffer, buffer, &buffer) == 3) {
        counter++;
    }

    fclose(filePointer);

    return counter;
}

int EnterStudents(int number, Student* s) {
    FILE* f = fopen("students.txt", "r");
    if (f == NULL) {
        printf("Failed in file opening!\n");
        return FILE_ERROR_OPEN;
    }

    for (int i = 0; i < number; i++) {
        fscanf(f, "%s %s %lf", (s + i)->name, (s + i)->surname, &(s + i)->score);
    }

    fclose(f);
    return EXIT_SUCCESS;
}

int PrintStudents(int number, Student* s) {
    for (int i = 0; i < number; i++) {
        double relativeScore;
        if ((s + i)->score >= max_br_bodova) {
            relativeScore = 100.0; // Maximum score
        }
        else {
            relativeScore = ((s + i)->score / max_br_bodova) * 100;
        }

        printf("Student: %s %s\nAbsolute score: %.2lf\nRelative score: %.2lf%%\n",
            (s + i)->name, (s + i)->surname, (s + i)->score, relativeScore);
    }
    return EXIT_SUCCESS;
}

int main() {
    int m = 0;
    Student* st = NULL;
    int result = ReadNORowsInFile();

    if (result == FILE_ERROR_OPEN) {
        return EXIT_FAILURE;
    }

    if (result <= 0) {
        printf("No students found in the file.\n");
        return EXIT_SUCCESS;
    }

    st = (Student*)malloc(result * sizeof(Student));
    if (st == NULL) {
        printf("Failed in dynamic allocation!\n");
        return EXIT_FAILURE;
    }

    m = EnterStudents(result, st);

    if (m != EXIT_SUCCESS) {
        return FILE_ERROR_OPEN;
    }

    PrintStudents(result, st);
    free(st);

    return EXIT_SUCCESS;
}

