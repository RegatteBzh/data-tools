# Recupération des données

## build.sh

Récupération des données côtières

## polaire.sh

Récupération des polaires pour imoca 60
* 1 => foc
* 2 => spi
* 4 => foc2
* 8 => genois
* 16 => code zéro
* 32 => spi léger
* 64 => gennaker

## weather.sh

Prédictions meteo (GFS). 
* Modifier la variable YYYYMMDD pour spécifier la date de calcul
* Modifier la variable FORECAST pour spécifier l'heure de prédiction (doit être un multiple de 3)

Téléchargé depuis: http://nomads.ncep.noaa.gov/

Des outils: http://www.nco.ncep.noaa.gov/pmb/codes/GRIB2/