# Optimize-Sqrt (`sqrt_game`)

A lightweight, header-only C++ implementation for approximating square roots using the **Binary Search (Bisection) algorithm**, developed under **Applied-PDE-Engine**.

---

## 🚀 Overview

`sqrt_game` provides a customizable approach to computing square roots without relying on external math libraries like `<cmath>`. By leveraging C++ templates, it allows developers to balance execution speed and numerical accuracy by controlling floating-point precision, iteration limits, and error tolerance—making it ideal for real-time applications like game engines and physics simulations.

## ✨ Key Features

* **Generic & Templated:** Supports customizable floating-point types (`float`, `double`, `long double`) and integer counters.
* **Configurable Precision:** Control the trade-off between speed and accuracy using `max_attemps` and error tolerance (`__eq`).
* **Zero Dependencies:** Pure C++ implementation with no external libraries required.
* **Edge-Case Safe:** Properly handles `0` inputs and fractional values between `0` and `1` by dynamically adjusting the upper search bound.

---

## ⚖️ Philosophy: Approximation Over Exact Precision

> **"If it looks right and runs at 60+ FPS, it is right."** — Core GameDev Principle

By design, `sqrt_game` **does not produce mathematically exact results** when run with low iteration counts (e.g., the default `max_attemps = 10`). Instead, it embraces a fundamental principle of game engineering and real-time graphics:

* **Good Enough is Optimal:** In video games, an error margin of `0.01` or `0.05` in a character's distance, lighting falloff, or particle velocity is completely invisible to the human eye.
* **Predictable Frame Budgets:** Standard library functions compute full IEEE-754 precision even when it isn't needed. `sqrt_game` lets you cap the CPU budget per call, trading unnecessary mathematical perfection for higher frame rates.
* **Scalable When Needed:** While tailored for fast game approximations, increasing `max_attemps` and switching to `double` allows the same function to scale up for stricter physics or PDE requirements.

---

## 🎮 Applications in GameDev & Physics

In real-time engines and numerical solvers, square root calculations are executed thousands of times per frame. `sqrt_game` allows you to tune accuracy based on the critical nature of each task:

### 1. Game Development (GameDev)
* **Euclidean Distance Checks:** Calculating distances between players, enemies, or projectiles for AI aggro ranges and trigger zones.
* **Vector Normalization:** Normalizing movement directions and surface normals for lighting and shading calculations.
* **Level of Detail (LOD) & Culling:** Estimating camera-to-object distances to switch mesh resolutions where a rough approximation (`max_attemps = 6..10`) is sufficient and saves frame time.

### 2. Physics & PDE Simulations
* **Collision Detection & Response:** Computing penetration depths and impulse magnitudes between rigid bodies and bounding spheres.
* **Particle Systems & Forces:** Evaluating inverse-square laws (e.g., gravity, electrostatic forces) and spring-damper tensions.
* **PDE Numerical Solvers:** Calculating CFL (Courant–Friedrichs–Lewy) stability conditions, wave propagation speeds ($c = \sqrt{T/\rho}$), and vector field magnitudes across grid cells using higher precision (`double`, `max_attemps = 40+`).

---

## 🧠 How It Works

The function uses the **Bisection Method** to narrow down the interval $[ \text{min\_value}, \text{max\_value} ]$ where $\sqrt{x}$ lies:

1. **Bounds Initialization:**
   * If $x = 0$, the function returns `0` immediately.
   * Sets the search range to $[0, \max(x, 1)]$ to ensure numbers in $(0, 1)$ are bounded properly (since $\sqrt{x} > x$ for $0 < x < 1$).
2. **Iterative Bisection:**
   * Computes the midpoint: $m = \frac{\text{min} + \text{max}}{2}$.
   * Compares $m^2$ against the target $x$ to halve the search space in each iteration.
3. **Termination:**
   * Stops early once the error falls within the tolerance threshold (`__eq`) or when `max_attemps` is reached.

---

## 🛠️ Getting Started

### Prerequisites

* A C++ compiler supporting **C++11 or later** (GCC, Clang, or MSVC).

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com
   ```
2. Include the header file containing `sqrt_game` in your project.

---

## 💻 Usage

```cpp
#include <iostream>
#include "optimize_sqrt.hpp" // Replace with your actual header filename

int main() {
    // 1. Fast GameDev approximation (imprecise, but fast and visually indistinguishable)
    float distSq = 144.0f;
    std::cout << "Distance ≈ " << sqrt_game(distSq, 8, 0.05f) << '\n';

    // 2. High-precision Physics/PDE calculation
    double tension_over_density = 2.0;
    double wave_speed = sqrt_game<double, unsigned int>(tension_over_density, 50, 1e-7);
    std::cout << "Wave speed = " << wave_speed << '\n';

    // 3. Fractional value between 0 and 1 (e.g., normalized vector component)
    float val3 = 0.25f;
    std::cout << "sqrt(" << val3 << ") = " << sqrt_game(val3) << '\n';

    return 0;
}
```

### Function Parameters

| Parameter | Type | Default | Description |
| :--- | :--- | :---: | :--- |
| `__l` | `number` (`float`) | *Required* | The non-negative input value to find the square root of. |
| `max_attemps` | `integer` (`unsigned short`) | `10` | Maximum number of binary search iterations. |
| `__eq` | `number` (`float`) | `0.01` | Acceptable error margin for early termination. |

---

## 🤝 Contributing

Contributions, performance benchmarks, and optimization ideas are welcome! Feel free to open an issue or submit a pull request.

## 📄 License

This project is open-source under the **Applied-PDE-Engine** organization.
