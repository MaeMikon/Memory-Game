using namespace std;

void logSDLError(ostream& os,const string &msg, bool fatal);

SDL_Texture* loadTexture(const string &file, SDL_Renderer *ren);

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilKeyPressed();

SDL_Texture *loadText(SDL_Renderer * renderer, const string &text, const string &font, int size);

void renderText(SDL_Texture *text, SDL_Renderer *renderer, string name, int sizeText, int x, int y);

void screenShot(SDL_Renderer*renderer);

