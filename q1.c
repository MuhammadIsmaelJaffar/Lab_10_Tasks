#include <stdio.h>
int main()
{
    FILE *fptr;
    int itemNo,qty;
    int id,stock;
    char name[25];
    float price,lineTotal,totalBill = 0;
    fptr = fopen("items.txt", "wb");
    if (fptr == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    fprintf(fptr, "%-4d %-20s %9.2f %5d\n", 1, "Rice", 250.00, 40);
    fprintf(fptr, "%-4d %-20s %9.2f %5d\n", 2, "Sugar", 160.00, 25);
    fprintf(fptr, "%-4d %-20s %9.2f %5d\n", 3, "Milk", 220.00, 30);
    fprintf(fptr, "%-4d %-20s %9.2f %5d\n", 4, "CookingOil", 560.00, 12);
    fprintf(fptr, "%-4d %-20s %9.2f %5d\n", 5, "Tea", 450.00, 18);
    fclose(fptr);
    fptr = fopen("items.txt", "rb+");
    if (fptr == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    while (1)
    {
        printf("Item no: ");
        scanf("%d", &itemNo);
        if (itemNo ==0)
        {
            break;
        }
        printf("Quantity: ");
        scanf("%d", &qty);

        if (itemNo <1 || itemNo >5)
        {
            printf("Invalid item number\n");
            continue;
        }
        fseek(fptr, (itemNo - 1) * 42, SEEK_SET);
        fscanf(fptr, "%d %s %f %d", &id, name, &price, &stock);
        if (stock >= qty)
        {
            lineTotal = qty * price;
            totalBill = totalBill + lineTotal;
            printf("%s %d x %f = %f\n", name, qty, price, lineTotal);

            stock = stock - qty;
            fseek(fptr, (itemNo - 1) * 42, SEEK_SET);
            fprintf(fptr, "%-4d %-20s %9.2f %5d\n", id, name, price, stock);
            fflush(fptr);
        }
        else
        {
            printf("Only %d %s in stock\n", stock, name);
        }
    }
    printf("Total bill: %f\n", totalBill);
    fclose(fptr);

    return 0;
}