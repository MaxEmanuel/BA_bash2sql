#!/bin/bash
# 2014-08-30
# misst die Ausführungsdauer und gibt sie in zeitquery.{csv,log} aus
echo Zeit für Querys messen
for i in `ls query*`; do
	echo -n "beginne $i; "
	echo -n $i >&2
	time ./$i | wc -l && echo $i ausgeführt
done 2>zeitquery.log
cat zeitquery.log  |  sed -r 'N; N; N; s/\n/|/g; s/\t/ /g' > zeitquery.csv

echo ende
