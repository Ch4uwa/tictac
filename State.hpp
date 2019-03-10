//
// Created by mrtnk on 2019-03-10.
//

#ifndef STUFFTHING_STATE_HPP
#define STUFFTHING_STATE_HPP

namespace Chauwa
{
    class State
    {
    public:
        virtual void init() = 0;

        virtual void handleInput() = 0;
        virtual void update() = 0;
        virtual void draw(float dt) = 0;

        virtual void pause() = 0;
        virtual void resume() = 0;
    };
}
#endif //STUFFTHING_STATE_HPP
