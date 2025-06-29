#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "array.h"

int main() {
    Array arr;
    if (!array_init(&arr)) {
        fprintf(stderr, "Failed to initialize array.\n");
        return EXIT_FAILURE;
    }

    int choice, x, index;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Display\n2. Append\n3. Insert\n4. Delete\n5. Linear Search\n");
        printf("6. Binary Search (array must be sorted)\n7. Max\n8. Min\n9. Sum\n10. Average\n11. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input.\n");
            while(getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                array_display(&arr);
                break;
            case 2:
                printf("Enter element to append: ");
                if (scanf("%d", &x) != 1) {
                    printf("Invalid input.\n");
                    while(getchar() != '\n');
                    break;
                }
                if (!array_append(&arr, x))
                    printf("Failed to append element\n");
                break;
            case 3:
                printf("Enter index and value: ");
                if (scanf("%d%d", &index, &x) != 2) {
                    printf("Invalid input.\n");
                    while(getchar() != '\n');
                    break;
                }
                if (!array_insert(&arr, index, x))
                    printf("Invalid index\n");
                break;
            case 4:
                printf("Enter index to delete: ");
                if (scanf("%d", &index) != 1) {
                    printf("Invalid input.\n");
                    while(getchar() != '\n');
                    break;
                }
                int deleted = array_delete(&arr, index);
                if (deleted == INT_MIN)
                    printf("Invalid index.\n");
                else
                    printf("Deleted element: %d\n", deleted);
                break;
            case 5:
                printf("Enter key to search: ");
                if (scanf("%d", &x) != 1) {
                    printf("Invalid input.\n");
                    while(getchar() != '\n');
                    break;
                }
                index = array_linear_search(&arr, x);
                if (index != -1)
                    printf("Found at index %d\n", index);
                else
                    printf("Not found\n");
                break;
            case 6:
                printf("Enter key for binary search: ");
                if (scanf("%d", &x) != 1) {
                    printf("Invalid input.\n");
                    while(getchar() != '\n');
                    break;
                }
                index = array_binary_search(&arr, x);
                if (index != -1)
                    printf("Found at index %d\n", index);
                else
                    printf("Not found or array not sorted\n");
                break;
            case 7:
                printf("Max element: %d\n", array_get_max(&arr));
                break;
            case 8:
                printf("Min element: %d\n", array_get_min(&arr));
                break;
            case 9:
                printf("Sum: %lld\n", array_sum(&arr));
                break;
            case 10:
                printf("Average: %.2f\n", array_average(&arr));
                break;
            case 11:
                array_free(&arr);
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}