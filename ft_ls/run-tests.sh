#!/bin/bash

rm Output-test.txt
rm Output-test-Recursion.txt
rm Output-test-Args.txt

echo "Running Tests..."
echo  "FT_LS Test Output\n\n" >> Output-test.txt
echo  "BASIC TESTS\n" >> Output-test.txt
echo  "BASIC TESTS\n"
echo  "   {FT_LS}\n" >> Output-test.txt
echo  "[================================]" >> Output-test.txt
echo  "	Std Ft_ls on current dir"
./ft_ls >> Output-test.txt
echo  "[================================]\n\n" >> Output-test.txt
echo  "   {LS}\n" >> Output-test.txt
echo  "[================================]" >> Output-test.txt
ls >> Output-test.txt
echo  "[================================]\n\n" >> Output-test.txt

echo  "   {FT_LS} -r\n" >> Output-test.txt
echo  "[================================]" >> Output-test.txt
echo "	Ft_ls -r on current dir"
./ft_ls -r >> Output-test.txt
echo  "[================================]\n\n" >> Output-test.txt
echo  "   {LS} -r \n" >> Output-test.txt
echo  "[================================]" >> Output-test.txt
ls  -r >> Output-test.txt
echo  "[================================]\n\n" >> Output-test.txt

echo  "   {FT_LS} -a\n" >> Output-test.txt
echo  "[================================]" >> Output-test.txt
echo "	Ft_ls -a on current dir"
./ft_ls -a >> Output-test.txt
echo  "[================================]\n\n" >> Output-test.txt
echo  "   {LS} -a \n" >> Output-test.txt
echo  "[================================]" >> Output-test.txt
ls  -a >> Output-test.txt
echo  "[================================]\n\n" >> Output-test.txt

echo  "   {FT_LS} -l\n" >> Output-test.txt
echo  "[================================]" >> Output-test.txt
echo "	Ft_ls -l on current dir"
./ft_ls -l >> Output-test.txt
echo  "[================================]\n\n" >> Output-test.txt
echo  "   {LS} -l \n" >> Output-test.txt
echo  "[================================]" >> Output-test.txt
ls  -l >> Output-test.txt
echo  "[================================]\n\n" >> Output-test.txt

echo  "   {FT_LS} -t\n" >> Output-test.txt
echo  "[================================]" >> Output-test.txt
echo "	Ft_ls -t on current dir"
./ft_ls -t >> Output-test.txt
echo  "[================================]\n\n" >> Output-test.txt
echo  "   {LS} -t \n" >> Output-test.txt
echo  "[================================]" >> Output-test.txt
ls  -t >> Output-test.txt
echo  "[================================]\n\n" >> Output-test.txt

echo  "   {FT_LS} -R\n" >> Output-test-Recursion.txt
echo  "[================================]" >> Output-test-Recursion.txt
echo "	Ft_ls -R on current dir"
./ft_ls -R >> Output-test-Recursion.txt
echo  "[================================]\n\n" >> Output-test-Recursion.txt
echo  "   {LS} -R \n" >> Output-test-Recursion.txt
echo  "[================================]" >> Output-test-Recursion.txt
ls  -R >> Output-test-Recursion.txt
echo  "[================================]\n\n" >> Output-test-Recursion.txt


echo "\nARGUMNET TESTS\n"
echo "	No Given Arguments"
echo  "   {FT_LS} -lart \n" >> Output-test-Args.txt
echo  "[================================]" >> Output-test-Args.txt
echo "	Ft_ls -lart\n"
./ft_ls -lart >> Output-test-Args.txt
echo  "[================================]\n\n" >> Output-test-Args.txt
echo  "   {LS} -lart \n" >> Output-test-Args.txt
echo  "[================================]" >> Output-test-Args.txt
ls  -lart >> Output-test-Args.txt
echo  "[================================]\n\n" >> Output-test-Args.txt

echo "	One Given Arguments"
echo  "   {FT_LS} -lart test\n" >> Output-test-Args.txt
echo  "[================================]" >> Output-test-Args.txt
echo "	Ft_ls -lart  on test\n"
./ft_ls -lart test >> Output-test-Args.txt
echo  "[================================]\n\n" >> Output-test-Args.txt
echo  "   {LS} -lart  on test\n" >> Output-test-Args.txt
echo  "[================================]" >> Output-test-Args.txt
ls  -lart test >> Output-test-Args.txt
echo  "[================================]\n\n" >> Output-test-Args.txt


echo "	Multiple Given Arguments"
echo  "   {FT_LS} -lart test test test src\n" >> Output-test-Args.txt
echo  "[================================]" >> Output-test-Args.txt
echo "	Ft_ls -lart  on test test test src\n"
./ft_ls -lart test test test src >> Output-test-Args.txt
echo  "[================================]\n\n" >> Output-test-Args.txt
echo  "   {LS} -lart  on test test test src\n" >> Output-test-Args.txt
echo  "[================================]" >> Output-test-Args.txt
ls  -lart test test test src >> Output-test-Args.txt
echo  "[================================]\n\n" >> Output-test-Args.txt

echo "	Multiple Given Arguments Recursive"
echo  "   {FT_LS} -lartR test src\n" >> Output-test-Recursion.txt
echo  "[================================]" >> Output-test-Recursion.txt
echo "	Ft_ls -lartR  on test src\n"
./ft_ls -lartR test src >> Output-test-Recursion.txt
echo  "[================================]\n\n" >> Output-test-Recursion.txt
echo  "   {LS} -lartR  on test src\n" >> Output-test-Recursion.txt
echo  "[================================]" >> Output-test-Recursion.txt
ls  -lartR test src >> Output-test-Recursion.txt
echo  "[================================]\n\n" >> Output-test-Recursion.txt



