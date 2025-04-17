//
// Created by Juan Pablo Hernandez Mosti on 14/04/25.
//

#ifndef LABEL_H
#define LABEL_H

#include <string>
#include <SDL3_ttf/SDL_ttf.h>

#include "Widget.h"

class SDL_Texture;
class TTF_Font;


class Label : public Widget {
public:
    Label(
        const char* msg,
        const Position& position,
        float width,
        float height,
        uint8_t fontSize = 24,
        const Color& color = Color(255, 255, 255, 255),
        const char* pathToFont = nullptr,
        bool setWidthAutomatically = false,
        bool setHeightAutomatically = false);

    ~Label() override;

    void render() override;
    void onHoverEnter() override;
    void onHoverExit() override;

    void updateMessage(const char* msg);
private:
    TTF_Font *loadFont(const char *fontPath) const;
    SDL_Texture* loadTexture(TTF_Font *font, const char *msg);

    TTF_Font* font;
    SDL_Texture* texture;
    std::string pathToFont;
    uint8_t fontSize;
    Color color;

    bool automaticWidth;
    bool automaticHeight;

};



#endif //LABEL_H
