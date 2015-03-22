The usage of aligned hashing is similar to STL hash\_map/set, but there are a few points need to be noted.

First, aligned hash map/set requires the key type supports '==' and 'long' operators. Some basic types such as 'int' and 'long' inherently support these operators; otherwise you need to implement the operators for the key type.

In addition, an iterator for aligned hash map/set does not have 'first' or
'second' data members. Instead, key and value for an iterator are accessed through key() and value() member functions respectively.

**Limitation**

The C++ containers for aligned hash table are based on the C version, which uses malloc/free to manage memory. This could be problematic when key/value of the hash table owns a customized constructor or destructor. In both cases, you can use pointer to the key/value instead, which should be recommended, especially for key/value larger than a CPU word size.