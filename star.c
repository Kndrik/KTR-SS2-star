#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isNumber(char string[]);
void drawStar(int size);
void drawTip(int size);
void drawLine(int size);
void drawInside(int size);
void drawReverseTip(int size);

int main(int argc, char* argv[])
{
	if (argc != 2) {
		printf("star only takes one argument size.\n");
		return -1;
	}

	if (argc == 2 && !isNumber(argv[1])) {
		printf("Argument size must be a positive number.\n");
	}

	if (isNumber(argv[1])) {
		int size = atoi(argv[1]);
		if (size < 0) {
			printf("Argument size must be a positive number.\n");
		}
		else if (size > 0) {
			drawStar(size);
		}
	}
}

// Returns true if the given string is a positive number
bool isNumber(char string[])
{
	for (int i = 0; string[i] != 0; i++) {
		if (string[i] < 48 || string[i] > 57) {
			return false;
		}
	}
	return true;
}

void drawStar(int size) {
	drawTip(size);
	drawLine(size);
	drawInside(size);
	drawLine(size);
	drawReverseTip(size);
}

// Draws the tip of the star
void drawTip(int size) {
	// Special case for a size 1
	if (size == 1)
		printf(" ");

	for (int i = 0; i < size; i++) {
		// create left gap
		for (int gap = 1; gap < size * 2; gap++) {
			printf(" ");
		}
		for (int j = 0; j < size + i + 1; j++) {
			if (j == size + i || j == size - i)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}

// Draws the lines under the tip of the star
void drawLine(int size)
{
	for (int i = 0; i < size * 2 + 1; i++)
		printf("*");

	// Special case for a size 1
	if (size == 1)
		printf(" ");

	for (int j = 0; j < size * 2 - 3; j++)
		printf(" ");

	for (int k = 0; k < size * 2 + 1; k++)
		printf("*");

	printf("\n");
}

// Draws the hourglass shaped part of the star
void drawInside(int size)
{
	// Special case for a size 1
	if (size == 1) {
		printf(" *   * \n");
		return;
	}

	int length = 6 * size;
	for (int i = 1; i < size * 2; i++) {
		printf(" ");
		for (int j = 1; j < length; j++) {
			if (i <= size) {
				if (j == i || j == length - i - 2)
					printf("*");
				else
					printf(" ");
			}
			else {
				int newI = i - size;
				if (j == size - newI || j == length - size + newI - 2)
					printf("*");
				else
					printf(" ");
			}
		}
		printf("\n");
	}
}

// Draws the bottom tip of the star
void drawReverseTip(int size) 
{
	// Special case for a size 1
	if (size == 1)
		printf(" ");

	for (int i = 0; i < size; i++) {
		// create left gap
		for (int gap = 0; gap < size * 2; gap++) {
			printf(" ");
		}
		for (int j = 0; j < size * 2 - 1; j++) {
			if (j == i || j == size * 2 - 2 - i) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}