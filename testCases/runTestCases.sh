#!/bin/bash

cd ..
make
./ppd stock.dat coins.dat < ./testCases/ppdTestREQ1.input > ./testCases/ppdTestREQ1.actual_ppd_out
./ppd stock.dat coins.dat < ./testCases/ppdTestREQ2.input > ./testCases/ppdTestREQ2.actual_ppd_out
./ppd stock.dat coins.dat < ./testCases/ppdTestREQ3.input > ./testCases/ppdTestREQ3.actual_ppd_out
./ppd stock.dat coins.dat < ./testCases/ppdTestREQ4.input > ./testCases/ppdTestREQ4.actual_ppd_out
./ppd stock.dat coins.dat < ./testCases/ppdTestREQ5.input > ./testCases/ppdTestREQ5.actual_ppd_out
./ppd stock.dat coins.dat < ./testCases/ppdTestREQ6.input > ./testCases/ppdTestREQ6.actual_ppd_out
./ppd stock.dat coins.dat < ./testCases/ppdTestREQ7.input > ./testCases/ppdTestREQ7.actual_ppd_out