# Addressdata
Is a small c++ programm to collect addressdata. 

Author: Daniel Rhein 

Project started: 29.06.2018

Project end: --.--.--

## Programm commandline

```bash
addressdata <options> [<addressdata>|id]
```

## Options

| optionname | meaning | parameter | done |
|---|---|---|---|
| -a     | adding addressdata | comma separated address|*|
| -r     | remove addressdata | id of the addressdata |*|
| -s     | search for Addressdata | string you are searching for|*|
| -e     | edit an existing Address | id of the addressdata and new addressdata | * |
| -c     | count content of addressdata | none |*|
| -i     | interactively choose add remove or search for address | none|*|
| -a -i  | adding addressdata interactively | none |*|
| -r -i | remove interactively an address| none|*|
| -s -i | search for a string interactively | none |*|
| -e -i | edit interactivly an address | -- |

## Dataparameter 

| parametername | meaning | done |
|---|---|---|
| addressdata | data of an address | |
| id | id of the addressdata | none ||


## Addressdata
In germany the address data consists minimally of

* familyname
* name
* streetname
* housenumber
* ZIP
* city

In addition this programm will also take care of

* birthday 

as a part of the address.

### Addresdata-Example


```bash
addressdata -a Max,Mustermann,Musterstrasse,2,66531 Phantasiestadt,01.01.00 00:00:00
```

 
## Id 

Every data is currently saved in an CSV-File. Each line is counted up, starting with 1.
Saved addresses will identified by its line. 

### Id-Example


```bash
addressdata -r id
```


# Project status

In development

#Planned development steps and their status

| steps | features | status | task branch|
|---|---|---|---|
| -a -i | interactively add an address | done 26.07 | master/develop |
| -r -i | interactively remove an address | done 4.08 | task/r1 |
| -c    | count address content | done 04.08 | task/c1 |
| -s -i | interactively simple search of an address | done 15.08.2018 | task/s1 |  
| -e -i | edit an address | -- | task/edit1 | 
| -a | add an address | done 18.08.2018 | task/add1 |
| -r | remove an address | done 18.08.2018 | task/remove |
| -s | search an address | done 18.08.2018 | task/search | 
| -e | edit an address | done 22.09.2018 | task/edit |  
| clean up and refactoring | continuing 09.08.2018 | task/clean | 
| test | test sources | test |task/test|
| document | document sources | done 09.08.2018 | task/doxygen | 
| man-document | man documentation | man | task/man |
| cmd-gui | ncurses gui | cmd-gui | feature/cmd-gui |
| gui | gtk-gui | gtk-gui | feature/gtk-gui |
| database| db | db | feature/db |
| improved interpreder for commandline commands |--|--| feature/interpreter |
| show different banner |--| -- | feature/banner |