#include <stdio.h>
#include <stdlib.h>

/* Structure Definition */
struct Student {
    int id;
    char name[50];
    float marks;
};

/* Function Declarations */
void writefile(int n);
void displayMthRecord(int m);
void deleteRecord(int del_id);

int main() {
    int n, m, choice, del_id;

    printf("Enter number of records: ");
    scanf("%d", &n);

    writefile(n);

    printf("\nEnter which record (m) to display: ");
    scanf("%d", &m);
    printf("the mth record is:");
    displayMthRecord(m);

    printf("\nEnter ID of record to delete: ");
    scanf("%d", &del_id);
    deleteRecord(del_id);

    printf("\nAfter deletion, records are:\n");

    FILE *fp;
    struct Student s;

    fp = fopen("stu.dat", "rb");

    while (fread(&s, sizeof(s), 1, fp)) {
        printf("ID: %d, Name: %s, Marks: %.2f\n", s.id, s.name, s.marks);
    }

    fclose(fp);

    return 0;
}

void writefile(int n){
    FILE *fp;
    struct Student s;
    fp=fopen("stu.dat","wb");

    for(int i=0;i<n;i++){
        printf("enter the id of the dtudent:");
        scanf("%d",&s.id);

        printf("enter the name of the student:");
        scanf("%s",s.name);

        printf("enter the marks of the student:");
        scanf("%f",&s.marks);

        fwrite(&s, sizeof(s), 1, fp);

    }
    fclose(fp);

}
void displayMthRecord(int m) {
    FILE *fp;
    struct Student s;

    fp = fopen("stu.dat", "rb");

    fseek(fp, (m - 1) * sizeof(s), SEEK_SET);

    if (fread(&s, sizeof(s), 1, fp)) {
        printf("\nM-th Record:\n");
        printf("ID: %d, Name: %s, Marks: %.2f\n", s.id, s.name, s.marks);
    } else {
        printf("\nRecord not found!\n");
    }

    fclose(fp);
}
void deleteRecord(int del_id) {
    FILE *fp, *temp;
    struct Student s;

    fp = fopen("stu.dat", "rb");
    temp = fopen("temp.dat", "wb");

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id != del_id) {
            fwrite(&s, sizeof(s), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("stu.dat");
    rename("temp.dat", "stu.dat");
}