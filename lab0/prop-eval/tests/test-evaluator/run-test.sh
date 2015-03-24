#!/bin/bash

# Adding by the Vasquez-Verblud group for intuitive testing
RED_COLOUR="\x1b[31m"
GREEN_COLOUR="\x1b[32m"
NC='\033[0m' # No Color
MAX_LOGS=5

# Evitamos llenarnos de logs al testear
totalLogs=0
for logs in *.log; do
	totalLogs=$((totalLogs+1))
done

if [ $totalLogs -gt $MAX_LOGS ]; then
	echo "TotalLogs is:" $totalLogs "then remove old logs "
	rm *.log
fi
# End adding

FOLDER=$1
TEST=./test-eval
TS=$(date +%s)
LOG=test-$TS.log
echo "Ejecutando tests sobre carpeta:" $FOLDER > $LOG
echo "-----------------------------------" >> $LOG
ok=0
fail=0
for f in $(find $FOLDER -type f -name "*.frm")
do

	g=$(basename $f)
	p=${g%.*}
	for a in $(find $FOLDER -type f -name "$p-*.asg")
	do
	#obtenemos el resultado esperado 
	s=${a##*-}
	e=${s%.*}

	#ejecutamos la prueba
	m="$($TEST $f $a 2>&1)"
	mark=""
	# chequeamos el resultado contra lo esperado
	if [ "$e" = "$m" ];
	then
			ok=$((ok+1))
			mark=$GREEN_COLOUR

	else
			fail=$((fail+1))
			mark=$RED_COLOUR
	fi
	# logueamos el resultado
	echo -e $mark"ve:"$e" - vo:"$m " - formula:"$g " - asg:"$(basename $a)$NC   >> $LOG

	done
done

 echo "-----------------------------------" >> $LOG
 echo "OK:" $ok " - ERROR:" $fail >> $LOG
 cat $LOG
# 
