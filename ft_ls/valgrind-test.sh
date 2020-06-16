#!/bin/bash

rm valgrind-out.txt

valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --show-reachable=yes --verbose --gen-suppressions=all --log-file=valgrind-out.txt ./ft_ls