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
| -a     | adding addressdata | comma seperated address||
| -r     | remove addressdata | id of the addressdata ||
| -s     | search for Addressdata | string you are searching for||
| -c     | count content of addressdata | none |*|
| -i     | interactively choose add remove or search for address | none|*|
| -a -i  | adding addressdata interactively | none |*|
| -r -i | remove interactively an address| none|*|
| -s -i | search for a string interactively | none |*|

## Dataparameter 

| parametername | meaning | done |
|---|---|---|
| addressdata | data of an address | |
| id | id of the addressdata | none ||


## Addressdata
In germany the address data consists minimally of

* Familyname
* Name
* Streetname
* Housenumber
* ZIP
* CITY

In addition this programm will also take care of

* Birthday 

as a part of the address.
 
## Id 

Every data is currently saved in an CSV-File. Each line is counted up, starting with 1.
Saved addresses will identified by its line. 

# Project status
In development

##Planned development steps and their status

| steps | features | status | task branch|
|---|---|---|---|
| -a -i | interactively add an address | done 26.07 | master/develop |
| -r -i | interactively remove an address | done 4.08 | task/r1 |
| -c    | count address content | done 04.08 | task/c1 |
| -s -i | interactively simple search of an address | done 15.08.2018 | task/s1 |  
| -a | interactively add an address | add | task/add1 |
| -r | interactively remove an address | remove | task/remove |
| -s | interactively search an address | search | task/search | 
| clean up and refacotring | clean code and refactoring | task/clean | 
| test | test sources | test |task/test|
| document | document sources | doxygen | task/doxygen | 
| man-document | man documentation | man | task/man |
| cmd-gui | ncurses gui | cmd-gui | feature/cmd-gui |
| gui | gtk-gui | gtk-gui | feature/gtk-gui |
| database| db | db | feature/db |
