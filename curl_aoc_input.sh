#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "USAGE: $0 <year> <day>"
    exit 1
fi

YEAR=$1
DAY=$2

if [ -z "$AOC_SESSION" ]; then
    echo "ERROR: AOC_SESSION is not set. Please export it or pass it as an argument."
    exit 1
fi

URL="https://adventofcode.com/${YEAR}/day/${DAY}/input"

OUTPUT_FILE="day_${DAY}.txt"

HTTP_STATUS=$(curl -s -w "%{http_code}" -b "session=${AOC_SESSION}" "${URL}" -o "${OUTPUT_FILE}")

if [ "$HTTP_STATUS" -eq 200 ]; then
    echo "Input for Advent Of Code's day  ${DAY}, ${YEAR} saved to ${OUTPUT_FILE}."
else
    rm -f "${OUTPUT_FILE}"
    echo "ERROR: Failed to download input. Check your session cookie or internet connection."
    echo "USAGE: $0 <year> <day>"
    exit 1
fi
