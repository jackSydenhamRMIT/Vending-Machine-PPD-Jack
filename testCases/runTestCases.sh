#!/bin/bash

cd ..
make


#REQ2 TESTS
./ppd stock.dat coins.dat < ./testCases/ppdTestREQ2.input > ./testCases/ppdTestREQ2.actual_ppd_out
diff -w ./testCases/ppdTestREQ2.output ./testCases/ppdTestREQ2.actual_ppd_out
diff -w -y ./testCases/ppdTestREQ2.expcoins ./coins.dat

#REQ3 TESTS
./ppd stock.dat coins.dat < ./testCases/ppdTestREQ3.input > ./testCases/ppdTestREQ3.actual_ppd_out
diff -w ./testCases/ppdTestREQ3.output ./testCases/ppdTestREQ3.actual_ppd_out
diff -w -y ./testCases/ppdTestREQ3.expcoins ./coins.dat

#REQ4 TESTS
./ppd stock.dat coins.dat < ./testCases/ppdTestREQ4.input > ./testCases/ppdTestREQ4.actual_ppd_out
diff -w ./testCases/ppdTestREQ4.output ./testCases/ppdTestREQ4.actual_ppd_out
diff -w -y ./testCases/ppdTestREQ4.expcoins ./coins.dat

#REQ5 TESTS
./ppd stock.dat coins.dat < ./testCases/ppdTestREQ5.input > ./testCases/ppdTestREQ5.actual_ppd_out
diff -w ./testCases/ppdTestREQ5.output ./testCases/ppdTestREQ5.actual_ppd_out
diff -w -y ./testCases/ppdTestREQ5.expcoins ./coins.dat

#REQ6 TESTS
./ppd stock.dat coins.dat < ./testCases/ppdTestREQ6.input > ./testCases/ppdTestREQ6.actual_ppd_out
diff -w ./testCases/ppdTestREQ6.output ./testCases/ppdTestREQ6.actual_ppd_out
diff -w -y ./testCases/ppdTestREQ6.expcoins ./coins.dat

#REQ7 TESTS
./ppd stock.dat coins.dat < ./testCases/ppdTestREQ7.input > ./testCases/ppdTestREQ7.actual_ppd_out
diff -w ./testCases/ppdTestREQ7.output ./testCases/ppdTestREQ7.actual_ppd_out
diff -w -y ./testCases/ppdTestREQ7.expcoins ./coins.dat

#REQ8 TESTS
./ppd stock.dat coins.dat < ./testCases/ppdTestREQ8.input > ./testCases/ppdTestREQ8.actual_ppd_out
diff -w ./testCases/ppdTestREQ8.output ./testCases/ppdTestREQ8.actual_ppd_out
diff -w -y ./testCases/ppdTestREQ8.expcoins ./coins.dat

#REQ9 TESTS
./ppd stock.dat coins.dat < ./testCases/ppdTestREQ9.input > ./testCases/ppdTestREQ9.actual_ppd_out
diff -w ./testCases/ppdTestREQ9.output ./testCases/ppdTestREQ9.actual_ppd_out
diff -w -y ./testCases/ppdTestREQ9.expcoins ./coins.dat

#REQ10 TESTS
./ppd stock.dat coins.dat < ./testCases/ppdTestREQ10.input > ./testCases/ppdTestREQ10.actual_ppd_out
diff -w ./testCases/ppdTestREQ10.output ./testCases/ppdTestREQ10.actual_ppd_out
diff -w -y ./testCases/ppdTestREQ10.expcoins ./coins.dat

#REQ11 TESTS
./ppd stock.dat coins.dat < ./testCases/ppdTestREQ11.input > ./testCases/ppdTestREQ11.actual_ppd_out
diff -w ./testCases/ppdTestREQ11.output ./testCases/ppdTestREQ11.actual_ppd_out
diff -w -y ./testCases/ppdTestREQ11.expcoins ./coins.dat

#REQ12 TESTS
./ppd stock.dat coins.dat < ./testCases/ppdTestREQ12.input > ./testCases/ppdTestREQ12.actual_ppd_out
diff -w ./testCases/ppdTestREQ12.output ./testCases/ppdTestREQ12.actual_ppd_out
diff -w -y ./testCases/ppdTestREQ12.expcoins ./coins.dat



