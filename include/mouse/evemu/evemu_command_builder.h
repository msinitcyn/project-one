// evemu_command_builder.h
#pragma once

#include <string>

namespace ProjectOne::Mouse::Evemu {
    class EvemuCommandBuilder {
    public:
        virtual std::string build(std::string event, int type, int code, int value) = 0;

        virtual ~EvemuCommandBuilder() {
        }
    };
}
