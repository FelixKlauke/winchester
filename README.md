# winchester
Fast and effective finite automaton software that can simulate acceptance tests in a state machine style.

# Example
_Creation and simple word test:_
```cpp
auto states = std::set<State>();
auto startState = State(0, "q0", false);
auto secondState = State(1, "q1", false);
auto thirdState = State(2, "q2", true);

states.insert(startState);
states.insert(secondState);
states.insert(thirdState);

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

auto accepted = dfa.ProcessInput("abaaaacab");
std::cout << "Accepted: " << accepted << std::endl;
```

_Create the complement (Accepts all words the former language didn't accept and vice versa):_
```cpp
auto complement = dfa.BuildComplement();
```

