//
// Created by mrtnk on 2019-03-10.
//

#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include <memory>
#include <stack>

#include "State.hpp"

namespace Chauwa
{
    typedef std::unique_ptr<State> stateRef;

    class StateMachine
    {
    public:
        StateMachine();
        virtual ~StateMachine();

        void addState(stateRef newState, bool isReplacing = true);
        void removeState();

        void processStateChanges();

        stateRef &getActiveState();
    private:
        std::stack<stateRef> _states;
        stateRef _newState;

        bool _isRemoving;
        bool _isAdding;
        bool _isReplacing;
    };
}

#endif //STATEMACHINE_HPP
