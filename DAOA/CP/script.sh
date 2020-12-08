#! /bin/bash
i=5
while [ $i -le 1000 ]
do
    ./cannon $i >> cannon_data.txt
    i=$[$i+5]
    if [ $(( $i % 100)) -eq 0 ]
    then
        echo $i
    fi
done 