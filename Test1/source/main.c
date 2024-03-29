#include <3ds.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	//Initialize gfx (note: not needed if you're using SF2Dlib)
	gfxInitDefault();

	consoleInit(GFX_TOP, NULL);

	// Main loop
	while (aptMainLoop())
	{
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();

		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		//hidKeysHeld returns information about which buttons are currently pressed (regardless if they were pressed or not pressed in the previous frame)
		//hidKeysUp returns information about which buttons are not pressed but were pressed in the previous frame
		u32 kDown = hidKeysDown();

		if (kDown & KEY_B) break; // break in order to return to hbmenu

		if (kDown & KEY_A) 
		{
			bool loop = true;
			while (loop == true)
			{
				int press = 0;
				press++;
				printf("\x1b[20;20HYou pressed the button %d times", press);
			}


		}

		// Flush and swap framebuffers, this is needed for rendering these will not be needed when using SF2D lib
		gfxFlushBuffers();
		gfxSwapBuffers();

		//Wait for VBlank, this is needed for rendering these will not be needed when using SF2D lib
		gspWaitForVBlank();
	}

	gfxExit();
	return 0;
}
