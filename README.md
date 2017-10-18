# tptest
Just a small test program

make options:
```
user@host:~/tptest$ make
make help   - show this message
make all    - alternative for: foo large test
make foo    - build foo from sources
make large  - create large file for test
make test   - run test and output results to test.out
make clean  - delete all created files
make web    - run simple web service
```

test output (file test.out):
```
./foo -l > test.out

4096 ./
3024 foo.o
8944 foo
21 test.out
4096 ../
1228 foo.c
5368709120 large_file
999 web.py
35 README.md
1074 LICENSE
4096 .git/
430 .gitignore
792 makefile

./foo >> test.out

./
foo.o
foo
test.out
../
foo.c
large_file
web.py
README.md
LICENSE
.git/
.gitignore
makefile
```