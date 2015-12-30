#!/bin/bash
# a speed test to compare the different command line tools

function alles {
	cat partsupp.csv > tmp1.csv
	cat partsupp.tbl | sort -t\| -k1,1 >> tmp1.csv
	cat part.csv > tmp2.csv
	cat part.tbl | sort -t\| -k1,1 >> tmp2.csv
	join --header -t\| tmp1.csv tmp2.csv > tmpj1.csv
}

function geschnitten {
	cut partsupp.csv -d\| -f1 > tmp1.csv
	cut partsupp.tbl -d\| -f1 | sort -t\| -k1,1 >> tmp1.csv
	cut part.csv -d\| -f1 > tmp2.csv
	cut part.tbl -d\| -f1 | sort -t\| -k1,1 >> tmp2.csv
	join --header -t\| tmp1.csv tmp2.csv > tmpj2.csv
}

function geschnitten2 {
	cut partsupp.csv -d\| -f1 > tmp1.csv
	cut partsupp.tbl -d\| -f1 | sort >> tmp1.csv
	cut part.csv -d\| -f1 > tmp2.csv
	cut part.tbl -d\| -f1 | sort >> tmp2.csv
	join --header -t\| tmp1.csv tmp2.csv > tmpj3.csv
}

function pipegeschnitten {
	cut partsupp.tbl -d\| -f1 | sort -t\| -k1,1 |\
	cut -d\| -f1 partsupp.csv - > tmp1.csv
	cut part.tbl -d\| -f1 | sort -t\| -k1,1 |\
	cut -d\| -f1 part.csv - |\
	join --header -t\| tmp1.csv - > tmpj4.csv
}

function pipecat {
	cat partsupp.tbl | sort -t\| -k1,1 |\
	cat partsupp.csv - > tmp1.csv
	cat part.tbl | sort -t\| -k1,1 |\
	cat part.csv - |\
	join --header -t\| tmp1.csv - > tmpj5.csv
}
function pipecatcut {
	cat partsupp.tbl | sort -t\| -k1,1 |\
	cut -d\| -f1 partsupp.csv - > tmp1.csv
	cat part.tbl | sort -t\| -k1,1 |\
	cut -d\| -f1 part.csv - |\
	join --header -t\| tmp1.csv - > tmpj6.csv
}

function pipecuttee {
	cut partsupp.tbl -d\| -f1 | sort -t\| -k1,1 |\
	cut -d\| -f1 partsupp.csv - > tmp1.csv
	cut part.tbl -d\| -f1 | sort -t\| -k1,1 |\
	cut -d\| -f1 part.csv - | tee tmp2.csv |\
	join --header -t\| tmp1.csv - > tmpj7.csv
}

function pipepipe {
	mkfifo tmpfifo.csv
	(cut partsupp.tbl -d\| -f1 | sort -t\| -k1,1 |\
	cut -d\| -f1 partsupp.csv - > tmpfifo.csv) &
	cut part.tbl -d\| -f1 | sort -t\| -k1,1 |\
	cut -d\| -f1 part.csv - |\
	join --header -t\| tmpfifo.csv - > tmpj8.csv
}

function pipestattpipe {
#	mkfifo tmpfifo.csv
	cut partsupp.tbl -d\| -f1 | sort -t\| -k1,1 |\
	cut -d\| -f1 partsupp.csv - > tmp1.csv
	(cut part.tbl -d\| -f1 | sort -t\| -k1,1 |\
	cut -d\| -f1 part.csv - >tmpfifo.csv) &
	join --header -t\| tmp1.csv tmpfifo.csv > tmpj8.csv
}

function nocat {
#	mkfifo tmpfifo.csv
	sort -t\| -k1,1 partsupp.tbl |\
	cut -d\| -f1 partsupp.csv - > tmpfifo.csv &
	sort -t\| -k1,1 part.tbl |\
	cut -d\| -f1 part.csv - |\
	join --header -t\| tmpfifo.csv -  > tmpj8.csv
}

function nocatonepipe {
#	mkfifo tmpfifo.csv
	sort -t\| -k1,1 partsupp.tbl |\
	cut -d\| -f1 partsupp.csv - > tmp1.csv
	sort -t\| -k1,1 part.tbl |\
	cut -d\| -f1 part.csv - |\
	join --header -t\| tmp1.csv - > tmpj8.csv
}

echo -n time alles
time alles
wc -l tmpj1.csv
echo -n time geschnitten
time geschnitten
wc -l tmpj2.csv
echo -n time geschnitten2
time geschnitten2
wc -l tmpj3.csv
echo -n time pipegeschnitten
time pipegeschnitten
wc -l tmpj4.csv
echo -n time pipecat
time pipecat
wc -l tmpj5.csv
echo -n time pipecatcut
time pipecatcut
wc -l tmpj6.csv
echo -n time pipecuttee
time pipecuttee
wc -l tmpj7.csv
echo -n time pipepipe
time pipepipe
echo -n time pipestattpipe
time pipestattpipe
echo -n time nocat
time nocat
echo -n time nocatonepipe
time nocatonepipe
rm tmp*.csv
