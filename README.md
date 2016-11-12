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

Prédictions meteo (GFS). 
* Modifier la variable YYYYMMDD pour spécifier la date de calcul
* Modifier la variable FORECAST pour spécifier l'heure de prédiction (doit être un multiple de 3)

Téléchargé depuis: http://nomads.ncep.noaa.gov/