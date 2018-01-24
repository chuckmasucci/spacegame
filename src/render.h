#ifndef render_h
#define render_h

#define Z_RENDER_0 0
#define Z_RENDER_1 1
#define Z_RENDER_2 2

#include "sprite.h"

int initialize_render();
void animate_sprite_rects(Sprite *sprite);
void render();
void add_to_render();
void destroy_render_queue();

#endif
