# addressdata
small c++ programm to collect addressdata 
Author daniel rhein 29.06.2018

#Mode
addressdata <options> [<addressdata>|count]

## Options

| option | meaning | parameter |
|---|---|---|
| -a     | adding addressdata | comma seperated address|
| -r     | remove addressdata | id of the addressdata |
| -s     | search for Addressdata | string you are searching for|
| -c     | count content of addressdata | count the amount of addressdata |
| -i     | interactively choose add remove or search for address | none|
| -a -ii  | adding addressdata interactively | adding addressdata interatively |
| -r -i | remove interactively an address| none|
| -s -i | search for a string interactively | none |
    
# Project status
In development

#Planned steps
| steps | features | status | task branch|
|=======|==========|========|============|
| -a -i | interactively add an address | done 26.07 | master/develop |
| -r -i | interactively add an address | r1 | task/r1 |
| -s -i | interactively add an address | s | task/s1 |  
| -a | interactively add an address | add | task/add1 |
| -r | interactively add an address | remove | task/remove |
| -s | interactively add an address | search | task/search |
| test | test sources | test |task/test|
| document | document sources | doxygen | task/doxygen | 
| man-document | man documentation | man | task/man |
| cmd-gui | ncurses gui | cmd-gui | feature/cmd-gui |
| gui | gtk-gui | gtk-gui | feature/gtk-gui |
| database| db | db | feature/db |