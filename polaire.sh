#!/bin/bash
POLAIRE=polaires
IMOCA=$POLAIRE/imoca60
MULTI=$POLAIRE/maxi_trimaran


mkdir -p $IMOCA
mkdir -p $MULTI

curl 'http://static.virtualregatta.com/vpp/mono/imoca_60_new/vpp_1_1.csv?ver=5.9' -o $IMOCA/vpp_1_1.csv
curl 'http://static.virtualregatta.com/vpp/mono/imoca_60_new/vpp_1_2.csv?ver=5.9' -o $IMOCA/vpp_1_2.csv
curl 'http://static.virtualregatta.com/vpp/mono/imoca_60_new/vpp_1_4.csv?ver=5.9' -o $IMOCA/vpp_1_4.csv
curl 'http://static.virtualregatta.com/vpp/mono/imoca_60_new/vpp_1_8.csv?ver=5.9' -o $IMOCA/vpp_1_8.csv
curl 'http://static.virtualregatta.com/vpp/mono/imoca_60_new/vpp_1_16.csv?ver=5.9' -o $IMOCA/vpp_1_16.csv
curl 'http://static.virtualregatta.com/vpp/mono/imoca_60_new/vpp_1_32.csv?ver=5.9' -o $IMOCA/vpp_1_32.csv
curl 'http://static.virtualregatta.com/vpp/mono/imoca_60_new/vpp_1_64.csv?ver=5.9' -o $IMOCA/vpp_1_64.csv

curl 'http://static.virtualregatta.com/vpp/multi/maxi_trimaran/vpp_1_1.csv?ver=5.34' -o $MULTI/vpp_1_1.csv
curl 'http://static.virtualregatta.com/vpp/multi/maxi_trimaran/vpp_1_2.csv?ver=5.34' -o $MULTI/vpp_1_2.csv
curl 'http://static.virtualregatta.com/vpp/multi/maxi_trimaran/vpp_1_4.csv?ver=5.34' -o $MULTI/vpp_1_4.csv
curl 'http://static.virtualregatta.com/vpp/multi/maxi_trimaran/vpp_1_8.csv?ver=5.34' -o $MULTI/vpp_1_8.csv
curl 'http://static.virtualregatta.com/vpp/multi/maxi_trimaran/vpp_1_16.csv?ver=5.34' -o $MULTI/vpp_1_16.csv
curl 'http://static.virtualregatta.com/vpp/multi/maxi_trimaran/vpp_1_32.csv?ver=5.34' -o $MULTI/vpp_1_32.csv
curl 'http://static.virtualregatta.com/vpp/multi/maxi_trimaran/vpp_1_64.csv?ver=5.34' -o $MULTI/vpp_1_64.csv

echo "1 - foc">$POLAIRE/voiles.txt
echo "2 - spi">>$POLAIRE/voiles.txt
echo "4 - foc2">>$POLAIRE/voiles.txt
echo "8 - genois">>$POLAIRE/voiles.txt
echo "16 - code zéro">>$POLAIRE/voiles.txt
echo "32 - spi léger">>$POLAIRE/voiles.txt
echo "64 - gennaker">>$POLAIRE/voiles.txt

