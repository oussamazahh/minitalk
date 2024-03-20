#! /bin/bash
./client $(ps | grep server | awk 'NR==1{print$1}') "123456789"
