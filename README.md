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



<blockquote>

<b>Binary Search Tree</b>

<img src="https://i.imgur.com/epXOS13.png" alt="drawing" width="800"/>

A Binary Search Tree (BST) is a binary tree data structure that has the following properties:

**Binary Tree Structure:**

- Each node in a BST has at most two children: a left child and a right child.
- These children are themselves the roots of binary subtrees.


**Ordering Property:**
- For each node n, all nodes in its left subtree have values less than n's value.
- For each node n, all nodes in its right subtree have values greater than n's value.


This ordering property ensures that for any given node in the tree, all nodes in its left subtree are smaller, and all nodes in its right subtree are larger.


**Operations on Binary Search Trees:**


- **Search:**
To search for a key in the tree, you start at the root node and compare the key with the current node's key. If they match, you've found the key. If the key is smaller, you move to the left subtree; if it's larger, you move to the right subtree. This process continues until you find the key or reach a empty subtree, indicating that the key is not present.


- **Insertion:**
To insert a new key into the tree, you start at the root and compare the key to be inserted with the current node's key. If the key is smaller, you move to the left subtree; if it's larger, you move to the right subtree. This process is repeated until you find an empty subtree where you can insert the new node.

- **Deletion:**
Deleting a node from a BST involves three cases:
   - If the node has no children, simply remove it.
   - If the node has one child, you can replace the node with its child.
   - If the node has two children, you can either find the node's in-order predecessor (the largest node in its left subtree) or in-order successor (the smallest node in its right subtree), replace the node's key with the predecessor or successor key, and then delete the predecessor or successor.

        <img src="https://i.imgur.com/n2fg60O.png" alt="drawing" width="400"/>


</blockquote>






<blockquote>

<b> AVL Tree</b>

<img src="https://i.imgur.com/LGZ42Py.png" alt="drawing" width="800"/>

An AVL tree (named after its inventors Adelson-Velsky and Landis) is a self-balancing binary search tree. The balance is maintained by ensuring that the height difference between the left and right subtrees of any node (called the balance factor) is at most 1.


**Node Balance Factor:** 
It is the height of the right subtree minus the height of the left subtree. The balance factor can be -1, 0, or 1.

**Binary Search Tree Property:** The AVL tree must maintain the binary search tree property, where all nodes in the left subtree have keys less than the node's key, and all nodes in the right subtree have keys greater than the node's key.


To ensure that the tree remains balanced after insertions and deletions, rotations are performed. There are four possible rotations:

- **Left Rotation (LL Rotation):** This rotation is performed when the balance factor of a node becomes greater than 1. It involves a rightward rotation to restore balance.

    <img src="https://i.imgur.com/hdLDad8.png" alt="drawing" width="400"/>


- **Right Rotation (RR Rotation):** This rotation is performed when the balance factor of a node becomes less than -1. It involves a leftward rotation to restore balance.

    <img src="https://i.imgur.com/gqy4uyv.png" alt="drawing" width="400"/>

- **Left-Right Rotation (LR Rotation):** This is a combination of left and right rotations. It is performed when the balance factor of the left child of a node becomes less than 0, and the balance factor of the left child's right child is greater than or equal to 0.

    <img src="https://media.geeksforgeeks.org/wp-content/uploads/20221229131629/avl33-(1)-768.png" alt="drawing" width="400"/>

- **Right-Left Rotation (RL Rotation):** This is a combination of right and left rotations. It is performed when the balance factor of the right child of a node becomes greater than 0, and the balance factor of the right child's left child is less than or equal to 0.

    <img src="https://media.geeksforgeeks.org/wp-content/uploads/20221229131517/avl44-(1)-768.png" alt="drawing" width="400"/>

The idea behind these rotations is to maintain balance during insertions and deletions, ensuring that the height of the tree remains logarithmic. The AVL tree guarantees that the height of the tree is O(log n), where n is the number of nodes.




</blockquote>




<blockquote>

