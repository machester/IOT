#!/bin/bash
echo "---------- start  in 2 seconds --------"
sleep 2s
echo "---------- clean *.o ------------------"
rm -vf `find ./ -name "*.o"`
sleep 2s
echo "---------- clean build folder ---------"
rm -rvf `find ./ -name build`
sleep 2s
echo "---------- clean *.old ---------"
rm -vf `find ./ -name *.old`
