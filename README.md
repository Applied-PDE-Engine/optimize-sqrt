# Optimize-Sqrt (`custom_sqrt`)

A lightweight, header-only C++ implementation for approximating square roots using the **Binary Search (Bisection)** algorithm, developed under **Applied-PDE-Engine**.

## 🔭 Overview

`custom_sqrt` provides a customizable approach to computing square roots without relying on external math libraries like `<cmath>`. By leveraging C++ templates, it allows developers to balance execution speed and numerical accuracy by controlling floating-point precision, iteration limits, and error tolerance—making it ideal for physics simulations, numerical solvers, and embedded systems.

## ⚙️ Function Signature & Parameters

```cpp
template <typename number = float, typename integer = unsigned short>
number custom_sqrt(number __l, integer max_attemps = 10, number __eq = 0.01)
```

### Template Parameters
* **`number`** *(default: `float`)*: The floating-point data type used for input, internal calculations, and the returned square root (e.g., `float`, `double`, `long double`).
* **`integer`** *(default: `unsigned short`)*: The integer type used for counting iterations in the bisection loop (e.g., `unsigned short`, `int`, `size_t`).

### Function Parameters
* **`__l`** *(Required)*: The non-negative target number whose square root you want to calculate ($x \geq 0$).
* **`max_attemps`** *(Optional, default: `10`)*: The maximum number of bisection iterations allowed. Increasing this value improves accuracy at the cost of execution time.
* **`__eq`** *(Optional, default: `0.01`)*: The error tolerance ($\epsilon$). The algorithm stops early if the squared approximation falls within this margin of error relative to the target value.

## 🚀 Installation & Usage

Since this is a **header-only** library, no compilation or CMake build step is required.

1. **Clone the repository:**
   ```bash
   git clone https://github.com/Applied-PDE-Engine
   ```

2. **Include the header in your C++ project:**
   Copy `sqrt_function.h` into your project directory and include it:
   ```cpp
   #include <iostream>
   #include "sqrt_function.h"

   int main() {
       // 1. Default usage (float, 10 iterations, 0.01 tolerance)
       float res1 = custom_sqrt(25.0f);

       // 2. High-precision usage (double, 50 iterations, 1e-6 tolerance)
       double res2 = custom_sqrt<double, int>(2.0, 50, 0.000001);

       std::cout << "Result 1: " << res1 << "\n";
       std::cout << "Result 2: " << res2 << "\n";
       return 0;
   }
   ```

## 📄 License

This project is open-source and available under the MIT License.
