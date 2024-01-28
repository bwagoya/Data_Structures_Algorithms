def rotate_array(nums, k):
    n = len(nums)
    k = k % n

    # Reverse the entire array
    reverse_array(nums, 0, n - 1)

    # Reverse the first k elements
    reverse_array(nums, 0, k - 1)

    # Reverse the remaining elements
    reverse_array(nums, k, n - 1)

    return nums


def reverse_array(nums, start, end):
    while start < end:
        nums[start], nums[end] = nums[end], nums[start]
        start += 1
        end -= 1
