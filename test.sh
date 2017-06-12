#!/bin/bash

export LD_PRELOAD=./my_malloc.so

./a.out
