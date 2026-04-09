# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    git.install.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kadferna <kadferna@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/10 00:00:56 by kadferna          #+#    #+#              #
#    Updated: 2026/04/10 00:24:43 by kadferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
cub="./cub3D"
BRIGHT_BLACK='\033[1;30m'
BRIGHT_RED='\033[1;31m'
BRIGHT_GREEN='\033[1;32m'
BRIGHT_YELLOW='\033[1;33m'
BRIGHT_BLUE='\033[1;34m'
BRIGHT_MAGENTA='\033[1;35m'
BRIGHT_CYAN='\033[1;36m'
BRIGHT_WHITE='\033[1;37m'

RESET='\033[0m'

if ! command -v git >/dev/null 2>&1
then
    echo -e "${BRIGHT_RED}Git is not installed.${RESET}"
    echo -e "${BRIGHT_YELLOW}Try: sudo apt install git -y${RESET}"
    exit 1
fi

echo -e "${BRIGHT_YELLOW}Cloning the repositary!${RESET}"
git clone https://github.com/murdex5/cub3D.git
exit_code=$?
if [ ! $? -eq 0 ]; then
    echo -e "${BRIGHT_RED}Something went wrong with cloning the repositary!${RESET}"
    echo -e "${BRIGHT_YELLOW}Try checking your internet connection or your git instilation.${RESET}"
    echo -e "${BRIGHT_YELLOW}Git version: $(git --version).${RESET}"
    echo -e "${BRIGHT_YELLOW}Git exit code: $exit_code${RESET}"
    exit 1
fi

if [ ! -d "$cub"  ]; then
    echo -e "${BRIGHT_RED}Something wrong with the repositary!${RESET}"
    echo -e "${BRIGHT_YELLOW}Try an alternative installation method.${RESET}"
    echo -e "${BRIGHT_MAGENTA}Like manually cloning the repositary and running the ./install.sh file.${RESET}"
    exit 1
fi

cd $cub
bash ./install.sh
