#include <iostream>
#include "Array.hpp"

int main() {
    Array arr;
    int choice, x, index;

    while (true) {
        std::cout << "\n--- MENU ---\n";
        std::cout << "1. Display\n2. Append\n3. Insert\n4. Delete\n5. Linear Search\n";
        std::cout << "6. Binary Search\n7. Max\n8. Min\n9. Sum\n10. Average\n11. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                arr.display();
                break;
            case 2:
                std::cout << "Enter element to append: ";
                std::cin >> x;
                arr.append(x);
                break;
            case 3:
                std::cout << "Enter index and value: ";
                std::cin >> index >> x;
                if (!arr.insert(index, x))
                    std::cout << "Invalid index\n";
                break;
            case 4:
                std::cout << "Enter index to delete: ";
                std::cin >> index;
                x = arr.remove(index);
                if (x == INT_MIN)
                    std::cout << "Invalid index\n";
                else
                    std::cout << "Deleted: " << x << "\n";
                break;
            case 5:
                std::cout << "Enter key to search: ";
                std::cin >> x;
                index = arr.linear_search(x);
                std::cout << (index != -1 ? "Found at index " + std::to_string(index) : "Not found") << "\n";
                break;
            case 6:
                std::cout << "Enter key for binary search: ";
                std::cin >> x;
                index = arr.binary_search(x);
                std::cout << (index != -1 ? "Found at index " + std::to_string(index) : "Not found or not sorted") << "\n";
                break;
            case 7:
                std::cout << "Max element: " << arr.get_max() << "\n";
                break;
            case 8:
                std::cout << "Min element: " << arr.get_min() << "\n";
                break;
            case 9:
                std::cout << "Sum: " << arr.sum() << "\n";
                break;
            case 10:
                std::cout << "Average: " << arr.average() << "\n";
                break;
            case 11:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice\n";
        }
    }

    return 0;
}