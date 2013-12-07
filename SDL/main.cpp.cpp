//Map for Pandemic
#include "view.h"
#include "board.h"
#include "player.h"
#include "SDL.h"
#include "city.h"
#include "model.h"
#include <string>

//The attributes of the screen
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 32;

//The surfaces that will be used
SDL_Surface *Cmessage = NULL;
SDL_Surface *Bmessage = NULL;
SDL_Surface *PMmessage = NULL;
SDL_Surface *Omessage = NULL;
SDL_Surface *Pmessage = NULL;
SDL_Surface *background = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *player1 = NULL;
SDL_Surface *player2 = NULL;
SDL_Surface *player3 = NULL;
SDL_Surface *player4 = NULL;
SDL_Surface *city1 = NULL;
SDL_Surface *city2 = NULL;
SDL_Surface *city3 = NULL;
SDL_Surface *city4 = NULL;
SDL_Surface *city5 = NULL;
SDL_Surface *city6 = NULL;
SDL_Surface *city7 = NULL;
SDL_Surface *city8 = NULL;
SDL_Surface *city9 = NULL;
SDL_Surface *city10 = NULL;
SDL_Surface *city11 = NULL;
SDL_Surface *city12 = NULL;
SDL_Surface *city13 = NULL;
SDL_Surface *city14 = NULL;
SDL_Surface *city15 = NULL;
SDL_Surface *city16 = NULL;
SDL_Surface *city17 = NULL;
SDL_Surface *city18 = NULL;
SDL_Surface *city19 = NULL;
SDL_Surface *city20 = NULL;
SDL_Surface *city21 = NULL;
SDL_Surface *city22 = NULL;
SDL_Surface *city23 = NULL;
SDL_Surface *city24 = NULL;
SDL_Surface *city25 = NULL;
SDL_Surface *city26 = NULL;
SDL_Surface *city27 = NULL;
SDL_Surface *city28 = NULL;
SDL_Surface *city29 = NULL;
SDL_Surface *city30 = NULL;
SDL_Surface *city31 = NULL;
SDL_Surface *city32 = NULL;
SDL_Surface *city33 = NULL;
SDL_Surface *city34 = NULL;
SDL_Surface *city35 = NULL;
SDL_Surface *city36 = NULL;
SDL_Surface *city37 = NULL;
SDL_Surface *city38 = NULL;
SDL_Surface *city39 = NULL;
SDL_Surface *city40 = NULL;
SDL_Surface *city41 = NULL;
SDL_Surface *city42 = NULL;
SDL_Surface *city43 = NULL;
SDL_Surface *city44 = NULL;
SDL_Surface *city45 = NULL;
SDL_Surface *city46 = NULL;
SDL_Surface *city47 = NULL;
SDL_Surface *city48 = NULL;
SDL_Surface *zero = NULL;
SDL_Surface *one = NULL;
SDL_Surface *two = NULL;
SDL_Surface *three = NULL;
SDL_Surface *four = NULL;
SDL_Surface *five = NULL;
SDL_Surface *six = NULL;
SDL_Surface *seven = NULL;
SDL_Surface *eight = NULL;

SDL_Event event;

SDL_Surface *load_image( std::string filename )
{
    //Temporary storage for the image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = SDL_LoadBMP( filename.c_str() );

    //If nothing went wrong in loading the image
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old image
        SDL_FreeSurface( loadedImage );
    }

    //Return the optimized image
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Pandemic", NULL );

    //If everything initialized fine
    return true;
}

