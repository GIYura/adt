#### Implementation

This approach uses dynamically allocated buffer.

**PROS**
1. Flexible, the user need to pass buffer size only.

**CONS**
1. Might lead to memory leak;

**NOTE:** The caller doesn't know internal implementation of the 'buffer'
module, so it is not obvious to free memmory.

