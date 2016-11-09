#!/bin/bash

FOLDER=weather
DEST=build

YYYYMMDD=20161108
#YYYYMMDD=<a date, for example: 20140101>

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
    fi
done

#mkdir -p $DEST
#grib2json -d -n -o $DEST/current-wind-surface-level-gfs-1.0.json $FOLDER/gfs.t00z.pgrb2.1p00.f000
