# Understanding Recursion Trees: Who Dominates?

I don't understand who dominates? Use recursion tree method and teach me time complexity.

## Step 1 – Basic idea of recursion tree method

For a recurrence like:

\[
T(n) = a T(n/b) + f(n)
\]

1. Draw the recursion tree:
   - Root has cost \( f(n) \)
   - Each of the \( a \) children gets \( T(n/b) \), so next level total cost = \( a \cdot f(n/b) \)
   - Continue until base case.

2. Sum all levels:  
   \[
   T(n) = f(n) + a f(n/b) + a^2 f(n/b^2) + \dots
   \]

3. Compare:
   - **Leaves dominate** → Last level has most total cost.
   - **Root dominates** → First level has most total cost.
   - **All levels equal** → Equal contribution from every level.

4. Compute total.

---

## Step 2 – Examples Explained

### Row 1: \( 3T(n/3) + n \)

\[
T(n) = n + 3(n/3) + 9(n/9) + \dots
\]
- Level 0: \( n \)  
- Level 1: \( 3 \cdot (n/3) = n \)  
- Level 2: \( 9 \cdot (n/9) = n \)  

Every level has total cost \( n \).  
Number of levels \( L \) satisfies \( n / 3^L \approx 1 \) ⇒ \( L \approx \log_3 n \).  
Total cost = \( n \times \log_3 n \) ⇒ \( O(n \log n) \).

**Who dominates?** All levels equal.

---

### Row 2: \( 2T(n/2) + 1 \)

Level 0: \( 1 \)  
Level 1: \( 2 \cdot 1 = 2 \)  
Level 2: \( 4 \cdot 1 = 4 \)  
Level k: \( 2^k \).

Last level \( k = \log_2 n \), cost \( 2^{\log_2 n} = n \).  
Sum = \( 1 + 2 + 4 + \dots + n \) (geometric series, last term biggest) ⇒ \( O(n) \).

**Who dominates?** Leaves (last level) dominate.

---

### Row 3: \( 2T(n/4) + n \)

Level 0: \( n \)  
Level 1: \( 2 \cdot (n/4) = n/2 \)  
Level 2: \( 4 \cdot (n/16) = n/4 \)  
Geometric sequence \( n, n/2, n/4, \dots \) ⇒ first term largest.  
Sum ≤ \( 2n \) ⇒ \( O(n) \).

**Who dominates?** Root dominates.

---

### Row 4: \( T(n-1) + 1 \)

Tree is a chain:  
Level 0: \( 1 \)  
Level 1: \( 1 \)  
…  
Level n-1: \( 1 \)  
Total cost = \( n \cdot 1 = O(n) \).

**Who dominates?** Every level has cost 1, but there are \( n \) levels. The “dominance” here means no single level dwarfs others; you can call it “flat, many levels” leading to \( O(n) \).

---

### Row 5: \( 8T(n/2) + n^2 \)

Level 0: \( n^2 \)  
Level 1: \( 8 \cdot (n/2)^2 = 8 \cdot n^2 /4 = 2 n^2 \)  
Level 2: \( 64 \cdot (n/4)^2 = 64 \cdot n^2 /16 = 4 n^2 \)  
Growth factor = 2 per level.  
Number of levels \( L = \log_2 n \).

Last level cost: \( n^2 \cdot 2^{\log_2 n} = n^2 \cdot n = n^3 \).  
Leaves dominate ⇒ \( O(n^3) \).

---

### Row 6: \( 2T(n/2) + n^2 \)

Level 0: \( n^2 \)  
Level 1: \( 2 \cdot (n/2)^2 = 2 \cdot n^2 /4 = n^2 / 2 \)  
Level 2: \( 4 \cdot (n/4)^2 = 4 \cdot n^2 /16 = n^2 / 4 \)  
Geometric series decreasing ⇒ root dominates ⇒ \( O(n^2) \).

---

## Step 3 – Summary Table

| Recurrence         | Cost trend           | Who dominates?            | Final complexity |
|--------------------|----------------------|---------------------------|------------------|
| \( 3T(n/3) + n \)  | same every level     | all levels equal          | \( O(n\log n) \) |
| \( 2T(n/2) + 1 \)  | doubles per level    | leaves dominate           | \( O(n) \)       |
| \( 2T(n/4) + n \)  | halves per level     | root dominates            | \( O(n) \)       |
| \( T(n-1) + 1 \)   | flat (1 each level)  | n levels × 1 (no single level dominates, but many levels) | \( O(n) \) |
| \( 8T(n/2) + n^2 \) | doubles per level   | leaves dominate           | \( O(n^3) \)     |
| \( 2T(n/2) + n^2 \) | halves per level    | root dominates            | \( O(n^2) \)     |

---

## Step 4 – Rule of Thumb

For \( T(n) = aT(n/b) + n^c \):

- If \( a < b^c \) → root dominates → \( O(n^c) \)  
- If \( a = b^c \) → all levels equal → \( O(n^c \log n) \)  
- If \( a > b^c \) → leaves dominate → \( O(n^{\log_b a}) \)  

**Check row 5:** \( a=8, b=2, c=2 \) ⇒ \( b^c = 4 \), \( a=8 > 4 \) ⇒ leaves dominate ⇒ \( n^{\log_2 8} = n^3 \).  

**Check row 6:** \( a=2, b^c = 4 \), \( 2 < 4 \) ⇒ root dominates ⇒ \( O(n^2) \).