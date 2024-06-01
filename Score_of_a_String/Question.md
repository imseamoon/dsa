# Score of a String

You are given a string `s`. The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.

For example, given the string "abc", the score would be calculated as follows:

- The absolute difference between the ASCII values of 'a' and 'b' is 1.
- The absolute difference between the ASCII values of 'b' and 'c' is 1.
- The total score is 1 + 1 = 2.

Write a function `scoreOfString(s: str) -> int` that takes in a string `s` and returns its score.

## Example

Input: "abc"
Output: 2

Input: "xyz"
Output: 4

Input: "hello"
Output: 8
