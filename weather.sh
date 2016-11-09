#!/bin/bash

FOLDER=weather
DEST=build

YYYYMMDD=20161108
#YYYYMMDD=<a date, for example: 20140101>

FORECAST=000
#FORECAST=<3 digit hour forecast; must be a multiple of 3>

FILE=gfs.t00z.pgrb2.1p00.f${FORECAST}

rm -rf $FOLDER
mkdir -p $FOLDER
mkdir -p $DEST

curl "http://nomads.ncep.noaa.gov/cgi-bin/filter_gfs_1p00.pl?file=${FILE}&lev_10_m_above_ground=on&var_UGRD=on&var_VGRD=on&leftlon=0&rightlon=360&toplat=90&bottomlat=-90&dir=%2Fgfs.${YYYYMMDD}00" -o $FOLDER/${FILE}

#curl "http://nomads.ncep.noaa.gov/cgi-bin/filter_gfs_1p00.pl?file=gfs.t12z.pgrb2.1p00.f000&lev_10_m_above_ground=on&var_UGRD=on&var_VGRD=on&leftlon=0&rightlon=360&toplat=90&bottomlat=-90&dir=%2Fgfs.2016110812" -o $FOLDER/gfs.t00z.pgrb2.1p00.f000
#curl "http://nomads.ncep.noaa.gov/cgi-bin/filter_gfs.pl?file=gfs.t00z.pgrb2.1p00.f000&lev_10_m_above_ground=on&var_UGRD=on&var_VGRD=on&dir=%2Fgfs.${YYYYMMDD}00" -o $FOLDER/gfs.t00z.pgrb2.1p00.f000

#grib2json -d -n -o $DEST/current-wind-surface-level-gfs-1.0.json $FOLDER/gfs.t00z.pgrb2.1p00.f000
