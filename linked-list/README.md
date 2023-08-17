### LINKED LIST

#### Description

A **Linked List** is a linear data structure. 
Every linked list has two parts, the data section and the address section that holds the address of the next element in the list,
which is called a node.

#### Rules:

1. Each **Node** contains 2 fields:
    * **".data"** field to store whatever element type the list holds
    * **".next"** field which is a pointer used to link one node to the next node;
2. Each **Node** contains a single **.next** pointer to the next **Node**;
3. The **.next** pointer of the last **Node** is **NULL**;
4. All of the **Nodes** are allocated in the **heap**.

### Main Operations:

* Traversal - access each element of the linked list
* Insertion - adds a new element to the linked list
* Deletion - removes the existing elements
* Peek - "look" at the Item without removing it
* Search - find a node in the linked list
* Sort - sort the nodes of the linked list

#### Put operation:

**NOTE:** **Head** and **User Data** should be passed as a parameter.
This is done to link newNode to the previous (in this case: **Head**)

**case 1: (Add Item at the end)**

* allocate **newNode** in the **heap** and set **.data** to whatever needs to be stored (malloc);
* link newNode **.next** to the current **Node** of the list (newNode->next = head);
* link **Head** to **newNode** (head = newNode), so head is the first **Item** in the **list**;

**case 2: (Add Item at the beginning)**

* allocate **newNode** in the **heap** and set **.data** to whatever needs to be stored (malloc);
* set **newNode** **.next = NULL** (in this case new node will be the last Item in the list);
* check whether **Head** is the fist Item in the list (head == NULL), if so head = newNode; if not move further
* iterete (traverse) over the list to reach **Node** with **.next** == NULL;
* link current **Node**.next to newNode (current->next = newNode);

**case 3: (Add Item at the middle)**

**NOTE:** In this case a **key** field is need to identify the rigth Node

**NOTE:**
**!!!** In order to modify **"right"** head, a *pointer-to-pointer* should be used.

#### Get operation (Delete Item):

**case 1: (Delete using additional pointer)**

* inside function two **Node** type pointers should be declared (**current & previous**). 
Current tracks current **Node**, previous tracks previous **Node**.
* iterate over List using current pointer and save current to previous (previous = current)
* once **key** is found, check whether it is first Item, if so advance **Head** (head = current->next), if not
* advance previous->next to current->next

**case 2: (Delete using pointer-to-pointer)**

* inside function pointer-to-pointer of Node type should be declared and assign to head;
* iterate over List using pointer-to-pointer (advance pointer-to-pointer);
* once **key** is found, dereference pointer-to-pointer and advance to next;



