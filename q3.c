#include <stdio.h>
int main()
{
    FILE *fptr;
    int i, cityNo, correctNo;
    char city[20], hottestCity[20];
    float temp, newTemp, maxTemp;

    fptr = fopen("temperature.txt", "wb");
    if (fptr == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    for (i = 0; i < 5; i++)
    {
        printf("City name: ");
        scanf("%s", city);
        printf("Temperature: ");
        scanf("%f", &temp);
        fprintf(fptr, "%-10s %5.1f\n", city, temp);
    }
    fclose(fptr);

    fptr = fopen("temperature.txt", "rb+");
    if (fptr == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    printf("City number: ");
    scanf("%d", &cityNo);
    fseek(fptr, (cityNo - 1) * 17, SEEK_SET);
    fscanf(fptr, "%s %f", city, &temp);
    printf("%s %.1f\n", city, temp);

    printf("City number to correct: ");
    scanf("%d", &correctNo);
    printf("New temperature: ");
    scanf("%f", &newTemp);
    fseek(fptr, (correctNo - 1) * 17, SEEK_SET);
    fscanf(fptr, "%s %f", city, &temp);
    fseek(fptr, (correctNo - 1) * 17, SEEK_SET);
    fprintf(fptr, "%-10s %5.1f\n", city, newTemp);
    fflush(fptr);
    printf("%s updated to %.1f\n", city, newTemp);

    rewind(fptr);
    if (fscanf(fptr, "%s %f", city, &temp) == 2)
    {
        maxTemp = temp;
        for (i = 0; city[i] != '\0'; i++)
        {
            hottestCity[i] = city[i];
        }
        hottestCity[i] = '\0';
        while (fscanf(fptr, "%s %f", city, &temp) == 2)
        {
            if (temp > maxTemp)
            {
                maxTemp = temp;
                for (i = 0; city[i] != '\0'; i++)
                {
                    hottestCity[i] = city[i];
                }
                hottestCity[i] = '\0';
            }
        }
        printf("Hottest city: %s (%.1f)\n", hottestCity, maxTemp);
    }

    fclose(fptr);

    return 0;
}