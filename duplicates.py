def remove_duplicates(input_array):
    unique_digits = 1  # Index for the unique elements

    # Iterate through the array starting from the second element
    for current_index in range(1, len(input_array)):
        # Compare the current element with the previous unique element
        if input_array[current_index] != input_array[unique_digits - 1]:
            # Update the unique element and move the unique index forward
            input_array[unique_digits] = input_array[current_index]
            unique_digits += 1

    # The unique_end now represents the length of the array without duplicates
    return unique_digits
