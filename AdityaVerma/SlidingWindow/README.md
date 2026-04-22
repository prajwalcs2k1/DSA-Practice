# Sliding Window Templates

## 1) Fixed Size Sliding Window (`k` is constant)

Use when subarray/substring length is exactly `k`.

### Generic Steps
1. Take two pointers: `i = 0`, `j = 0`.
2. Keep a running window state (like `sum`, `freq map`, `max/min`, etc.).
3. Expand with `j` until window size becomes `k`.
4. When window size is `k`:
   - Update answer.
   - Remove contribution of `arr[i]` from state.
   - Move `i++`, `j++` (slide by 1).

### Template (C++-style pseudocode)
```cpp
int i = 0, j = 0;
auto state = ...;   // sum/freq/deque/etc.
auto ans = ...;     // best result

while (j < n) {
    // add arr[j] to state

    if (j - i + 1 < k) {
        j++;
    } else if (j - i + 1 == k) {
        // evaluate answer using current state

        // remove arr[i] from state
        i++;
        j++;
    }
}
```

Time: `O(n)` (usually), Space: depends on maintained state.

---

## 2) Variable Size Sliding Window

Use when window length is not fixed and depends on condition:
- longest/shortest subarray with condition,
- at most/exactly `k` distinct chars,
- sum `>= target`, sum `<= k`, etc.

### Generic Steps
1. Start with `i = 0`, `j = 0`.
2. Expand window by moving `j` and updating state.
3. While condition is invalid, shrink from left (`i++`) and clean state.
4. Whenever condition is valid, update answer (max length / min length / count).

### Template (C++-style pseudocode)
```cpp
int i = 0, j = 0;
auto state = ...;
auto ans = ...;

while (j < n) {
    // add arr[j] to state

    while (/* window invalid */) {
        // remove arr[i] from state
        i++;
    }

    // now window is valid
    // update answer using (j - i + 1) or current state

    j++;
}
```

Time: `O(n)` (each pointer moves at most `n` times), Space: depends on state.

---

## Quick Rule of Thumb
- Fixed size question with exact `k` -> fixed sliding window.
- Max/min length under condition -> variable sliding window.
