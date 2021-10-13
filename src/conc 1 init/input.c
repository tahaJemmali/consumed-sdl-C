typedef struct
{
    char key[SDLK_LAST];
    int mousex,mousey;
    int mousexrel,mouseyrel;
    char mousebuttons[8];
        char quit;
} Input;

void UpdateEvents(Input* in)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
       
        switch (event.type)
        {
        case SDL_KEYDOWN:
            in->key[event.key.keysym.sym]=1;
            break;
        case SDL_KEYUP:
            in->key[event.key.keysym.sym]=0;
            break;
        case SDL_MOUSEMOTION:
            in->mousex=event.motion.x;
            in->mousey=event.motion.y;
            in->mousexrel=event.motion.xrel;
            in->mouseyrel=event.motion.yrel;
            break;
        case SDL_MOUSEBUTTONDOWN:
            in->mousebuttons[event.button.button]=1;
            break;
        case SDL_MOUSEBUTTONUP:
            in->mousebuttons[event.button.button]=0;
            break;
    case SDL_QUIT:
            in->quit = 1;
            break;
        default:
            break;
        }
    }
}


