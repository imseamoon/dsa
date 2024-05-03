# frozen_string_literal: true

# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
    nums.each_with_index do |num, index|
        complement = target - num
        complement_index = nums.index(complement)
        return [index, complement_index] if complement_index && complement_index != index
    end
end

# Get space-separated numbers from command-line input and convert them into an array of integers
numbers = gets.chomp.split.map(&:to_i)

# Get target number from command-line input
target = gets.chomp.to_i

puts two_sum(numbers, target).inspect