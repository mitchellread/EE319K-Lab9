// Fifo.c
// Runs on LM4F120/TM4C123
// Provide functions that implement the Software FiFo Buffer
// Last Modified: November 14, 2018
// Student names: Adit Jain, Edie Zhou
// Last modification date: change this to the last modification date or look very silly

#include <stdint.h>
// FIFO state variables
// Size, put index, get index, and FIFO buffer
#define SIZE 16			// size constant

int8_t putI;				// insertion index
int8_t getI;				// retrieval index
int8_t elements;		// number of elements
char fifo[SIZE];		// FIFO queue


// --UUU-- Declare state variables for Fifo
//        buffer, put and get indexes

// *********** Fifo_Init**********
// Initializes a software FIFO of a
// fixed size and sets up indexes for
// put and get operations
void Fifo_Init() {	
	getI = SIZE - 1;
	putI = SIZE - 1;	// set putI, getI to last index				
	elements = 0;			// set number of elements to 0
}

// *********** Fifo_Put**********
// Adds an element to the FIFO
// Input: Character to be inserted
// Output: 1 for success and 0 for failure
//         failure is when the buffer is full
uint32_t Fifo_Put(char data) {
	if(elements == SIZE){			// if buffer is full return 0
		return 0;								// return false
	}	
	elements++;								// increment number of elements
	
	fifo[putI] = data;				// insert data into fifo at put index
	putI--;										// decrement put index
	if(putI < 0){							// put index returned to original position
		putI = SIZE - 1;				// if out of bounds
	}
	return 1;									// return true
}

// *********** FiFo_Get**********
// Gets an element from the FIFO
// Input: Pointer to a character that will get the character read from the buffer
// Output: 1 for success and 0 for failure
//         failure is when the buffer is empty
uint32_t Fifo_Get(char *datapt)
{
	if(elements == 0){				// if buffer is empty return 0
		return 0;								// return false
	}	
	elements--;								// decrement number of elements
	
	*datapt = fifo[getI];			// retrieve data from fifo, place at address
	getI--;										// decrement get index
	if(getI < 0){							// return get index to last position
		getI = SIZE - 1;				// if out of bounds
	}
	
	return 1;									// return true

}
