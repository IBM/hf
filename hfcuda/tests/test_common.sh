color_none="\033[0m"    
color_green="\033[0;32m"
color_red="\033[0;31m"  
pad0=-15
pad1=-30

function pretty_print {
    code=$1
    shift

    if [ ${code} -eq 0 ]; then
        echo -e ${color_green}"[  OK  ]"${color_none}
    else
        echo -e ${color_red}"[ FAIL ]"${color_none}
        for file in $@; do
            cat ${file} | xargs -i echo "    {}"
        done
    fi
}

