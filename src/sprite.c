#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <list.h>
#include "animate.h"
#include "dbg.h"
#include "flags.h"
#include "sprite.h"
#include "gfx.h"

Sprite *create_sprite(char *id, char *path, int frames, SDL_Rect *size, SDL_Rect *mask, void *animation)
{
    Sprite *sprite = malloc(sizeof(Sprite));
    sprite->animations = NULL;
    sprite->animation = animation;
    sprite->alpha = ALPHA_MAX;
    sprite->flags = 0;
    sprite->frames = frames;
    sprite->id = id;
    sprite->is_animating = 0;
    sprite->mask = mask;
    sprite->path = path;
    sprite->size = size;
    sprite->texture = create_sprite_texture(renderer, path, ALPHA_MAX);
    sprite->visible = 1;
    return sprite;
}

void add_animation(Sprite *sprite, Animation2 *animation)
{
    List_push(&sprite->animations, animation);
}

SDL_Texture *create_sprite_texture(SDL_Renderer *renderer, char *imgPath, int alpha)
{
    SDL_Surface *sprite_surface = IMG_Load(imgPath);
    check(sprite_surface, "Could not load image: %s, error = %s", imgPath, SDL_GetError())

    SDL_Texture *sprite_texture = SDL_CreateTextureFromSurface(renderer, sprite_surface);
    check(sprite_texture, "Could not create texture: %s", SDL_GetError());
    SDL_SetTextureAlphaMod(sprite_texture, alpha);

    SDL_FreeSurface(sprite_surface);

    return sprite_texture;

error:
    SDL_Quit();
    log_err("SDL Error: Shutdown");

    return NULL;
}

Node *cleanup_sprite(Sprite *sprite, Node **render_index, int node_id)
{
    Node *updated_node;

    // Clean up the sprite
    if(sprite->flags & FLAG_REMOVE) {
        // Remove the flag
        sprite->flags &= ~(FLAG_REMOVE);

        // Destroy the sprite
        destroy_sprite(sprite);

        // Remove the node and get the next node
        updated_node = List_remove(render_index, node_id);

        return updated_node;
    }

    return NULL;
}

void destroy_sprite(Sprite *sprite)
{
    /*debug("destroy sprite");*/
    if(sprite->id) {
        free(sprite->id);
    }

    if(sprite->size) {
        free(sprite->size);
    }

    if(sprite->mask) {
        free(sprite->mask);
    }

    if(sprite->animation) {
        free(sprite->animation);
        Animation *animation = (Animation *)sprite->animation;
        if(animation->type == BEZIER) {
            /*debug("bezier");*/
        }
    }

    free(sprite);
}
