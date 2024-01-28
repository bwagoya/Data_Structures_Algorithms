def summation(nums):
    return sum(nums)

def maximum(nums):
    return max(nums)

def main():

    n = int(input("Enter the length of the array: "))

    integer_array = []

    for i in range(n):
        num = int(input(f"Enter integer {i+1}: "))
        integer_array.append(num)

    sum_result = summation(integer_array)
    max_result = maximum(integer_array)

    print(f"Sum of the integers: {sum_result}")
    print(f"Largest integer in the array: {max_result}")

if __name__ == "__main__":
    main()