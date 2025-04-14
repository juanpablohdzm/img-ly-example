//
// Created by Juan Pablo Hernandez Mosti on 14/04/25.
//

#ifndef LABEL_H
#define LABEL_H

#include "Widget.h"

class SDL_Texture;


class Label : public Widget {
public:
    Label(
        const Position& position,
        int width,
        int height,
        const char* msg,
        const char* pathToFont = nullptr,
        uint8_t fontSize = 24,
        const Color& color = Color(255, 255, 255, 255));

    ~Label() override;

    void render() override;
    void onHoverEnter() override;
    void onHoverExit() override;

private:
    SDL_Texture* texture;

};



#endif //LABEL_H
