def calculate_checksum(data):
    # Initialize checksum to zero
    checksum = 0

    # Iterate over each byte in the data
    for byte in data:
        # Add the byte value to the checksum
        checksum += byte

        # Ensure the checksum doesn't exceed 8 bits
        checksum &= 0xFF

    # Return the calculated checksum
    return checksum


def add_checksum(data):
    # Calculate the checksum for the given data
    checksum = calculate_checksum(data)

    # Add the checksum to the end of the data
    data.append(checksum)

    # Return the data with the added checksum
    return data


def verify_checksum(data):
    # Extract the checksum from the last byte of the data
    received_checksum = data[-1]

    # Remove the checksum from the data
    data_without_checksum = data[:-1]

    # Calculate the checksum for the remaining data
    calculated_checksum = calculate_checksum(data_without_checksum)

    # Compare the calculated checksum with the received checksum
    return calculated_checksum == received_checksum


# Example usage:
original_data = [0x01, 0x02, 0x03, 0x04, 0x05]
data_with_checksum = add_checksum(original_data)

# Simulate transmission by introducing an error in the received data
received_data_with_error = original_data.copy()
received_data_with_error[2] = 0xAA  # Introducing an error

# Verify checksum for the received data
checksum_verification_result = verify_checksum(received_data_with_error)

print("Original Data:", original_data)
print("Data with Checksum:", data_with_checksum)
print("Received Data with Error:", received_data_with_error)
print("Checksum Verification Result:", checksum_verification_result)
