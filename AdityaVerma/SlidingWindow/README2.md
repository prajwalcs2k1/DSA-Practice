A good way to recognize a **sliding window problem** isn’t by memorizing patterns—it’s by spotting a *structure* in the problem.

Here’s a **general identification rule** you can rely on:

---

### 🔑 Core Identification Rule

If a problem involves:

> **A contiguous segment (subarray / substring) and you are asked to optimize or count something while moving across the array**

👉 then sliding window is *very likely* the right approach.

---

### 🧠 How to Think About It

Ask yourself these questions:

1. **Is the data linear?**
   (array / string / list — not trees, graphs)

2. **Does the problem talk about contiguous elements?**
   Words like:

   * subarray
   * substring
   * consecutive
   * continuous segment

3. **Are you asked to:**

   * find *maximum / minimum / longest / shortest*
   * count valid subarrays
   * maintain some condition dynamically

4. **Can you “expand and shrink” a range instead of recomputing from scratch?**
   If yes → sliding window fits.

---

### ⚡ The Real Trigger (Most Important Insight)

> If you feel:
> “I am repeatedly checking overlapping ranges, and doing redundant work”

➡️ Sliding window removes that redundancy.

---

### 🔍 Mental Model

Instead of:

* Checking every subarray independently (O(n²))

You:

* Maintain a **window [L, R]**
* Expand `R` → include new element
* Shrink `L` → remove invalid elements

So you're always working with a **moving range**, not restarting.

---

### 🚫 When NOT to Use Sliding Window

Be careful—don’t force it.

Sliding window usually **won’t work** when:

* Non-contiguous selection is allowed
* Order doesn’t matter
* Problem involves complex branching (like recursion, DP on subsets)
* Data structure is not linear (tree/graph)

---

### 🧩 Quick Recognition Shortcut

If the problem can be rephrased as:

> “Find something about a *range that moves step by step*”

→ That’s sliding window.

---

### 💡 One-Line Intuition

> Sliding window = **“Reuse previous work while moving a continuous range forward”**

---
