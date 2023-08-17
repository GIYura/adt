### CIRCULAR (RING) BUFFER

### Description

**Circular buffer** (further - **CB**) is a FIFO data structure that treats memory to be circular; that is, 
the read/write index loops back to 0 after it reaches the buffer length. 

This is achieved by two pointers (or variables) to the array, the **Start** pointer and the **End** pointer.
As data is added (write) to the buffer, the **End** pointer is incremented and likewise, when the data is being removed 
(read) the **Start** pointer is incremented. 

#### Rules:

1. There should be 2 indexes;
2. Write (Put) should start at **End** index and then advance it;
3. Read (Get) should start at **Start** index and then advance it;
4. If the end of the buffer reached, indexes will wrap around. Modulo operation shuold be applied each time index increments;

#### Conditions:
```
Full:     (End + 1) % BufferSize == Start
Empty:    End == Start
Initail:  Start == End == 0
```

### Main Operations:

* Put an item to the buffer;
* retrieve an item from the buffer;

#### Put:

* verify whether the buffer is *Full*, if *Full* return *false*, otherwise continue;
* add new **Item** to the buffer where **End** is pointing;
* advance **End** (End = (End + 1) % bufferSize)

#### Get:

* verify whether the buffer is *Empty*, if *Empty* return *false*, otherwise continue;
* retrieve **Item** from the buffer where **Start** is pointing;
* advance **Start** (Start = (Start + 1) % bufferSize)

**NOTE:** Aforementioned conditions called **"Waste"** and it is **Thread-safe**, because data "Consumer" and "Producer" access 
corresponding indexes.

There is another way to define *Full* and *Empty* condition using bool **Flag**. 
This approach involse different logic and extra logic should be consider to provide **Thread-safe** usage.

**NOTE:** What should be done when new data arrived, but the buffer is *Full*?

There are two ways: 
* discard new data (Not add new data, use bool to return);
* discard the oldest data (add new data to the buffer and advance **Start**); 

