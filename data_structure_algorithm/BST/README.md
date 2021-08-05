# Types of balanced BST

> ## **Time complexity of member functions in BST class**:
>
> *(Note: h = height, n = number of nodes)*
>
> **Search**():
>  - hasData(): T = O(h)
>  - insert(): T = O(h)
>  - deleteData(): T = O(h)
>  - Worst case: T = O(n) when h = n
> 
> *So, to prevent the worst case, we have **balanced BST***

> ## **Balanced BST**:
> 
> <p style="text-align: center;"> | left height - right height | &le; 1 for every node </p>
> 
> In balanced BST, as the tree grows deeper, there will be more nodes and the additional amount of nodes are approximately 2^(previous amount). Therefore, we have totally:
> 
> <p style="text-align: center;"> n &asymp; 2<sup>0</sup> + 2<sup>1</sup> + 2<sup>2</sup> + ... + 2<sup>k</sup> (nodes) </p>
>
> In this case of BST search, **time** goes up linearly, while the **number of elements** is exponential. As we traverse the tree, we either go left or right eliminating half of the whole tree/subtree. Therefore, the average time complexity of a balanced BST is O(log(n)) for a single search and O(n.log(n)) for n searches. While in an unbalanced BST, the average time complexity is O(h) and the worst case is O(n) for a single search and O(n<sup>2</sup>) for n searches.

> ## **Types of self-balancing binary search tree:**
> 
> 1. AVL tree: Perform left or right rotation until the binary tree is balanced
> 2. Red-Black tree (less important)
> 3. 2-4 tree (less important)

> ## **The logarithmic function:**
> ![The logarithmic function](https://github.com/hottruong98/cplusplus-examples/blob/bcdecae309b798d631b431524a7b58d3e3ec5af5/data_structure_algorithm/BST/log_function.png)
