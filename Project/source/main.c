#include <stdio.h>
#include <gb/gb.h>
#include "../source/Sprites/Emojis.c"
#include "../source/Utility/InputManager.c"

int main()
{
	// Sprite Index
	int sprite = 0;
	int maxSprites = 5;
	// Sprite Position
	int x = 75;
	int y = 75;
	
	// Set mode to 8x16 sprites
	SPRITES_8x16;
	// Load emoji sprites
	set_sprite_data(0, 20, Emojis);
	
	// Set the first emoji
	set_sprite_tile(0, (maxSprites - 1) * sprite);
	move_sprite(0, x, y);
	set_sprite_tile(1, (maxSprites - 1) * sprite + 2);
	move_sprite(1, x + 8, y);
	
	// Render the sprites
	SHOW_SPRITES;

	// Game loop
	while(1)
	{
		UpdateInputs();
		
		if(GetButton(J_RIGHT) == TRUE){
			x++;
		}
		if(GetButton(J_LEFT) == TRUE){
			x--;
		}
		if(GetButton(J_UP) == TRUE){
			y--;
		}
		if(GetButton(J_DOWN) == TRUE){
			y++;
		}
		
		if(GetButtonDown(J_A) == TRUE){
			sprite++;
			if(sprite >= maxSprites){
				sprite = 0;
			}
		}
		if(GetButtonUp(J_A) == TRUE){
			sprite--;
			if(sprite < 0){
				sprite = maxSprites - 1;
			}
		}
		
		// Rerender the sprite
		set_sprite_tile(0, (maxSprites - 1) * sprite);
		move_sprite(0, x, y);
		set_sprite_tile(1, (maxSprites - 1) * sprite + 2);
		move_sprite(1, x + 8, y);
	}
	
	return 0;
}
