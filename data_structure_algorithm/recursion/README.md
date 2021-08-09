## Time complexity of recursion
### **MASTER METHOD:**
**1. Theory and proof:**

Reference: https://www.cs.cornell.edu/courses/cs3110/2012sp/lectures/lec20-master/mm-proof.pdf

Consider the recurrence:
>
> $$ T(n) = aT(\frac{n}{b})+f(n) \quad(1) $$
> - $n$ is the size of the problem
> - $a$ is the number of sub problems in the recursion
> - $\frac{n}{b}$ is the size of each sub problem. (All sub problems are assumed to have the same size) 
> - $f(n)$ is the cost of the work done outside the recursive call, which includes the cost of dividing the problem and cost of merging the solutions
> 
> Here, $a ≥ 1$ and $b > 1$ are constants, and $f(n)$ is an asymptotically positive function.

The solution of the recurrence is:
> $$ T(n) = \sum_{i=0}^{\log_{b}n} a^i f(\frac{n}{b^i}) + O(n^{log_b{a}}) \quad(2) $$
This can be seen by drawing the tree of the recurrence (with case $a = 2$) (1):

$$ f(n) $$
$$ \text{.} \qquad\qquad\qquad\qquad \text{.} $$
$$ f(\frac{n}{b}) \qquad\qquad\qquad f(\frac{n}{b}) $$
$$ \text{.} \qquad\qquad \text{.} \qquad\qquad \text{.} \qquad\qquad \text{.} $$
$$ f(\frac{n}{b^2}) \qquad f(\frac{n}{b^2}) \qquad f(\frac{n}{b^2}) \qquad f(\frac{n}{b^2}) $$
$$ \text{.} \qquad\qquad \text{.} \qquad\qquad \text{.}  \qquad\qquad \text{.} $$
$$ \text{.} \qquad\qquad \text{.} \qquad\qquad \text{.}  \qquad\qquad \text{.} $$

Height of the tree or number of division times: 
$$ \log_{b}n $$

$T(n)$ is the sum of the values of all the nodes of the tree:
$$ T(n) = f(n) + af(\frac{n}{b}) + a^2f(\frac{n}{b^2}) + a^3f(\frac{n}{b^3}) + ... + a^{\log_{b}n}f(1) $$
According to the logarithm formula:
$$ a^{\log_{b}n} = n^{\log_{b}a} $$
Then $T(n)$ can be written as:
$$ T(n) = \sum_{i=0}^{\log_{b}n} a^i f(\frac{n}{b^i}) + O(n^{\log_{b}a}) $$
, with $O(n^{\log_{b}a})$ is the sum across the leaves.

Assuming that $f(n) = O(n^k)$, then:
> $$ T(n) = \sum_{i=0}^{\log_{b}n} (\frac{a}{b^k})^i n^k + O(n^{\log_{b}a}) $$
>
> - **Case 1:** 
> $k < \log_{b}a \Rightarrow n^k \ll n^{\log_{b}a}$, then $T(n) = O(n^{\log_{b}a})$
> 
> - **Case 2:** $k \approxeq \log_{b}a \Rightarrow n^k \approxeq n^{\log_{b}a}$, then $T(n) = O(n^{\log_{b}a}log_{}n)$
> 
> - **Case 3:** $k > \log_{b}a \Rightarrow n^k \gg n^{log_{b}a}$, then $T(n) = O(n^k)$

**2. Examples:**

**2.1. Merge sort problem:**
```
void mergeSort(vector<int> &nums, int left, int right) {
    if(left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, right);
}
```
- The size of the problem is also the size of the input array $\Rightarrow n = nums.size()$
  
- Sub problems are left part and right part of the array $\Rightarrow a = 2$
  
- $f(n)$ in this case includes the cost of dividing big problems into 2 smaller problems by calculating the position $mid$ $(O(1))$ + merging the solutions $(O(n))$ $\Rightarrow f(n) = 1 + O(n) = O(n)$ 
```
void merge(vector<int> &nums, int left, int right) {
    vector<int> output(right - left + 1, 0);
    int mid = (left + right) / 2;
    int index = 0;
    int leftIndex = left;
    int rightIndex = mid + 1;
    while(leftIndex <= mid && rightIndex <= right) {
        output[index++] = nums[leftIndex] < nums[rightIndex] ? nums[leftIndex++] : nums[rightIndex++];
    }
    while(leftIndex <= mid) {
        output[index++] = nums[leftIndex++];
    }
    while(rightIndex <= right) {
        output[index++] = nums[rightIndex++];
    }
    for(int i = left; i <= right; i++) {
        nums[i] = output[i];
    }
}
```
So, the recurrence relation of the MERGE SORT problem can be written as:

> $$ T(n) = 2T(\frac{n}{2}) + O(n) $$
According to the MASTER METHOD:
> $a = 2, \quad b = 2, \quad f(n) = O(n)$
> 
> $n = n^{\log_{b}a} \Rightarrow$ then $T(n) = O(n\log_{}n)$

Proof: 

$$T(n) = \sum_{i=0}^{\log_{b}n} a^i f(\frac{n}{b^i}) + O(n^{log_b{a}})$$

$T(n) = \sum_{i=0}^{\log_{b}n} (\frac{a}{b^k})^i n^k + O(n^{\log_{b}a})$

$T(n) = \sum_{i=0}^{\log_{2}n} (\frac{2}{2^1})^i n + O(n^{\log_{2}2})$ 

$T(n) = \sum_{i=0}^{\log_{2}n} 1^i n + O(n)$

$T(n) = (\log_{2}n + 1)n + O(n)$

$T(n) = O(n\log_{}n)$

**2.2. Problem 2:**

> $$ T(n) = 8T(\frac{n}{2}) + O(n^2) $$

According to the MASTER METHOD:

> $a = 8, \quad b = 2, \quad f(n) = O(n^2)$
> 
> $n^2 < n^{\log_{b}a} = n^3 \Rightarrow$ then $T(n) = O(n^3)$

Proof: 

$$T(n) = \sum_{i=0}^{\log_{2}n} 2^i n^2 + O(n^3)$$ 

$T(n) = \frac{2^{1 + \log_{2}n} - 1}{2 - 1} n^2 + O(n^3)= (2^{1 + \log_{2}n} - 1)n^2 + O(n^3)$

$T(n) = (2n^{\log_{2}2} - 1)n^2 + O(n^3) = 2n^3 - n^2 + O(n^3) = O(n^3)$