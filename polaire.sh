#!/bin/bash
FOLDER=polaire_imoca60

mkdir -p $FOLDER

curl 'http://static.virtualregatta.com/vpp/mono/imoca_60_new/vpp_1_1.csv?ver=5.9' -o $FOLDER/vpp_1_1.csv
curl 'http://static.virtualregatta.com/vpp/mono/imoca_60_new/vpp_1_2.csv?ver=5.9' -o $FOLDER/vpp_1_2.csv
curl 'http://static.virtualregatta.com/vpp/mono/imoca_60_new/vpp_1_4.csv?ver=5.9' -o $FOLDER/vpp_1_4.csv
curl 'http://static.virtualregatta.com/vpp/mono/imoca_60_new/vpp_1_8.csv?ver=5.9' -o $FOLDER/vpp_1_8.csv
curl 'http://static.virtualregatta.com/vpp/mono/imoca_60_new/vpp_1_16.csv?ver=5.9' -o $FOLDER/vpp_1_16.csv
curl 'http://static.virtualregatta.com/vpp/mono/imoca_60_new/vpp_1_32.csv?ver=5.9' -o $FOLDER/vpp_1_32.csv
curl 'http://static.virtualregatta.com/vpp/mono/imoca_60_new/vpp_1_64.csv?ver=5.9' -o $FOLDER/vpp_1_64.csv

echo "1 - foc">$FOLDER/voiles.txt
echo "2 - spi">>$FOLDER/voiles.txt
echo "4 - foc2">>$FOLDER/voiles.txt
echo "8 - genois">>$FOLDER/voiles.txt
echo "16 - code zéro">>$FOLDER/voiles.txt
echo "32 - spi léger">>$FOLDER/voiles.txt
echo "64 - gennaker">>$FOLDER/voiles.txt
