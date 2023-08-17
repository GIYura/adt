##### Circular buffer 

**NOTE:** key notes described below

1. There are 2 indexes:

- Start - Index of head of buffer;
- End - Index of next available space; 

They used to define the rigth place to put and get incomming data.

2. **End** index is used to track incomming data. Once new data put to the buffer, **End** advanced.

3. **Start** index is used to track outcomming data. Once the data retrieved from the buffer, **Start** advanced.

4. Every time the index advanced it should be compared with the length of the buffer, in order to wrap around (not to overflow the buffer).

```
 index = (index + 1) % BUFFER_SIZE
```

5. Once the **End** reaches the end of the buffer, it should be set to the start point ([0]) and it should 
advance the **Start** (to overwrite the oldest data) or just discard the new data.

6. Functions **BufferPut()** and **BufferGet()** should be start with verifying the state of the buffer (full / empty).

7. The **empty**: 

```
End == Start
```

8. The **full**:

```
((End + 1) % BUFFER_SIZE) == Start
```

