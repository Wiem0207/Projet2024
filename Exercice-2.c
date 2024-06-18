#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Définition de la taille de la fenêtre
float corde (float x, float t, int k) {
 return 400+ 50* sin((k * 3.14 * x) / 800) * sin((k * 3.14 * t) / 800);
}

// Fonction pour générer des points de contrôle aléatoires à chaque itération
int main(int argc, char** argv) {
 // Initialisation de SDL
 if (SDL_Init(SDL_INIT_VIDEO) != 0) {
 SDL_Log("Error : SDL initialisation - %s\n", 
 SDL_GetError()); // l'initialisation de la SDL a échoué 
 exit(EXIT_FAILURE);
 }
 SDL_Window 
 *window = NULL;

 window = SDL_CreateWindow(
 "Fenêtre d'animation ", // codage en utf8, donc accents possibles
 0, 0, // coin haut gauche en haut gauche de l'écran
 850, 850 , // largeur = 400, hauteur = 300
 SDL_WINDOW_RESIZABLE); 
 if (window== NULL)
 {
 SDL_Log("Error : SDL window 1 creation - %s\n", 
 SDL_GetError()); 
 exit(EXIT_FAILURE);
 }
 SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
 if (!renderer) 
 {
 fprintf(stderr, "Erreur de création du renderer : %s\n", SDL_GetError());
 SDL_DestroyWindow(window);
 SDL_Quit();
 return EXIT_FAILURE;
 }
 float time=0.0f;
 SDL_bool program_on = SDL_TRUE ;
 SDL_Event event; 

 while(program_on)
 {
 while (SDL_PollEvent(&event)) {
 if (event.type == SDL_QUIT) {
 program_on =SDL_FALSE;}}
 SDL_SetRenderDrawColor(renderer,0,0,0,255); 
 SDL_RenderClear(renderer); 
 SDL_SetRenderDrawColor(renderer,255,165,0,255);
 for(int x=0;x<800;x++)
 {
 float y=corde(x,time,10);
 SDL_RenderDrawPoint(renderer,x,(int)y);
 
 }
 SDL_SetRenderDrawColor(renderer,255,165,0,255);
 for(int y1=0;y1<800;y1++)
 {
 float x1=corde(y1,time,10);
 SDL_RenderDrawPoint(renderer,(int)x1,y1);
 }
 SDL_SetRenderDrawColor(renderer,255,165,0,255);
 for(int y1=0;y1<800;y1++)
 {
 float x1=corde(y1,time,10);
 int x_out = (int)((x1-400)*cos(3.14/4)) - ((y1-400) *sin(3.14/4));
 int y_out = (int)((x1-400)*sin(3.14/4)) + ((y1-400) *sin(3.14/4));
 SDL_RenderDrawPoint(renderer,x_out+400,y_out+400);
 }
 SDL_SetRenderDrawColor(renderer,255,165,0,255);
 for(int x2=0;x2<800;x2++)
 {
 float y2=corde(x2,time,10);
 int x_out1 = (int)((x2-400)*cos(3.14/4)) - ((y2-400) *sin(3*3.14/4));
 int y_out1 = (int)((x2-400)*sin(3.14/4)) + ((y2-400) *sin(3.14/4));
 SDL_RenderDrawPoint(renderer,x_out1+400,y_out1+400);
 }
 SDL_Delay(10);
 time+=1;
 SDL_RenderPresent(renderer);
 }
 SDL_DestroyRenderer(renderer);
 SDL_DestroyWindow(window);
 SDL_Quit();
 return 0;

}
