### QUEUE

#### Description

A **Queue** is a linear data structure that stores a collection of elements.
The queue operates on first-in-first-out (FIFO) algorithm. 

#### Rules:

1. There are 2 indexes (pointers): **FRONT & REAR**;
2. Write (Enqueue) should start at **REAR** index and then advance it;
3. Read (Dequeue) should start at **FRONT** index and then advance it;
4. If the end of the buffer reached, indexes will wrap around. Modulo operation shuold be applied each time index increments;

#### Conditions:
```
Full:     COUNTER == CAPACITY
Empty:    COUNTER == 0
Initail:  FRONT == 0; REAR == SIZE - 1
```

### Main Operations:

* enqueue **Item** to the buffer;
* dequeue **Item** from the buffer;

#### Enqueue:

* verify whether the buffer is *Full*, if *Full* return *false*, otherwise continue;
* advance **REAR** ((Rear + 1) % Capacity);
* add new **Item** to the buffer where **REAR** is pointing;
* increment **Counter**;

#### Dequeue:

* verify whether the buffer is *Empty*, if *Empty* return *false*, otherwise continue;
* retrieve **Item** from the buffer, where **FRONT** is pointing;
* advance **FRONT** ((Front + 1) % Capacity);
* decrement **Counter**;

**NOTE:** Time complaxity:

- Enqueue: O(1);
- Dequeue: O(1);
- Front: O(1);
- Search O(n).

