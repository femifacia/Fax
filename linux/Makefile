##
## EPITECH PROJECT, 2019
## Makefile
## File description:
##  Makefile
##

UNIT_SRC	=	$(SRC)

VAL_FLAG1	=	--track-origins=yes

VAL_FLAG2	=	--leak-check=full

VAL_FLAG3	=	--leak-cresolution=high

VAL_FLAG4	=	--track-fds=yes

VAL_FLAGS	=	$(VAL_FLAGS1) $(VAL_FLAGS2)

BIN1	=	myteams_cli

BIN2	=	myteams_server

all:	$(BIN1)	$(BIN2)

$(BIN1):
	@echo -e "\e[05;01;34m=====COMPILATION DU CLIENT=====\e[00;01;34m"
	make -s -C ./client
	@echo -e "\e[05;01;34m=====CLIENT COMPILÉ =====\e[00;01;34m"
$(BIN2):
	@echo -e "\e[05;01;34m=====COMPILATION DU SERVER=====\e[00;01;34m"
	make -s -C ./server
	@echo -e "\e[05;01;34m=====SERVER COMPILÉ=====\e[00;01;34m"

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
	make clean -s -C ./client
	make clean -s -C ./server

fclean:	clean
	@echo -e "\e[05;01;31m=====SUPPRESSION DE L'EXECUTABLE=====\e[00;01;31m"
	make fclean -s -C ./client
	make fclean -s -C ./server
	rm -f $(BIN1)
	rm -f $(BIN2)
	

re: fclean all
