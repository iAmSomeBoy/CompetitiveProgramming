# How to Determine the Solution of a Problem by Looking at Its Constraints

*By eanacra (adapted)*

---

By analyzing the **constraints** of a problem, we can often **predict or "guess" the appropriate approach and time complexity**.

---

## 🔹 Common Time Complexities

Let `n` be the main variable in the problem.

| Constraint on n | Suitable Time Complexity |
|----------------|--------------------------|
| n ≤ 12         | O(n!)                    |
| n ≤ 25         | O(2ⁿ)                    |
| n ≤ 100        | O(n⁴)                    |
| n ≤ 500        | O(n³)                    |
| n ≤ 10⁴        | O(n²)                    |
| n ≤ 10⁶        | O(n log n)               |
| n ≤ 10⁸        | O(n)                     |
| n > 10⁸        | O(log n) or O(1)         |

---

## 🔹 Examples of Common Time Complexities

### O(n!) — Factorial Time
- Example: Generating all permutations of numbers from 1 to n

### O(2ⁿ) — Exponential Time
- Example: Generating all subsets of an array

### O(n³) — Cubic Time
- Example: Checking all possible triangles with side lengths less than n

### O(n²) — Quadratic Time
- Example: Bubble Sort, Insertion Sort, Selection Sort

### O(n log n) — Linearithmic Time
- Example: Merge Sort, efficient sorting algorithms

### O(n) — Linear Time
- Example: Finding maximum/minimum in an array, Counting Sort

### O(log n) — Logarithmic Time
- Example: Binary Search, GCD using Euclidean Algorithm

### O(1) — Constant Time
- Example: Simple calculations like solving a linear equation

---

## 🔹 Explanation with Example Problems

### 1. Mr. Bender and Square (255D)

- Constraint: 1 ≤ n, c ≤ 10⁹  
- Expected complexity: O(log n) or O(1)  
- Since O(1) is not feasible → Use **Binary Search**

---

### 2. Kefa and Company (580B)

- Constraint: 1 ≤ n ≤ 10⁵  
- Expected complexity: O(n log n) or O(n)  
- Sorting is required → **O(n log n)** solution

---

### 3. Robot's Task (583B)

- Constraint: 1 ≤ n ≤ 1000  
- Expected complexity: O(n²)  
- Use **simulation**

---

## 🔹 Key Insight

Constraints act like a **guide**:
- Small `n` → brute force is acceptable  
- Medium `n` → optimize (sorting, DP, etc.)  
- Large `n` → need highly efficient methods (binary search, math, greedy)

---

## ⚠️ Important Note

This method is **not always perfect**.

- Some problems may require **unexpected optimizations**
- Example:  
  - Problem 591B (Rebranding)  
  - Constraints suggest O(n log n) or O(n)  
  - But actual solution works in **O(1)**

---

## ✅ Conclusion

Understanding constraints helps you:
- Narrow down possible approaches quickly  
- Avoid inefficient solutions  
- Think like a competitive programmer  

> “Before solving, always ask: *What time complexity can pass?*”

---

Happy Coding 🚀