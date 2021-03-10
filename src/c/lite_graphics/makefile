.PHONY: all lgw lgm lgl lgw-r lgm-r lgl-r

all:
#-L/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks -l/Quartz.framework
lgw:
	clang -std=c11 test_lite_graphics_windows.c -o test_lite_graphics_windows
lgm:
	clang -std=c11 test_lite_graphics_macos.c -v -o test_lite_graphics_macos
lgl:
	clang -std=c11 test_lite_graphics_linux.c -o test_lite_graphics_linux
lgw-r:
	./test_lite_graphics_windows
lgm-r:
	./test_lite_graphics_macos
lgl-r:
	./test_lite_graphics_linux