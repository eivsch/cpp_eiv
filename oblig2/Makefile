GPP=g++
GPPOPT=-std=c++11 -g
FLTK=-L/usr/local/lib -lfltk -lXfixes -lXext -lpthread -ldl -lm -lX11

OBJ=fireworks fireworks2

all: $(OBJ)

fireworks: classes
	$(GPP) $(GPPOPT) main.cpp has_color.o is_vector.o dot.o rocket.o animation_canvas.o fireworks.o -o fireworks $(FLTK)

fireworks2: classes
	$(GPP) $(GPPOPT) main.cpp has_color.o is_vector.o dot.o Factories.o rocket2.o animation_canvas.o fireworks2.o -o fireworks2 $(FLTK)

classes:
	$(GPP) $(GPPOPT) -c has_color.cpp is_vector.cpp dot.cpp rocket.cpp rocket2.cpp animation_canvas.cpp fireworks.cpp fireworks2.cpp Factories.cpp $(FLTK)

clean:
	rm *.o