HOME_DIR := $(shell echo ~)

CC = gcc
build_Path_Gameboard = $(HOME_DIR)/Documents/Code/Projects/Magic/Gameboard/build

build_Path_Connect = $(HOME_DIR)/Documents/Code/Projects/Magic/Contact/build
Contact_inlude = -I$(HOME_DIR)/Documents/Code/Projects/Magic/Contact/include


REQUEST_CARD = $(HOME_DIR)/Documents/Code/Projects/Magic/Contact/src/main/scryfall_request_card_data.c
TEST = $(HOME_DIR)/Documents/Code/Projects/Magic/Contact/src/test/test.c


cJson_Build_Flag = -lcjson
libcurl_build_flag = -lcurl

CONTACTLIBS = $(cJson_Build_Flag) $(libcurl_build_flag)

#complie scryfall_request_data
requestCardTestCompile : 
	$(CC) $(Contact_inlude) $(REQUEST_CARD) $(TEST) -o $(HOME_DIR)/Documents/Code/Projects/Magic/Contact/src/test/test $(CONTACTLIBS)

requestCardTest:
	$(HOME_DIR)/Documents/Code/Projects/Magic/Contact/src/test/./test