# Recupération des données

## relief.sh

Récupération des données côtières et les lacs

## polaire.sh

Récupération des polaires pour imoca 60
* 1 => foc
* 2 => spi
* 4 => foc2
* 8 => genois
* 16 => code zéro
* 32 => spi léger
* 64 => gennaker

## tools.sh

Téléchargement et compilation de wgrib2 (ftp://ftp.cpc.ncep.noaa.gov/wd51we/wgrib2/)
voir aussi: http://www.nco.ncep.noaa.gov/pmb/codes/GRIB2/

## weather.sh

Lancer ``./tools.sh`` au préalable

lancer ``./weather.sh 20161113`` (avec YYYYMMDD pour spécifier la date de calcul)

Téléchargé depuis: http://nomads.ncep.noaa.gov/

Pour chaque forecast, un fichier csv et un fichier bin est généré. A priori, pour lire le fichier bin:

1. On saute les 4 premiers octets (toujours égals à 20 fa 03 00) 
2. puis, on a la liste des UGRD (dans l'ordre du CSV) [0,-90], [1, -90], ... [360, 90]
3. les mesures sont des floats (4 octets par mesure)

En latitude on couvre de -90 à +90
En longitude, on couvre de 0 à 180 puis de -179 à -1 (soit de 0 à 359)

Nombre de points : 181 x 360
Taille d'une mesure : 4 (float)
Deux composantes : 2

Il y a 521280 octets de données. Le fichier bin fait 521296; il y a donc 16 octets qui ne sont pas des données.

### UGRD / VGRD
DIRECTION=57.29578*(arctangent(UGRD,VGRD))+180. 
SPEED=SQRT(UGRD x UGRD + VGRD x VGRD) 

In essence, the UGRD is the North/South wind component (North is + & South is -) 
and VGRD is the East/West wind component (East is + West is - [I think...]).
UGRD représente la composante du vent zonal en m/s
VGRD représente la composante du vent méridien en m/s

# Calcul vitesse

http://www.csgnetwork.com/degreelenllavcalc.html