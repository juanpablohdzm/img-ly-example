//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#ifndef BUTTON_H
#define BUTTON_H
#include <SDL3/SDL_rect.h>

class SDL_Renderer;
class SDL_Texture;

class Button {
public:
    Button(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);

    virtual ~Button();

    void render() const;
    [[nodiscard]] bool isClicked(int mouseX, int mouseY) const;

private:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    SDL_Rect buttonRect;
};


#endif //BUTTON_H
