#This file is licenced under the GNU General Public License v3.0
#!/bin/bash
for $str in $@; do
    if [ $str = "--docker" -o $str = "-d" ]; then
        #docker run -d probas:latest --name probas_tools -it
        exit 0
    fi
done;
./bin/probas.out $@