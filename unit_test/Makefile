CC = cc -Wall -Wextra -Werror

SRC_utils = $(wildcard utils/*.c)
OBJ_utils = $(patsubst %.c, obj/%.o, $(SRC_utils))
OUT_utils = $(patsubst %.c, out/%.out, $(SRC_utils))

all: $(OUT_utils)

out/%.out: obj/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $^ -L. ../src/lib/utils.a

# *** create object files. ***
# https://stackoverflow.com/questions/1950926/create-directories-using-make-file
obj/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

clean:
	rm -r -f out/
	rm -r -f obj/

re: clean
	make all

.PHONY: all clean re
