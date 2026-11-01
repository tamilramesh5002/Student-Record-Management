CC = gcc
CFLAGS = -Wall -g

TARGET = student

SRC = main.c stud_add.c stud_del.c stud_show.c stud_mod.c stud_save.c stud_sort.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
		gcc $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c
		gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
