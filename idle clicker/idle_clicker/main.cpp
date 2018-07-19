#include "idle_clicker_helper.h"

bool should_keep_running = true;
int bits = 0; 
int bytes = 0;
int cpus = 1;
int graphics_card = 1;
int desktop = 0;
int pc = 0;
int polygons = 0;
void update()
{
	bits += cpus * 1;

	bits += graphics_card * 16;

	bytes += desktop * 8;
	
	while (bits >= 8)
	{
		bits = bits - 8;
		bytes = bytes + 1;
	}
}

void draw()
{
	system("cls");
	std::cout << "You have " << bits << std::endl; 
	if (bytes>0)
	{
		std::cout << "You have " << bytes << "bytes" << std::endl;
	}
	if (cpus > 0)
	{
		std::cout << "You have " << cpus << " CPU's!" << std::endl;
	}
	if (polygons > 0)
	{
		std::cout << "You have " << polygons << " polygons!" << std::endl;
	}
	if (graphics_card > 0)
	{
		std::cout << "You have " << graphics_card << " Graphic's Card(s)!" << std::endl;
	}
	if (desktop > 0)
	{
		std::cout << "You have " << desktop << " Desktop(s)!" << std::endl;
	}
}

void handleKey(char c)
{
	//If the user hits the "q" key quit the program 
	if (c == 'q')
	{
		std::cout << "Should quit" << std::endl;
		should_keep_running = false;
	}
	if (c == '1')

	{
		bits = bits + 1;

		if (bits >= 8)
		{
			bytes = bytes + 1;

			bits = bits - 8;
		}

		draw();


	}


	if (c == '2')
	{
		if (bytes >= 18)
		{
			bytes -= 18;
			cpus++;
			draw();
		}
		else
		{
			std::cout << "you dont have enough bytes to do that" << std::endl;
		}
	}
	if (c == '3')
	{
		if (cpus > 0)
		{
         polygons = polygons + 1;
		}
		draw();
	}
	if (c == '4')
	{    if (polygons >=30)
		{
			polygons -= 30;
			graphics_card++;
			draw();
		}
	}
	if (c == '5')
	{
		if (graphics_card >= 10)
		{
			graphics_card -= 10;
			desktop++;
			draw();
	}

     }

} 




int main()
{
	



	AsyncKeyboard::setupKeyboard(handleKey);

	while (should_keep_running) 
	{
		update();

		draw();
		std::this_thread::sleep_for(1s);
	}

	AsyncKeyboard::shutdown();


    return 0;
}