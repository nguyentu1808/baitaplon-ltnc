#include "SDLTools.h"


//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;
SDL_Surface* gWin = NULL;
SDL_Surface* gLose = NULL;
SDL_Surface* g0 = NULL;
SDL_Surface* g2 = NULL;
SDL_Surface* g4 = NULL;
SDL_Surface* g8 = NULL;
SDL_Surface* g16 = NULL;
SDL_Surface* g32 = NULL;
SDL_Surface* g64 = NULL;
SDL_Surface* g128 = NULL;
SDL_Surface* g256 = NULL;
SDL_Surface* g512 = NULL;
SDL_Surface* g1024 = NULL;
SDL_Surface* g2048 = NULL;

SDL_Rect srcRect = {0, 0, 100, 100};
SDL_Rect dst1 = {10, 10, 300, 300};
SDL_Rect dst2 = {120, 10, 300, 300};
SDL_Rect dst3 = {230, 10, 300, 300};
SDL_Rect dst4 = {340, 10, 300, 300};
SDL_Rect dst5 = {10, 120, 300, 300};
SDL_Rect dst6 = {120, 120, 300, 300};
SDL_Rect dst7 = {230, 120, 300, 300};
SDL_Rect dst8 = {340, 120, 300, 300};
SDL_Rect dst9 = {10, 230, 300, 300};
SDL_Rect dst10 = {120, 230, 300, 300};
SDL_Rect dst11 = {230, 230, 300, 300};
SDL_Rect dst12 = {340, 230, 300, 300};
SDL_Rect dst13 = {10, 340, 300, 300};
SDL_Rect dst14 = {120, 340, 300, 300};
SDL_Rect dst15 = {230, 340, 300, 300};
SDL_Rect dst16 = {340, 340, 300, 300};

int a[4][4];

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
	}

	return success;
}

SDL_Surface* loadSurface( std::string path )
{
    SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }

    return loadedSurface;
}
bool loadMedia()
{
    bool success = true;

	gHelloWorld = loadSurface("image/background.bmp" );
	if( gHelloWorld == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }
    gWin = loadSurface("image/win.bmp" );
	if( gWin == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }
    gLose = loadSurface("image/Lose.bmp" );
	if( gLose == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }
    g0 = loadSurface("image/0.bmp");
	if( g0 == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }
	g2 = loadSurface("image/2.bmp");
	if( g2 == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }
	g4 = loadSurface("image/4.bmp");
	if( g4 == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }
	g8 = loadSurface("image/8.bmp");
	if( g8 == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }
	g16 = loadSurface("image/16.bmp");
	if( g16 == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }
	g32 = loadSurface("image/32.bmp");
	if( g32 == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }
	g64 = loadSurface("image/64.bmp");
	if( g64 == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }
	g128 = loadSurface("image/128.bmp");
	if( g128 == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }
	g256 = loadSurface("image/256.bmp");
	if( g256 == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }
	g512 = loadSurface("image/512.bmp");
	if( g512 == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }
	g1024 = loadSurface("image/1024.bmp");
	if( g1024 == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }
    g2048 = loadSurface("image/2048.bmp");
	if( g2048 == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }
	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface( gHelloWorld );
	gHelloWorld = NULL;
	SDL_FreeSurface( gWin );
	gWin = NULL;
	SDL_FreeSurface( gLose );
	gLose = NULL;
	SDL_FreeSurface( g0 );
	g0 = NULL;
    SDL_FreeSurface( g2 );
	g2 = NULL;
    SDL_FreeSurface( g4 );
	g4 = NULL;
    SDL_FreeSurface( g8 );
	g8 = NULL;
    SDL_FreeSurface( g16 );
	g16 = NULL;
    SDL_FreeSurface( g32 );
	g32 = NULL;
    SDL_FreeSurface( g64 );
	g64 = NULL;
    SDL_FreeSurface( g128 );
	g128 = NULL;
    SDL_FreeSurface( g256 );
	g256 = NULL;
    SDL_FreeSurface( g512 );
	g512 = NULL;
    SDL_FreeSurface( g1024 );
	g1024 = NULL;
	SDL_FreeSurface( g2048 );
	g2048 = NULL;
	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}