bool load_files()
{
	//Load the images
    Pmessage = load_image( "statsPR.bmp" );
    background = load_image( "board.bmp" );
	PMmessage = load_image( "statsPM.bmp" );
	Omessage = load_image( "statsO.bmp" );
	Cmessage = load_image( "statsC.bmp" );
	Bmessage = load_image( "OutBreakC.bmp" );
	player1 = load_image( "player1.bmp" );
	player2 = load_image( "player2.bmp" );
	player3 = load_image( "player3.bmp" );
	player4 = load_image( "player4.bmp" );
	city1 = load_image( "city1.bmp" );
	city2 = load_image( "city2.bmp" );
	city3 = load_image( "city3.bmp" );
	city4 = load_image( "city4.bmp" );
	city5 = load_image( "city5.bmp" );
	city6 = load_image( "city6.bmp" );
	city7 = load_image( "city7.bmp" );
	city8 = load_image( "city8.bmp" );
	city9 = load_image( "city9.bmp" );
	city10 = load_image( "city10.bmp" );
	city11 = load_image( "city11.bmp" );
	city12 = load_image( "city12.bmp" );
	city13 = load_image( "city13.bmp" );
	city14 = load_image( "city14.bmp" );
	city15 = load_image( "city15.bmp" );
	city16 = load_image( "city16.bmp" );
	city17 = load_image( "city17.bmp" );
	city18 = load_image( "city18.bmp" );
	city19 = load_image( "city19.bmp" );
	city20 = load_image( "city20.bmp" );
	city21 = load_image( "city21.bmp" );
	city22 = load_image( "city22.bmp" );
	city23 = load_image( "city23.bmp" );
	city24 = load_image( "city24.bmp" );
	city25 = load_image( "city25.bmp" );
	city26 = load_image( "city26.bmp" );
	city27 = load_image( "city27.bmp" );
	city28 = load_image( "city28.bmp" );
	city29 = load_image( "city29.bmp" );
	city30 = load_image( "city30.bmp" );
	city31 = load_image( "city31.bmp" );
	city32 = load_image( "city32.bmp" );
	city33 = load_image( "city33.bmp" );
	city34 = load_image( "city34.bmp" );
	city35 = load_image( "city35.bmp" );
	city36 = load_image( "city36.bmp" );
	city37 = load_image( "city37.bmp" );
	city38 = load_image( "city38.bmp" );
	city39 = load_image( "city39.bmp" );
	city40 = load_image( "city40.bmp" );
	city41 = load_image( "city41.bmp" );
	city42 = load_image( "city42.bmp" );
	city43 = load_image( "city43.bmp" );
	city44 = load_image( "city44.bmp" );
	city45 = load_image( "city45.bmp" );
	city46 = load_image( "city46.bmp" );
	city47 = load_image( "city47.bmp" );
	city48 = load_image( "city48.bmp" );
	zero = load_image( "zero.bmp" );
	one = load_image( "one.bmp" );
	two = load_image( "two.bmp" );
	three = load_image( "three.bmp" );
	four = load_image( "four.bmp" );
	five = load_image( "five.bmp" );
	six = load_image( "six.bmp" );
	seven = load_image( "seven.bmp" );
	eight = load_image( "eight.bmp" );
   

    //If there was an error in loading the image
    if( Pmessage == NULL )
    {
        return false;
    }
	if( background == NULL )
    {
        return false;
    }
	if( PMmessage == NULL )
    {
        return false;
    }
	if( Omessage == NULL )
    {
        return false;
    }
	if( Cmessage == NULL )
    {
        return false;
    }
	if( Bmessage == NULL )
    {
        return false;
    }
	if( player1 == NULL )
    {
        return false;
    }
	if( player2 == NULL )
    {
        return false;
    }
	if( player3 == NULL )
    {
        return false;
    }
	if( player4 == NULL )
    {
        return false;
    }
	if( city1 == NULL )
    {
        return false;
    }
	if( city2 == NULL )
    {
        return false;
    }
	if( city3 == NULL )
    {
        return false;
    }
	if( city4 == NULL )
    {
        return false;
    }
	if( city5 == NULL )
    {
        return false;
    }
	if( city6 == NULL )
    {
        return false;
    }
	if( city7 == NULL )
    {
        return false;
    }
	if( city8 == NULL )
    {
        return false;
    }
	if( city9 == NULL )
    {
        return false;
    }
	if( city10 == NULL )
    {
        return false;
    }
	if( city11 == NULL )
    {
        return false;
    }
	if( city12 == NULL )
    {
        return false;
    }
	if( city13 == NULL )
    {
        return false;
    }
	if( city14 == NULL )
    {
        return false;
    }
	if( city15 == NULL )
    {
        return false;
    }
	if( city16 == NULL )
    {
        return false;
    }
	if( city17 == NULL )
    {
        return false;
    }
	if( city18 == NULL )
    {
        return false;
    }
	if( city19 == NULL )
    {
        return false;
    }
	if( city20 == NULL )
    {
        return false;
    }
	if( city21 == NULL )
    {
        return false;
    }
	if( city22 == NULL )
    {
        return false;
    }
	if( city23 == NULL )
    {
        return false;
    }
	if( city24 == NULL )
    {
        return false;
    }
	if( city25 == NULL )
    {
        return false;
    }
	if( city26 == NULL )
    {
        return false;
    }
	if( city27 == NULL )
    {
        return false;
    }
	if( city28 == NULL )
    {
        return false;
    }
	if( city29 == NULL )
    {
        return false;
    }
	if( city30 == NULL )
    {
        return false;
    }
	if( city31 == NULL )
    {
        return false;
    }
	if( city32 == NULL )
    {
        return false;
    }
	if( city33 == NULL )
    {
        return false;
    }
	if( city34 == NULL )
    {
        return false;
    }
	if( city35 == NULL )
    {
        return false;
    }
	if( city36 == NULL )
    {
        return false;
    }
	if( city37 == NULL )
    {
        return false;
    }
	if( city38 == NULL )
    {
        return false;
    }
	if( city39 == NULL )
    {
        return false;
    }
	if( city40 == NULL )
    {
        return false;
    }
	if( city41 == NULL )
    {
        return false;
    }
	if( city42 == NULL )
    {
        return false;
    }
	if( city43 == NULL )
    {
        return false;
    }
	if( city44 == NULL )
    {
        return false;
    }
	if( city45 == NULL )
    {
        return false;
    }
	if( city46 == NULL )
    {
        return false;
    }
	if( city47 == NULL )
    {
        return false;
    }
	if( city48 == NULL )
    {
        return false;
    }
	if( zero == NULL )
	{
		return false;
	}
	if( one == NULL )
	{
		return false;
	}
	if( two == NULL )
	{
		return false;
	}
	if( three == NULL )
	{
		return false;
	}
	if( four == NULL )
	{
		return false;
	}
	if( five == NULL )
	{
		return false;
	}
	if( six == NULL )
	{
		return false;
	}
	if( seven == NULL )
	{
		return false;
	}
	if( eight == NULL )
	{
		return false;
	}

    //If everything loaded fine
    return true;
}

