# frozen_string_literal: true

def anagram?(first, second)
  return false if first.length != second.length
  
  # Initialize an array to hold the count of characters
  char_count = Array.new(256, 0)
  
  # Count occurrences of characters in the first string
  first.each_byte { |ch| char_count[ch] ||= 0; char_count[ch] += 1 }
  
  # Decrement the count for characters in the second string
  second.each_byte { |ch| char_count[ch] ||= 0; char_count[ch] -= 1 }
  
  # If all counts are zero, the strings are anagrams
  char_count.all? { |count| count.zero? }
end


string = gets.chomp.split(' ')
print(anagram?(string[0], string[1]))
