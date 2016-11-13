#!/bin/bash

YYYYMMDD=20161108
#YYYYMMDD=<a date, for example: 20140101>

FOLDER=weather
WGRIB=./wgrib2
BINJSON=./bin2json
DATE_REGEX="^[0-9]{8}$"

if [[ $1 =~ $DATE_REGEX ]];
then
    echo "Date is OK."
    YYYYMMDD=`echo $1`
else
    echo "Date $1 must be YYYYMMDD format."
    exit 1
fi

if [ -f "$WGRIB" ]
then
	echo "$WGRIB found."
else
	echo "$WGRIB not found. Please launch './tools.sh' before"
    exit 1
fi

if [ -f "$BINJSON" ]
then
	echo "$BINJSON found."
else
	echo "$BINJSON not found. Please launch './tools.sh' before"
    exit 1
fi

#FORECAST=<3 digit hour forecast; must be a multiple of 3>

rm -rf $FOLDER
mkdir -p $FOLDER


for i in `seq 0 3 384`; do 
    FORECAST=$(printf "%03d" $i)
    FILE=gfs.t00z.pgrb2.1p00.f${FORECAST}
    echo "==== $FILE ===="
    curl "http://nomads.ncep.noaa.gov/cgi-bin/filter_gfs_1p00.pl?file=${FILE}&lev_10_m_above_ground=on&var_UGRD=on&var_VGRD=on&leftlon=0&rightlon=360&toplat=90&bottomlat=-90&dir=%2Fgfs.${YYYYMMDD}00" -o $FOLDER/${FILE}
    actualsize=`wc -c <$FOLDER/${FILE}`
    minimumsize=1000
    echo "$minimumsize $actualsize"
    if [ $minimumsize -ge $actualsize ]
    then
        rm -f $FOLDER/${FILE}
    else
        ${WGRIB} $FOLDER/${FILE} -bin $FOLDER/${FILE}.bin
        ${WGRIB} $FOLDER/${FILE} -csv $FOLDER/${FILE}.csv
        ${BINJSON} $FOLDER/${FILE}.bin >$FOLDER/${FILE}.json
    fi
done

#mkdir -p $DEST
#grib2json -d -n -o $DEST/current-wind-surface-level-gfs-1.0.json $FOLDER/gfs.t00z.pgrb2.1p00.f000
