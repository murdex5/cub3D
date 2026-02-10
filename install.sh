# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    install.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kadferna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/26 12:05:49 by kadferna          #+#    #+#              #
#    Updated: 2026/02/10 08:30:09 by kadferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

mlx="./mlx"
BRIGHT_BLACK='\033[1;30m'
BRIGHT_RED='\033[1;31m'
BRIGHT_GREEN='\033[1;32m'
BRIGHT_YELLOW='\033[1;33m'
BRIGHT_BLUE='\033[1;34m'
BRIGHT_MAGENTA='\033[1;35m'
BRIGHT_CYAN='\033[1;36m'
BRIGHT_WHITE='\033[1;37m'

RESET='\033[0m'

# -r will remove the binary
if [ "$1" = "-r" ]; then
    make -s fclean
    echo -e "${BRIGHT_GREEN}Cub3D is removed.${RESET}"
    exit 0
fi

# Checking the requiremtns
if command -v git > /dev/null 2>&1; then
    echo -e "${BRIGHT_GREEN}Git is installed.${RESET}"
    echo -e "${BRIGHT_YELLOW}Git version: $(git --version).${RESET}"
else
    echo -e "${BRIGHT_RED}Git is not installed.${RESET}"
    echo -e "${BRIGHT_YELLOW}Please install Git to your device.${RESET}"
    exit 1
fi

if command -v gcc > /dev/null 2>&1; then
    echo -e "${BRIGHT_GREEN}Gcc is installed.${RESET}"
    echo -e "${BRIGHT_YELLOW}Gcc version: $(git --version).${RESET}"
else
    echo -e "${BRIGHT_RED}Gcc is not installed.${RESET}"
    echo -e "${BRIGHT_YELLOW}Trying to install gcc${RESET}"
    sudo apt install gcc -y
    echo -e "${BRIGHT_GREEN}Gcc is installed.${RESET}"
fi

# Pulling the mlx lib from linux

if [ -d "$mlx"  ]; then
    echo -e "${BRIGHT_CYAN}mlx directory exists.Checking if it's a valid git repository...${RESET}"
    
    if [ -d "$mlx/.git" ]; then
        echo -e "${BRIGHT_CYAN}mlx is already a git repository nothing to do.${RESET}"
    else 
        echo -e "${BRIGHT_CYAN}mlx exists but not a git repository${RESET}"
        echo -e "${BRIGHT_YELLOW}Removing existing directory and cloning fresh...${RESET}"
        rm -rf "$mlx"
        git clone https://github.com/42paris/minilibx-linux.git mlx
    fi
else
    echo -e "${BRIGHT_CYAN}mlx does not exists.${RESET}"
    echo -e "${BRIGHT_CYAN}Cloning mlx from github...${RESET}"
    git clone https://github.com/42paris/minilibx-linux.git mlx
fi

# Compiling the prgrame
echo -e "${BRIGHT_YELLOW}Compiling the programme...${RESET}"
make -s all
if [ $? -ne 0  ]; then
    echo -e "${BRIGHT_YELLOW}Make all failed with exit code: $? ${RESET}"
    echo -e "${BRIGHT_RED}Failed to compile the programme.${RESET}"
    exit 1
else
    echo -e "${BRIGHT_YELLOW}Removing the object files...${RESET}"
    make -s clean
    if [ $? -ne 0  ]; then
        echo -e "${BRIGHT_YELLOW}Make cleam failed with exit code: $? ${RESET}"
        echo -e "${BRIGHT_RED}Failed to clean the object files.${RESET}"
        exit 1
    else
        echo -e "${BRIGHT_BLUE}================================================${RESET}"
        echo -e "${BRIGHT_GREEN}           Cub3D is ready to run!              ${RESET}"
        echo -e "${BRIGHT_BLUE}================================================${RESET}"

        echo -e "Command: ${BRIGHT_CYAN}./cub3D ./path_to_the_map${RESET}"
    fi
fi
