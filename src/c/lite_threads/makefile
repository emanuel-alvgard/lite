.PHONY: all ltp ltw ltp-r ltw-r

all:

ltp:
	clang -std=c11 test_lite_threads_posix.c -o test_lite_threads_posix
ltw:
	clang -std=c11 test_lite_threads_win32.c -o test_lite_threads_win32

ltp-r: 
	./test_lite_threads_posix
ltw-r: 
	./test_lite_threads_win32