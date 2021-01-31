#! /bin/bash
i=4
while [ $i -le 1000 ]
do
    ./simple_matrix $i >> simple_matrix_data.txt
    i=$[$i+4]
    if [ $(( $i % 100)) -eq 0 ]
    then
        echo $i
    fi
done 