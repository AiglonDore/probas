# This file is licenced under the GNU General Public License v3.0
foreach ($item in %*)
{
    if ($($item -eq '--docker' -or $item -eq '-d'))
    {
        docker run -d probas:latest --name probas_tools -it
        docker exec -it probas_tools /bin/bash
        docker stop probas_tools
        exit 0
    }
}
.\bin\probas.exe %*
