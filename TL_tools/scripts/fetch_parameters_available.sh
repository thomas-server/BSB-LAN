#!/bin/bash

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

# Function to log messages with timestamp
log() {
    color=$2
    echo -e "[${color}$(date '+%Y-%m-%d %H:%M:%S')${NC}] $1"
}


# Define the directory for storing results
result_dir="TL_tools/scripts/par_cat"

# Create result directory if it does not exist
if [[ ! -d "$result_dir" ]]; then
    mkdir -p "$result_dir"
    log "Created directory $result_dir for storing category files." "$GREEN"
fi

# Fetch and store the list of parameter categories
log "Starting the parameter fetch script." "$YELLOW"
log "Fetching list of parameter categories..." "$YELLOW"
curl -s http://192.168.1.11/JK=ALL -o "$result_dir/par_cat_available.json"

# Check if par_cat_available.json was created successfully
if [[ ! -f "$result_dir/par_cat_available.json" ]]; then
    log "Failed to fetch or create par_cat_available.json" "$RED"
    exit 1
else
    log "Successfully fetched and stored parameter categories in $result_dir/par_cat_available.json" "$GREEN"
fi

# Loop through each category and fetch details (same as before, with updated file paths)...
jq -c 'to_entries[]' "$result_dir/par_cat_available.json" | while IFS='' read -r entry; do
    cat_num=$(echo "$entry" | jq -r '.key')
    cat_name=$(echo "$entry" | jq -r '.value.name' | tr ' ' '_' | tr -d "'")
    file_name="${result_dir}/${cat_num}_${cat_name}.json"

    log "Fetching category : $cat_name" "$YELLOW"
    if curl -s "http://192.168.1.11/JK=$cat_num" -o "$file_name"; then
        log "Stored details for category $cat_num in $file_name" "$GREEN"
    else
        log "Failed to fetch details for category $cat_num" "$RED"
    fi
done

log "Parameter fetch script completed." "$GREEN"
