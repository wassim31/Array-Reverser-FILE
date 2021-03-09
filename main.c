#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    // enter the number of elements
    do
    {
        scanf("%d", &num);

    } while(num > 21);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }
    FILE* tmpf = tmpfile();

    int n = num-1;
    printf("before : ");
    for(i = 0 ; i < num ; i++, n--)
    {
        fprintf(tmpf,"%d ", arr[n]);
        printf("%d ", arr[i]);
    }
    rewind(tmpf);
    printf("\nafter : ");
    for(i = 0 ; i < num ; i++)
    {
            fscanf(tmpf,"%d", &arr[i]);
            printf("%d ", arr[i]);
    }
    fclose(tmpf);
    free(arr);
    return 0;
}
