#include <gb/gb.h>
#include "Utilities.c"

// NOTE: to make this more efficient in the future, change all these bools into a single UINT8.  Use those bits!
// Current frame state for each button
BOOL isUp = FALSE;
BOOL isDown = FALSE;
BOOL isLeft = FALSE;
BOOL isRight = FALSE;

BOOL isA = FALSE;
BOOL isB = FALSE;
BOOL isStart = FALSE;
BOOL isSelect = FALSE;

// Last frame state for each button
BOOL prevIsUp = FALSE;
BOOL prevIsDown = FALSE;
BOOL prevIsLeft = FALSE;
BOOL prevIsRight = FALSE;

BOOL prevIsA = FALSE;
BOOL prevIsB = FALSE;
BOOL prevIsStart = FALSE;
BOOL prevIsSelect = FALSE;

// To be able to use the input manager this function needs to be called in the game loop, at the start of the loop.
void UpdateInputs()
{
	// Get inputs
	//UINT8 inputs;
	//inputs = joypad();
	
	// Right
	if(joypad() == J_RIGHT){
		if(isRight == FALSE){
			isRight = TRUE;
		}else{
			prevIsRight = TRUE;
		}
	}else{
		if(isRight == TRUE){
			isRight = FALSE;
		}else{
			prevIsRight = FALSE;
		}
	}
	// Left
	if(joypad() == J_LEFT){
		if(isLeft == FALSE){
			isLeft = TRUE;
		}else{
			prevIsLeft = TRUE;
		}
	}else{
		if(isLeft == TRUE){
			isLeft = FALSE;	
		}else{
			prevIsLeft = FALSE;
		}
	}
	// Up
	if(joypad() == J_UP){
		if(isUp == FALSE){
			isUp = TRUE;
		}else{
			prevIsUp = TRUE;
		}
	}else{
		if(isUp == TRUE){
			isUp = FALSE;	
		}else{
			prevIsUp = FALSE;
		}
	}
	// Down
	if(joypad() == J_DOWN){
		if(isDown == FALSE){
			isDown = TRUE;
		}else{
			prevIsDown = TRUE;
		}
	}else{
		if(isDown == TRUE){
			isDown = FALSE;	
		}else{
			prevIsDown = FALSE;
		}
	}
	// Start
	if(joypad() == J_START){
		if(isStart == FALSE){
			isStart = TRUE;
		}else{
			prevIsStart = TRUE;
		}
	}else{
		if(isStart == TRUE){
			isStart = FALSE;	
		}else{
			prevIsStart = FALSE;
		}
	}
	// Select
	if(joypad() == J_SELECT){
		if(isSelect == FALSE){
			isSelect = TRUE;
		}else{
			prevIsSelect = TRUE;
		}
	}else{
		if(isSelect == TRUE){
			isSelect = FALSE;	
		}else{
			prevIsSelect = FALSE;
		}
	}
	// A
	if(joypad() == J_A){
		if(isA == FALSE){
			isA = TRUE;
		}else{
			prevIsA = TRUE;
		}
	}else{
		if(isA == TRUE){
			isA = FALSE;	
		}else{
			prevIsA = FALSE;
		}
	}
	// B
	if(joypad() == J_B){
		if(isB == FALSE){
			isB = TRUE;
		}else{
			prevIsB = TRUE;
		}
	}else{
		if(isB == TRUE){
			isB = FALSE;	
		}else{
			prevIsB = FALSE;
		}
	}
	
	delay(10);
}

// True on the frame the button is pressed
BOOL GetButtonDown(UINT8 button)
{
	switch(button) {
	case J_RIGHT : 
		return (prevIsRight == FALSE && isRight == TRUE);
	case J_LEFT : 
		return (prevIsLeft == FALSE && isLeft == TRUE);
	case J_UP : 
		return (prevIsUp == FALSE && isUp == TRUE);
	case J_DOWN : 
		return (prevIsDown == FALSE && isDown == TRUE);
	case J_START : 
		return (prevIsStart == FALSE && isStart == TRUE);
	case J_SELECT :
		return (prevIsSelect == FALSE && isSelect == TRUE);
	case J_A : 
		return (prevIsA == FALSE && isA == TRUE);
	case J_B :
		return (prevIsB == FALSE && isB == TRUE);
	default :
		break;
		}
}

// True on the frame that the button has been released
BOOL GetButtonUp(UINT8 button)
{
	switch(button) {
	case J_RIGHT : 
		return (prevIsRight == TRUE && isRight == FALSE);
	case J_LEFT : 
		return (prevIsLeft == TRUE && isLeft == FALSE);
	case J_UP : 
		return (prevIsUp == TRUE && isUp== FALSE);
	case J_DOWN : 
		return (prevIsDown == TRUE && isDown == FALSE);
	case J_START : 
		return (prevIsStart == TRUE && isStart == FALSE);
	case J_SELECT :
		return (prevIsSelect == TRUE && isSelect == FALSE);
	case J_A : 
		return (prevIsA	== TRUE && isA == FALSE);
	case J_B :
		return (prevIsB == TRUE && isB == FALSE);
	default :
		break;
		}
}

// Is the button being held down
BOOL GetButton(UINT8 button)
{
	switch(button) {
	case J_RIGHT : 
		return isRight;
	case J_LEFT : 
		return isLeft;
	case J_UP : 
		return isUp;
	case J_DOWN : 
		return isDown;
	case J_START : 
		return isStart;
	case J_SELECT :
		return isSelect;
	case J_A : 
		return isA;
	case J_B :
		return isB;
	default :
		break;
		}
}