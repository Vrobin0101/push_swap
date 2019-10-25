echo -n "pa\nrra\nra\nsha\n" > test && ARG="1 2 3 4 5 --" ; ./checker $ARG < test
./checker "-- --" et push
./checker --
