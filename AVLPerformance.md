## AVL Performance Comparison ##
The comparison involves GNU libavl, OpenSolaris Kernel AVL, and ULIB AVL implementation.

First, we fed each AVL tree with 64-bit random numbers during which the insert speed was measured, as shown in the following figure.

![http://ulib.googlecode.com/svn/wiki/avl_ins.png](http://ulib.googlecode.com/svn/wiki/avl_ins.png)

Next, we performed massive random searches on those AVL trees and the search speed was measured. The following figure depicts the search performance for various tree sizes.

![http://ulib.googlecode.com/svn/wiki/avl_find.png](http://ulib.googlecode.com/svn/wiki/avl_find.png)