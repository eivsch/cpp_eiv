GPP=g++
GPPOPT=-std=c++11 -g
FLTK=-L/usr/local/lib -lfltk -lXfixes -lXext -lpthread -ldl -lm -lX11

OBJ=fireworks

all: $(OBJ)

fireworks: classes
	$(GPP) $(GPPOPT) main.cpp has_color.o is_vector.o dot.o rocket.o animation_canvas.o fireworks.o -o fireworks $(FLTK)

classes:
	$(GPP) $(GPPOPT) -c has_color.cpp is_vector.cpp dot.cpp rocket.cpp animation_canvas.cpp fireworks.cpp $(FLTK)


#g++ -std=c++11 main.cpp has_color.o is_vector.o animated.o dot.o rocket.o animation_canvas.o fireworks.o -o fireworks_TEST -L/usr/local/lib -lfltk -lXfixes -lXext -lpthread -ldl -lm -lX11
