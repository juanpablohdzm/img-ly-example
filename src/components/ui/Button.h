//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#ifndef BUTTON_H
#define BUTTON_H

#include "interfaces/Clickable.h"
#include "Widget.h"
#include "../../utils/Timer.h"

class SDL_Renderer;
class SDL_Texture;

class Button :  public Widget, public Clickable {
public:
    Button(
        const char* defaultImagePath,
        const char* hoverImagePath,
        const char* clickedImagePath,
        const Position& position,
        float width, float height);

    ~Button() override;

    void render() override;
    void onHoverEnter() override;
    void onHoverExit() override;
    void click() override;

    virtual void setOnClickCallback(std::function<void()>&& onClickCallback);

private:
    SDL_Texture* loadTexture(const char* path) const;

    SDL_Texture* currentTexture;

    SDL_Texture* defaultImageTexture;
    SDL_Texture* hoverImageTexture;
    SDL_Texture* clickedImageTexture;

    Timer clickTimer;
    std::function<void()> onClickCallback;
};


#endif //BUTTON_H
