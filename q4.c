#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fptr;
    int i, roomNo, nights;
    char status, guestName[21], searchName[21];
    float rate = 8000;
    int rooms[10];
    char guests[10][21];
    char fStatus;
    int fNights;
    float fRate;

    fptr = fopen("hotel.txt", "wb");
    if (fptr == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    for (i = 0; i < 10; i++)
    {
        fprintf(fptr, "%3d %c %-20s %2d %8.2f\n", 101 + i, 'F', "-", 0, rate);
    }
    fclose(fptr);

    fptr = fopen("hotel.txt", "rb+");
    if (fptr == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    printf("Check-in room: ");
    scanf("%d", &roomNo);
    printf("Name: ");
    scanf("%s", guestName);
    printf("Nights: ");
    scanf("%d", &nights);
    fseek(fptr, (roomNo - 101) * 39, SEEK_SET);
    fscanf(fptr, "%d %c %s %d %f", &rooms[0], &status, guests[0], &fNights, &fRate);
    if (status == 'F')
    {
        fseek(fptr, (roomNo - 101) * 39, SEEK_SET);
        fprintf(fptr, "%3d %c %-20s %2d %8.2f\n", roomNo, 'B', guestName, nights, rate);
        fflush(fptr);
        printf("Room %d booked\n", roomNo);
    }
    else
    {
        printf("Room already booked\n");
    }
    printf("Check-in room: ");
    scanf("%d", &roomNo);
    printf("Name: ");
    scanf("%s", guestName);
    printf("Nights: ");
    scanf("%d", &nights);
    fseek(fptr, (roomNo - 101) * 39, SEEK_SET);
    fscanf(fptr, "%d %c %s %d %f", &rooms[0], &status, guests[0], &fNights, &fRate);
    if (status == 'F')
    {
        fseek(fptr, (roomNo - 101) * 39, SEEK_SET);
        fprintf(fptr, "%3d %c %-20s %2d %8.2f\n", roomNo, 'B', guestName, nights, rate);
        fflush(fptr);
        printf("Room %d booked\n", roomNo);
    }
    else
    {
        printf("Room already booked\n");
    }
    rewind(fptr);
    for (i = 0; i < 10; i++)
    {
        fscanf(fptr, "%d %c %s %d %f", &rooms[i], &fStatus, guests[i], &fNights, &fRate);
    }
    printf("Search name: ");
    scanf("%s", searchName);
    for (i = 0; i < 10; i++)
    {
        if (strcmp(guests[i], searchName) == 0)
        {
            printf("%s is in room %d\n", searchName, rooms[i]);
            break;
        }
    }

    printf("Check-out room: ");
    scanf("%d", &roomNo);
    fseek(fptr, (roomNo - 101) * 39, SEEK_SET);
    fscanf(fptr, "%d %c %s %d %f", &rooms[0], &status, guests[0], &fNights, &fRate);
    printf("Bill: %d x %.2f = %.2f\n", fNights, fRate, fNights * fRate);
    fseek(fptr, (roomNo - 101) * 39, SEEK_SET);
    fprintf(fptr, "%3d %c %-20s %2d %8.2f\n", roomNo, 'F', "-", 0, fRate);
    fflush(fptr);

    fclose(fptr);
    return 0;
}