#include <iostream>
#include "Array.hpp"

using namespace std;

int main() {
    Array arr;
    int choice, x, index;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Display\n2. Append\n3. Insert\n4. Delete\n5. Linear Search\n";
        cout << "6. Binary Search\n7. Max\n8. Min\n9. Sum\n10. Average\n11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                arr.display();
                break;
            case 2:
                cout << "Enter element to append: ";
                cin >> x;
                arr.append(x);
                break;
            case 3:
                cout << "Enter index and value: ";
                cin >> index >> x;
                if (!arr.insert(index, x))
                    cout << "Invalid index\n";
                break;
            case 4:
                cout << "Enter index to delete: ";
                cin >> index;
                x = arr.remove(index);
                if (x == INT_MIN)
                    cout << "Invalid index\n";
                else
                    cout << "Deleted: " << x << "\n";
                break;
            case 5:
                cout << "Enter key to search: ";
                cin >> x;
                index = arr.linear_search(x);
                cout << (index != -1 ? "Found at index " + to_string(index) : "Not found") << "\n";
                break;
            case 6:
                cout << "Enter key for binary search: ";
                cin >> x;
                index = arr.binary_search(x);
                cout << (index != -1 ? "Found at index " + to_string(index) : "Not found or not sorted") << "\n";
                break;
            case 7:
                cout << "Max element: " << arr.get_max() << "\n";
                break;
            case 8:
                cout << "Min element: " << arr.get_min() << "\n";
                break;
            case 9:
                cout << "Sum: " << arr.sum() << "\n";
                break;
            case 10:
                cout << "Average: " << arr.average() << "\n";
                break;
            case 11:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}
