#!/bin/bash

# Function to log messages with timestamp
log() {
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] $1"
}

# Define the directory for storing results
result_dir="par_cat"

# Create result directory if it does not exist
if [[ ! -d "$result_dir" ]]; then
    mkdir -p "$result_dir"
    log "Created directory $result_dir for storing category files."
fi

# Fetch and store the list of parameter categories
log "Starting the parameter fetch script."
log "Fetching list of parameter categories..."
curl -s http://192.168.1.90/JK=ALL -o par_cat_available.json

# Check if par_cat_available.json was created successfully
if [[ ! -f par_cat_available.json ]]; then
    log "Failed to fetch or create par_cat_available.json"
    exit 1
else
    log "Successfully fetched and stored parameter categories in par_cat_available.json"
fi

# Loop through each category and fetch details
# Extracting the numeric keys and corresponding names from the JSON
jq -c 'to_entries[]' par_cat_available.json | while IFS='' read -r entry; do
    cat_num=$(echo "$entry" | jq -r '.key')
    cat_name=$(echo "$entry" | jq -r '.value.name' | tr ' ' '_' | tr -d "'")
    file_name="${result_dir}/${cat_num}_${cat_name}.json"

    log "Fetching category : $cat_name"
    if curl -s "http://192.168.1.90/JK=$cat_num" -o "$file_name"; then
        log "Stored details for category $cat_num in $file_name"
    else
        log "Failed to fetch details for category $cat_num"
    fi
done

log "Parameter fetch script completed."
