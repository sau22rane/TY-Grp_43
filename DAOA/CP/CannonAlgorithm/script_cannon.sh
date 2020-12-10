#! /bin/bash
i=4
while [ $i -le 1000 ]
do
    mpirun -n 4 ./cannon $i >> cannon_data.txt
    i=$[$i+4]
    if [ $(( $i % 100)) -eq 0 ]
    then
        echo $i
    fi
done 