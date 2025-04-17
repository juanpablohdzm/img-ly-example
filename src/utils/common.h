//
// Created by Juan Pablo Hernandez Mosti on 10/04/25.
//

#ifndef COMMON_H
#define COMMON_H

// Tag used to identify entities that shouldn't pass beyond the window bounds
struct WindowGuard {
    float width;
    float height;
};

struct Position {
    float x;
    float y;
};

struct Velocity {
    float dx;
    float dy;
};

struct Speed {
    float value;
};

struct Color {
    int r;
    int g;
    int b;
    int a;
};

struct EnemyTag {
};

struct PlayerTag {
};
#endif //COMMON_H