void clean_up()
{
    //Free the surfaces
    SDL_FreeSurface( Pmessage );
    SDL_FreeSurface( background );
	SDL_FreeSurface( PMmessage );
	SDL_FreeSurface( Omessage );
	SDL_FreeSurface( Cmessage );
	SDL_FreeSurface( Bmessage );
	SDL_FreeSurface( player1 );
	SDL_FreeSurface( player2 );
	SDL_FreeSurface( player3 );
	SDL_FreeSurface( player4 );
	SDL_FreeSurface( city1 );
	SDL_FreeSurface( city2 );
	SDL_FreeSurface( city3 );
	SDL_FreeSurface( city4 );
	SDL_FreeSurface( city5 );
	SDL_FreeSurface( city6 );
	SDL_FreeSurface( city7 );
	SDL_FreeSurface( city8 );
	SDL_FreeSurface( city9 );
	SDL_FreeSurface( city10 );
	SDL_FreeSurface( city11 );
	SDL_FreeSurface( city12 );
	SDL_FreeSurface( city13 );
	SDL_FreeSurface( city14 );
	SDL_FreeSurface( city15 );
	SDL_FreeSurface( city16 );
	SDL_FreeSurface( city17 );
	SDL_FreeSurface( city18 );
	SDL_FreeSurface( city19 );
	SDL_FreeSurface( city20 );
	SDL_FreeSurface( city21 );
	SDL_FreeSurface( city22 );
	SDL_FreeSurface( city23 );
	SDL_FreeSurface( city24 );
	SDL_FreeSurface( city25 );
	SDL_FreeSurface( city26 );
	SDL_FreeSurface( city27 );
	SDL_FreeSurface( city28 );
	SDL_FreeSurface( city29 );
	SDL_FreeSurface( city30 );
	SDL_FreeSurface( city31 );
	SDL_FreeSurface( city32 );
	SDL_FreeSurface( city33 );
	SDL_FreeSurface( city34 );
	SDL_FreeSurface( city35 );
	SDL_FreeSurface( city36 );
	SDL_FreeSurface( city37 );
	SDL_FreeSurface( city38 );
	SDL_FreeSurface( city39 );
	SDL_FreeSurface( city40 );
	SDL_FreeSurface( city41 );
	SDL_FreeSurface( city42 );
	SDL_FreeSurface( city43 );
	SDL_FreeSurface( city44 );
	SDL_FreeSurface( city45 );
	SDL_FreeSurface( city46 );
	SDL_FreeSurface( city47 );
	SDL_FreeSurface( city48 );
	SDL_FreeSurface( zero );
	SDL_FreeSurface( one );
	SDL_FreeSurface( two );
	SDL_FreeSurface( three );
	SDL_FreeSurface( four );
	SDL_FreeSurface( five );
	SDL_FreeSurface( six );
	SDL_FreeSurface( seven );
	SDL_FreeSurface( eight );

    //Quit SDL
    SDL_Quit();
}

