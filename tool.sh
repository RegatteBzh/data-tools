#!/bin/bash

FOLDER=tmp
mkdir -p "${FOLDER}"
ORIG_FOLDER=`pwd`

cd "${FOLDER}"

# wgrib
curl "ftp://ftp.cpc.ncep.noaa.gov/wd51we/wgrib/wgrib.c" -o "wgrib.c"
gcc -o "${ORIG_FOLDER}/wgrib"" "wgrib.c

#wgrib2
curl "ftp://ftp.cpc.ncep.noaa.gov/wd51we/wgrib2/wgrib2.tgz" -o "wgrib2.tgz"
tar xf "wgrib2.tgz"
cd grib2
make
cp wgrib2/wgrib2 "${ORIG_FOLDER}/."
cp README "${ORIG_FOLDER}/README.wgrib2"

#bin2json
cd "${ORIG_FOLDER}"
cd bin2json-src
make
cp bin2json "${ORIG_FOLDER}/bin2json"

# Clean folders
cd "${ORIG_FOLDER}"
rm -rf "${FOLDER}"


rm -rf "${FOLDER}"