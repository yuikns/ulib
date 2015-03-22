
```
.
|-- include                  -- output headers for the library
|-- lib                      -- output static libraries
|-- perf                     -- performance benchmarks
|   |-- avl                  -- AVL tree performance
|   |   |-- libavl
|   |   |-- solaris
|   |   `-- ulib
|   |-- hashmap              -- hash map performance
|   |   `-- result
|   `-- mapreduce            -- MapReduce framework performance
|-- src
|   |-- base                 -- core items
|   |-- ext1                 -- extended items
|   |   |-- bloom_filter
|   |   |-- c++              -- C++ containers and wrapper classes
|   |   |-- comb             -- combinatorics enumerator
|   |   |-- console          -- command-line interpreter
|   |   `-- rng              -- various RNG's
|   `-- ext2                 -- advanced items
|       |-- mapreduce        -- MapReduce framework
|       |-- osdep            -- OS dependent items
|       |-- reentrant        -- thread-safe items
|       `-- thread           -- thread and scheduling primitives
`-- test                     -- tests for everything
```