Here is a compact note that includes the key text, definitions, and examples directly from the provided lecture slides.

---

### **Lecture 1: Introduction to Numerical Methods**

- **What is Numerical Computing?**
    - An approach for solving complex mathematical problems using only simple arithmetic operations (+, -, ×, ÷).
    - It involves the formulation of mathematical models and the development, analysis, and use of algorithms.
- **Necessity:**
    - Plays an indispensable role in solving real-life mathematical, physical, and engineering problems.
- **Some Applications:**
    - Finding roots of equations
    - Solving systems of linear algebraic equations
    - Interpolation and regression analysis
    - Numerical integration and differentiation
    - Solution of differential equations
- **Process of Numerical Computing:**
    1.  **Formulation of a Mathematical Model:** Translating a physical problem into a mathematical problem by making simplifying assumptions and identifying important variables.
    2.  **Construction of an Appropriate Numerical Method:** Selecting a suitable algorithm.
    3.  **Implementation of the Method:** Designing an algorithm, writing a program, and executing it to obtain a solution.
    4.  **Validation of the Solution:** Verifying the results for desired accuracy. If not accurate, the model, method, or algorithm must be modified.
- **Characteristics of Numerical Computation:**
    - **Accuracy:** Refers to the number of significant digits in a value and is affected by errors. The result must be sufficiently accurate for its purpose.
    - **Rate of Convergence:** For iterative methods, how quickly a sequence of approximations converges to the required solution. Faster convergence means less execution time.
    - **Numerical Stability:** A process is numerically unstable if errors grow exponentially during computation. Stable methods are preferred.
    - **Efficiency:** The amount of effort (computing time and programming) required to implement a method.

---

### **Lecture 2: Errors in Computing**

- **Integer Arithmetic Errors:**
    - **Overflow:** When an operation results in a number larger than the maximum limit.
    - **Underflow:** When the result is smaller than the lower limit.
    - **Truncation:** When integer division results in the remainder being discarded.
- **Floating Point Arithmetic Errors:**
    - **Inexact Representation:** A decimal number cannot always be represented exactly in binary form (e.g., 0.1 in binary is 0.0001100110011...), so it must be terminated.
    - **Rounding:** Limiting the number of significant digits by chopping or symmetric rounding.
    - **Subtractive Cancellation:** A phenomenon where subtracting two nearly equal numbers results in a loss of significant digits.
        - **Example:** Subtract 0.499998 from 0.500000.
            - \( f_x - f_y = 0.000002 \)
            - Result: \( 0.200000 \times 10^{-5} \) (contains only one significant digit).

---

### **Lecture 3: Accuracy, Precision, and Error Analysis**

- **Significant Digits:**
    - **Rules:** All non-zero digits are significant. Zeros between non-zero digits are significant. Trailing zeros following a decimal point are significant.
    - **Example:** 3.50, 65.0, and 0.230 have three significant digits each.
    - Zeros between the decimal point and a non-zero digit are not significant (e.g., 0.0001234 has four significant digits).
- **Accuracy vs. Precision:**
    - **Accuracy:** Refers to the number of significant digits in a value (e.g., 57.396 is accurate to five significant digits).
    - **Precision:** Refers to the number of decimal positions or the order of magnitude of the last digit (e.g., 57.396 has a precision of 0.001 or \(10^{-3}\)).
- **Types of Errors (Taxonomy):**
    - **Inherent Errors (Input Errors):**
        - **Data Errors:** Due to limitations in experimental measurement and instrumentation.
        - **Conversion Errors:** Due to limitations of the computer to store data exactly (e.g., representing 0.01 in binary).
    - **Numerical Errors (Procedural Errors):**
        - **Round-off Errors:** Occur when a fixed number of digits are used to represent exact numbers. Can be done by **chopping** (dropping extra digits) or **symmetric rounding** (rounding up if the first discarded digit is ≥5).
        - **Truncation Errors:** Arise from using an approximation in place of an exact mathematical procedure (e.g., using a finite number of terms for an infinite series).
    - **Modeling Errors:** Due to simplifying assumptions made when formulating a mathematical model (e.g., ignoring wind force on a falling body).
    - **Blunders:** Human errors, such as mistakes in a computer program or wrong initial guesses.
