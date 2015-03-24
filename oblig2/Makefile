GPP=g++
GPPOPT=-std=c++11
FLTK=-L/usr/local/lib -lfltk -lXfixes -lXext -lpthread -ldl -lm -lX11

OBJ=fireworks

all: $(OBJ)

fireworks: classes
	$(GPP) $(GPPOPT) main.cpp has_color.o is_vector.o animated.o 
					 dot.o rocket.o animation_canvas.o 
					 fireworks.o -o fireworks $(FLTK)

classes:
	$(GPP) $(GPPOPT) -c has_color.cpp $(FLTK)
	$(GPP) $(GPPOPT) -c is_vector.cpp $(FLTK)
	$(GPP) $(GPPOPT) -c animated.cpp $(FLTK)
	$(GPP) $(GPPOPT) -c dot.cpp $(FLTK)
	$(GPP) $(GPPOPT) -c rocket.cpp $(FLTK)
	$(GPP) $(GPPOPT) -c animation_canvas.cpp $(FLTK)
	$(GPP) $(GPPOPT) -c fireworks.cpp $(FLTK)


#g++ -std=c++11 main.cpp has_color.o is_vector.o animated.o dot.o rocket.o animation_canvas.o fireworks.o -o fireworks_TEST -L/usr/local/lib -lfltk -lXfixes -lXext -lpthread -ldl -lm -lX11
