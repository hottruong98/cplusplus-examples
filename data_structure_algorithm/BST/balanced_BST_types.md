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
> $$ | \text{ left height - right height } | \leq 1 \text{ for every node}$$
> 
> In balanced BST, as the tree grows deeper, there will be more nodes and the additional amount of nodes are approximately 2^(previous amount). Therefore, we have totally:
> 
> $$ n \approx 2^0 + 2^1 + 2^2 + ... + 2^k \text{ (nodes)} $$
>
> In this case of BST search, **time** goes up linearly, while the **number of elements** is exponential. As we traverse the tree, we either go left or right eliminating half of the whole tree/subtree. Therefore, the average time complexity of a balanced BST is O(log(n)) for a single search and O(n.log(n)) for n searches. While in an unbalanced BST, the average time complexity is O(h) and the worst case is O(n) for a single search and O(n^2) for n searches.

