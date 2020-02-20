#!/bin/bash

n=$1

mkdir out$n

./a.out < inputs/a_example.txt > out$n/a.out
./a.out < inputs/b_read_on.txt > out$n/b.out
./a.out < inputs/c_incunabula.txt > out$n/c.out
./a.out < inputs/d_tough_choices.txt > out$n/d.out
./a.out < inputs/e_so_many_books.txt > out$n/e.out
./a.out < inputs/f_libraries_of_the_world.txt > out$n/f.out
