all:
	@echo "Building NYASH"
	gcc -o nyash main.c commands/*.c processor/*.c utils/*.c
	@echo "Success"