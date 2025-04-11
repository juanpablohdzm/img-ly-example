//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#ifndef BUTTON_H
#define BUTTON_H
#include <string>
#include <SDL3/SDL_rect.h>

#include "interfaces/Clickable.h"
#include "Widget.h"
#include "../../utils/Timer.h"

class SDL_Renderer;
class SDL_Texture;

class Button :  public Widget, public Clickable {
public:
    Button(
        SDL_Renderer* renderer,
        const char* defaultImagePath,
        const char* hoverImagePath,
        const char* clickedImagePath,
        int x, int y,
        int width, int height,
        const std::function<void()>& onClickCallback = nullptr);

    ~Button() override;

    void render() override;
    void onHoverEnter() override;
    void onHoverExit() override;
    void onClick() override;

private:
    SDL_Texture* loadTexture(const char* path) const;

    SDL_Renderer* renderer;

    SDL_Texture* currentTexture;

    SDL_Texture* defaultImageTexture;
    SDL_Texture* hoverImageTexture;
    SDL_Texture* clickedImageTexture;

    Timer clickTimer;
    std::function<void()> onClickCallback;
};


#endif //BUTTON_H
