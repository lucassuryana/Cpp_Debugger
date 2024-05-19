## Cache and Memory Access Patterns
Modern processors use a hierarchy of caches to speed up memory access. These caches take advantage of spatial locality and temporal locality:
* Spatial locality: If a program accesses a memory location, it's likely to access nearby memory locations soon.
* Temporal locality: If a program accesses a memory location, it's likely to access the same location again soon.

## Memory Layout of Arrays
In C++ (and most other languages), multi-dimensional arrays are stored in row-major order. This means that elements of a row are stored in contiguous memory locations. For an array x defined as int x[4][4], the memory layout will be:

```
x[0][0], x[0][1], x[0][2], x[0][3], x[1][0], x[1][1], x[1][2], x[1][3], ..., x[3][3]
```

### Impact of Loop Order on Cache Efficiency
The order in which you access the elements of the array can significantly impact cache performance.

* Row-major order access (optimal for caches):

```cpp
for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
        x[i][j] = i + j;
    }
}
```

Here, the innermost loop variable (j) iterates over columns, while the outer loop variable (i) iterates over rows. Since x[i][j] elements of a row are stored contiguously, accessing them in this order makes full use of spatial locality. The elements of x[i] are fetched into the cache as a block, leading to fewer cache misses.

* Column-major order access (less optimal for caches):

```cpp
for (int j = 0; j < size; j++) {
    for (int i = 0; i < size; i++) {
        x[i][j] = i + j;
    }
}
```
Here, the innermost loop variable (i) iterates over rows, while the outer loop variable (j) iterates over columns. Since elements of a column are not stored contiguously in memory, each access to x[i][j] is likely to result in a cache miss, as the memory locations are further apart.

When you run both versions of the code, you may observe that the execution time for the row-major order access (x[i][j]) is generally faster compared to the column-major order access (x[j][i]). This difference is due to better cache utilization in the row-major order case.

The video below shows how the way we define a loop can effect the workload of the cache memory.
![Alt text](cache_memory.gif)