#!/bin/bash

ARCHITECTURE=$(uname -a)
CPU_PHYSICAL=$(lscpu | grep "^CPU(s):" | awk '{print $2}')
VCPU=$(cat /proc/cpuinfo | grep -c "processor")
CPU_LOAD=$(echo "$(top -bn1 | grep "^%Cpu(s):" | awk '{print $2 + $4 + $6}')%")
LAST_BOOT=$(who -b | awk '{print $3, $4}')
CONNECTIONS_TCP=$(echo "$(netstat -ant | grep -c ESTABLISHED) ESTABLISHED")
USER_LOG=$(who | wc -l)
NETWORK=$(echo "IP $(hostname -I) ($(cat /sys/class/net/*/address | sed -n 1p))")
SUDO=$(echo "$(journalctl -q _COMM=sudo | grep -c "COMMAND") cmd")


# Memory Usage
RAM_USED_MEMORY=$(free -m | grep "^Mem:" | awk '{print $3}')
RAM_TOTAL_MEMORY=$(free -m | grep "^Mem:" | awk '{print $2}')
RAM_USED_PERCENT=$(echo "scale=2; $RAM_USED_MEMORY*100/$RAM_TOTAL_MEMORY" | bc)
MEMORY_USAGE=$(echo "$RAM_USED_MEMORY/$RAM_TOTAL_MEMORY"MB "($RAM_USED_PERCENT%)")


# Disk Usage
DISK_USED_MEMORY=0
DISK_TOTAL_MEMORY=0

for i in $(df -m | grep "^/dev/sd" | awk '{print $3}')
do
    DISK_USED_MEMORY=$((DISK_USED_MEMORY + i))
done

for j in $(df -m | grep "^/dev/sd" | awk '{print $2}')
do
    DISK_TOTAL_MEMORY=$((DISK_TOTAL_MEMORY + j))
done

DISK_USED_PERCENT=$(printf "%.0f" $(echo "scale=2; $DISK_USED_MEMORY*100/$DISK_TOTAL_MEMORY" | bc))

if [ $DISK_USED_MEMORY -ge 1024 ]
then
    DISK_USED_MEMORY=$(printf "%.0fGb" $(echo "scale=2; $DISK_USED_MEMORY/1024" | bc))
else
    DISK_USED_MEMORY=$(echo "$DISK_USED_MEMORY"Mb)
fi

DISK_TOTAL_MEMORY=$(printf "%.0fGb" $(echo "scale=2; $DISK_TOTAL_MEMORY/1024" | bc))
DISK_USAGE=$(echo "$DISK_USED_MEMORY/$DISK_TOTAL_MEMORY" "($DISK_USED_PERCENT%)")


# LVM use
LVM_USE=no

if [[ "$(lsblk)" == *"lvm"* ]]
then
    LVM_USE=yes
fi


wall "
    #Architecture: $ARCHITECTURE
    #CPU physical : $CPU_PHYSICAL
    #vCPU : $VCPU
    #Memory Usage: $MEMORY_USAGE
    #Disk Usage: $DISK_USAGE
    #CPU load: $CPU_LOAD
    #Last boot: $LAST_BOOT
    #LVM use: $LVM_USE
    #Connections TCP : $CONNECTIONS_TCP
    #User log: $USER_LOG
    #Network: $NETWORK
    #Sudo : $SUDO
"
