def find_single_number(nums):
    result = 0
    for num in nums:
        result ^= num
    return result

# Example usage
array_with_single_number = [1,3,3,64,5,64,5]
single_number = find_single_number(array_with_single_number)
print("Single number:", single_number)