- **Error Quantification:**
    - **Absolute Error:** \( e_a = |x_t - x_a| \), where \( x_t \) is the true value and \( x_a \) is the approximate value.
    - **Relative Error:** \( e_r = \frac{|x_t - x_a|}{|x_t|} \)

---

### **Lecture 4: Roots of Nonlinear Equations**

- **Problem:** Find the roots (or zeros) of an equation of the form \( f(x) = 0 \).
- **Bisection Method (Bracketing Method):**
    - Relies on the fact that if \( f(a) \cdot f(b) < 0 \), there is at least one real root between \(a\) and \(b\).
    - **Formula:** The midpoint is \( x_0 = \frac{x_1 + x_2}{2} \). The interval containing the root is halved iteratively.
    - **Example:** Find a root of \( x^2 - 4x - 10 = 0 \) in the interval (-2, -1).
        - **Iteration 1:** \( x_1 = -2, x_2 = -1, x_0 = -1.5 \). \( f(x_1)=2, f(x_0)=-1.75 \) → root in (-2, -1.5).
        - **Iteration 2:** \( x_1 = -2, x_2 = -1.5, x_0 = -1.75 \). \( f(x_1)=2, f(x_0)=0.0625 \) → root in (-1.75, -1.5).
        - Process continues until the interval is very small, eventually converging to approximately -1.7416.
    - **Convergence:** Linear convergence; the error reduces by a factor of 0.5 each step.
- **False Position Method (Bracketing Method):**
    - Uses a straight line between the two bracketing points. The intersection of this line with the x-axis gives the next approximation.
    - **Formula:** \( x_0 = x_1 - \frac{f(x_1)(x_2 - x_1)}{f(x_2) - f(x_1)} \)
    - **Example:** Find a root of \( f(x) = x^2 - x - 2 = 0 \) in the range (1, 3).
        - **Iteration 1:** \( x_1=1, x_2=3 \). \( f(1)=-2, f(3)=4 \). \( x_0 = 1 - \frac{(-2)(3-1)}{4 - (-2)} = 1.6667 \).
        - **Iteration 2:** \( x_1=1.6667, x_2=3 \). \( f(1.6667) = -0.8889 \). \( x_0 = 1.6667 - \frac{(-0.8889)(3-1.6667)}{4 - (-0.8889)} = 1.909 \).
        - **Iteration 3:** \( x_1=1.909, x_2=3 \). \( f(1.909) = -0.2647 \). \( x_0 = 1.909 - \frac{(-0.2647)(3-1.909)}{4 - (-0.2647)} = 1.986 \). The actual root is 2.
