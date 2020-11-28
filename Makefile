all:
	g++ -std=c++17  main.cpp -I /opt/X11/include -L /opt/X11/lib -lX11 -ljpeg -lpng -lz
clean:
	rm a.out