# SPOJ Problem Solutions in Python

This repository contains my Python solutions to programming problems from  SPOJ.
Each problem is implemented as a separate script.  
---

## 📂 Repository Structure

Currently, the repository contains:

### 📄 `swap_min_max.py`

**Problem code:** `PCPSWAPM - Swapping min and max`

---

## 📘 Problem Description

You are given a sequence of integers.  
Your task is to swap all occurrences of the minimum and maximum values in that sequence.

### 🔹 Input
- The first line contains one integer `N`, where `1 ≤ N ≤ 100`.
- The second line contains `N` integers, each between `-1000` and `1000`.

### 🔹 Output
- Print the modified sequence where:
  - Every occurrence of the **minimum value** is replaced with the **maximum value**.
  - Every occurrence of the **maximum value** is replaced with the **minimum value**.
  - All other numbers remain unchanged.

---

## ✅ Example 1

**Input**

5
0 8 5 8 0


**Output**

8 0 5 0 8


---

## ✅ Example 2

**Input**

6
-10 5 2 10 -10 3


**Output**

10 5 2 -10 10 3

---
