#include <stdio.h>
#include <gb/gb.h>
#include "../source/Sprites/Emojis.c"

int main()
{
	// Load 8x16 sprites
	SPRITES_8x16;
	
	// Load emoji sprites
	set_sprite_data(0, 16, Emojis);
	
	// Set the first emoji
	set_sprite_tile(0, 0);
	move_sprite(0, 55, 75);
	set_sprite_tile(1, 2);
	move_sprite(1, 55 + 8, 75);
	
	// Set the second emoji
	set_sprite_tile(2, 8);
	move_sprite(2, 95, 75);
	set_sprite_tile(3, 10);
	move_sprite(3, 95 + 8, 75);
	
	// Render the sprites
	SHOW_SPRITES;

	while(1)
	{
		set_sprite_tile(0, 4);
		set_sprite_tile(1, 6);
		set_sprite_tile(2, 12);
		set_sprite_tile(3, 14);
		delay(500);
		set_sprite_tile(0, 0);
		set_sprite_tile(1, 2);
		set_sprite_tile(2, 8);
		set_sprite_tile(3, 10);
		delay(500);
	}
	
	return 0;
}
