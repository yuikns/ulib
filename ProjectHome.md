The ULIB is a collection of efficient building blocks for developing high-performance and scalable systems in C and C++. These building blocks mainly cover, multithreading, parallel computing, efficient data indexing, numerical approximation, and cryptography. The detailed list is provided at the bottom.

Some building blocks are based on other open-source projects, such as the Linux kernel. Please refer to the copyright of the specific source code files.

I would be happy to know if your projects are using ULIB.

### ULIB has been used in ###
  * **TIBCO Spotfire** - Business intelligence analytics software & data visualization. http://spotfire.tibco.com.
  * **ArangoDB** - the multi-purpose NoSQL DB. https://www.arangodb.org.
  * **NXWEB** - Ultra-fast and super-lightweight web server for applications written in C. https://bitbucket.org/yarosla/nxweb/wiki/Home.
  * **Bzing** - Low-level Bitcoin database library. https://github.com/bitcoinjs/bzing.
  * **ECDSA Util** - Tiny collection of programs used for ECDSA. https://github.com/tcatm/ecdsautils.

### Performance Comparison ###
  1. ULIB AlignHash performance [AlignedHashingPerformance](AlignedHashingPerformance.md).
  1. Analysis of FastHash http://code.google.com/p/fast-hash/.
  1. AVL tree performance [AVLPerformance](AVLPerformance.md).
> _Performance tests are located under perf/_

### Updates ###
  1. **10/17/2014**
    * 2.1.0 released, changes include:
      1. Added the chain\_hash\_set container (aka. the hash list).
      1. Added the maximum profit scheduler dp\_mps.
      1. Fixed a parameter bug of SIGN() in math\_bit.h.
      1. Other minor fixes.
> > > The download link is given in "External links."
  1. **08/01/2013**
    * Added a patch to the SVN trunk. This patch fixes a segmentation fault raised in the sort() method of hash\_chain. This issue only occurs when it is complied by certain buggy GCCs. If you have the hash\_chain tests failed due to segmentation fault, please consider applying this patch.
  1. Starting from 2.0.0 beta, the ULIB targets only x86\_64 architecture. In other words, newer versions may not compile/work on other architectures.

### Main Features ###
  * **Basic Data Structures and Algorithms**
    1. An extremely efficient open addressing hash table, comparable or even better performance than STL hashmap, Google sparse/dense hash, EASTL hashmap and RDESTL hashmap.
    1. A chaining hash table, corner stone for building concurrent hash tables.
    1. A concurrent hash table based on the chaining hash table. Significantly faster (~30%) than several popular ones, e.g., TBB(http://threadingbuildingblocks.org), nbds(http://code.google.com/p/nbds/) and Visual Studio 2012. [LocksCanMakeSense](LocksCanMakeSense.md) provides some analysis.
    1. The fast-hash hash function http://fast-hash.googlecode.com. Efficient and robust general purpose hash function.
    1. A set of robust, efficient, and invertible integer hash functions.
    1. Heap and heapsort. Improved performance than STL.
    1. A text binary search algorithm.
    1. A robust O(n) median algorithm.
    1. Various random number generators, e.g. Zipf RNG, Normal RNG, and Gamma RNG.
    1. General AVL and Splay trees. Faster than Solaris Kernel AVL and libavl.
    1. Bit tricks.
    1. Cryptographic algorithms.

  * **Parallel Computing**
    1. MapReduce framework for multicores.
    1. A set of scalable locks.
    1. Atomic primitives for x86\_64.

