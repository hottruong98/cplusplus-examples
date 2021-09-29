Convert A[0..n-1] into a max heap:

Build_max_heap(A):

for i = n/2-1 down to 0

do max_heapify(A,i)

We don't need to heapify leaf nodes. Therefore, there are only n/2 nodes to be heapified.

The last leaf node has index (n-1) -> it's parent where we'll start heapify has index [(n-1)-1]/2 = n/2-1

