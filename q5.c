#include <stdio.h>
int main()
{
    FILE *fptr;
    int i, entryNo;
    char newCat[20], cat[20];
    float newAmt, amt, total = 0;
    int pos;

    fptr = fopen("expenses.txt", "wb");
    if (fptr == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    fprintf(fptr, "%-12s %9.2f\n", "Food", 1200.00);
    fprintf(fptr, "%-12s %9.2f\n", "Transport", 500.00);
    fprintf(fptr, "%-12s %9.2f\n", "Books", 850.00);
    fprintf(fptr, "%-12s %9.2f\n", "Mobile", 300.00);
    fclose(fptr);

    printf("Category: ");
    scanf("%s", newCat);
    printf("Amount: ");
    scanf("%f", &newAmt);

    fptr = fopen("expenses.txt", "ab");
    if (fptr == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    fprintf(fptr, "%-12s %9.2f\n", newCat, newAmt);
    fclose(fptr);

    fptr = fopen("expenses.txt", "rb+");
    if (fptr == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    fseek(fptr, -2 * 23, SEEK_END);
    printf("Latest two: ");
    fscanf(fptr, "%s %f", cat, &amt);
    printf("%s %.2f, ", cat, amt);
    fscanf(fptr, "%s %f", cat, &amt);
    printf("%s %.2f\n", cat, amt);

    printf("Entry to fix: ");
    scanf("%d", &entryNo);
    printf("Correct amount: ");
    scanf("%f", &newAmt);

    pos = (entryNo - 1) * 23;
    fseek(fptr, pos, SEEK_SET);
    fscanf(fptr, "%s %f", cat, &amt);
    fseek(fptr, pos, SEEK_SET);
    fprintf(fptr, "%-12s %9.2f\n", cat, newAmt);
    fflush(fptr);
    rewind(fptr);
    while (fscanf(fptr, "%s %f", cat, &amt) == 2)
    {
        printf("%s %.2f\n", cat, amt);
        total = total + amt;
    }
    printf("Total: %.2f\n", total);

    fclose(fptr);

    return 0;
}