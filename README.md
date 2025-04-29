# 🧠 User-Level Virtual Memory Management in C

This project implements a user-space memory management system in C, designed to simulate virtual memory mechanisms typically handled by operating systems. It features a fully functional paging system, a custom memory allocator (`t_malloc`/`t_free`), and a translation lookaside buffer (TLB) with LRU eviction, along with support for internal fragmentation reduction.

---

## 📦 Features

- **Paging System Simulation**
  - Virtual to physical address translation using page directory and page tables
  - Dynamic calculation of address breakdown based on page size

- **TLB with LRU Replacement**
  - Caches address translations with least-recently-used eviction policy

- **Custom Memory Allocation**
  - `t_malloc()` and `t_free()` simulate memory allocation and deallocation
  - Bitmaps track available virtual and physical pages

- **Internal Fragmentation Support**
  - Multiple small allocations share memory pages efficiently
  - Allocations tracked per page to reduce wasted space

- **Data Access APIs**
  - `put_value()` and `get_value()` read/write data through translated virtual addresses

- **Configurable Page Sizes**
  - Page size can be changed via macros with no need to modify core logic

---

## 🧪 Benchmarking

The `benchmark/` folder contains tests to validate and evaluate performance:

- `test.c` – Basic test coverage
- `multi_test.c` – Stress test with large data structures and multithreading
- Includes analysis of TLB miss rates and memory usage

### Build Instructions

From root directory:
```bash
make  # Builds libvm.a


## 📓 Notes

- Written in **C**, compiled in **32-bit mode** (`-m32`)
- No external libraries required
- Designed for educational Operating System and systems programming projects