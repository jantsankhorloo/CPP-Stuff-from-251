# BinaryHeap

Input for n lines of the following format:
The character ‘c’ (for create) followed by an integer. If the integer value is ‘1’, create an empty maxheap. 
If the integer value is ‘2’ create an empty minheap.

The character ‘i’ (for insert) followed by 2 integers. Insert these two values into the heap as <key, value> pair.

The character ‘p’ (for peek). Call peek() and print the key and value of the 
returned element separated by a space. Print “empty” in case the heap is empty.

The character ‘e’ (for extract/delete). Call extract and print the key and value
separated by a space. Print “empty” in case the heap is empty.

The character ‘h’ (for heapify) followed by many integers separated by a space.

Consider the first integer as the size of the array, and the rest of the integers as
the keys for the elements. Consider the value as 0 for all the elements of the
heap. Here you can safely assume that the heap is empty when heapify is called.

The character ‘s’ (for size). Print the current size of the heap.


For the sorting part the following lines of the input file are as follows:

An integer that represents the order of the sorting. The value 1 represents that you have
to sort in increasing order. The value 2 represents decreasing order.

An integer n representing the number of elements that you have to sort.
n lines each containing two integers. First integer is the key and the second one is the
value.

The character ‘q’ represents that now you need to sort the elements and print the sorted
list. While printing the sorted list you will print each pair at each line. The key and value
will be separated by one space character.


Run the code:

program < inputtest1.txt > outputtest1.txt

or 

program < inputtest1.txt