void print(int a,SDL_Rect* x)
{
    if (a==0) SDL_BlitSurface( g0, &srcRect, gScreenSurface, x);
    if (a==2) SDL_BlitSurface( g2, &srcRect, gScreenSurface, x);
    if (a==4) SDL_BlitSurface( g4, &srcRect, gScreenSurface, x);
    if (a==8) SDL_BlitSurface( g8, &srcRect, gScreenSurface, x);
    if (a==16) SDL_BlitSurface( g16, &srcRect, gScreenSurface, x);
    if (a==32) SDL_BlitSurface( g32, &srcRect, gScreenSurface, x);
    if (a==64) SDL_BlitSurface( g64, &srcRect, gScreenSurface, x);
    if (a==128) SDL_BlitSurface( g128, &srcRect, gScreenSurface, x);
    if (a==256) SDL_BlitSurface( g256, &srcRect, gScreenSurface, x);
    if (a==512) SDL_BlitSurface( g512, &srcRect, gScreenSurface, x);
    if (a==1024) SDL_BlitSurface( g1024, &srcRect, gScreenSurface, x);
    if (a==2048) SDL_BlitSurface( g2048, &srcRect, gScreenSurface, x);
}
SDL_Rect* dstx(int x)
{
    if (x==0) return &dst1;
    if (x==1) return &dst2;
    if (x==2) return &dst3;
    if (x==3) return &dst4;
    if (x==4) return &dst5;
    if (x==5) return &dst6;
    if (x==6) return &dst7;
    if (x==7) return &dst8;
    if (x==8) return &dst9;
    if (x==9) return &dst10;
    if (x==10) return &dst11;
    if (x==11) return &dst12;
    if (x==12) return &dst13;
    if (x==13) return &dst14;
    if (x==14) return &dst15;
    if (x==15) return &dst16;
}

void update()
{
    SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(gScreenSurface->format, 0, 0, 0));
    SDL_UpdateWindowSurface(gWindow);
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
        print(a[i][j],dstx(i*4+j));
    SDL_UpdateWindowSurface(gWindow);
}

