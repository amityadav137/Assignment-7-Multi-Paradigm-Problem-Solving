#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

double mean(int arr[], int n) {
    long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double)sum / n;
}

double median(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);
    if (n % 2 == 0) {
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    } else {
        return arr[n/2];
    }
}

void mode(int arr[], int n, int **modes, int *mode_count) {
    qsort(arr, n, sizeof(int), compare);
    int max_count = 0;
    int current = arr[0], count = 1;
    *mode_count = 0;
    *modes = malloc(n * sizeof(int));
    for (int i = 1; i < n; i++) {
        if (arr[i] == current) {
            count++;
        } else {
            if (count > max_count) {
                max_count = count;
                *mode_count = 0;
                (*modes)[(*mode_count)++] = current;
            } else if (count == max_count) {
                (*modes)[(*mode_count)++] = current;
            }
            current = arr[i];
            count = 1;
        }
    }
    // handle last run
    if (count > max_count) {
        max_count = count;
        *mode_count = 0;
        (*modes)[(*mode_count)++] = current;
    } else if (count == max_count) {
        (*modes)[(*mode_count)++] = current;
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }
    int *arr = malloc(n * sizeof(int));
    if (!arr) return 1;
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    double m = mean(arr, n);
    double med = median(arr, n);
    int *modes;
    int mode_count;
    mode(arr, n, &modes, &mode_count);

    printf("Mean: %.2f\n", m);
    printf("Median: %.2f\n", med);
    printf("Mode: ");
    for (int i = 0; i < mode_count; i++) {
        printf("%d ", modes[i]);
    }
    printf("\n");

    free(arr);
    free(modes);
    return 0;
}
