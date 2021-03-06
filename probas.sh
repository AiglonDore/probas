#This file is licenced under the GNU General Public License v3.0
#!/bin/bash
for i in $@
do
    if [ $i = "--docker" -o $i = "-d" ]; then
        docker run -d probas:latest --name probas_tools -it
        docker exec -it probas_tools /bin/bash
        docker stop probas_tools
        exit 0
    fi
done;
./bin/probas.out $@