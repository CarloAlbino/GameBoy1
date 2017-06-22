#include <stdio.h>
//#include <stdlib.h>
//#include <gb/gb.h>
#include <gb/malloc.h>

#include "../source/Sprites/Emojis.c"
#include "../source/Utility/InputManager.c"

struct entity
{
	int x;
	int y;
	int numOfSprites;
	int* spritePositions;
	
	void (*Move) (struct entity *);
	void (*Render) (struct entity *);
};

typedef struct entity ent;
typedef ent *Entity;

void Entity_Move(Entity this)
{
	if(GetButton(J_RIGHT) == TRUE){
		this->x++;
	}
	if(GetButton(J_LEFT) == TRUE){
		this->x--;
	}
	if(GetButton(J_UP) == TRUE){
		this->y--;
	}
	if(GetButton(J_DOWN) == TRUE){
		this->y++;
	}
}

void Entity_Render(Entity this)
{
	int i;	// Change this in the future for objec toriented goodness
	for(i = 0; i < this->numOfSprites; i++)
	{
		set_sprite_tile(i, this->spritePositions[i]);
		move_sprite(i, this->x + i*8, this->y);
	}
}

Entity new_Entity(int startPosX, int startPosY, int numSprites, int startSpriteIndex, int endSpriteIndex)
{
	Entity obj = (Entity)malloc(sizeof(ent));
	
	// Set the entity's position
	obj->x = startPosX;
	obj->y= startPosY;

	// Allocate space for int array and set the sprite positions to it
	obj->numOfSprites = numSprites;
	obj->spritePositions = (int*) calloc(numSprites, sizeof(int));
	
	if(obj->spritePositions == NULL)
	{
		set_sprite_tile(0, (4) * 0);
		move_sprite(0, 75, 75);
		printf("ERROR: OUT OF MEMORY. - Entity Constructor.\n");
		return obj;
	}
	else
	{
		int i;
		for(i = 0; i < endSpriteIndex - startSpriteIndex; i++)
		{
				obj->spritePositions[i] = startSpriteIndex + i;
		}
	}
	
	// Connec the methods
	obj->Move = Entity_Move;
	obj->Render = Entity_Render;
	
	return obj;
}

void Destroy_Entity(Entity e)
{
	free(e);
}




