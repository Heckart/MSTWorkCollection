if [[ "$#" -ne 2 ]]; then
    echo "Usage goog.sh WORD WEBSITE"
else
    wget -O download.txt "$2" --quiet
    grep -o "$1" download.txt > instances.txt
    RESULT=$(wc -l < instances.txt)
    echo ""$1": $RESULT"
    echo "" 
    exit 1
fi
