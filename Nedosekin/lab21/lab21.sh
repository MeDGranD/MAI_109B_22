#!/bin/bash

while [ -n "$1" ]
do
case "$1" in
    -f) file_to_copy="$2"
    shift ;;
    -n) num_copies="$2"
    shift ;;
    --) shift
    break ;;
    *) echo "$1 is not an option";;
esac
shift
done


#cheking for file
if [ -f  "$file_to_copy" ];
then

#generation
for i in $(seq 1 $num_copies)
do
cp $file_to_copy $file_to_copy$i
done

else
echo "file not found"
fi


