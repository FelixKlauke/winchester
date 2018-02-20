//
// Created by Felix Klauke on 20.02.18.
//

#ifndef WINCHESTER_STATE_H
#define WINCHESTER_STATE_H

#include <string>

class State {
public:
    State(int id, const std::string &label);

private:
    int id;
    std::string label;
};


#endif //WINCHESTER_STATE_H