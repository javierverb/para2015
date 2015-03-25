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
EXT=$2
TEST=./test-fparser
TS=$(date +%s)
LOG=test-$TS.log
echo "Ejecutando tests sobre carpeta:" $FOLDER > $LOG
echo "Extension de las Formulas: *."$EXT >>$LOG
echo "-----------------------------------" >> $LOG
ok=0
fail=0
for f in $(find $FOLDER -type f -name "*.$EXT")
do	
	# obtenemos la fórmula a testear. Adding for the Vasquez-Verblud 
	chain="$(cat $f)"
	# End adding

    #obtenemos el resultado esperado 
    s=${f##*-}
    e=${s%.*}
    #ejecutamos la prueba
    m="$($TEST $f 2>&1)"
    o=$?
    mark=""
    #chequeamos el resultado contra lo esperado
    if [ $e -eq $o ];
    then
	ok=$((ok+1))
	mark=$GREEN_COLOUR
    else
	fail=$((fail+1))
	mark=$RED_COLOUR
    fi
    #logueamos el resultado
    echo -e $mark"ve:"$e" - vo:"$o" - output: "$m" \nformula: "$chain""$NC >> $LOG
done

echo "-----------------------------------" >> $LOG
echo "OK:" $ok " - ERROR:" $fail >> $LOG
echo "OK:" $ok " - ERROR:" $fail " - ARCHIVO LOG:" $LOG
cat $LOG
