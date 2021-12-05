##
## EPITECH PROJECT, 2019
## Makefile
## File description:
##  Makefile
##

SRC	=	$(shell find src/ -name '*.c')

UNIT_SRC	=	$(SRC)

OBJ	=	$(SRC:.c=.o)

VAL_FLAG1	=	--track-origins=yes

VAL_FLAG2	=	--leak-check=full

VAL_FLAG3	=	--leak-cresolution=high

VAL_FLAG4	=	--track-fds=yes

VAL_FLAGS	=	$(VAL_FLAGS1) $(VAL_FLAGS2)

EXEC	=	fax_cli

LIB_PATH = $(shell pwd)
LIB_PATH = $(shell pwd)/../libs/myteams

CFLAGS	=	-g3 -luuid
LIBFLAGS	=	-I$(LIB_PATH) -L$(LIB_PATH)/ -Wl,-rpath=$(LIB_PATH) -lmyteams -ldl -fPIC
#LIBFLAGS	=	-L../libs/myteams -lmyteams -ldl -fPIC

all:	$(EXEC)

$(EXEC):	$(OBJ)
	@echo -e "\e[05;01;34m=====COMPILATION DE L'EXECUTABLE=====\e[00;01;34m"
	@echo -e $(LIB_PATH)
	gcc -o ../$(EXEC) $(OBJ) $(CFLAGS) $(LIBFLAGS)

%.o:	%.c
	@echo -e "\e[05;01;32m=====COMPILATION DES .O EN .C=====\e[00;01;32m"
	gcc -o $@ -c $< $(CFLAGS) $(LIBFLAGS)

test_run:	$(UNIT_SRC)
		gcc -o unit_test $(UNIT_SRC) --coverage -lcriterion
		./unit_test
		gcovr --exclude ./tests
		gcovr --exclude ./tests --branches
deb:
	@echo -e "\e[05;01;36m=====COMPILATION EN MODE DEBUG =====\e[00;01;36m"
	gcc $(SRC) -g3
	@echo -e "\e[00;00m"

clean:
	@echo -e "\e[05;01;35m=====SUPPRESSION DES .O=====\e[00;01;35m"
	rm -f $(OBJ)

fclean:	clean
	@echo -e "\e[05;01;31m=====SUPPRESSION DE L'EXECUTABLE=====\e[00;01;31m"
	rm -f ../$(EXEC)

re: fclean all
