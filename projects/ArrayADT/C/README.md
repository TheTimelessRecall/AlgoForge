# ArrayADT (C Project)



A dynamic, menu-driven implementation of the **Array Abstract Data Type (ADT)** written in C.  

This project covers essential array operations with memory management, modular code structure, and full unit testing



---



## Directory Structure



```

ArrayADT/

├── include/

│   └── array.h        

├── src/

│   └── array.c 
    └── main.c          

├── tests/

│   └── test\_array.c                  

└── README.md            

```


---



## Build & Run



### Run Tests



```bash

gcc -Wall -Wextra -Iinclude -o tests/test_array tests/test_array.c src/array.c

./tests/test_array        # Linux/macOS

tests\test_array.exe      # Windows CMD

```



### Run the Menu Program



```bash

gcc -Wall -Wextra -Iinclude -o main src/main.c src/array.c

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

1. Display

2. Append

3. Insert

4. Delete

5. Linear Search

6. Binary Search (array must be sorted)

7. Max

8. Min

9. Sum

10. Average

11. Exit

```



---




<p align="center">
  <strong>TimelessRecall</strong><br>
  <br>
  <a href="https://github.com/TheTimelessRecall" target="_blank">
    <img src="https://img.shields.io/badge/GitHub-000000?style=for-the-badge&logo=github&logoColor=white" alt="GitHub" />
  </a>
  <a href="https://medium.com/@TimelessRecall" target="_blank">
    <img src="https://img.shields.io/badge/Medium-000000?style=for-the-badge&logo=medium&logoColor=white" alt="Medium" />
  </a>
  <a href="https://x.com/TimelessRecall" target="_blank">
    <img src="https://img.shields.io/badge/Twitter-1DA1F2?style=for-the-badge&logo=twitter&logoColor=white" alt="Twitter" />
  </a>
</p>


