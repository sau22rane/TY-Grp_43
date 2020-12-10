#! /bin/bash
i=504
while [ $i -le 600 ]
do
    ./strassen $i >> strassen_data.txt
    i=$[$i+4]
    if [ $(( $i % 100)) -eq 0 ]
    then
        echo $i
    fi
done 