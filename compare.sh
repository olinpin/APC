# how to use:
# ./compare.sh directoryWithData/ test.py
directory="$1"
filename="$2"
files=$(find $directory | grep -e "\.in$")
for entry in $files
do 
    ans="${entry%.*}.ans"
    solution=$(cat $ans)
    res=$(python3 $filename < $entry)
    if [ "$solution" = "$res" ]; then
        echo "COOL " $entry
    else
        echo "ERROR IN " $entry
    fi
done
