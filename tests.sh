#!/bin/bash

# Define the expected output for each test case
expected_output_1="zero dollars"
expected_output_2="one dollar"
expected_output_3="five dollars and twenty-five cents"
expected_output_4="twelve dollars and ten cents"
expected_output_5="one hundred twenty-three dollars and forty-five cents"
expected_output_6="one thousand dollars and ninety-nine cents"
expected_output_7="nine hundred ninety-nine million nine hundred ninety-nine thousand nine hundred ninety-nine dollars and ninety-nine cents"

# Function to run the tests
run_test() {
    input=$1
    expected_output=$2

    echo "Running input: $input"
    result=$(./cache_money "$input")
    
    if [ "$result" == "$expected_output" ]; then
        echo "Test Passed!"
    else
        echo "Test Failed!"
        echo "Expected: $expected_output"
        echo "Got: $result"
    fi
    echo "-------------------------------------"
}

# Run the test cases

run_test 0.00 "$expected_output_1"
run_test 1.00 "$expected_output_2"
run_test 5.25 "$expected_output_3"
run_test 12.10 "$expected_output_4"

echo "All tests completed!"
