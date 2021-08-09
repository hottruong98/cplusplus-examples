### What are some real-world applications of AVL trees today?

> Link: https://www.quora.com/What-are-some-real-world-applications-of-AVL-trees-today

> "**Trains in a railway system**":
> 
> I am not sure how IRCTC (Or, any other Railway system) implements it, but taking the fact into account that newer trains come up very few every year and the[code] struct train {};[/code] remains constant for a good period of time, an AVL implementation of this would be better than any other tree for searching.
>
> AVL trees are beneficial in the cases where you are designing some database "**where insertions and deletions are not that frequent**" but you have to "**frequently look-up**" for the items present in there.

> AVL tree is a height balanced tree, so the complexity of inserting and searching a node is always "**O(logn)**". But the problem with AVL tree is when you insert a new node you need to perform rotation to make the tree balanced. This rotation mechanism is time consuming, so when your job is mostly insertion than searching then AVL tree is not efficient(Red black is used in this case). AVL tree is efficient when your job have "**more searching than insertion**".

> There are as many applications of AVL tree as there are applications of set<>, TreeSet<>, etc. It provides you with the same interface as RB-tree which is used in implementation of standard libraries mentioned above. Actually, it is even faster than RB-tree, but requires one bit more memory to store additional info used for self-balancing.

> "**Search, insert, delete, min and max**" operations all run in O(logN). So, it has many use cases, all operations needs to have same time complexity, particularly look up intensive applications.