- **Newton-Raphson Method (Open Method):**
    - Uses the tangent line at an initial guess to find the next approximation.
    - **Formula:** \( x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)} \)
    - **Example:** Find a root of \( f(x) = x^2 - 3x + 2 \) starting from \( x=0 \). (Actual roots: 1 and 2).
        - \( f'(x) = 2x - 3 \)
        - **Iteration 1:** \( x_2 = 0 - \frac{2}{-3} = 0.6667 \)
        - **Iteration 2:** \( x_3 = 0.6667 - \frac{0.4444}{-1.6667} = 0.9333 \)
        - **Iteration 3:** \( x_4 = 0.9333 - \frac{0.071}{-1.334} = 0.9959 \)
        - After a few iterations, it converges to 1.0.
- **Secant Method (Open Method):**
    - Approximates the derivative by a finite difference using two initial estimates.
    - **Formula:** \( x_{i+1} = x_i - \frac{f(x_i)(x_i - x_{i-1})}{f(x_i) - f(x_{i-1})} \)
    - **Example:** Estimate a root of \( f(x) = x^2 - 4x - 10 \) with \( x_1=4, x_2=2 \).
        - **Iteration 1:** \( x_3 = 2 - \frac{-14(2-4)}{-14 - (-10)} = 9 \)
        - **Iteration 2:** \( x_3 = 9 - \frac{35(9-2)}{35 - (-14)} = 4 \)
        - **Iteration 3:** \( x_3 = 4 - \frac{-10(4-9)}{-10 - 35} = 5.1111 \)
        - **Iteration 4:** \( x_3 = 5.1111 - \frac{-4.3207(5.1111-4)}{-4.3207 - (-10)} = 5.9563 \)
        - **Iteration 5:** \( x_3 = 5.9563 - \frac{1.6523(5.9563-5.1111)}{1.6523 - (-4.3207)} = 5.7225 \)

---

### **Lecture 5: Direct Solution of Linear Equations**

- **Gauss Elimination Method:**
    - **Strategy:** Reduces the system of equations to an upper triangular form using forward elimination, then solves using back substitution.
- **Gauss Elimination with Pivoting:**
    - To avoid division by zero and reduce round-off errors, rows are interchanged so that the pivot element (diagonal element) is the largest in magnitude in its column (partial pivoting).
- **Gauss-Jordan Method:**
    - Eliminates variables from all other rows (both below and above), producing a diagonal matrix.
    - The augmented matrix \( [A|I] \) is transformed to \( [I|A^{-1}] \).
    - **Example:** Solve \( 2x_1 + 4x_2 - 6x_3 = -8 \), \( x_1 + 3x_2 + x_3 = 10 \), \( 2x_1 - 4x_2 - 2x_3 = -12 \).
        - After row operations, the solution is found to be \( x_1 = 1, x_2 = 2, x_3 = 3 \).

---

### **Lecture 6: Iterative Solution of Linear Equations**

- **Jacobi Iteration Method:**
    - Solves each equation for the diagonal unknown, using the previous iteration's values for all other unknowns.
    - **Example:** Solve \( 2x_1 + x_2 + x_3 = 5 \), \( 3x_1 + 5x_2 + 2x_3 = 15 \), \( 2x_1 + x_2 + 4x_3 = 8 \).
        - Rewrite: \( x_1 = (5 - x_2 - x_3)/2 \), \( x_2 = (15 - 3x_1 - 2x_3)/5 \), \( x_3 = (8 - 2x_1 - x_2)/4 \).
        - Starting with (0,0,0), the first iteration yields (2.5, 3, 2). After successive iterations, values approach (1, 2, 1).
- **Gauss-Seidel Method:**
    - An improved version of Jacobi. It uses the most recently available values for each unknown.
    - **Example:** Using the same system as above.
        - **Iteration 1:** \( x_1 = (5 - 0 - 0)/2 = 2.5 \), \( x_2 = (15 - 3×2.5 - 2×0)/5 = 1.5 \), \( x_3 = (8 - 2×2.5 - 1.5)/4 = 0.4 \).
        - **Iteration 2:** \( x_1 = (5 - 1.5 - 0.4)/2 = 1.6 \), \( x_2 = (15 - 3×1.6 - 2×0.4)/5 = 1.9 \), \( x_3 = (8 - 2×1.6 - 1.9)/4 = 0.7 \).
        - Continues until reaching (1, 2, 1).

---

### **Lecture 7: Interpolation**

- **Linear Interpolation:**
    - Connects two data points with a straight line.
    - **Formula:** \( f(x) = f(x_1) + (x - x_1)\frac{f(x_2) - f(x_1)}{x_2 - x_1} \)
- **Lagrange Interpolation Polynomial:**
    - An \(n\)-th degree polynomial that passes through \(n+1\) points.
    - **Formula:** \( p_n(x) = \sum_{i=0}^{n} f_i l_i(x) \), where \( l_i(x) = \prod_{j \neq i} \frac{x - x_j}{x_i - x_j} \).
    - **Example:** Estimate \( e^{1.5} \) from data: (0, -1.7183), (1, 0), (2, 6.3891), (3, 19.0855).
        - The polynomial is derived as \( p(x) = 0.8455x^3 - 1.0604x^2 + 1.9331x \).
        - \( p(1.5) = 3.3674 \), so \( e^{1.5} = 4.3674 \).
- **Newton's Divided Difference Interpolation:**
    - Uses divided differences to construct the polynomial, allowing for easy addition of new data points.
    - **Formula:** \( p_n(x) = f[x_0] + f[x_0,x_1](x-x_0) + f[x_0,x_1,x_2](x-x_0)(x-x_1) + \dots \)
    - **Example:** Estimate \( \log 2.5 \) from data: (1,0), (2,0.3010), (3,0.4771), (4,0.6021).
        - Using first three points: \( a_0=0, a_1=0.3010, a_2=-0.06245 \).
        - \( p_2(x) = 0 + 0.3010(x-1) -0.06245(x-1)(x-2) \)
        - \( p_2(2.5) = 0.3010(1.5) -0.06245(1.5)(0.5) = 0.4047 \).

---

### **Lecture 8: Regression (Least Squares)**

- **Least Squares Regression:**
    - Minimizes the sum of the squares of the vertical distances (errors) between the data points and the fitting curve.
- **Fitting a Straight Line:**
    - Model: \( y = a + bx \)
    - **Formulas:**
        - \( b = \frac{n\sum x_i y_i - \sum x_i \sum y_i}{n\sum x_i^2 - (\sum x_i)^2} \)
        - \( a = \bar{y} - b\bar{x} \)
    - **Example:** Fit a line to data: (1,3), (2,4), (3,5), (4,6), (5,8).
        - \( b = \frac{5×90 - 15×26}{5×55 - 15^2} = 1.20 \)
        - \( a = \frac{26}{5} - 1.20×\frac{15}{5} = 1.60 \)
        - Equation: \( y = 1.6 + 1.2x \)
- **Fitting Transcendental Equations:**
    - **Example:** Fit a power-function model \( y = a x^b \) to data: (1,0.5), (2,2), (3,4.5), (4,8), (5,12.5).
        - Transform: \( \ln y = \ln a + b \ln x \). Apply linear least squares to the transformed data.
        - Compute \( b = 1.9998 \), \( \ln a = -0.6929 \), so \( a = 0.5001 \).
        - The fitted equation is \( y = 0.5001 x^{1.9998} \), which is close to the exact \( y = x^2/2 \).

---

### **Lecture 9: Numerical Differentiation**

- **Forward Difference Quotient (2-point formula):**
    - \( f'(x) \approx \frac{f(x+h) - f(x)}{h} \)
    - Truncation error is of order \(h\).
- **Backward Difference Quotient (2-point formula):**
    - \( f'(x) \approx \frac{f(x) - f(x-h)}{h} \)
- **Central Difference Quotient (3-point formula):**
    - \( f'(x) \approx \frac{f(x+h) - f(x-h)}{2h} \)
    - Truncation error is of order \(h^2\), making it more accurate.
    - **Example:** For \( f(x) = x^2 \) at \( x=1 \), with \( h=0.2 \), the central difference gives \( f'(1) = \frac{(1.2)^2 - (0.8)^2}{0.4} = 2.0 \), which is exact.
- **Second Derivative Approximation:**
    - \( f''(x) \approx \frac{f(x+h) - 2f(x) + f(x-h)}{h^2} \)
    - **Example:** For \( f(x) = \cos x \) at \( x=0.75 \) with \( h=0.01 \), the approximation is \( f''(0.75) \approx -0.7300000 \), while the exact value is \( -\cos(0.75) = -0.7316888 \).

---

### **Lecture 10: Numerical Integration**

- **Trapezoidal Rule (2-point formula):**
    - \( I_t = (b-a) \frac{f(a) + f(b)}{2} \)
- **Composite Trapezoidal Rule:**
    - \( I_{ct} = \frac{h}{2} [f(a) + f(b)] + h \sum_{i=1}^{n-1} f(a+ih) \), where \( h = (b-a)/n \)
- **Simpson's 1/3 Rule (3-point formula):**
    - \( I_s = \frac{h}{3} [f(a) + 4f(\frac{a+b}{2}) + f(b)] \), with \( h = (b-a)/2 \)
- **Composite Simpson's 1/3 Rule (n even):**
    - \( I_{cs} = \frac{h}{3} [f(a) + 4\sum_{i=1}^{n/2} f(x_{2i-1}) + 2\sum_{i=1}^{n/2 - 1} f(x_{2i}) + f(b)] \)
    - **Example:** Compute \( \int_0^{\pi/2} \sqrt{\sin x} dx \) with \( n=4 \) and \( n=6 \).
        - For \( n=4 \), \( h=\pi/8 \), \( I_{cs} \approx 1.17823 \).
        - For \( n=6 \), \( h=\pi/12 \), \( I_{cs} \approx 1.18728 \).

---

### **Lecture 11: Numerical Solution of ODEs (Initial Value Problems)**

- **Euler's Method:**
    - **Formula:** \( y_{i+1} = y_i + h f(x_i, y_i) \)
- **Heun's Method (Predictor-Corrector):**
    - **Predictor (Euler):** \( y_{i+1}^e = y_i + h f(x_i, y_i) \)
    - **Corrector:** \( y_{i+1} = y_i + \frac{h}{2} [f(x_i, y_i) + f(x_{i+1}, y_{i+1}^e)] \)
    - **Example:** Solve \( y' = 2y/x \) with \( y(1)=2 \) to find \( y(2) \) using \( h=0.25 \).
        - Euler's method gives \( y(2) \approx 7.2 \), Heun's method gives \( y(2) \approx 7.86 \), while the analytical solution \( y=2x^2 \) gives 8.00. Heun's is more accurate.
- **Runge-Kutta 4th Order Method:**
    - **Formula:** \( y_{i+1} = y_i + \frac{1}{6}(m_1 + 2m_2 + 2m_3 + m_4)h \)
        - \( m_1 = f(x_i, y_i) \)
        - \( m_2 = f(x_i + h/2, y_i + m_1 h/2) \)
        - \( m_3 = f(x_i + h/2, y_i + m_2 h/2) \)
        - \( m_4 = f(x_i + h, y_i + m_3 h) \)
    - **Example:** Solve \( y' = x^2 + y^2 \) with \( y(0)=0 \) to find \( y(0.4) \) using \( h=0.2 \).
        - **Iteration 1 (to \( y(0.2) \)):** \( m_1=0, m_2=0.01, m_3=0.01, m_4=0.04 \). \( y(0.2) \approx 0.002667 \).
        - **Iteration 2 (to \( y(0.4) \)):** Using \( y(0.2) \), \( y(0.4) \approx 0.021360 \). The exact solution is 0.021359, showing high accuracy.

---

### **Lecture 12: Boundary Value and Eigenvalue Problems**

- **Shooting Method for BVPs:**
    - Converts a BVP into an IVP by guessing the initial slope. The guess is refined (e.g., by linear interpolation) until the solution matches the boundary condition at the other end.
    - **Example:** Solve \( \frac{d^2y}{dx^2} = 6x \) with \( y(1)=2, y(2)=9 \).
        - Convert to \( y'=z, z'=6x \).
        - Guess \( z(1)=2 \) → \( y(2) \approx 7.75 \) (too low).
        - Guess \( z(1)=4 \) → \( y(2) \approx 9.75 \) (too high).
        - Interpolate to get \( z(1)=3.25 \) → \( y(2)=9 \). The solution matches the exact \( y(x)=x^3+1 \).
- **Finite Difference Method for BVPs:**
    - Replaces derivatives with finite difference approximations to convert the ODE into a system of algebraic equations.
    - **Example:** Solve \( \frac{d^2y}{dx^2} = e^{x^2} \) with \( y(0)=0, y(1)=0 \), for \( x=0.25, 0.5, 0.75 \) using \( h=0.25 \).
        - Using \( y''_i \approx \frac{y_{i+1} - 2y_i + y_{i-1}}{h^2} \), we get a system of three equations.
        - Solving yields \( y(0.25) \approx -0.1175, y(0.5) \approx -0.1684, y(0.75) \approx -0.1391 \).
- **Eigenvalue Problem:**
    - Defined by \( Ax = \lambda x \).
- **Polynomial Method (Fadeev-Leverrier):**
    - Determines the coefficients of the characteristic polynomial \( \lambda^n - p_1 \lambda^{n-1} - \dots - p_n = 0 \).
    - **Example:** For the system from a previous example, the polynomial is \( \lambda^3 + 6\lambda^2 + 5\lambda = 0 \), giving eigenvalues \( 0, -1, -5 \).
- **Power Method:**
    - An iterative method to find the largest eigenvalue (dominant eigenvalue) and its corresponding eigenvector.
    - **Process:** \( Y = AX \), \( X = Y/k \), where \(k\) is the largest magnitude element in \(Y\).
    - **Example:** For a given matrix, starting with \( X = [2,1,0]^T \), the iterations converge to \( k = 3 \) (the largest eigenvalue) and \( X = [1,1,0]^T \) (the corresponding eigenvector).