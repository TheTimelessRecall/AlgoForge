# ArrayADT (C Project)



A dynamic, menu-driven implementation of the \*\*Array Abstract Data Type (ADT)\*\* written in C.  

This project covers essential array operations with memory management, modular code structure, and full unit testing



---



## Directory Structure



```

arrayadt/

├── include/

│   └── array.h        

├── src/

│   └── array.c         

├── tests/

│   └── test\_array.c     

├── main.c               

└── README.md            

```



---



## Build \& Run



### Run Tests



```bash

gcc -Wall -Wextra -Iinclude -o tests/test\_array tests/test\_array.c src/array.c

./tests/test\_array        # Linux/macOS

tests\\test\_array.exe     # Windows CMD

```



### Run the Menu Program



```bash

gcc -Wall -Wextra -Iinclude -o main main.c src/array.c

./main                    # Linux/macOS

main.exe                  # Windows CMD

```



---



## Sample Test Output



```

All tests passed!

```



---



## Menu Options



```

--- MENU ---

1\. Display

2\. Append

3\. Insert

4\. Delete

5\. Linear Search

6\. Binary Search (array must be sorted)

7\. Max

8\. Min

9\. Sum

10\. Average

11\. Exit

```



---



## License



MIT License — free to use, modify, and share.  



---



## Author



**TimelessRecall** 

• [GitHub](https://github.com/TheTimelessRecall) • [Medium](https://medium.com/@TimelessRecall) •  [Twitter](https://x.com/TimelessRecall)

