# Merge Strings Alternately

You are given two strings `word1` and `word2`. Merge the strings by adding letters in alternating order, starting with `word1`. If one of the strings is longer than the other, append the remaining letters onto the end of the merged string.

Return the merged string.

**Example 1:**

Input: `word1 = "abc", word2 = "def"`
Output: `"adbecf"`
Explanation: The merged string will be `"a" + "d" + "b" + "e" + "c" + "f"`.

**Example 2:**

Input: `word1 = "ab", word2 = "pqrs"`
Output: `"apbqrs"`
Explanation: The merged string will be `"a" + "p" + "b" + "q" + "r" + "s"`.

**Example 3:**

Input: `word1 = "abcd", word2 = "efgh"`
Output: `"aebfcgdh"`
Explanation: The merged string will be `"a" + "e" + "b" + "f" + "c" + "g" + "d" + "h"`.

**Constraints:**

- `1 <= word1.length, word2.length <= 100`
- `word1` and `word2` consist of lowercase English letters.
