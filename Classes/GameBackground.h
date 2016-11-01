#ifndef __GAME_BACKGROUND__
#define __GAME_BACKGROUND__

#include "BackGround.h"

class GameBackground : public BackGround
{
public:
	virtual bool init();
	CREATE_FUNC(GameBackground);
};

#endif