How to read data:

There are 2 types of implementaitons:
1) Reading lines from a file
2) Reading the input given by the user through STDIN
This can be selected by using the macro READ_FILE defined in the driver program (check_count.c).

If you are reading from a file, then the program will read all the lines from the file specified in the main() function, update their counts and print the output towards the end.
If you are reading from STDIN, then every time you read a line, it will update its count and print the output to STDOUT.

Data structure used:

I am storing all the strings(lines read) in a hashmap, which is the array arr. The size of the array is 27; first 26 locations for each alphabet and the 27th for all other characters. The hashing function is such that it adds the string to the array according to its first character. Also, each location of the array actually stores a pointer to the root of a Binary Search Tree. So, each tree contains all strings starting from the same alphabet and stored in a sorted order.

If just a single BST was maintained, then the insertion and search time complexity would be O(log n), where n is the total number of lines read. For large data sets, this increases the time complexity. So, to reduce it, separate trees are maintained for each alphabet. Thus, now the time complexity is reduced to O(log k) where k is the number of strings(lines) present in the tree of that particular alphabet. More levels of indirection can be added to reduce the time complexity even further.
