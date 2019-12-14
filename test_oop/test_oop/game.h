#include<vector>
#include"ball.h"
#include <SFML/Graphics.hpp>
#include"bar.h"
#include"paddle.h"
#include"player.h"
using namespace sf;
class game
{
	vector<object*> objArr;
public:
	void init();
	void run();
	void render(RenderWindow &window);
	void objMove(int t);
};



