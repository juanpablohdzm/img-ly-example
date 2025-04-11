//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#ifndef CLICKABLE_H
#define CLICKABLE_H



class Clickable {
public:
    virtual ~Clickable() = default;

    virtual void onClick() = 0;
};



#endif //CLICKABLE_H
