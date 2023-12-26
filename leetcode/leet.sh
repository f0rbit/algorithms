#!/bin/bash
ROOT_DIR=$(pwd)

# Function to list all files in numerical order
list_files() {
  find "${ROOT_DIR}" -type f -name '*.ts' | sort -t'-' -k1,1n | xargs -n 1 basename | sort -V
}

# Function to find a specific problem number
find_problem() {
  local problem_number="$1"
  local file_path=$(find "${ROOT_DIR}" -type f -name "${problem_number}-*.ts")
  
  if [ -n "${file_path}" ]; then
    echo "found @ ${file_path}"
    exit 0
  else
    echo "not found"
    exit 1
  fi
}

# Main script logic
if [ "$#" -eq 0 ]; then
  echo "Usage: $0 [--list | --find <problem_number>]"
  exit 1
fi

case "$1" in
  --list)
    list_files
    ;;
  --find)
    if [ "$#" -eq 2 ]; then
      find_problem "$2"
    else
      echo "Usage: $0 --find <problem_number>"
      exit 1
    fi
    ;;
  *)
    echo "Invalid option. Use --list or --find <problem_number>"
    exit 1
    ;;
esac
