#!/bin/bash

echo "Top 10 processes in descending order (by memory usage):"
ps -eo pid,ppid,cmd,%mem,%cpu --sort=-%mem | head

echo -e "\nProcesses with highest memory usage:"
ps aux --sort=-%mem | head

echo -e "\nCurrent logged in user:"
logname

echo -e "\nCurrent shell is:"
echo $SHELL

echo -e "\nHome directory is:"
echo $HOME

echo -e "\nCurrent path is:"
echo $PATH

echo -e "\nCurrent working directory is:"
pwd

echo -e "\nCurrent OS version, release number, and kernel version:"
uname -a
