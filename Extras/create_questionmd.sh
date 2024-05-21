#!/bin/bash

for dir in */; do
  if [[ "$dir" != "./" ]]; then
    touch "$dir/Question.md"
  fi
done

echo "Question.md files created in subdirectories."
