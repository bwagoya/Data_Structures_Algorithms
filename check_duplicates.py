def duplicates(nums):
    # Use a set to keep track of unique elements
    unique_elements = set()

    # Iteration
    for num in nums:
        if num in unique_elements:
            return True
        else:
            unique_elements.add(num)

    return False

