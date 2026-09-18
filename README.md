# Challenge AACACP2

This repository contains two C implementations of the approximation of π using OpenMP parallelization.

## Objective

The program computes an approximate value of π using the integral formula:

$$
\pi \approx \sum_{i=0}^{N-1} \frac{4}{1 + x_i^2} \cdot \Delta x
$$

where:

- $N$ is the number of steps
- $x_i = (i + 0.5) \cdot \Delta x$
- $\Delta x = \frac{1}{N}$

The algorithm is executed in parallel with OpenMP to reduce computation time as the number of steps and threads increases.

## Repository structure

- `code/non_ottimizzata.c` — version with manual workload distribution across threads
- `code/ottimizzata.c` — optimized version using `reduction` and a parallel `for` loop

## How to compile

Make sure you have a GCC compiler with OpenMP support installed.

### Linux / macOS

```bash
gcc -fopenmp code/non_ottimizzata.c -lm -o non_ottimizzata
gcc -fopenmp code/ottimizzata.c -lm -o ottimizzata
```

### Windows (MinGW / MSYS2)

```bash
gcc -fopenmp code/non_ottimizzata.c -lm -o non_ottimizzata.exe
gcc -fopenmp code/ottimizzata.c -lm -o ottimizzata.exe
```

## How to run

```bash
./non_ottimizzata
./ottimizzata
```

or on Windows:

```bash
non_ottimizzata.exe
ottimizzata.exe
```

## Main parameters

The files contain two global variables that control the computation:

- `num_threads`: number of threads to use
- `num_steps`: number of steps used to approximate the integral

Example:

```c
int num_threads = 4;
long long num_steps = 10000000;
```

You can modify these values directly in the code to test different performance and precision scenarios.

## Expected output

The program prints:

- the approximation of π
- number of threads
- number of steps
- total execution time
- total parallel computation time

An example output is similar to:

```text
Approximation of pi: 3.1415926535897931
Number of threads: 4
Number of steps: 10000000
Total execution time: 0.123456
Total parallel computation time: 0.045678
```

## Notes

- The optimized version is generally simpler and more maintainable.
- The main difference between the two versions is how the final result is reduced and how work is assigned to threads.
- The value obtained gets closer to π as the number of steps increases.

## Author

Project developed as an OpenMP parallelization challenge in C.
