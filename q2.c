#include <stdio.h>
int main()
{
    FILE *fptr;
    int rollNo,leaveRollNo,leaveLectures;
    int roll, attended;
    char name[20];
    float percentage;

    fptr = fopen("attendance.txt", "wb");
    if (fptr == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    fprintf(fptr, "%-3d %-15s %3d\n", 1, "Ayesha", 18);
    fprintf(fptr, "%-3d %-15s %3d\n", 2, "Bilal", 14);
    fprintf(fptr, "%-3d %-15s %3d\n", 3, "Hamza", 20);
    fprintf(fptr, "%-3d %-15s %3d\n", 4, "Sana", 12);
    fprintf(fptr, "%-3d %-15s %3d\n", 5, "Zainab", 16);
    fclose(fptr);

    fptr = fopen("attendance.txt", "rb+");
    if (fptr == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    printf("Roll number: ");
    scanf("%d", &rollNo);
    fseek(fptr, (rollNo - 1) * 24, SEEK_SET);
    fscanf(fptr, "%d %s %d", &roll, name, &attended);
    percentage = (attended / 20.0) * 100;
    if (percentage < 75.0)
    {
        printf("%s: %d / 20 (%.1f%%) Short attendance\n", name, attended, percentage);
    }
    else
    {
        printf("%s: %d / 20 (%.1f%%)\n", name, attended, percentage);
    }
    printf("Roll number for leave: ");
    scanf("%d", &leaveRollNo);
    printf("Lectures: ");
    scanf("%d", &leaveLectures);
    fseek(fptr, (leaveRollNo - 1) * 24, SEEK_SET);
    fscanf(fptr, "%d %s %d", &roll, name, &attended);
    attended = attended + leaveLectures;
    fseek(fptr, (leaveRollNo - 1) * 24, SEEK_SET);
    fprintf(fptr, "%-3d %-15s %3d\n", roll, name, attended);
    fflush(fptr);
    percentage = (attended / 20.0) * 100;
    printf("%s: now %d / 20 (%.1f%%)\n", name, attended, percentage);
    fseek(fptr, -24, SEEK_END);
    fscanf(fptr, "%d %s %d", &roll, name, &attended);
    printf("Last record: %d %s %d\n", roll, name, attended);

    fclose(fptr);

    return 0;
}