<b>Graph</b>

<img src="https://web.cecs.pdx.edu/~sheard/course/Cs163/Graphics/graph7.png" alt="drawing" width="400"/>

A graph is a versatile and widely used data structure that consists of a set of nodes (or vertices) and a set of edges connecting pairs of nodes. Graphs are used to model relationships and connections between various entities. The entities are represented by nodes, and the relationships between them are represented by edges.


**Nodes (Vertices):** Nodes are the fundamental units of a graph, representing entities or points in the graph. Each node can have additional information associated with it, known as attributes.

**Edges:** Edges are connections between pairs of nodes. An edge can be directed or undirected. In a directed graph, edges have a direction from one node to another, while in an undirected graph, edges have no direction and simply connect two nodes.

**Adjacency:** Two nodes are said to be adjacent if there is an edge connecting them. The set of neighbors of a node is the collection of nodes that are directly connected to it.


**Representations:**
 - **Adjacency Matrix:** A two-dimensional matrix where the rows and columns represent nodes, and the entries indicate whether there is an edge between the corresponding nodes.
    
    <img src="https://www.cs.mtsu.edu/~xyang/3080/images/adjDirectedGraph.png" alt="drawing" width="400"/>

 - **Adjacency List:** Each node has a list of its adjacent nodes. This representation is often more space-efficient for sparse graphs.

    <img src="https://www.researchgate.net/publication/228563151/figure/fig1/AS:301851523207168@1448978419114/An-example-of-graph-and-its-adjacency-list.png" alt="drawing" width="400"/>


**Graph Traversal:** 
 - **Depth-First Search (DFS)**  DFS explores a graph or tree by going as deep as possible along each branch before backtracking. It uses a stack to keep track of the vertices to be visited.
    - Start from a source vertex and visit one of its neighbors.
    - Continue visiting neighbors until you reach a vertex with no unvisited neighbors.
    - Backtrack to the previous vertex and explore any remaining unvisited neighbors.
    - Repeat this process until all vertices are visited.

    <img src="https://codeforces.com/predownloaded/8d/be/8dbe5d89e58b67f3d8e4d8e0e8eb3358ba921b28.png" alt="drawing" width="200"/>
  
 - **Breadth-First Search (BFS)** BFS explores a graph or tree level by level, visiting all neighbors of a node before moving on to the next level. It uses a queue to keep track of the vertices to be visited.
    - Start from a source vertex and enqueue it.
    - Dequeue a vertex, visit it, and enqueue its unvisited neighbors.
    - Continue this process until the queue is empty.
   
    <img src="https://upload.wikimedia.org/wikipedia/commons/5/5d/Breadth-First-Search-Algorithm.gif?20100504223639" alt="drawing" width="200"/>


</blockquote>






<blockquote>

<b>Hash Table</b>

<img src="https://www.jsmount.com/wp-content/uploads/2021/02/hash-table-structure.png" alt="drawing" width="400"/>

A hash table, also known as a hash map, is a data structure that implements an associative array abstract data type. It is a collection of key-value pairs, where each key is unique, and the corresponding value can be efficiently retrieved using the key. The key is processed through a hash function to determine the index or location in the array where the associated value can be found.


**Hash Function:** A hash function is a mathematical function that takes a key as input and produces a fixed-size string of characters, which is typically a hash code or hash value. The purpose of the hash function is to map keys to indices in the array. A good hash function aims to distribute keys uniformly across the array to minimize collisions.

**Collision:** A collision occurs when two or more keys hash to the same index in the array. Since the array has a fixed size, collisions are inevitable. Hash tables use various techniques to handle collisions, and one common approach is to use separate chaining or open addressing.

  - **Separate Chaining:** In this method, each array index contains a linked list or another data structure (like a binary search tree) that stores all the key-value pairs that hash to the same index.

  - **Open Addressing:** In this method, when a collision occurs, the algorithm searches for the next available slot in the array (probing) until an empty slot is found
</blockquote>