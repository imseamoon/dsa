#!/bin/bash

# Function to create nested directories
create_directories() {
    local depth=$1
    local count=$2
    local base_dir=$3

    # Create directories based on depth and count
    for ((i=1; i<=depth; i++)); do
        for ((j=1; j<=count; j++)); do
            dir_name="${base_dir}/dir_${i}_${j}"
            mkdir -p "$dir_name"
            base_dir="$dir_name"
        done
    done
}

# Prompt user for depth and count
read -p "Enter the depth of the directory trap: " depth
read -p "Enter the count of directories at each level: " count

# Create the directory trap
base_dir="/home/moon_byte/Documents/programs/code/Extras/dir_trap"
create_directories "$depth" "$count" "$base_dir"

echo "Directory trap created successfully!"