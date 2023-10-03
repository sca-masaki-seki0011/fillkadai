// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Game.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <iostream>


const int SCREEN_WIDTHS = 640;
const int SCREEN_HEIGHTS = 480;

int main(int argc, char** argv)
{
	Mix_Music* music=NULL;
	


	Game game;
	bool success = game.Initialize();
	
	if (success)
	{
	
		Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
		music = Mix_LoadMUS("Assets/music.ogg");
		Mix_PlayMusic(music, -1);
		
		TTF_Init();
		game._window = SDL_CreateWindow("Draw Text Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTHS, SCREEN_HEIGHTS, SDL_WINDOW_SHOWN);
		game._renderer = SDL_CreateRenderer(game._window, -1, SDL_RENDERER_ACCELERATED);
		game.font = TTF_OpenFont("Assets/DBSTRAIG.ttf", 50);

		SDL_Color col = { 0xff,0xff,0xff };

		game.surface = TTF_RenderUTF8_Blended(game.font, "Game Start!!", col);
		game.texture = SDL_CreateTextureFromSurface(game._renderer, game.surface);
		SDL_SetRenderDrawColor(game._renderer, 0, 0, 0, 255);
		SDL_RenderClear(game._renderer);

		//•¶š‚ğ•`Ê‚µ‚½Texture‚ÌƒTƒCƒY‚ğæ“¾‚·‚é      
		int iw, ih;
		SDL_QueryTexture(game.texture, NULL, NULL, &iw, &ih);

		SDL_Rect txtRect = (SDL_Rect{ 0,0,iw,ih });
		SDL_Rect pasteRect = (SDL_Rect{ 135,240,iw,ih });

		//Texture‚ğ•`Ê‚·‚é      
		//•`ÊŒ³‚Ì•`Ê‚·‚é•”•ª,•`Êæ‚Ì•`Ê‚·‚é•”•ª)      
		//ƒTƒCƒY‚ªˆá‚¤‚ÆŸè‚ÉTexture‚ğL“W‚µ‚Ä‚­‚ê‚é      
		SDL_RenderCopy(game._renderer, game.texture, &txtRect, &pasteRect);
		//window‚ÉƒŒƒ“ƒ_ƒŠƒ“ƒO‚·‚é      
		SDL_RenderPresent(game._renderer);


		SDL_Delay(3000);

		SDL_FreeSurface(game.surface);
		SDL_DestroyTexture(game.texture);
		SDL_DestroyRenderer(game._renderer);
		SDL_DestroyWindow(game._window);
		TTF_CloseFont(game.font);
		TTF_Quit();
		
		game.RunLoop();
		if (game.zenmetu)
		{

			TTF_Init();
			game._window = SDL_CreateWindow("Draw Text Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTHS, SCREEN_HEIGHTS, SDL_WINDOW_SHOWN);
			game._renderer = SDL_CreateRenderer(game._window, -1, SDL_RENDERER_ACCELERATED);
			game.font = TTF_OpenFont("Assets/DBSTRAIG.ttf", 50);

			SDL_Color col = { 0xff,0xff,0xff };

			game.surface = TTF_RenderUTF8_Blended(game.font, "Game Clear!!", col);
			game.texture = SDL_CreateTextureFromSurface(game._renderer, game.surface);
			SDL_SetRenderDrawColor(game._renderer, 0, 0, 0, 255);
			SDL_RenderClear(game._renderer);

			//•¶š‚ğ•`Ê‚µ‚½Texture‚ÌƒTƒCƒY‚ğæ“¾‚·‚é      
			int iw, ih;
			SDL_QueryTexture(game.texture, NULL, NULL, &iw, &ih);

			SDL_Rect txtRect = (SDL_Rect{ 0,0,iw,ih });
			SDL_Rect pasteRect = (SDL_Rect{ 135,240,iw,ih });

			//Texture‚ğ•`Ê‚·‚é      
			//•`ÊŒ³‚Ì•`Ê‚·‚é•”•ª,•`Êæ‚Ì•`Ê‚·‚é•”•ª)      
			//ƒTƒCƒY‚ªˆá‚¤‚ÆŸè‚ÉTexture‚ğL“W‚µ‚Ä‚­‚ê‚é      
			SDL_RenderCopy(game._renderer, game.texture, &txtRect, &pasteRect);
			//window‚ÉƒŒƒ“ƒ_ƒŠƒ“ƒO‚·‚é      
			SDL_RenderPresent(game._renderer);


			SDL_Delay(3000);

			SDL_FreeSurface(game.surface);
			SDL_DestroyTexture(game.texture);
			SDL_DestroyRenderer(game._renderer);
			SDL_DestroyWindow(game._window);
			TTF_CloseFont(game.font);
			TTF_Quit();
		}
		
		
	}
	Mix_HaltMusic();
	Mix_FreeMusic(music);
	Mix_CloseAudio();
	SDL_Quit();
	game.Shutdown();
	return 0;
}
