### STACK

#### Description

**Stack** is an abstract data type with a bounded(predefined) capacity. 
It is a simple data structure that allows adding and removing elements in a particular order.
Every time an element is added, it goes on the top of the stack and the only element that 
can be removed is the element that is at the top of the stack, just like a pile of objects.
The stack operates on last-in-first-out (LIFO) algorithm. 

#### Rules:

1. There is one index, called **Top**, pointing to the top of the **Stack**;
2. Write (Push) should start at **Top** index, and advance it;
3. Read (Pop) should stast at **Top** index, and decrease it;
4. If the end of the buffer reached, means the **Stack** is *Full* and nothing should be done.

#### Conditions:

```
Full:     TOP == Size - 1
Empty:    TOP == -1**
Initail:  TOP == -1**
```

### Main Operations:

* push **Item** to the buffer;
* pop **Item** from the buffer;

#### Push:

* verify whether the buffer is *Full*, if *Full* return *false*, otherwise continue;
* advance **TOP**;
* add new **Item** to the buffer, where **TOP** is pointing;

#### Pop:

* verify whether the buffer is *Empty*, if *Empty* return *false*, otherwise continue;
* retrieve **Item** from the buffer, where **TOP** is pointing;
* decrement **TOP**;

**NOTE:** Time complexity:

- Push: O(1);
- Pop: O(1);
- Top: O(1);
- Access: O(n);

