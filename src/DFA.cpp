//
// Created by Felix Klauke on 20.02.18.
//

#include <set>
#include <DFA.h>

DFA::DFA(std::set<State> states, const std::set<char> &alphabet, std::map<State, Transition> stateTransitions)
        : alphabet(alphabet), states(states), stateTransitions(stateTransitions) {
    this->alphabet = alphabet;
    this->states = states;
}

bool DFA::ProcessInput(std::string input) {
    return false;
}
