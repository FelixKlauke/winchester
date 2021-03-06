#include <DFA.h>
#include <iostream>

int main() {
    auto states = std::set<State>();
    auto startState = State(0, "q0", false);
    auto secondState = State(1, "q1", false);
    auto thirdState = State(2, "q2", true);
    auto fourthState = State(3, "q3", false);

    states.insert(startState);
    states.insert(secondState);
    states.insert(thirdState);
    states.insert(fourthState);

    auto alphabet = std::set<char>();
    alphabet.insert('a');
    alphabet.insert('b');
    alphabet.insert('c');

    auto transitions = std::map<State, std::set<Transition>>();

    auto dfa = DFA(states, alphabet, transitions, startState);
    dfa.AddTransition(startState, Transition('a', secondState));
    dfa.AddTransition(startState, Transition('b', startState));
    dfa.AddTransition(startState, Transition('c', startState));

    dfa.AddTransition(secondState, Transition('a', secondState));
    dfa.AddTransition(secondState, Transition('b', thirdState));
    dfa.AddTransition(secondState, Transition('c', startState));

    dfa.AddTransition(thirdState, Transition('a', thirdState));
    dfa.AddTransition(thirdState, Transition('b', thirdState));
    dfa.AddTransition(thirdState, Transition('c', thirdState));

    dfa.AddTransition(fourthState, Transition('a', fourthState));
    dfa.AddTransition(fourthState, Transition('b', thirdState));
    dfa.AddTransition(fourthState, Transition('c', secondState));

    auto accepted = dfa.ProcessInput("aa");
    std::cout << "Accepted: " << accepted << std::endl;

    auto complement = dfa.BuildComplement();
}