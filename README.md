# Programming of Data Structures and Fundamental Algorithms

## Table of contents:

- [Time Complexity](#com)
- [Search Algorithms](#se-a)
- [Sort Algorithms](#so-a)
- [Data Structures](#d-s)

<!--------------------------Time Complexity------------------------->

<a id="com"></a>

## Time Complexity

<a href = "https://www.quora.com/Whats-an-example-of-an-algorithm-that-is-O-n-log-n-in-time-complexity">`Big O notation`</a> - _How code slows as data grows_

<img src="https://miro.medium.com/v2/resize:fit:1400/1*5ZLci3SuR0zM_QlZOADv8Q.jpeg" alt="drawing" width="400"/>

<blockquote>

<b>O(1) = constant time</b>

- Random access of an element in an array
- Inserting at the beginning of linkedlist

```js
function PrintFirstElement(arr):
    firstElement = arr[0]
    print(firstElement)

```

</blockquote>

<blockquote>

<b>O(log n) = logarithmic time</b>

- Binary search

```js
function findPowerOfTwo(n):
    power = 0
    while n > 1:
        n = n / 2
        power = power + 1
    return power
```

</blockquote>

<blockquote>

<b>O(n) = linear time</b>

- Looping through elements in an array
- Searching through a linkedlist

```js
function linearSearch(arr, target):
    for i from 0 to length(arr) - 1:
        if arr[i] == target:
            return i
    return -1
```

</blockquote>

<blockquote>

<b>O(n log n) = quasilinear time</b>

- Quicksort
- Mergesort
- Heapsort

```js
function nlogn(n):
    x = n
    while ( x > 0 ) {
        y = x
        while ( y > 0 ) {
            y = y / 2
        }
        x = x - 1
    }
```

</blockquote>

<blockquote>

<b>O(n^2) = quadratic time</b>

- Insertion sort
- Selection sort
- Bubblesort

```js
function n2(n):
    for i in range(n):
        for j in range(n):
            print("Hello")
```

</blockquote>

<!--------------------------Search Algorithms------------------------->

<a id="se-a"></a>

## Search Algorithms

<blockquote>

<b>Binary Search</b>

![Alt text](images/bin.gif)

```js
BinarySearch(arr, target):
    left = 0
    right = length(arr) - 1

    while left <= right:
        mid = (left + right) // 2  // Calculate the middle index

        if arr[mid] == target:
            return mid  // Found the target, return its index
        elif arr[mid] < target:
            left = mid + 1  // Target is in the right half
        else:
            right = mid - 1  // Target is in the left half

    return -1  // Target not found in the array
```

</blockquote>

<blockquote>

<b>Sequential Search</b>

![Alt text](images/seq.gif)

```js
SequentialSearch(arr, target):
    for i from 0 to length(arr) - 1:
        if arr[i] == target:
            return i  // Found the target, return its index

    return -1  // Target not found in the array
```

</blockquote>

<!--------------------------Sort Algorithms----------------------- -->

<a id="so-a"></a>

## Sort Algorithms

<blockquote>

<b>Insertion Sort</b>

<img src="https://miro.medium.com/v2/resize:fit:600/1*bmfRxyIQZEK0Iu5T6YV1sw.gif" alt="drawing" width="300"/>

```js
InsertionSort(arr):
    for i from 1 to length(arr) - 1: //start in second element (index 1)
        key = arr[i]
        j = i - 1

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j] //Swap [j+1] and [j]
            j = j - 1

        // Place the key in its correct position
        arr[j + 1] = key

```

</blockquote>

<blockquote>

<b>Selection Sort</b>

<img src="https://miro.medium.com/v2/resize:fit:720/1*5WXRN62ddiM_Gcf4GDdCZg.gif" alt="drawing" width="300"/>

```js
SelectionSort(arr):
    n = length(arr)
    for i from 0 to n - 1:
        // Find the index of the minimum element in the unsorted part of the array
        minIndex = i
        for j from i + 1 to n - 1:
            if arr[j] < arr[minIndex]:
                minIndex = j

        // Swap the minimum element with the first element in the unsorted part
        if minIndex != i:
            swap(arr[i], arr[minIndex])
```

</blockquote>

<blockquote>

<b>Bubble Sort</b>

<img src="https://upload.wikimedia.org/wikipedia/commons/0/06/Bubble-sort.gif" alt="drawing" width="300"/>

```js
BubbleSort(arr):
    n = length(arr)
    for i from 0 to n - 1:
        swapped = false
        for j from 0 to n - i - 1:
            // If the current element is greater than the next element, swap them
            if arr[j] > arr[j + 1]:
                swap(arr[j], arr[j + 1])
                swapped = true

        // If no two elements were swapped in inner loop, the array is already sorted
        if swapped == false:
            break

```

</blockquote>

<blockquote>

<b>Quick Sort</b>

https://github.com/Jose-AE/Jose-AE/assets/107892696/2cfb8321-5fb8-40bb-952c-ea62b28e924d

```js
QuickSort(arr, low, high):
    if low < high:
        //Find where pivot should be and swap it into that index and return that new index
        pivotIndex = Partition(arr, low, high)

        // Recursively sort the sub-arrays
        QuickSort(arr, low, pivotIndex - 1)
        QuickSort(arr, pivotIndex + 1, high)

Partition(arr, low, high):
    // Choose the rightmost element as the pivot
    pivot = arr[high]

    // Index of the smaller element
    i = low - 1

    for j from low to high - 1:
        // If the current element is smaller than or equal to the pivot
        if arr[j] <= pivot:
            // Swap arr[i] and arr[j]
            i = i + 1
            swap(arr[i], arr[j])

    // Swap arr[i+1] and arr[high] (put the pivot in its correct position)
    swap(arr[i + 1], arr[high])

    return i + 1
```

</blockquote>

<blockquote>

<b>Merge Sort</b>

https://github.com/Jose-AE/Jose-AE/assets/107892696/92e3959f-7cdf-4c9c-adac-0a74e9453ee4

```js
MergeSort(arr):
    if length(arr) <= 1:
        return arr

    // Split the array into two halves
    middle = length(arr) / 2
    left = arr[0 to middle - 1]
    right = arr[middle to end]

    // Recursively sort each half
    left = MergeSort(left)
    right = MergeSort(right)

    // Merge the sorted halves
    mergedArr = Merge(left, right)

    return mergedArr

Merge(left, right):
    result = []
    leftIndex = 0
    rightIndex = 0

    // Compare elements from the left and right sub-arrays and merge them
    while leftIndex < length(left) and rightIndex < length(right):
        if left[leftIndex] < right[rightIndex]:
            result.append(left[leftIndex])
            leftIndex = leftIndex + 1
        else:
            result.append(right[rightIndex])
            rightIndex = rightIndex + 1

    // Add any remaining elements from the left and right sub-arrays
    while leftIndex < length(left):
        result.append(left[leftIndex])
        leftIndex = leftIndex + 1

    while rightIndex < length(right):
        result.append(right[rightIndex])
        rightIndex = rightIndex + 1

    return result
```

</blockquote>

<!--------------------------Data structures------------------------->

<a id="d-s"></a>

## Data Structures

<blockquote>

<b>Singly Linked List</b>

<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/20200922124319/Singly-Linked-List1.png" alt="drawing" width="500"/>

```
Class Node:
    Initialize:
        data: value to store
        next: reference to the next node (initialized to None)

Class LinkedList:
    Initialize:
        head: reference to the first node in the list (initialized to None)

    Method add(value):
        Create a new node with the given value
        Set the new node's next to the current head
        Set head to the new node

```

</blockquote>

<blockquote>

<b>Doubly Linked List</b>

<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/20200922124412/Doubly-Linked-List.png" alt="drawing" width="500"/>

```
Class Node:
    Initialize:
        data: value to store
        next: reference to the next node (initialized to None)
        prev: reference to the previous node (initialized to None)

Class DoublyLinkedList:
    Initialize:
        head: reference to the first node in the list (initialized to None)
        tail: reference to the last node in the list (initialized to None)

    Method add(value):
        Create a new node with the given value
        If the list is empty (head is None):
            Set head and tail to the new node
        Else:
            Set the new node's next to the current head
            Set the current head's prev to the new node
            Set head to the new node
```

</blockquote>

<blockquote>

<b>Circular Linked List</b>

<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/20200922124456/Circular-Linked-List.png" alt="drawing" width="500"/>

```
Class Node:
    Initialize:
        data: value to store
        next: reference to the next node (initialized to None)

Class CircularLinkedList:
    Initialize:
        head: reference to the first node in the list (initialized to None)

    Method add(value):
        Create a new node with the given value
        If head is None:
            Set the new node's next to itself (circular reference)
            Set head to the new node
        Else:
            Set the new node's next to the current head
            Update the last node's next to the new node
            Set head to the new node
```

</blockquote>

<blockquote>

<b>Stack</b>

<img src="https://i.imgur.com/ZcvWIMk.png" alt="drawing" width="300"/>

```
Class Stack:
    Initialize an empty list to store stack elements

    Method push(item):
        # Add an item to the top of the stack
        Append item to the end of the list

    Method pop():
        # Remove and return the item from the top of the stack
        If the list is empty:
            Raise an error (e.g., "Stack is empty")
        Else:
            Remove and return the last item from the list

```

</blockquote>

<blockquote>

<b>Queue</b>

<img src="https://i.imgur.com/HBgRzgz.png" alt="drawing" width="400"/>

```
Class Queue:
    Initialize an empty list to store queue elements
    Initialize two pointers: front and rear

    Method enqueue(item):
        # Add an item to the rear of the queue
        Append item to the end of the list
        Update rear pointer to the last element

    Method dequeue():
        # Remove and return the item from the front of the queue
        If the list is empty:
            Raise an error (e.g., "Queue is empty")
        Else:
            Remove and return the first item from the list
            Update front pointer to the new front element
```

</blockquote>


<blockquote>

<b>Deque</b>

<img src="https://learnersbucket.com/wp-content/uploads/2019/08/Deque-Data-Structure-1.png" alt="drawing" width="400"/>

```
class Deque:
    // Initialize an empty deque
    function Deque():
        create an empty list or array

    // Add an element to the front of the deque
    function addFront(item):
        insert item at the beginning of the deque

    // Add an element to the back of the deque
    function addBack(item):
        insert item at the end of the deque

    // Remove and return the element from the front of the deque
    function removeFront():
        if not isEmpty():
            remove and return the first element of the deque
        else:
            raise an exception or return an error

    // Remove and return the element from the back of the deque
    function removeBack():
        if not isEmpty():
            remove and return the last element of the deque
        else:
            raise an exception or return an error
```

</blockquote>