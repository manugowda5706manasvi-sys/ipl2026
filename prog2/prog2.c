#include <stdio.h>

struct Student {
    int id;
    char name[20];
    float marks;
};

void writeRecords(int n, long pos[]);
void displayRecord(int index, long pos[]);

int main() {
    int n, index;
    long pos[100];

    printf("Enter number of records: ");
    scanf("%d", &n);

    writeRecords(n, pos);

    printf("Enter index to display (0-based): ");
    scanf("%d", &index);

    displayRecord(index, pos);

    return 0;
}


void writeRecords(int n, long pos[]) {
    FILE *fp;
    struct Student s;
    int i;

    fp = fopen("data.txt", "w");

    for(i = 0; i < n; i++) {
        pos[i] = ftell(fp);   

        printf("Enter id name marks: ");
        scanf("%d %s %f", &s.id, s.name, &s.marks);

        fprintf(fp, "%d %s %.2f\n", s.id, s.name, s.marks);
    }

    fclose(fp);
}


void displayRecord(int index, long pos[]) {
    FILE *fp;
    struct Student s;

    fp = fopen("data.txt", "r");

    fseek(fp, pos[index], SEEK_SET);

    fscanf(fp, "%d %s %f", &s.id, s.name, &s.marks);

    printf("Record: %d %s %.2f\n", s.id, s.name, s.marks);

    fclose(fp);
}

