#### Implementation

This approach based on statically allocated buffer outside of 'buffer' module

**PROS**
1. Flexible, the caller responsible for passing proper buffer to the module.

**CONS**
1. Buffer size defined at compile time.