void make()
{
    int d=0;

    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            if (a[i][j]==0) d++;
    if (d!=0)
    {
    d=rand()%d;
    int x,y,v;
    v=0;
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            if (a[i][j]==0 && v==d) {x=i;y=j;v++;}
                else if (a[i][j]==0) v++;
    if (rand()%20==5) a[x][y]=4;
    else a[x][y]=2;
    }
}
void nen(int* f)
{
    int i,j,d,x;
    i=0;
    d=0;
    x=0;
    while (i<4)
    {
        while (f[i]==0&&i<4)
            i++;
        if (i<4) d=1;
        j=i+1;
        while (f[j]==0) j++;
        if (j<4) d++;
        else break;
       // cout<<i<<" "<<j<<" "<<x<<endl;
        if (d==2)
        {
            if (f[i]==f[j]) {f[x]=f[i]*2;x++;i=j+1;d=0;}
            else {d=1;f[x]=f[i];x++;i=j;}
        }
       // cout<<i<<" "<<j<<" "<<x<<" "<<f[x]<<endl;
    }
    if (i<4 && d==1) {f[x]=f[i];x++;}
    for (int i=x;i<4;i++) f[i]=0;
}
void Left()
{
    for (int i=0;i<4;i++)
    {
        int b[4];
        for (int j=0;j<4;j++) b[j]=a[i][j];
        nen(b);
       // for (int i=0;i<4;i++) cout<<b[i]<<" ";
       //cout<<endl;
        for (int j=0;j<4;j++) a[i][j]=b[j];
    }
    make();
    update();
}
void Up()
{
    for (int i=0;i<4;i++)
    {
        int b[4];
        for (int j=0;j<4;j++) b[j]=a[j][i];
        nen(b);
       // for (int i=0;i<4;i++) cout<<b[i]<<" ";
        //cout<<endl;
        for (int j=0;j<4;j++) a[j][i]=b[j];
    }
    make();
    update();
}
void Right()
{
    for (int i=0;i<4;i++)
    {
        int b[4];
        for (int j=0;j<4;j++) b[3-j]=a[i][j];
        nen(b);
       // for (int i=0;i<4;i++) cout<<b[i]<<" ";
       // cout<<endl;
        for (int j=0;j<4;j++) a[i][j]=b[3-j];
    }
    make();
    update();
}
void Down()
{
    for (int i=0;i<4;i++)
    {
        int b[4];
        for (int j=0;j<4;j++) b[3-j]=a[j][i];
        nen(b);
       // for (int i=0;i<4;i++) cout<<b[i]<<" ";
       // cout<<endl;
        for (int j=0;j<4;j++) a[j][i]=b[3-j];
    }
    make();
    update();
}
bool kiemtra(int i,int j)
{
    if ( i==0 && j==0 && (a[i][j]==a[i][j+1] || a[i][j]==a[i+1][j]) ) return true;
    else if ( i==3 && j==0 && (a[i][j]==a[i][j+1] || a[i][j]==a[i-1][j]) ) return true;
    else if ( i==0 && j==3 && (a[i][j]==a[i][j-1] || a[i][j]==a[i+1][j]) ) return true;
    else if ( i==3 && j==3 && (a[i][j]==a[i][j-1] || a[i][j]==a[i-1][j]) ) return true;
    else if ( i==0 && (j!=0&&j!=3) && (a[i][j]==a[i][j+1] || a[i][j]==a[i+1][j] || a[i][j]==a[i][j-1] ) ) return true;
    else if ( i==3 && (j!=0&&j!=3) && (a[i][j]==a[i][j+1] || a[i][j]==a[i-1][j] || a[i][j]==a[i][j-1] ) ) return true;
    else if ( (i!=0&&i!=3) && j==0 && (a[i][j]==a[i][j+1] || a[i][j]==a[i+1][j] || a[i][j]==a[i-1][j] ) ) return true;
    else if ( (i!=0&&i!=3) && j==3 && (a[i][j]==a[i][j-1] || a[i][j]==a[i+1][j] || a[i][j]==a[i-1][j] ) ) return true;
    else if ( (i!=0&&i!=3) && (j!=0&&j!=3) && (a[i][j]==a[i+1][j] || a[i][j]==a[i-1][j] || a[i][j]==a[i][j+1] || a[i][j]==a[i][j-1]) ) return true;
    return false;
}
int check()
{
    int k=1;
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
        {
            if (a[i][j]==2048) return 0;
            if (a[i][j]==0) return 2;
            if (kiemtra(i,j)) k=2;
        }
    return k;
}
void finish(bool &quit)
{
    if (check()==1)
        {
            SDL_Delay(5000);
            SDL_BlitSurface( gLose, NULL, gScreenSurface, NULL);
            SDL_UpdateWindowSurface( gWindow );
            SDL_Delay(2000);
            quit=true;
        }
    if (check()==0)
        {
            SDL_Delay(5000);
            SDL_BlitSurface( gWin, NULL, gScreenSurface, NULL);
            SDL_UpdateWindowSurface( gWindow );
            SDL_Delay(2000);
            quit=true;
        }
}
void start()
{
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{

			bool quit = false;
			SDL_Event e;
			srand(time(NULL));
            for (int i=0;i<4;i++)
                for (int j=0;j<4;j++) a[i][j]=0;
            make();
            make();
            a[0][1]=1024;
            a[0][0]=1024;
            a[1][1]=1024;
            update();
            while (! quit)
            {
                while( SDL_PollEvent( &e ) != 0 )
				{
					if( e.type == SDL_QUIT || quit==true )
					{
						quit = true;
					}
					else if( e.type == SDL_KEYDOWN )
					{
					    switch( e.key.keysym.sym )
						{
							case SDLK_UP:
                            Up();
                            finish(quit);
							break;

							case SDLK_DOWN:
                            Down();
                            finish(quit);
							break;

							case SDLK_LEFT:
                            Left();
                            finish(quit);
							break;

							case SDLK_RIGHT:
                            Right();
                            finish(quit);
							break;
						}
					}
				}
            }

		}
	}

	close();

}