int main( int argc, char* args[] )
{
	bool quit = false;

	if( init() == false )
    {
        return 1;
    }
	if( load_files() == false )
    {
        return 1;
    }

    //Apply the background to the screen
    apply_surface( 0, 0, background, screen );

    //Apply the message to the screen
    apply_surface( 721, 480, Pmessage, screen );
	apply_surface( 879, 480, PMmessage, screen );
	apply_surface( 717, 20, Omessage, screen );
	apply_surface( 912, 20, Cmessage, screen );
	//if(getInfectRate() = 0)
		apply_surface( 82, 350, Bmessage, screen );
	//if(getInfectRate() = 1)
		apply_surface( 124, 380, Bmessage, screen );
	//if(getInfectRate() = 2)
		apply_surface( 82, 408, Bmessage, screen );
	//if(getInfectRate() = 3)
		apply_surface( 124, 435, Bmessage, screen );
	//if(getInfectRate() = 4)
		apply_surface( 82, 464, Bmessage, screen );
	//if(getInfectRate() = 5)
		apply_surface( 124, 490, Bmessage, screen );
	//if(getInfectRate() = 6)
		apply_surface( 82, 516, Bmessage, screen );
	//if(getInfectRate() = 7)
		apply_surface( 124, 543, Bmessage, screen );
	//if(getInfectRate() = 8)
		apply_surface( 82, 570, Bmessage, screen );

	//if(getPID() = 0)
		//apply_surface( 790, 500, player1, screen );
	//if(getPID() = 1)
		//apply_surface( 790, 500, player2, screen );
	//if(getPID() = 2)
		//apply_surface( 790, 500, player3, screen );
	//if(getPID() = 3)
		apply_surface( 790, 500, player4, screen );

	//if(getCID() = 0)
		apply_surface( 930, 60, city1, screen );
	/*if(getCID() = 1)
		apply_surface( 930, 60, city2, screen );
	//if(getCID() = 2)
		apply_surface( 930, 60, city3, screen );
	//if(getCID() = 3)
		apply_surface( 930, 60, city4, screen );
	//if(getCID() = 4)
		apply_surface( 930, 60, city5, screen );
	//if(getCID() = 5)
		apply_surface( 930, 60, city6, screen );
	//if(getCID() = 6)
		apply_surface( 930, 60, city7, screen );
	//if(getCID() = 7)
		apply_surface( 930, 60, city8, screen );
	//if(getCID() = 8)
		apply_surface( 930, 60, city9, screen );
	//if(getCID() = 9)
		apply_surface( 930, 60, city10, screen );
	//if(getCID() = 10)
		apply_surface( 930, 60, city11, screen );
	//if(getCID() = 11)
		apply_surface( 930, 60, city12, screen );
	//if(getCID() = 12)
		apply_surface( 930, 60, city13, screen );
	//if(getCID() = 13)
		apply_surface( 930, 60, city14, screen );
	//if(getCID() = 14)
		apply_surface( 930, 60, city15, screen );
	//if(getCID() = 15)
		apply_surface( 930, 60, city16, screen );
	//if(getCID() = 16)
		apply_surface( 930, 60, city17, screen );
	//if(getCID() = 17)
		apply_surface( 930, 60, city18, screen );
	//if(getCID() = 18)
		apply_surface( 930, 60, city19, screen );
	//if(getCID() = 19)
		apply_surface( 930, 60, city20, screen );
	//if(getCID() = 20)
		apply_surface( 930, 60, city21, screen );
	//if(getCID() = 21)
		apply_surface( 930, 60, city22, screen );
	//if(getCID() = 22)
		apply_surface( 930, 60, city23, screen );
	//if(getCID() = 23)
		apply_surface( 930, 60, city24, screen );
	//if(getCID() = 24)
		apply_surface( 930, 60, city25, screen );
	//if(getCID() = 25)
		apply_surface( 930, 60, city26, screen );
	//if(getCID() = 26)
		apply_surface( 930, 60, city27, screen );
	//if(getCID() = 27)
		apply_surface( 930, 60, city28, screen );
	//if(getCID() = 28)
		apply_surface( 930, 60, city29, screen );
	//if(getCID() = 29)
		apply_surface( 930, 60, city30, screen );
	//if(getCID() = 30)
		apply_surface( 930, 60, city31, screen );
	//if(getCID() = 31)
		apply_surface( 930, 60, city32, screen );
	//if(getCID() = 32)
		apply_surface( 930, 60, city33, screen );
	//if(getCID() = 33)
		apply_surface( 930, 60, city34, screen );
	//if(getCID() = 34)
		apply_surface( 930, 60, city35, screen );
	//if(getCID() = 35)
		apply_surface( 930, 60, city36, screen );
	//if(getCID() = 36)
		apply_surface( 930, 60, city37, screen );
	//if(getCID() = 37)
		apply_surface( 930, 60, city38, screen );
	//if(getCID() = 38)
		apply_surface( 930, 60, city39, screen );
	//if(getCID() = 39)
		apply_surface( 930, 60, city40, screen );
	//if(getCID() = 40)
		apply_surface( 930, 60, city41, screen );
	//if(getCID() = 41)
		apply_surface( 930, 60, city42, screen );
	//if(getCID() = 42)
		apply_surface( 930, 60, city43, screen );
	//if(getCID() = 43)
		apply_surface( 930, 60, city44, screen );
	//if(getCID() = 44)
		apply_surface( 930, 60, city45, screen );
	//if(getCID() = 45)
		apply_surface( 930, 60, city46, screen );
	//if(getCID() = 46)
		apply_surface( 930, 60, city47, screen );
	//if(getCID() = 47)
		apply_surface( 930, 60, city48, screen );*/

	//if(getVCount() = 0)
		apply_surface( 800, 60, zero, screen );
	//if(getVCount() = 1)
		apply_surface( 800, 60, one, screen );
	//if(getVCount() = 2)
		apply_surface( 800, 60, two, screen );
	//if(getVCount() = 3)
		apply_surface( 800, 60, three, screen );
	//if(getVCount() = 4)
		apply_surface( 800, 60, four, screen );
	//if(getVCount() = 5)
		apply_surface( 800, 60, five, screen );
	//if(getVCount() = 6)
		apply_surface( 800, 60, six, screen );
	//if(getVCount() = 7)
		apply_surface( 800, 60, seven, screen );
	//if(getVCount() = 8)
		apply_surface( 800, 60, eight, screen );

	//if(getActionCount() = 1)
		//apply_surface( 920, 550, player1, screen );
	//if(getActionCount() = 2)
		//apply_surface( 920, 550, player2, screen );
	//if(getActionCount() = 2)
		//apply_surface( 920, 550, player3, screen );
	//if(getActionCount() = 2)
		apply_surface( 920, 550, player4, screen );



    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {
        return 1;
    }

    //While the user hasn't quit
    while( quit == false )
    {
        //While there's an event to handle
        while( SDL_PollEvent( &event ) )
        {
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }
    }

    //Free the surface and quit SDL
    clean_up();

    return 0;
}