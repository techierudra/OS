#!/bin/bash

echo "Enter the first number: "
read num1

echo "Enter the second number: "
read num2

echo "Enter the third number: "
read num3

max=$num1

if [ $num2 -gt $max ]; then
    max=$num2
fi

if [ $num3 -gt $max ]; then
    max=$num3
fi

echo "The greatest number is $max"
